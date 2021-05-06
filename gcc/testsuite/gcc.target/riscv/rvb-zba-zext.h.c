/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zba -mabi=lp64 -O2" } */

unsigned short a;
int c(int); int b() { c(a); }
