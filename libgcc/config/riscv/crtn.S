/* crtn.S is empty because .init_array/.fini_array are used exclusively. */

#undef VALUE_FOR_FEATURE_1_AND
#if defined (__riscv_zicfilp) || defined (__riscv_zicfiss)
#  if defined (__riscv_zicfilp)
#    if defined (__riscv_zicfiss)
#      define VALUE_FOR_FEATURE_1_AND 0x3
#    else
#      define VALUE_FOR_FEATURE_1_AND 0x1
#    endif
#  else
#    if defined (__riscv_zicfiss)
#      define VALUE_FOR_FEATURE_1_AND 0x2
#    else
#      error "What?"
#    endif
#  endif
#endif

#if defined (VALUE_FOR_FEATURE_1_AND)
        .section ".note.gnu.property", "a"
        .p2align 3
        .long 1f - 0f           /* name length */
        .long 5f - 2f           /* data length */
        .long 5                 /* note type */
0:      .asciz "GNU"            /* vendor name */
1:
        .p2align 3
2:      .long 0xc0000000        /* pr_type.  */
        .long 4f - 3f           /* pr_datasz.  */
3:
        .long VALUE_FOR_FEATURE_1_AND
4:
        .p2align 3
5:
#endif
