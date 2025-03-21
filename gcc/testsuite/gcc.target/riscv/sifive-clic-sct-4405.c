/* { dg-do compile } */
/* { dg-options "-march=rv32imafc_zicsr_zifencei_zba_zbb -mabi=ilp32f -mcmodel=medlow -Os -fomit-frame-pointer -fno-schedule-insns2" } */
/* { dg-skip-if "" { *-*-* } {"-O1" "-O2" "-O3" "-Og" "-Oz" "-flto"} } */
/* { dg-final { check-function-bodies "**" "" } } */

/*
**software_handler:
**	addi	sp,sp,-192
**	sw	s0,188(sp)
**	sw	s1,184(sp)
**	csrr	s0,mcause
**	csrr	s1,mepc
**	csrrsi	zero,mstatus,8
**	sw	ra,180(sp)
**	...
**	fsw	ft8,12(sp)
**	fsw	ft9,8(sp)
**	fsw	ft10,4(sp)
**	fsw	ft11,0(sp)
**	...
**	lw	ra,180(sp)
**	lw	t0,172(sp)
**	...
**	flw	ft10,4(sp)
**	flw	ft11,0(sp)
**	csrrci	zero,mstatus,8
**	csrw	mepc,s1
**	csrw	mcause,s0
**	lw	s0,188(sp)
**	lw	s1,184(sp)
**	addi	sp,sp,192
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
