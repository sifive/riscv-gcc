/* RISC-V Function Signature Support for Control Flow Integrity (CFI).

   This file implements function signature-based CFI for RISC-V targets
   with the Zicfilp (Control Flow Integrity Landing Pad) extension.

   ARCHITECTURE OVERVIEW:
   ----------------------
   This implementation uses a two-tier approach for type mangling:

   1. C++ Code:
      - Uses lang_hooks.mangle_type → cp/mangle.cc
      - Full Itanium C++ ABI support
      - Handles templates, namespaces, member functions, etc.

   2. C Code (and fallback):
      - Uses simplified mangling in this file
      - Handles only C types: basic types, pointers, arrays, structs, functions
      - Does NOT handle C++ features (templates, namespaces, references, etc.)

   WHY WE NEED BOTH:
   -----------------
   - cp/mangle.cc is only compiled into cc1plus (C++ compiler)
   - It's NOT available in cc1 (C compiler) or lto1
   - It depends on C++ specific data structures (cp-tree.h)
   - C code cannot use cp/mangle.cc directly

   WHAT THIS FILE PROVIDES:
   ------------------------
   1. Simplified type mangling for C (riscv_mangle_type_string)
   2. GIMPLE pass to attach function signatures (pass_insert_func_sig)
   3. Integration with RISC-V LPAD instruction generation

   C++ SPECIFIC FEATURES (handled by lang_hooks.mangle_type):
   ----------------------------------------------------------
   - Templates and template arguments
   - Namespaces
   - Member functions (METHOD_TYPE)
   - References (lvalue and rvalue)
   - Exception specifications
   - Ref-qualifiers (& and &&)

   C FEATURES (handled by this file):
   -----------------------------------
   - Basic types (int, char, void, float, double, etc.)
   - Pointers
   - Arrays
   - Structs and unions
   - Function types
   - Variadic functions

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "c-family/c-common.h"
#include "backend.h"
#include "target.h"
#include "tree.h"
#include "gimple.h"
#include "stringpool.h"
#include "tree-pass.h"
#include "ssa.h"
#include "fold-const.h"
#include "cgraph.h"
#include "langhooks.h"
#include "gimple-pretty-print.h"
#include "gimple-iterator.h"
#include "cfgloop.h"
#include "cfghooks.h"
#include "attribs.h"
#include "asan.h"
#include "diagnostic-core.h"
#include "print-tree.h"
#include "flags.h"
#include "function.h"

/* Append a single character to the end of the mangled
 *    representation.  */
#define write_char(CHAR) \
  obstack_1grow (mangle_obstack, (CHAR))

/* Append a sized buffer to the end of the mangled representation.  */
#define write_chars(CHAR, LEN) \
  obstack_grow (mangle_obstack, (CHAR), (LEN))

/* Append a NUL-terminated string to the end of the mangled
 *    representation.  */
#define write_string(STRING) \
  obstack_grow (mangle_obstack, (STRING), strlen (STRING))

/* Write out an unsigned quantity in base 10.  */
#define write_unsigned_number(NUMBER) \
  write_number ((NUMBER), /*unsigned_p=*/1, 10)

/* 1 iff FUNCTION_TYPE or METHOD_TYPE has a ref-qualifier (either & or &&). */
#define FUNCTION_REF_QUALIFIED(NODE) \
  TREE_LANG_FLAG_4 (FUNC_OR_METHOD_CHECK (NODE))

/* 1 iff FUNCTION_TYPE or METHOD_TYPE has &&-ref-qualifier.  */
#define FUNCTION_RVALUE_QUALIFIED(NODE) \
  TREE_LANG_FLAG_5 (FUNC_OR_METHOD_CHECK (NODE))

#define same_type_p(TYPE1, TYPE2) \
  comptypes ((TYPE1), (TYPE2), 0)

#define COMPARE_STRICT        0
#define COMPARE_REDECLARATION 4
#define COMPARE_STRUCTURAL    8

/* The obstack on which we build mangled names.  */
static struct obstack *mangle_obstack;

/* The obstack on which we build mangled names that are not going to
   be IDENTIFIER_NODEs.  */
static struct obstack name_obstack;

/* The first object on the name_obstack; we use this to free memory
   allocated on the name_obstack.  */
static void *name_base;

/* ============================================================================
   TYPE MANGLING IMPLEMENTATION
   ============================================================================

   The following code implements a simplified version of the Itanium C++ ABI
   type mangling scheme. Much of this code is adapted from gcc/cp/mangle.cc,
   which provides the full C++ mangling implementation.

   KEY DIFFERENCES FROM cp/mangle.cc:
   ----------------------------------
   1. Simplified: Only handles C types and basic C++ constructs
   2. No C++ features: No templates, namespaces, references, etc.
   3. Fallback: Used when lang_hooks.mangle_type is not available

   ADAPTED FUNCTIONS:
   ------------------
   The following functions are adapted from cp/mangle.cc:
   - start_mangling, finish_mangling: Mangling session management
   - write_type, write_function_type: Type encoding
   - write_number, write_source_name: Basic encoding primitives
   - decl_mangling_context: Context determination (simplified for C)

   For full C++ support, use lang_hooks.mangle_type (cp/mangle.cc).
   ======================================================================== */

/* Things we only need one of.  This module is not reentrant.
   Adapted from cp/mangle.cc:globals. */
struct GTY(()) globals {
  /* An array of the current substitution candidates, in the order
     we've seen them.  Contains NULLS, which correspond to module
     substitutions.  */
  vec<tree, va_gc> *substitutions;

  /* The entity that is being mangled.  */
  tree GTY ((skip)) entity;

  /* How many parameter scopes we are inside.  */
  int parm_depth;
};

static GTY (()) globals G;

static void write_type (tree);
static void write_name (tree, const int);
static void write_number (unsigned HOST_WIDE_INT, const int,
			  const unsigned int);
static bool structural_comptypes (tree, tree, int);
static bool comptypes (tree, tree, int);

enum compare_bounds_t { bounds_none, bounds_either, bounds_first };

/* Single-letter codes for builtin integer types, defined in
   <builtin-type>.  These are indexed by integer_type_kind values.  */
static const char
integer_type_codes[itk_none] =
{
  'c',  /* itk_char */
  'a',  /* itk_signed_char */
  'h',  /* itk_unsigned_char */
  's',  /* itk_short */
  't',  /* itk_unsigned_short */
  'i',  /* itk_int */
  'j',  /* itk_unsigned_int */
  'l',  /* itk_long */
  'm',  /* itk_unsigned_long */
  'x',  /* itk_long_long */
  'y',  /* itk_unsigned_long_long */
  /* __intN types are handled separately */
  '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'
};

static inline void
start_mangling (const tree entity)
{
  G = {};
  G.entity = entity;

  static bool name_obstack_initialized = false;
  if (!name_obstack_initialized)
    {
      gcc_obstack_init (&name_obstack);
      name_base = obstack_alloc (&name_obstack, 0);
      name_obstack_initialized = true;
    }

  obstack_free (&name_obstack, name_base);
  mangle_obstack = &name_obstack;
}

static inline const char *
finish_mangling (void)
{
  /* Null-terminate the string.  */
  write_char ('\0');

  return (const char *) obstack_finish (mangle_obstack);
}

static bool
compparms (const_tree parms1, const_tree parms2)
{
  const_tree t1, t2;

  /* An unspecified parmlist matches any specified parmlist
     whose argument types don't need default promotions.  */

  for (t1 = parms1, t2 = parms2;
       t1 || t2;
       t1 = TREE_CHAIN (t1), t2 = TREE_CHAIN (t2))
    {
      /* If one parmlist is shorter than the other,
	 they fail to match.  */
      if (!t1 || !t2)
	return false;
      if (!same_type_p (TREE_VALUE (t1), TREE_VALUE (t2)))
	return false;
    }
  return true;
}

static bool
comp_array_types (const_tree t1, const_tree t2, compare_bounds_t cb,
		  bool strict)
{
  tree d1;
  tree d2;

  if (t1 == t2)
    return true;

  d1 = TYPE_DOMAIN (t1);
  d2 = TYPE_DOMAIN (t2);

  if (d1 == d2)
    return true;

  /* If one of the arrays is dimensionless, and the other has a
     dimension, they are of different types.  However, it is valid to
     write:

       extern int a[];
       int a[3];

     by [basic.link]:

       declarations for an array object can specify
       array types that differ by the presence or absence of a major
       array bound (_dcl.array_).  */
  if (!d1 && d2)
    return cb >= bounds_either;
  else if (d1 && !d2)
    return cb == bounds_either;

  return true;
}

/* Subroutine in comptypes.  */

