/* { dg-do compile } */
<<<<<<< HEAD
/* { dg-options "-march=rv64i_zalasr -mabi=lp64" } */
int foo ()
{
}
=======
/* { dg-options "-march=rv64i -mabi=lp64d" } */
int
foo ()
{}

/* { dg-error "requested ABI requires '-march' to subsume the 'D' extension" "" { target *-*-* } 0 } */
>>>>>>> refs/rewritten/420aef66461965586293516945c6f5dcfda911ed-2
