#ifdef __arm__

/*
 * See this for more info on ARM:
 * http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0041c/ch09s02s02.html
 */
#define TRACY_REGS_NAME pt_regs

/* Unsure about some of the registers */
#define TRACY_SYSCALL_OPSIZE 8

/* ARM EABI puts System call number in r7 */
#define TRACY_SYSCALL_REGISTER ARM_r7
#define TRACY_SYSCALL_N ARM_r8

#define TRACY_RETURN_CODE ARM_r0

#define TRACY_IP_REG ARM_pc

#define TRACY_STACK_POINTER ARM_sp

/*
 * ARM does nasty stuff
 * http://www.arm.linux.org.uk/developer/patches/viewpatch.php?id=3105/4
 */
#define TRACY_ARG_0 ARM_r0
#define TRACY_ARG_1 ARM_r1
#define TRACY_ARG_2 ARM_r2
#define TRACY_ARG_3 ARM_r3
#define TRACY_ARG_4 ARM_r4
#define TRACY_ARG_5 ARM_r5

#define TRACY_NR_MMAP __NR_mmap2

#endif

#ifdef __i386__
#define TRACY_REGS_NAME user_regs_struct /* pt_regs doesn't work */

#define TRACY_SYSCALL_OPSIZE 2

#define TRACY_SYSCALL_REGISTER orig_eax
#define TRACY_SYSCALL_N eax

#define TRACY_RETURN_CODE eax
#define TRACY_IP_REG eip

#define TRACY_STACK_POINTER esp

#define TRACY_ARG_0 ebx
#define TRACY_ARG_1 ecx
#define TRACY_ARG_2 edx
#define TRACY_ARG_3 esi
#define TRACY_ARG_4 edi
#define TRACY_ARG_5 ebp

#define TRACY_NR_MMAP __NR_mmap2

#endif

/* 'cs' determines the call type, we can use this to check if we are calling a
* 32 bit function on 64 bit */

#ifdef __x86_64__
#define TRACY_REGS_NAME user_regs_struct /* pt_regs doesn't work */

#define TRACY_SYSCALL_OPSIZE 2

#define TRACY_SYSCALL_REGISTER orig_rax
#define TRACY_SYSCALL_N rax

#define TRACY_RETURN_CODE rax
#define TRACY_IP_REG rip

#define TRACY_STACK_POINTER rsp

#define TRACY_ARG_0 rdi
#define TRACY_ARG_1 rsi
#define TRACY_ARG_2 rdx
#define TRACY_ARG_3 r10
#define TRACY_ARG_4 r8
#define TRACY_ARG_5 r9

#define TRACY_NR_MMAP __NR_mmap

#endif