static bool
structural_comptypes (tree t1, tree t2, int strict)
{
  /* Both should be types that are not obviously the same.  */
  gcc_checking_assert (t1 != t2 && TYPE_P (t1) && TYPE_P (t2));

  /* Different classes of types can't be compatible.  */
  if (TREE_CODE (t1) != TREE_CODE (t2))
    return false;

  /* Qualifiers must match.  For array types, we will check when we
     recur on the array element types.  */
  if (TREE_CODE (t1) != ARRAY_TYPE
      && TYPE_QUALS (t1) != TYPE_QUALS (t2))
    return false;

  /* Allow for two different type nodes which have essentially the same
     definition.  Note that we already checked for equality of the type
     qualifiers (just above).  */
  if (TREE_CODE (t1) != ARRAY_TYPE
      && TYPE_MAIN_VARIANT (t1) == TYPE_MAIN_VARIANT (t2))
    goto check_alias;

  /* Compare the types.  Return false on known not-same. Break on not
     known.   Never return true from this switch -- you'll break
     specialization comparison.    */
  switch (TREE_CODE (t1))
    {
    case VOID_TYPE:
    case BOOLEAN_TYPE:
      /* All void and bool types are the same.  */
      break;

    case OPAQUE_TYPE:
    case INTEGER_TYPE:
    case FIXED_POINT_TYPE:
    case REAL_TYPE:
      /* With these nodes, we can't determine type equivalence by
	 looking at what is stored in the nodes themselves, because
	 two nodes might have different TYPE_MAIN_VARIANTs but still
	 represent the same type.  For example, wchar_t and int could
	 have the same properties (TYPE_PRECISION, TYPE_MIN_VALUE,
	 TYPE_MAX_VALUE, etc.), but have different TYPE_MAIN_VARIANTs
	 and are distinct types. On the other hand, int and the
	 following typedef

	  typedef int INT __attribute((may_alias));

	 have identical properties, different TYPE_MAIN_VARIANTs, but
	 represent the same type.  The canonical type system keeps
	 track of equivalence in this case, so we fall back on it.  */
      if (TYPE_CANONICAL (t1) != TYPE_CANONICAL (t2))
	return false;

      /* We don't need or want the attribute comparison.  */
      goto check_alias;

    case RECORD_TYPE:
    case UNION_TYPE:
      return false;

    case REFERENCE_TYPE:
      if (TYPE_REF_IS_RVALUE (t1) != TYPE_REF_IS_RVALUE (t2))
	return false;
      /* fall through to checks for pointer types */
      gcc_fallthrough ();

    case POINTER_TYPE:
      if (TYPE_MODE (t1) != TYPE_MODE (t2)
	  || !same_type_p (TREE_TYPE (t1), TREE_TYPE (t2)))
	return false;
      break;

    case METHOD_TYPE:
    case FUNCTION_TYPE:
      /* Exception specs and memfn_rquals were checked above.  */
      if (!same_type_p (TREE_TYPE (t1), TREE_TYPE (t2)))
	return false;
      if (!compparms (TYPE_ARG_TYPES (t1), TYPE_ARG_TYPES (t2)))
	return false;
      break;

    case ARRAY_TYPE:
      /* Target types must match incl. qualifiers.  */
      if (!comp_array_types (t1, t2, ((strict & COMPARE_REDECLARATION)
				      ? bounds_either : bounds_none),
			     /*strict=*/true))
	return false;
      break;

    case COMPLEX_TYPE:
      if (!same_type_p (TREE_TYPE (t1), TREE_TYPE (t2)))
	return false;
      break;

    case VECTOR_TYPE:
      if (gnu_vector_type_p (t1) != gnu_vector_type_p (t2)
	  || maybe_ne (TYPE_VECTOR_SUBPARTS (t1), TYPE_VECTOR_SUBPARTS (t2))
	  || !same_type_p (TREE_TYPE (t1), TREE_TYPE (t2)))
	return false;
      break;

    default:
      return false;
    }

  /* If we get here, we know that from a target independent POV the
     types are the same.  Make sure the target attributes are also
     the same.  */
  if (!comp_type_attributes (t1, t2))
    return false;

 check_alias:

  return true;
}

/* Return true if T1 and T2 are related as allowed by STRICT.  STRICT
   is a bitwise-or of the COMPARE_* flags.  */

static bool
comptypes (tree t1, tree t2, int strict)
{
  gcc_checking_assert (t1 && t2);

  /* TYPE_ARGUMENT_PACKS are not really types.  */
  gcc_checking_assert (TREE_CODE (t1) != TYPE_ARGUMENT_PACK
		       && TREE_CODE (t2) != TYPE_ARGUMENT_PACK);

  if (t1 == t2)
    return true;

  /* Suppress errors caused by previously reported errors.  */
  if (t1 == error_mark_node || t2 == error_mark_node)
    return false;

  if (strict == COMPARE_STRICT)
    {
      if (TYPE_STRUCTURAL_EQUALITY_P (t1) || TYPE_STRUCTURAL_EQUALITY_P (t2))
	/* At least one of the types requires structural equality, so
	   perform a deep check. */
	return structural_comptypes (t1, t2, strict);

      if (flag_checking && param_use_canonical_types)
	{
	  bool result = structural_comptypes (t1, t2, strict);

	  if (result && TYPE_CANONICAL (t1) != TYPE_CANONICAL (t2))
	    /* The two types are structurally equivalent, but their
	       canonical types were different. This is a failure of the
	       canonical type propagation code.*/
	    internal_error
	      ("canonical types differ for identical types %qT and %qT",
	       t1, t2);
	  else if (!result && TYPE_CANONICAL (t1) == TYPE_CANONICAL (t2))
	    /* Two types are structurally different, but the canonical
	       types are the same. This means we were over-eager in
	       assigning canonical types. */
	    internal_error
	      ("same canonical type node for different types %qT and %qT",
	       t1, t2);

	  return result;
	}
      if (!flag_checking && param_use_canonical_types)
	return TYPE_CANONICAL (t1) == TYPE_CANONICAL (t2);
      else
	return structural_comptypes (t1, t2, strict);
    }
  else if (strict == COMPARE_STRUCTURAL)
    return structural_comptypes (t1, t2, COMPARE_STRICT);
  else
    return structural_comptypes (t1, t2, strict);
}

static inline tree
canonicalize_for_substitution (tree node)
{
  /* For a TYPE_DECL, use the type instead.  */
  if (TREE_CODE (node) == TYPE_DECL)
    node = TREE_TYPE (node);
  if (TYPE_P (node)
      && TYPE_CANONICAL (node) != node
      && TYPE_MAIN_VARIANT (node) != node)
    {
      /* Here we want to strip the topmost typedef only.
	 We need to do that so is_std_substitution can do proper
	 name matching.  */
      if (TREE_CODE (node) == FUNCTION_TYPE)
	/* Use build_qualified_type and TYPE_QUALS here to preserve
	   the old buggy mangling of attribute noreturn with abi<5.  */
	node = build_qualified_type (TYPE_MAIN_VARIANT (node),
				     TYPE_QUALS (node));
    }
  return node;
}

static void
write_substitution (const int seq_id)
{
  write_char ('S');
  if (seq_id > 0)
    write_number (seq_id - 1, /*unsigned=*/1, 36);
  write_char ('_');
}

static void
add_substitution (tree node)
{
  tree c;

  /* Get the canonicalized substitution candidate for NODE.  */
  c = canonicalize_for_substitution (node);
  node = c;

  /* Put the decl onto the varray of substitution candidates.  */
  vec_safe_push (G.substitutions, node);
}

static int
find_substitution (tree node)
{
  int i;
  const int size = vec_safe_length (G.substitutions);
  tree decl;
  tree type;

  /* Obtain the canonicalized substitution representation for NODE.
     This is what we'll compare against.  */
  node = canonicalize_for_substitution (node);

  /* Check for builtin substitutions.  */

  decl = TYPE_P (node) ? TYPE_NAME (node) : node;
  type = TYPE_P (node) ? node : TREE_TYPE (node);


  /* Now check the list of available substitutions for this mangling
     operation.  */
    for (i = 0; i < size; ++i)
      if (tree candidate = (*G.substitutions)[i])
	{
	  /* NODE is a matched to a candidate if it's the same decl node or
	     if it's the same type.  */

	  if (decl == candidate
	      || (TYPE_P (candidate) && type && TYPE_P (node)
		  && same_type_p (type, candidate)))
	    {
	      write_substitution (i);
	      return 1;
	    }
	}

  return 0;
}

/* Check for -fabi-version dependent mangling and also set the need_abi_warning
 *    flag as appropriate.  */
