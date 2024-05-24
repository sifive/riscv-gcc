/* { dg-do compile } */
/* { dg-options "-march=rv64gzb -mabi=lp64" } */
int foo()
{
}

/* { dg-error "'-march=rv64gzb': unsupported extension 'zb'" "" { target *-*-* } 0 } */
/* { dg-error "extension 'zb' starts with 'z' but is unsupported standard extension" "" { target *-*-* } 0 } */
