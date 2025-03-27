/* { dg-do compile } */
/* { dg-options "-march=rv32imafc_zicsr_zifencei_zba_zbb -mabi=ilp32f -mcmodel=medlow -Os -fomit-frame-pointer -fno-schedule-insns2" } */
/* { dg-skip-if "" { *-*-* } {"-O1" "-O2" "-O3" "-Og" "-Oz" "-flto"} } */
/* { dg-final { check-function-bodies "**" "" } } */

/*
**software_handler:
**	addi\s+sp,sp,-192
**	sw\s+s0,188\(sp\)
**	sw\s+s1,184\(sp\)
**	csrr\s+s0,mcause
**	csrr\s+s1,mepc
**	csrrsi\s+zero,mstatus,8
**	sw\s+ra,180\(sp\)
**	...
**	fsw\s+ft8,12\(sp\)
**	fsw\s+ft9,8\(sp\)
**	fsw\s+ft10,4\(sp\)
**	fsw\s+ft11,0\(sp\)
**	...
**	lw\s+ra,180\(sp\)
**	lw\s+t0,172\(sp\)
**	...
**	flw\s+ft10,4\(sp\)
**	flw\s+ft11,0\(sp\)
**	csrrci\s+zero,mstatus,8
**	csrw\s+mepc,s1
**	csrw\s+mcause,s0
**	lw\s+s0,188\(sp\)
**	lw\s+s1,184\(sp\)
**	addi\s+sp,sp,192
**	mret
*/
void __attribute__((interrupt("SiFive-CLIC-preemptible"))) software_handler (void) {
  unsigned long mcause = ({ unsigned long __tmp; asm volatile ("csrr %0, " "mcause" : "=r"(__tmp)); __tmp; });
  unsigned long mepc = ({ unsigned long __tmp; asm volatile ("csrr %0, " "mepc" : "=r"(__tmp)); __tmp; });
  unsigned long mtval = ({ unsigned long __tmp; asm volatile ("csrr %0, " "mtval" : "=r"(__tmp)); __tmp; });
  unsigned long mstatus = ({ unsigned long __tmp; asm volatile ("csrr %0, " "mstatus" : "=r"(__tmp)); __tmp; });

  __builtin_printf("mcause=0x%x\n", mcause);
  __builtin_printf("mepc=0x%x\n", mepc);
  __builtin_printf("mtval=0x%x\n", mtval);
  __builtin_printf("mstatus=0x%x\n", mstatus);

  ((*(volatile unsigned int *)((33554432UL + 0UL + (({ unsigned long __tmp; asm volatile ("csrr %0, " "mhartid" : "=r"(__tmp)); __tmp; }) * 0x4)))) = 0x0);
}