static bool
abi_check (int ver)
{
  return abi_version_at_least (ver);
}

static void
write_compact_number (int num)
{
  gcc_checking_assert (num >= 0);
  if (num > 0)
    write_unsigned_number (num - 1);
  write_char ('_');
}

static void
write_identifier (const char *identifier)
{
  write_string (identifier);
}

static void
write_source_name (tree identifier)
{
  write_unsigned_number (IDENTIFIER_LENGTH (identifier));
  write_identifier (IDENTIFIER_POINTER (identifier));
}

static int
discriminator_for_string_literal (tree /*function*/,
				  tree /*string*/)
{
  /* For now, we don't discriminate amongst string literals.  */
  return 0;
}

static int
hwint_to_ascii (unsigned HOST_WIDE_INT number, const unsigned int base,
		char *buffer, const unsigned int min_digits)
{
  static const char base_digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unsigned digits = 0;

  while (number)
    {
      unsigned HOST_WIDE_INT d = number / base;

      *--buffer = base_digits[number - d * base];
      digits++;
      number = d;
    }
  while (digits < min_digits)
    {
      *--buffer = base_digits[0];
      digits++;
    }
  return digits;
}

static void
write_number (unsigned HOST_WIDE_INT number, const int unsigned_p,
	      const unsigned int base)
{
  char buffer[sizeof (HOST_WIDE_INT) * 8];
  unsigned count = 0;

  if (!unsigned_p && (HOST_WIDE_INT) number < 0)
    {
      write_char ('n');
      number = -((HOST_WIDE_INT) number);
    }
  count = hwint_to_ascii (number, base, buffer + sizeof (buffer), 1);
  write_chars (buffer + sizeof (buffer) - count, count);
}

static void
write_discriminator (const int discriminator)
{
  /* If discriminator is zero, don't write anything.  Otherwise...  */
  if (discriminator > 0)
    {
      write_char ('_');
      if (discriminator - 1 >= 10)
	{
	  if (abi_check (11))
	    write_char ('_');
	}
      write_unsigned_number (discriminator - 1);
      if (abi_version_at_least (11) && discriminator - 1 >= 10)
	write_char ('_');
    }
}


/* Non-terminal <builtin-type>.

     <builtin-type> ::= v   # void
		    ::= b   # bool
		    ::= w   # wchar_t
		    ::= c   # char
		    ::= a   # signed char
		    ::= h   # unsigned char
		    ::= s   # short
		    ::= t   # unsigned short
		    ::= i   # int
		    ::= j   # unsigned int
		    ::= l   # long
		    ::= m   # unsigned long
		    ::= x   # long long, __int64
		    ::= y   # unsigned long long, __int64
		    ::= n   # __int128
		    ::= o   # unsigned __int128
		    ::= f   # float
		    ::= d   # double
		    ::= e   # long double, __float80
		    ::= g   # __float128          [not supported]
		    ::= u <source-name>  # vendor extended type */

static void
write_builtin_type (tree type)
{
  if (TYPE_CANONICAL (type))
    type = TYPE_CANONICAL (type);

  switch (TREE_CODE (type))
    {
    case VOID_TYPE:
      write_char ('v');
      break;

    case BOOLEAN_TYPE:
      write_char ('b');
      break;

    case INTEGER_TYPE:
      {
	size_t itk;
	/* Assume TYPE is one of the shared integer type nodes.  Find
	   it in the array of these nodes.  */
	iagain:
	  for (itk = 0; itk < itk_none; ++itk)
	    if (integer_types[itk] != NULL_TREE
		&& integer_type_codes[itk] != '\0'
		&& type == integer_types[itk])
	      {
		/* Print the corresponding single-letter code.  */
		write_char (integer_type_codes[itk]);
		break;
	      }

	if (itk == itk_none)
	  {
	    tree t = lang_hooks.types.type_for_mode (TYPE_MODE (type),
						     TYPE_UNSIGNED (type));
	    if (type != t)
	      {
		type = t;
		goto iagain;
	      }

	    if (TYPE_PRECISION (type) == 128)
	      write_char (TYPE_UNSIGNED (type) ? 'o' : 'n');
	    else
	      {
		/* Allow for cases where TYPE is not one of the shared
		  integer type nodes and write a "vendor extended builtin
		  type" with a name the form intN or uintN, respectively.
		  Situations like this can happen if you have an
		  __attribute__((__mode__(__SI__))) type and use exotic
		  switches like '-mint8' on AVR.  Of course, this is
		  undefined by the C++ ABI (and '-mint8' is not even
		  Standard C conforming), but when using such special
		  options you're pretty much in nowhere land anyway.  */
		const char *prefix;
		char prec[11];	/* up to ten digits for an unsigned */

		prefix = TYPE_UNSIGNED (type) ? "uint" : "int";
		sprintf (prec, "%u", (unsigned) TYPE_PRECISION (type));
		write_char ('u');	/* "vendor extended builtin type" */
		write_unsigned_number (strlen (prefix) + strlen (prec));
		write_string (prefix);
		write_string (prec);
	      }
	  }
      }
      break;

    case REAL_TYPE:
      if (type == float_type_node)
	write_char ('f');
      else if (type == double_type_node)
	write_char ('d');
      else if (type == long_double_type_node)
	write_char ('e');
      else if (type == dfloat32_type_node)
	write_string ("Df");
      else if (type == dfloat64_type_node)
	write_string ("Dd");
      else if (type == dfloat128_type_node)
	write_string ("De");
      else if (type == float16_type_node)
	write_string ("DF16_");
      else if (type == float32_type_node)
	write_string ("DF32_");
      else if (type == float64_type_node)
	write_string ("DF64_");
      else if (type == float128_type_node)
	write_string ("DF128_");
      else if (type == float32x_type_node)
	write_string ("DF32x");
      else if (type == float64x_type_node)
	write_string ("DF64x");
      else if (type == float128x_type_node)
	write_string ("DF128x");
      else if (type == bfloat16_type_node)
	write_string ("DF16b");
      else
	{
	  /* Unknown floating point type - this should not happen in normal
	     code.  If we reach here, it means a new floating point type was
	     added to GCC but not handled in this mangling code.  Use a
	     generic encoding.  */
	  if (dump_file)
	    fprintf (dump_file,
		     "  warning: unknown floating point type, "
		     "using generic encoding\n");
	  write_string ("DFunk");
	}
      break;

    default:
      /* Unknown type code - this should not happen in normal C code.
	 For C++ code, lang_hooks.mangle_type should be used instead.
	 If we reach here, it likely means:
	 1. A new type was added to GCC but not handled here
	 2. C++ code is being processed without lang_hooks.mangle_type
	 3. The type is corrupted or invalid

	 We don't crash - just skip this type and let the caller handle it. */
      if (dump_file)
	fprintf (dump_file, "  warning: unsupported type code %d (%s), skipping\n",
		 TREE_CODE (type), get_tree_code_name (TREE_CODE (type)));
      break;
    }
}

/* Write the mangled representation of a method parameter list of
   types given in PARM_TYPES.  If METHOD_P is nonzero, the function is
   considered a non-static method, and the this parameter is omitted.
   If non-NULL, DECL is the FUNCTION_DECL for the function whose
   parameters are being emitted.  */

static void
write_method_parms (tree parm_types)
{
  tree first_parm_type;

  /* Assume this parameter type list is variable-length.  If it ends
     with a void type, then it's not.  */
  int varargs_p = 1;

  if (parm_types == NULL)
    {
      write_char ('v');
      varargs_p = 0;
    }
  else
    {
      for (first_parm_type = parm_types;
	   parm_types;
	   parm_types = TREE_CHAIN (parm_types))
	{
	  tree parm = TREE_VALUE (parm_types);
	  if (parm == void_type_node)
	    {
	      /* "Empty parameter lists, whether declared as () or
		 conventionally as (void), are encoded with a void parameter
		 (v)."  */
	      if (parm_types == first_parm_type)
		write_type (parm);
	      /* If the parm list is terminated with a void type, it's
		 fixed-length.  */
	      varargs_p = 0;
	      /* A void type better be the last one.  */
	      gcc_assert (TREE_CHAIN (parm_types) == NULL);
	    }
	  else
	    write_type (parm);
	}
    }

  if (varargs_p)
    /* <builtin-type> ::= z  # ellipsis  */
    write_char ('z');
}

/* Non-terminal <bare-function-type>.  TYPE is a FUNCTION_TYPE or
   METHOD_TYPE.  If INCLUDE_RETURN_TYPE is nonzero, the return value
   is mangled before the parameter types.  If non-NULL, DECL is
   FUNCTION_DECL for the function whose type is being emitted.  */

