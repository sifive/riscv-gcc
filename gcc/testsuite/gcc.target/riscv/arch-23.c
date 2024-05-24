/* { dg-do compile } */
/* { dg-options "-march=rv64gvcw_zvl128_s123_x123 -mabi=lp64d" } */
int foo()
{
}

/* { dg-error "unsupported extension 'w'" "" { target *-*-* } 0 } */
/* { dg-error "extension 'w' is unsupported standard single letter extension" "" { target *-*-* } 0 } */
/* { dg-error "unsupported version number '128.0' for extension 'zvl'" "" { target *-*-* } 0 } */
/* { dg-error "extension 'zvl' starts with 'z' but is unsupported standard extension" "" { target *-*-* } 0 } */
/* { dg-error "unsupported extension 's123'" "" { target *-*-* } 0 } */
/* { dg-error "extension 's123' starts with 's' but is unsupported standard supervisor extension" "" { target *-*-* } 0 } */
/* { dg-error "unsupported extension 'x123'" "" { target *-*-* } 0 } */
/* { dg-error "extension 'x123' starts with 'x' but is unsupported non-standard extension" "" { target *-*-* } 0 } */
