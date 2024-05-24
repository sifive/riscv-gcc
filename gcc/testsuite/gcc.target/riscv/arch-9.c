/* { dg-do compile } */
/* { dg-options "-march=rv32g2 -mabi=ilp32" } */
int foo()
{
}
/* { dg-error "'-march=rv32g2': unsupported version number '2.0' for extension 'g'" "" { target *-*-* } 0 } */
/* { dg-warning "version of 'g' will be omitted, please specify version for individual extension" "" { target *-*-* } 0 } */