static void
write_bare_function_type (const tree type, const int include_return_type_p)
{
  /* Mangle the return type, if requested.  */
  if (include_return_type_p)
    write_type (TREE_TYPE (type));

  /* Now mangle the types of the arguments.  */
  ++G.parm_depth;
  write_method_parms (TYPE_ARG_TYPES (type));
  --G.parm_depth;
}

/* Non-terminal <function-type>.  NODE is a FUNCTION_TYPE or
   METHOD_TYPE.  The return type is mangled before the parameter
   types.

     <function-type> ::= F [Y] <bare-function-type> [<ref-qualifier>] E   */

static void
write_function_type (const tree type)
{
  write_char ('F');
  /* We don't track whether or not a type is `extern "C"'.  Note that
     you can have an `extern "C"' function that does not have
     `extern "C"' type, and vice versa:

       extern "C" typedef void function_t();
       function_t f; // f has C++ linkage, but its type is
		     // `extern "C"'

       typedef void function_t();
       extern "C" function_t f; // Vice versa.

     See [dcl.link].  */
  write_bare_function_type (type, /*include_return_type_p=*/1);
  if (FUNCTION_REF_QUALIFIED (type))
    {
      if (FUNCTION_RVALUE_QUALIFIED (type))
	write_char ('O');
      else
	write_char ('R');
    }
  write_char ('E');
}

/* Lambdas can have a bit more context for mangling, specifically VAR_DECL
   or PARM_DECL context, which doesn't belong in DECL_CONTEXT.  */

static tree
decl_mangling_context (tree decl)
{
  /* Safety check: if decl is NULL, return NULL */
  if (decl == NULL_TREE)
    return NULL_TREE;

  tree tcontext = targetm.cxx.decl_mangling_context (decl);

  if (tcontext != NULL_TREE)
    return tcontext;

  if (TREE_CODE (decl) != IDENTIFIER_NODE)
    {
      /* For C language, just use DECL_CONTEXT.
	 For C++, CP_DECL_CONTEXT would be used, but we can't use it here
	 because it's C++ specific and requires global_namespace.
	 Since we're in riscv-func-sig.cc (not cp/mangle.cc), we use
	 DECL_CONTEXT for both C and C++. */
      tcontext = DECL_CONTEXT (decl);
    }
  else
    tcontext = NULL_TREE;

  return tcontext;
}

/*   <encoding>		::= <function name> <bare-function-type>
			::= <data name>  */

static void
write_encoding (const tree decl)
{
  write_name (decl, /*ignore_local_scope=*/0);
  if (TREE_CODE (decl) == FUNCTION_DECL)
    {
      tree fn_type;
      fn_type = TREE_TYPE (decl);
      write_bare_function_type (fn_type, 0);
    }
}

static void
write_unqualified_name (tree decl)
{
  bool found = false;

  if (DECL_NAME (decl) == NULL_TREE)
    {
      /* If no DECL_NAME, try to use DECL_ASSEMBLER_NAME */
      if (DECL_ASSEMBLER_NAME_SET_P (decl))
	{
	  found = true;
	  write_source_name (DECL_ASSEMBLER_NAME (decl));
	}
      else
	{
	  /* No name at all, skip this decl */
	  found = true;
	  return;
	}
    }

  if (found)
    /* OK */;
  else
    {
      if (TREE_CODE (decl) == IDENTIFIER_NODE)
	write_source_name (decl);
      else
	write_source_name (DECL_NAME (decl));
    }
}

/* <unscoped-name> ::= <unqualified-name>
		   ::= St <unqualified-name>   # ::std::  */

static void
write_unscoped_name (const tree decl)
{
  tree context = decl_mangling_context (decl);

    {
      /* If not, it should be either in the global namespace, or directly
	 in a local function scope.  A lambda can also be mangled in the
	 scope of a default argument.  */
      gcc_assert (context == NULL_TREE
		  || TREE_CODE (context) == PARM_DECL
		  || TREE_CODE (context) == FUNCTION_DECL);

      write_unqualified_name (decl);
    }
}

static void
write_local_name (tree function, const tree local_entity,
		  const tree entity)
{
  tree parm = NULL_TREE;

  if (TREE_CODE (function) == PARM_DECL)
    {
      parm = function;
      function = DECL_CONTEXT (parm);
    }

  write_char ('Z');
  write_encoding (function);
  write_char ('E');

  /* For this purpose, parameters are numbered from right-to-left.  */
  if (parm)
    {
      int i = list_length (parm);
      write_char ('d');
      write_compact_number (i - 1);
    }

  if (TREE_CODE (entity) == STRING_CST)
    {
      write_char ('s');
      write_discriminator (discriminator_for_string_literal (function,
							     entity));
    }
  else
    {
      /* Now the <entity name>.  Let write_name know its being called
	 from <local-name>, so it doesn't try to process the enclosing
	 function scope again.  */
      write_name (entity, /*ignore_local_scope=*/1);
    }
}

/* <prefix> ::= <prefix> <unqualified-name>
	    ::= <template-param>
	    ::= <template-prefix> <template-args>
	    ::= <decltype>
	    ::= # empty
	    ::= <substitution>  */

static void
write_prefix (const tree node)
{
  tree decl;

  if (node == NULL)
    return;

  if (TREE_CODE (node) == DECLTYPE_TYPE)
    {
      write_type (node);
      return;
    }

  if (find_substitution (node))
    return;

  if (DECL_P (node))
    {
      /* If this is a function or parm decl, that means we've hit function
	 scope, so this prefix must be for a local name.  In this
	 case, we're under the <local-name> production, which encodes
	 the enclosing function scope elsewhere.  So don't continue
	 here.  */
      if (TREE_CODE (node) == FUNCTION_DECL
	  || TREE_CODE (node) == PARM_DECL)
	return;

      decl = node;
    }
  else
    {
      /* Node is a type.  */
      decl = TYPE_NAME (node);
    }

  /* Safety check: if decl or its type is NULL, we can't proceed.  */
  if (decl == NULL_TREE || TREE_TYPE (decl) == NULL_TREE)
    return;

  if (TREE_CODE (TREE_TYPE (decl)) == TYPENAME_TYPE)
    {
      write_prefix (decl_mangling_context (decl));
      write_unqualified_name (decl);
    }
  else
    /* Not templated.  */
    {
      write_prefix (decl_mangling_context (decl));
      write_unqualified_name (decl);
      if (VAR_P (decl)
	  || TREE_CODE (decl) == FIELD_DECL)
	{
	  /* <data-member-prefix> := <member source-name> M */
	  write_char ('M');

	  /* Before ABI 18, we did not count these as substitution
	     candidates.  This leads to incorrect demanglings (and
	     ABI divergence to other compilers).  */
	  if (!abi_check (18))
	    return;
	}
    }

  add_substitution (node);
}

static void
write_nested_name (const tree decl)
{
  write_char ('N');
  write_prefix (decl_mangling_context (decl));
  write_unqualified_name (decl);
  write_char ('E');
}

static void
write_name (tree decl, const int ignore_local_scope)
{
  tree context;

  /* Safety check: if decl is NULL, we can't proceed */
  if (decl == NULL_TREE)
    return;

  context = decl_mangling_context (decl);

  /* A decl in :: or ::std scope is treated specially.  The former is
     mangled using <unscoped-name> or <unscoped-template-name>, the
     latter with a special substitution.  Also, a name that is
     directly in a local function scope is also mangled with
     <unscoped-name> rather than a full <nested-name>.  */
  if (context == NULL_TREE
      || (ignore_local_scope
	  && (TREE_CODE (context) == FUNCTION_DECL
	      || (abi_version_at_least (7)
		  && TREE_CODE (context) == PARM_DECL))))
    {
	/* Everything else gets an <unqualified-name>.  */
	write_unscoped_name (decl);
    }
  else
    {
      /* Handle local names, unless we asked not to (that is, invoked
	 under <local-name>, to handle only the part of the name under
	 the local scope).  */
      if (!ignore_local_scope)
	{
	  /* Scan up the list of scope context, looking for a
	     function.  If we find one, this entity is in local
	     function scope.  local_entity tracks context one scope
	     level down, so it will contain the element that's
	     directly in that function's scope, either decl or one of
	     its enclosing scopes.  */
	  tree local_entity = decl;
	  while (context != NULL_TREE)
	    {
	      /* Make sure we're always dealing with decls.  */
	      if (TYPE_P (context))
		{
		  context = TYPE_NAME (context);
		  /* If TYPE_NAME is NULL, we can't continue.  */
		  if (context == NULL_TREE)
		    break;
		}
	      /* Is this a function?  */
	      if (TREE_CODE (context) == FUNCTION_DECL
		  || TREE_CODE (context) == PARM_DECL)
		{
		  /* Yes, we have local scope.  Use the <local-name>
		     production for the innermost function scope.  */
		  write_local_name (context, local_entity, decl);
		  return;
		}
	      /* Up one scope level.  */
	      local_entity = context;
	      context = decl_mangling_context (context);
	    }

	  /* No local scope found?  Fall through to <nested-name>.  */
	}

      /* Other decls get a <nested-name> to encode their scope.  */
      write_nested_name (decl);
    }
}

