/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test function signature generation for struct types */

struct point {
  int x;
  int y;
};

struct point create_point(int x, int y)
{
  struct point p;
  p.x = x;
  p.y = y;
  return p;
}

void update_point(struct point *p, int x, int y)
{
  p->x = x;
  p->y = y;
}

int get_x(struct point p)
{
  return p.x;
}

/* Verify function signatures:
   create_point: struct point(int, int) -> F5pointiiE
   update_point: void(struct point*, int, int) -> FvP5pointiiE
   get_x: int(struct point) -> Fi5pointE */
/* { dg-final { scan-assembler "%lpad_hash\\(\"F5pointiiE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FvP5pointiiE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"Fi5pointE\"\\)" } } */

