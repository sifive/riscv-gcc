/* Verify proper errors are generated for invalid code.  */
int __attribute__ ((interrupt))
sub0 (void)
{ /* { dg-error "function cannot return a value" } */
  return 10;
}

void __attribute__ ((interrupt))
sub1 (int i)
{ /* { dg-error "function cannot have arguments" } */
}

void __attribute__ ((interrupt, naked))
sub2 (void)
{ /* { dg-error "are mutually exclusive" } */
}

void __attribute__ ((interrupt ("hypervisor")))
sub3 (void)
{ /* { dg-warning "argument to" } */
}

void __attribute__ ((interrupt ("user", "machine")))
sub4 (void)
{ /* { dg-error "cannot have two modes" } */
}

void __attribute__ ((interrupt ("user", "SiFive-CLIC-preemptible")))
sub5 (void)
{ /* { dg-error "must be machine mode" } */
}

void __attribute__ ((interrupt ("user", "SiFive-CLIC-stack-swap")))
sub6 (void)
{ /* { dg-error "must be machine mode" } */
}