/* <class-enum-type> ::= <name>  */

static void
write_class_enum_type (const tree type)
{
  tree type_name = TYPE_NAME (type);

  /* If TYPE_NAME is an IDENTIFIER_NODE (C language), we need to create
     a temporary TYPE_DECL for mangling purposes. Do NOT modify the
     original TYPE_NAME as it would affect subsequent passes (e.g., strub).  */
  if (TREE_CODE (type_name) == IDENTIFIER_NODE)
    {
      tree typedef_decl = build_decl (UNKNOWN_LOCATION, TYPE_DECL,
				      type_name, type);
      TREE_TYPE (typedef_decl) = type;
      DECL_ARTIFICIAL (typedef_decl) = 1;
      DECL_CONTEXT (typedef_decl) = NULL_TREE;
      type_name = typedef_decl;
      /* Do NOT modify TYPE_NAME (type) here!  */
    }
  write_name (type_name, /*ignore_local_scope=*/0);
}

static void
write_array_type (const tree type)
{
  write_char ('A');
  if (TYPE_DOMAIN (type))
    {
      tree index_type;

      index_type = TYPE_DOMAIN (type);
      /* The INDEX_TYPE gives the upper and lower bounds of the array.
	 It's null for flexible array members which have no upper bound
	 (this is a change from GCC 5 and prior where such members were
	 incorrectly mangled as zero-length arrays).  */
      if (tree max = TYPE_MAX_VALUE (index_type))
	{
	  if (TREE_CODE (max) == INTEGER_CST)
	    {
	      /* The ABI specifies that we should mangle the number of
		 elements in the array, not the largest allowed index.  */
	      offset_int wmax = wi::to_offset (max) + 1;
	      /* Truncate the result - this will mangle [0, SIZE_INT_MAX]
		 number of elements as zero.  */
	      wmax = wi::zext (wmax, TYPE_PRECISION (TREE_TYPE (max)));
	      gcc_assert (wi::fits_uhwi_p (wmax));
	      write_unsigned_number (wmax.to_uhwi ());
	    }
	  else
	    {
	      /* Detected VLA: its bound is not an INTEGER_CST, so the number
		 of elements is only known at runtime and cannot be encoded in
		 a compile-time function signature.  We intentionally omit the
		 element count and element type from the mangled representation
		 so that VLAs are not included in the CFI signature mangling.
		 This is safe for CFI purposes because VLA parameters are
		 typically passed as pointers anyway.  */
	      return;
	    }
	}
    }
  write_char ('_');
  write_type (TREE_TYPE (type));
}

static int
write_CV_qualifiers_for_type (const tree type)
{
  int num_qualifiers = 0;

  /* The order is specified by:

       "In cases where multiple order-insensitive qualifiers are
       present, they should be ordered 'K' (closest to the base type),
       'V', 'r', and 'U' (farthest from the base type) ..."  */

  /* Mangle attributes that affect type identity as extended qualifiers.

     We don't do this with classes and enums because their attributes
     are part of their definitions, not something added on.  */
  int quals = TYPE_QUALS (type);

  if (quals & TYPE_QUAL_RESTRICT)
    {
      write_char ('r');
      ++num_qualifiers;
    }
  if (quals & TYPE_QUAL_VOLATILE)
    {
      write_char ('V');
      ++num_qualifiers;
    }
  if (quals & TYPE_QUAL_CONST)
    {
      write_char ('K');
      ++num_qualifiers;
    }

  return num_qualifiers;
}

static void
write_type (tree type)
{
  /* This gets set to nonzero if TYPE turns out to be a (possibly
     CV-qualified) builtin type.  */
  int is_builtin_type = 0;

  if (type == error_mark_node)
    return;

  type = canonicalize_for_substitution (type);
  if (find_substitution (type))
    return;

  if (write_CV_qualifiers_for_type (type) > 0)
    /* If TYPE was CV-qualified, we just wrote the qualifiers; now
       mangle the unqualified type.  The recursive call is needed here
       since both the qualified and unqualified types are substitution
       candidates.

       NOTE: In C, CV qualifiers on function parameters are part of the
       function type. For example:
         void foo(const int *p);  // Different from void foo(int *p);

       However, in some edge cases (e.g., with sanitizer instrumentation
       or certain type transformations), TYPE_MAIN_VARIANT may return the
       same type even when TYPE_QUALS indicates CV qualifiers are present.
       This can happen when the type system is in an inconsistent state
       during compilation passes.

       We handle this by only recursing if TYPE_MAIN_VARIANT actually
       returns a different type, avoiding infinite recursion.  */
    {
      tree t = TYPE_MAIN_VARIANT (type);
      if (t != type)
	write_type (t);
      /* When T == TYPE, there is no distinct unqualified variant to
	 mangle: the qualifiers we just wrote fully describe this type,
	 so we intentionally avoid recursing here.  */
    }
  else if (TREE_CODE (type) == ARRAY_TYPE)
    write_array_type (type);
  else
    {
      tree type_orig = type;

      /* See through any typedefs.  */
      type = TYPE_MAIN_VARIANT (type);

      /* According to the C++ ABI, some library classes are passed the
	 same as the scalar type of their single member and use the same
	 mangling.  */
      if (TREE_CODE (type) == RECORD_TYPE && TYPE_TRANSPARENT_AGGR (type))
	type = TREE_TYPE (first_field (type));

	  /* Handle any target-specific fundamental types.  */
	  const char *target_mangling
	    = targetm.mangle_type (type_orig);

	  if (target_mangling)
	    {
	      write_string (target_mangling);
	      /* Add substitutions for types other than fundamental
		 types.  */
	      if (!VOID_TYPE_P (type)
		  && TREE_CODE (type) != INTEGER_TYPE
		  && TREE_CODE (type) != REAL_TYPE
		  && TREE_CODE (type) != BOOLEAN_TYPE)
		add_substitution (type);
	      return;
	    }

	  switch (TREE_CODE (type))
	    {
	    case VOID_TYPE:
	    case BOOLEAN_TYPE:
	    case INTEGER_TYPE:  /* Includes wchar_t.  */
	    case REAL_TYPE:
	    case FIXED_POINT_TYPE:
	      {
		/* If this is a typedef, TYPE may not be one of
		   the standard builtin type nodes, but an alias of one.  Use
		   TYPE_MAIN_VARIANT to get to the underlying builtin type.  */
		write_builtin_type (TYPE_MAIN_VARIANT (type));
		++is_builtin_type;
	      }
	      break;

	    case COMPLEX_TYPE:
	      write_char ('C');
	      write_type (TREE_TYPE (type));
	      break;

	    case FUNCTION_TYPE:
	    case METHOD_TYPE:
	      write_function_type (type);
	      break;

	    case UNION_TYPE:
	    case RECORD_TYPE:
	    case ENUMERAL_TYPE:
	      /* Filter out problematic anonymous structs like:
		 void f(struct {int b;}) {}. and struct { char (*p)[++n]; }  */
	      if (TYPE_NAME (type))
		{
		  /* Skip types with hardbool attribute - they can cause issues
		     in mangling due to their special handling */
		  if (lookup_attribute ("hardbool", TYPE_ATTRIBUTES (type)))
		    break;

		  write_class_enum_type (type);
		}

	      break;

	    case POINTER_TYPE:
	    case REFERENCE_TYPE:
	      if (TREE_CODE (type) == POINTER_TYPE)
		write_char ('P');
	      else if (TYPE_REF_IS_RVALUE (type))
		write_char ('O');
	      else
		write_char ('R');
	      {
		tree target = TREE_TYPE (type);
		/* Attribute const/noreturn are not reflected in mangling.
		   We strip them here rather than at a lower level because
		   a typedef or template argument can have function type
		   with function-cv-quals (that use the same representation),
		   but you can't have a pointer/reference to such a type.  */
		if (TREE_CODE (target) == FUNCTION_TYPE)
		  {
		    if (abi_version_at_least (5))
		      target = build_qualified_type (target, TYPE_UNQUALIFIED);
		  }
		write_type (target);
	      }
	      break;

	    case VECTOR_TYPE:
	      if (abi_version_at_least (4))
		{
		  write_string ("Dv");
		  /* Non-constant vector size would be encoded with
		     _ expression, but we don't support that yet.  */
		  write_unsigned_number (TYPE_VECTOR_SUBPARTS (type)
					 .to_constant ());
		  write_char ('_');
		}
	      else
		write_string ("U8__vector");

	      write_type (TREE_TYPE (type));
	      break;
	    case NULLPTR_TYPE:
	      write_string ("Dn");
	      if (abi_check (7))
		++is_builtin_type;
	      break;

	    case TYPEOF_TYPE:
	      sorry ("mangling %<typeof%>, use %<decltype%> instead");
	      break;

	    case TRAIT_TYPE:
	      error ("use of built-in trait %qT in function signature; "
		     "use library traits instead", type);
	      break;

	    case LANG_TYPE:
	      /* Language-specific types should be handled by
		 lang_hooks.mangle_type.  If we reach here, it means we're
		 trying to mangle a language-specific type without using the
		 language hook.  This is likely a bug.  */
	      if (dump_file)
		fprintf (dump_file,
			 "  warning: LANG_TYPE encountered, "
			 "should use lang_hooks.mangle_type\n");
	      /* fall through.  */

	    default:
	      /* Unknown type - this should not happen in normal code.
		 We don't crash - just skip and let the caller handle it. */
	      if (dump_file)
		fprintf (dump_file, "  warning: unsupported type in write_type: %s\n",
			 get_tree_code_name (TREE_CODE (type)));
	      break;
	    }
    }

  /* Types other than builtin types are substitution candidates.  */
  if (!is_builtin_type)
    add_substitution (type);
}

