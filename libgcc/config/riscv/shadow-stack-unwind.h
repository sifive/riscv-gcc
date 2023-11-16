/* _Unwind_Frames_Extra with shadow stack.
   Copyright (C) 2017-2023 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* Unwind the shadow stack for EH.  */
#undef _Unwind_Frames_Extra
#define _Unwind_Frames_Extra(x)					\
  do								\
    {								\
      _Unwind_Word ssp;						\
      asm volatile ("ssrdp %0" : "=r"(ssp));			\
      if (ssp != 0)						\
	{							\
	  _Unwind_Word tmp = (x);				\
	  while (tmp > ssp)					\
	    {							\
	      if ((tmp - ssp) >= 4096)				\
		ssp += 4096;					\
	      else						\
		ssp = tmp;					\
	      asm volatile ("csrw ssp, %0" :: "r"(ssp));	\
	      asm volatile ("sspush x5");			\
	      asm volatile ("sspopchk");			\
	    }							\
	}							\
    }								\
    while (0)

#undef _Unwind_Frames_Increment
#define _Unwind_Frames_Increment(exc, context, frames)	\
    {							\
      frames++;						\
      if (exc->exception_class != 0			\
	  && _Unwind_GetIP (context) != 0		\
	  && !_Unwind_IsSignalFrame (context))		\
	{						\
	  _Unwind_Word ssp;				\
	  asm volatile ("ssrdp %0" : "=r"(ssp));	\
	  if (ssp != 0)					\
	    {						\
	      ssp += 8 * frames;			\
	      _Unwind_Word ra = *(_Unwind_Word *) ssp;	\
	      if (ra != _Unwind_GetIP (context))	\
		return _URC_FATAL_PHASE2_ERROR;		\
	    }						\
	}						\
    }
