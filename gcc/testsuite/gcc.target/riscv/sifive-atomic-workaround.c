/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-flto" } { "" } } */
/* { dg-options "-march=rv64gc -mabi=lp64 -matomic-store-workaround" } */
/* { dg-final { check-function-bodies "**" "" } } */

void atomic_store_8_seq_cst (unsigned char *ptr, unsigned char val)
{
/*
** atomic_store_8_seq_cst:
** ...
** lr\.w\.aqrl\s+.*
** and\s+.*
** or\s+.*
** sc\.w\.rl\s+.*
** bnez\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_SEQ_CST);
}

void atomic_store_8_relaxed (unsigned char *ptr, unsigned char val)
{
/*
** atomic_store_8_relaxed:
** ...
** lr\.w\s+.*
** and\s+.*
** or\s+.*
** sc\.w\s+.*
** bnez\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_RELAXED);
}

void atomic_store_8_release (unsigned char *ptr, unsigned char val)
{
/*
** atomic_store_8_release:
** ...
** lr\.w\s+.*
** and\s+.*
** or\s+.*
** sc\.w\.rl\s+.*
** bnez\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_RELEASE);
}

void atomic_store_16_seq_cst (unsigned short *ptr, unsigned short val)
{
/*
** atomic_store_16_seq_cst:
** ...
** lr\.w\.aqrl\s+.*
** and\s+.*
** or\s+.*
** sc\.w\.rl\s+.*
** bnez\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_SEQ_CST);
}

void atomic_store_16_relaxed (unsigned short *ptr, unsigned short val)
{
/*
** atomic_store_16_relaxed:
** ...
** lr\.w\s+.*
** and\s+.*
** or\s+.*
** sc\.w\s+.*
** bnez\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_RELAXED);
}

void atomic_store_16_release (unsigned short *ptr, unsigned short val)
{
/*
** atomic_store_16_release:
** ...
** lr.w\s+.*
** and\s+.*
** or\s+.*
** sc\.w\.rl\s+.*
** bnez\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_RELEASE);
}

void atomic_store_32_seq_cst (unsigned int *ptr, unsigned int val)
{
/*
** atomic_store_32_seq_cst:
** ...
** amoswap\.w\.aqrl\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_SEQ_CST);
}

void atomic_store_32_relaxed (unsigned int *ptr, unsigned int val)
{
/*
** atomic_store_32_relaxed:
** ...
** amoswap\.w\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_RELAXED);
}

void atomic_store_32_release (unsigned int *ptr, unsigned int val)
{
/*
** atomic_store_32_release:
** ...
** amoswap\.w\.rl\s+.*
** ...
*/
    __atomic_store_n (ptr, val, __ATOMIC_RELEASE);
}