/* Generate the mangled representation of TYPE for function signatures.

   This is the main entry point for type mangling in the func_sig pass.
   It provides a fallback mangling implementation for C code and when
   lang_hooks.mangle_type is not available or returns NULL.

   MANGLING SCHEME:
   ----------------
   Uses a simplified version of the Itanium C++ ABI mangling:
   - Function types: F<return-type><param-types>E
   - Basic types: v (void), i (int), c (char), d (double), etc.
   - Pointers: P<type>
   - Arrays: A<size>_<type>
   - Structs: <length><name>

   EXAMPLES:
   ---------
   - int(int, int)     -> "FiiiE"
   - void(void)        -> "FvvE"
   - int*(char)        -> "FPicE"
   - void(int, ...)    -> "FvizE"  (z = ellipsis)

   LIMITATIONS:
   ------------
   - Does NOT handle C++ features (templates, namespaces, references)
   - Does NOT handle complex C++ member functions

   For C++ code, lang_hooks.mangle_type should be used instead, which
   provides full Itanium C++ ABI support via cp/mangle.cc.

   PARAMETERS:
   -----------
   type: The tree node representing the type to mangle. Must be a valid
	 FUNCTION_TYPE, METHOD_TYPE, or other supported type.

   RETURNS:
   --------
   A NUL-terminated string containing the mangled representation.
   The returned string is allocated on the mangling obstack and remains
   valid until the next call to this function.  */

const char *
riscv_mangle_type_string (const tree type)
{
  const char *result;

  start_mangling (type);
  write_type (type);
  result = finish_mangling ();
  return result;
}

/* Helper function to remove exception specification from mangled signature.
   Exception specs are encoded according to Itanium C++ ABI as:
   - "Do" for noexcept/noexcept(true)/throw()
   - "DO...E" for noexcept(expr) where expr is template-dependent
   - "Dw...E" for throw(type1, type2, ...)
   - "Dx" for transaction-safe

   We need to remove these from the signature for func_sig pass,
   as exception specs should not affect CFI signatures.

   Note: The returned string is allocated with xmalloc and the caller
   is responsible for freeing it when no longer needed.  */
static const char *
remove_exception_spec_from_signature (const char *mangled)
{
  if (!mangled || !*mangled)
    return mangled;

  size_t len = strlen (mangled);
  char *result = (char *) xmalloc (len + 1);
  const char *src = mangled;
  char *dst = result;

  while (*src)
    {
      if (*src == 'D' && src[1])
	{
	  if (src[1] == 'o')
	    {
	      /* Skip "Do" (noexcept) */
	      src += 2;
	      continue;
	    }
	  else if (src[1] == 'O')
	    {
	      /* Skip "DO...E" (noexcept(expr)).  The depth counter tracks
		 nested exception specifications.  While nested exception
		 specs are rare in practice, they can occur in template
		 contexts.  Each "DO" or "Dw" opens a new level, and each
		 "E" closes one.  We only increment depth when we see a
		 complete "DO" or "Dw" sequence to avoid false matches.  */
	      src += 2;
	      int depth = 1;
	      while (*src && depth > 0)
		{
		  if (*src == 'E')
		    depth--;
		  /* Check for nested exception specs.  We need to verify
		     src[1] is valid before accessing it.  Only increment
		     depth for complete "DO" or "Dw" sequences.  */
		  else if (*src == 'D' && src[1]
			   && (src[1] == 'O' || src[1] == 'w'))
		    {
		      depth++;
		      src++;  /* Skip the 'O' or 'w' as well.  */
		    }
		  src++;
		}
	      continue;
	    }
	  else if (src[1] == 'w')
	    {
	      /* Skip "Dw...E" (throw(types...)).  Same depth tracking
		 logic as above for nested exception specifications.  */
	      src += 2;
	      int depth = 1;
	      while (*src && depth > 0)
		{
		  if (*src == 'E')
		    depth--;
		  /* Check for nested exception specs.  We need to verify
		     src[1] is valid before accessing it.  */
		  else if (*src == 'D' && src[1]
			   && (src[1] == 'O' || src[1] == 'w'))
		    {
		      depth++;
		      src++;  /* Skip the 'O' or 'w' as well.  */
		    }
		  src++;
		}
	      continue;
	    }
	  else if (src[1] == 'x')
	    {
	      /* Skip "Dx" (transaction-safe) */
	      src += 2;
	      continue;
	    }
	}

      /* Copy character */
      *dst++ = *src++;
    }

  *dst = '\0';

  if (dump_file && strcmp (mangled, result) != 0)
    fprintf (dump_file, "  removed exception spec: '%s' -> '%s'\n",
	     mangled, result);

  return result;
}

/* Helper function to process C++ member function signatures.
   For METHOD_TYPE, this function:
   1. Simplifies class pointers in return type to 'Pv' (for covariant
      return types)
   2. Adds 'M1v' prefix

   Returns the processed signature, or the original if not a METHOD_TYPE.  */
static const char *
process_cxx_member_function_signature (const char *mangled, tree func_type)
{
  if (TREE_CODE (func_type) != METHOD_TYPE)
    return mangled;

  /* Save the original function mangling before we call
     lang_hooks.mangle_type again, as it may modify global state */
  const char *original_fun_mangled = xstrdup (mangled);
  const char *result = original_fun_mangled;

  /* Simplify class pointers/references in return type.
     According to RISC-V PSABI, we need to replace pointer or reference to
     class types in the return type with 'Pv' or 'Rv' for covariant
     return types. */

  tree return_type = TREE_TYPE (func_type);
  if (POINTER_TYPE_P (return_type) || TREE_CODE (return_type) == REFERENCE_TYPE)
    {
      tree pointee = TREE_TYPE (return_type);
      if (pointee && TREE_CODE (pointee) == RECORD_TYPE)
	{
	  /* Get the mangled name of the pointee (class type) */
	  const char *pointee_mangled = lang_hooks.mangle_type (pointee);
	  if (pointee_mangled)
	    {
	      /* Replace class name with "v" in the full signature.
		 For example: "FP4BaseiE" -> "FPviE" or "FR4BasevE" -> "FRvvE"
		 We need to find and replace just the class name part (e.g., "4Base"),
		 not the whole pointer/reference type (e.g., "P4Base" or "R4Base").

		 We search for the pointee name in the expected context, i.e.
		 immediately preceded by a pointer/reference/rvalue-ref qualifier
		 such as 'P', 'R', or 'O'.  This avoids matching the pointee name
		 at an incorrect location if it appears multiple times.  */
	      size_t fun_len = strlen (original_fun_mangled);
	      size_t pointee_len = strlen (pointee_mangled);

	      /* Allocate new string with enough space */
	      char *new_result = (char *) xmalloc (fun_len + 3);

	      /* Find the pointee name preceded by P, R, or O.  */
	      const char *pos = NULL;
	      const char *search = original_fun_mangled;
	      while ((pos = strstr (search, pointee_mangled)) != NULL)
		{
		  if (pos > original_fun_mangled)
		    {
		      char prev = pos[-1];
		      if (prev == 'P' || prev == 'R' || prev == 'O')
			break;
		    }
		  /* Not the occurrence we want; continue searching.  */
		  search = pos + 1;
		}

	      if (pos && pos > original_fun_mangled)
		{
		  /* Copy prefix (before class name, including P/R/O) */
		  size_t prefix_len = pos - original_fun_mangled;
		  memcpy (new_result, original_fun_mangled, prefix_len);

		  /* Add "v" to replace the class name */
		  new_result[prefix_len] = 'v';

		  /* Copy suffix (after class name) */
		  strcpy (new_result + prefix_len + 1, pos + pointee_len);

		  result = new_result;

		  if (dump_file)
		    fprintf (dump_file,
			     "  simplified class type '%s' to 'v': '%s'\n",
			     pointee_mangled, result);
		}
	    }
	}
    }

  /* Add M1v prefix */
  size_t mangled_len = strlen (result);
  char *final_result = (char *) xmalloc (3 + mangled_len + 1);
  strcpy (final_result, "M1v");
  strcat (final_result, result);

  /* Free intermediate mangled strings now that final_result is built.  */
  if (result != original_fun_mangled)
    free (const_cast<char *> (result));
  free (const_cast<char *> (original_fun_mangled));

  if (dump_file)
    fprintf (dump_file, "  final signature: '%s'\n", final_result);

  return final_result;
}

