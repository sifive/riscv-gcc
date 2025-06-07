/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O2 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Verify the function signature is preserved and used when calling a function
   pointer stored in a struct field (e.g., obstack.chunkfun). */

struct _obstack_chunk;

struct obstack
{
  long chunk_size;
  struct _obstack_chunk *(*chunkfun) (void *, long);
};

void
_obstack_newchunk (struct obstack *h, int length)
{
  long new_size = h->chunk_size;
  h->chunkfun(h, new_size);
}

/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"FP14_obstack_chunkPvlE\"\\)" } } */