static unsigned int
rest_of_insert_func_sig_call (function *fun)
{
  tree fptr;
  gimple *stmt;
  basic_block bb;
  gimple_stmt_iterator gsi;

  FOR_EACH_BB_FN (bb, fun)
    for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
      {
	stmt = gsi_stmt (gsi);

	if (!is_gimple_call (stmt)
	    || gimple_call_internal_p (as_a <gcall*> (stmt)))
	  continue;

	fptr = gimple_call_fn (stmt);

	switch (TREE_CODE (fptr))
	  {
	  case INTEGER_CST:
	    continue;

	  case SSA_NAME:
	    break;
	  case ADDR_EXPR:
	  case OBJ_TYPE_REF:
	    break;
	  default:
	    /* Unexpected expression type for function pointer.
	       This should not happen in normal code. If we reach here,
	       it means we encountered an indirect call through an expression
	       type we don't handle. Skip this call site. */
	    if (dump_file)
	      fprintf (dump_file, "  warning: unexpected fptr expression type: %s\n",
		       get_tree_code_name (TREE_CODE (fptr)));
	    continue;  /* Skip this call site */
	  }

	gcc_assert ((TREE_CODE (TREE_TYPE (fptr)) == POINTER_TYPE)
		    || (TREE_CODE (TREE_TYPE (fptr)) == REFERENCE_TYPE));

	const char *type_mangled;
	tree func = TREE_TYPE (TREE_TYPE (fptr));
	tree func_attr = lookup_attribute ("lpad_func_sig", TYPE_ATTRIBUTES (func));

	if (dump_file)
	  {
	    fprintf (dump_file,
		     "\n[LPAD FUNC_SIG_CALL] Indirect call in function: %s (UID=%d)\n",
		     fndecl_name (fun->decl), DECL_UID (fun->decl));
	    fprintf (dump_file, "  stmt location: ");
	    print_gimple_stmt (dump_file, stmt, 0, TDF_SLIM);
	    fprintf (dump_file, "  function type: %s\n",
		     get_tree_code_name(TREE_CODE (func)));
	  }

	if (!func_attr)
	  {
	    if (TREE_CODE (func) == FUNCTION_TYPE
		&& TYPE_NAME (func)
		&& TREE_CODE (TYPE_NAME (func)) == IDENTIFIER_NODE
		&& strcmp (IDENTIFIER_POINTER (TYPE_NAME (func)), "main") == 0)
	      {
		type_mangled = "FiiPPcE";
		if (dump_file)
		  fprintf (dump_file, "  special handling for 'main': using "
			   "fixed signature '%s'\n", type_mangled);
	      }
	    else
	      {
		/* For C++, use lang_hooks.mangle_type to get standard C++ mangling.
		   For C, use riscv_mangle_type_string as fallback. */
		type_mangled = lang_hooks.mangle_type (func);
		if (dump_file && type_mangled)
		  fprintf (dump_file, "  lang_hooks.mangle_type(func) = '%s'\n",
			   type_mangled);

		if (type_mangled == NULL)
		  {
		    /* C language or mangling failed, use our simple implementation */
		    type_mangled = riscv_mangle_type_string (func);
		    if (dump_file)
		      fprintf (dump_file, "  fallback to riscv_mangle_type_string\n");
		  }
		else
		  {
		    /* C++ language: remove exception spec and process member function signatures */
		    type_mangled = remove_exception_spec_from_signature (type_mangled);
		    type_mangled = process_cxx_member_function_signature (type_mangled, func);
		  }
	      }

	    tree value = tree_cons (NULL_TREE, get_identifier (type_mangled),
				    NULL_TREE);
	    TYPE_ATTRIBUTES (func)
	      = tree_cons (get_identifier ("lpad_func_sig"), value,
			   TYPE_ATTRIBUTES (func));

	    if (dump_file)
	      fprintf (dump_file, "  inserted lpad_func_sig = '%s'\n",
		       type_mangled);
	  }
	else if (dump_file)
	  {
	    fprintf (dump_file, "  existing lpad_func_sig found"
		     " — skipping insert.\n");
	  }
      }
  return 0;
}

/* Process function definitions to attach function signatures.

   This function is part of the pass_insert_func_sig GIMPLE pass and handles
   the function-definition side of function signature CFI. It processes the
   current function being compiled and attaches its signature to its type.

   ALGORITHM:
   -----------
   For the function being compiled:
   1. Extract the function type from the function declaration
   2. Check if the type already has an "lpad_func_sig" attribute
   3. If not, generate the mangled signature for the function type
   4. Attach the signature as an "lpad_func_sig" attribute to the type

   SPECIAL CASES:
   --------------
   - main function: Always uses fixed signature "FiiPPcE" regardless of
     actual signature (int main(void) or int main(int, char**))
   - Already processed types: Skips (reuses existing attribute)

   MANGLING STRATEGY:
   ------------------
   1. For C++ code: Uses lang_hooks.mangle_type (cp/mangle.cc)
   2. For C code or fallback: Uses riscv_mangle_type_string

   WHY SPECIAL HANDLING FOR MAIN:
   -------------------------------
   The C standard allows two signatures for main:
   - int main(void)
   - int main(int argc, char *argv[])

   To ensure consistent CFI checking, we normalize both to "FiiPPcE"
   (the signature of int main(int, char**)).

   PARAMETERS:
   -----------
   fun: The function being compiled

   RETURNS:
   --------
   0 on success (required by GIMPLE pass infrastructure)

   SIDE EFFECTS:
   -------------
   - Attaches "lpad_func_sig" attribute to the function's type
   - May output diagnostic information to dump_file if enabled  */

static unsigned int
rest_of_insert_func_sig (function *fun)
{
  const char *fun_mangled = NULL;
  tree decl = fun->decl;

  if (dump_file)
    {
      fprintf (dump_file, "\n[LPAD FUNC_SIG] Processing: %s (UID=%d)\n",
	       fndecl_name (decl), DECL_UID (decl));
      fprintf (dump_file, "  is_artificial: %d, is_public: %d, is_comdat: %d\n",
	       DECL_ARTIFICIAL (decl), TREE_PUBLIC (decl), DECL_COMDAT (decl));
      fprintf (dump_file, "  function type: %s\n",
	       get_tree_code_name (TREE_CODE (TREE_TYPE (decl))));
    }

  /* Get the function type. All lpad_func_sig attributes are stored
     in TYPE_ATTRIBUTES for consistency and simplicity.  */
  tree func_type = TREE_TYPE (decl);

  if (dump_file)
    {
      fprintf (dump_file, "  func_type code: %s\n",
	       get_tree_code_name (TREE_CODE (func_type)));
      if (TREE_CODE (func_type) == METHOD_TYPE
	  || TREE_CODE (func_type) == FUNCTION_TYPE)
	{
	  tree ret_type = TREE_TYPE (func_type);
	  fprintf (dump_file, "  return type: %s\n",
		   get_tree_code_name (TREE_CODE (ret_type)));
	  tree parms = TYPE_ARG_TYPES (func_type);
	  fprintf (dump_file, "  parameters: ");
	  for (tree p = parms; p; p = TREE_CHAIN (p))
	    {
	      tree ptype = TREE_VALUE (p);
	      fprintf (dump_file, "%s ", get_tree_code_name (TREE_CODE (ptype)));
	    }
	  fprintf (dump_file, "\n");
	}
    }

  tree attr = lookup_attribute ("lpad_func_sig", TYPE_ATTRIBUTES (func_type));

  if (!attr)
    {
      /* Check for main function.  DECL_NAME can be NULL for some
	 compiler-generated functions, so we need to check it first.  */
      const char *fname = DECL_NAME (decl)
			  ? IDENTIFIER_POINTER (DECL_NAME (decl))
			  : NULL;
      if (fname && strcmp (fname, "main") == 0)
	{
	  fun_mangled = "FiiPPcE";
	  if (dump_file)
	    fprintf (dump_file, "  special handling for 'main': "
		     "using fixed signature '%s'\n", fun_mangled);
	}
      else
	{
	  /* For C++, use lang_hooks.mangle_type to get standard C++ mangling.
	     For C, use riscv_mangle_type_string as fallback. */
	  fun_mangled = lang_hooks.mangle_type (func_type);
	  if (dump_file && fun_mangled)
	    fprintf (dump_file, "  lang_hooks.mangle_type(func_type) = '%s'\n",
		     fun_mangled);
	  if (fun_mangled == NULL)
	    {
	      /* C language or mangling failed, use our simple implementation */
	      fun_mangled = riscv_mangle_type_string (func_type);
	      if (dump_file)
		fprintf (dump_file, "  fallback to riscv_mangle_type_string\n");
	    }
	  else
	    {
	      /* C++ language: remove exception spec and process member function
		 signatures */
	      fun_mangled = remove_exception_spec_from_signature (fun_mangled);
	      fun_mangled = process_cxx_member_function_signature (fun_mangled,
								    func_type);
	    }
	}

      /* Add lpad_func_sig attribute to the function type.
	 This ensures all functions with the same type share the same signature,
	 which is semantically correct since the signature is a property of
	 the function type, not the individual declaration.  */
      tree value = build_tree_list (NULL_TREE, get_identifier (fun_mangled));
      tree new_attr = build_tree_list (get_identifier ("lpad_func_sig"),
					value);
      TYPE_ATTRIBUTES (func_type) = chainon (TYPE_ATTRIBUTES (func_type),
					     new_attr);

      if (dump_file)
	fprintf (dump_file, "  Added lpad_func_sig='%s' to TYPE_ATTRIBUTES\n",
		 fun_mangled);
    }
  else if (dump_file)
    {
      fprintf (dump_file, "  already has lpad_func_sig — skipping insert.\n");
    }

  return 0;
}

/* Late pass wrapper: Only insert function signature checks at call sites.
   Function signatures themselves are already inserted by the early pass. */
static unsigned int
rest_of_insert_func_sig_late_wrapper (void)
{
  cgraph_node *node;

  if (dump_file)
    fprintf (dump_file, "\n=== LPAD FUNC_SIG LATE PASS ===\n");

  FOR_EACH_FUNCTION_WITH_GIMPLE_BODY (node)
    {
      if (!gimple_has_body_p (node->decl))
	continue;

      function *fun = DECL_STRUCT_FUNCTION (node->decl);
      if (!fun || !fun->cfg)
	continue;

      push_cfun (fun);
      rest_of_insert_func_sig_call (fun);
      pop_cfun ();
    }

  return 0;
}

namespace {

const pass_data pass_data_insert_func_sig =
{
  GIMPLE_PASS, /* type.  */
  "func_sig", /* name.  */
  OPTGROUP_NONE, /* optinfo_flags.  */
  TV_NONE, /* tv_id.  */
  (PROP_cfg | PROP_ssa), /* properties_required.  */
  0, /* properties_provided.  */
  0, /* properties_destroyed.  */
  0, /* todo_flags_start.  */
  0, /* todo_flags_finish.  */
};


class pass_insert_func_sig : public gimple_opt_pass
{
public:
  pass_insert_func_sig (gcc::context *ctxt)
    : gimple_opt_pass (pass_data_insert_func_sig, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *)
    {
      return is_zicfilp_p () && riscv_lpad_type == LPAD_FUNC_SIG;
    }

  virtual unsigned int execute (function *)
    {
      return rest_of_insert_func_sig_late_wrapper ();
    }
}; // class pass_insert_func_sig

} // anon namespace

gimple_opt_pass *
make_pass_insert_func_sig (gcc::context *ctxt)
{
  return new pass_insert_func_sig (ctxt);
}

/* Early pass: Insert function signatures before pass_ipa_free_lang_data.
   This ensures TYPE_LANG_FLAG_2 and other C++ type information is still
   available, allowing us to handle pointer-to-member types correctly even
   with LTO. */

static unsigned int
rest_of_insert_func_sig_early_wrapper (void)
{
  struct cgraph_node *node;

  if (dump_file)
    fprintf (dump_file, "\n=== LPAD FUNC_SIG EARLY PASS ===\n");

  /* Process init_array/fini_array functions BEFORE computing signatures.
     Functions in these sections are declared with void(void) prototype but
     invoked using a generic function pointer void (*)(int, char**, char**).
     This leads to LPAD signature mismatches, so we set their signature
     to lpad_func_sig("0") (unlabeled) to avoid CFI violations at runtime.

     We do this before rest_of_insert_func_sig so that when the function
     is processed, it will see the lpad_func_sig("0") attribute and skip
     computing a signature.  */
  struct varpool_node *vnode;
  FOR_EACH_VARIABLE (vnode)
    {
      tree decl = vnode->decl;

      const char *sec = DECL_SECTION_NAME (decl);
      if (!sec || (
	  strcmp (sec, ".init_array") != 0 &&
	  strcmp (sec, ".fini_array") != 0 &&
	  strcmp (sec, ".preinit_array") != 0))
	continue;

      tree init = DECL_INITIAL (decl);
      if (!init || TREE_CODE (init) != ADDR_EXPR)
	continue;

      tree func = TREE_OPERAND (init, 0);
      if (!func || TREE_CODE (func) != FUNCTION_DECL)
	continue;

      tree fntype = TREE_TYPE (func);
      if (!fntype)
	continue;

      /* Check if user already specified lpad_func_sig attribute in source.
	 If so, respect the user's choice.  */
      if (lookup_attribute ("lpad_func_sig", TYPE_ATTRIBUTES (fntype)))
	continue;

      /* Set lpad_func_sig("0") for init_array functions.  */
      tree value = tree_cons (NULL_TREE, get_identifier ("0"), NULL_TREE);
      tree attr = tree_cons (get_identifier ("lpad_func_sig"), value,
			     TYPE_ATTRIBUTES (fntype));
      TYPE_ATTRIBUTES (fntype)
	= merge_attributes (attr, TYPE_ATTRIBUTES (fntype));

      if (dump_file)
	fprintf (dump_file,
		 "Set lpad_func_sig(\"0\") for init_array function %s\n",
		 DECL_NAME (func)
		 ? IDENTIFIER_POINTER (DECL_NAME (func))
		 : "<unnamed>");
    }

  /* Process all functions with GIMPLE body.  */
  FOR_EACH_FUNCTION_WITH_GIMPLE_BODY (node)
    {
      if (!gimple_has_body_p (node->decl))
	continue;

      function *fun = DECL_STRUCT_FUNCTION (node->decl);
      if (!fun)
	continue;

      push_cfun (fun);
      rest_of_insert_func_sig (fun);
      pop_cfun ();
    }

  return 0;
}

namespace {

const pass_data pass_data_insert_func_sig_early =
{
  SIMPLE_IPA_PASS, /* type.  */
  "func_sig_early", /* name.  */
  OPTGROUP_NONE, /* optinfo_flags.  */
  TV_NONE, /* tv_id.  */
  0, /* properties_required - no CFG or SSA needed.  */
  0, /* properties_provided.  */
  0, /* properties_destroyed.  */
  0, /* todo_flags_start.  */
  0, /* todo_flags_finish.  */
};

class pass_insert_func_sig_early : public simple_ipa_opt_pass
{
public:
  pass_insert_func_sig_early (gcc::context *ctxt)
    : simple_ipa_opt_pass (pass_data_insert_func_sig_early, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *)
    {
      return is_zicfilp_p () && riscv_lpad_type == LPAD_FUNC_SIG;
    }

  virtual unsigned int execute (function *)
    {
      return rest_of_insert_func_sig_early_wrapper ();
    }
}; // class pass_insert_func_sig_early

} // anon namespace

simple_ipa_opt_pass *
make_pass_insert_func_sig_early (gcc::context *ctxt)
{
  return new pass_insert_func_sig_early (ctxt);
}
