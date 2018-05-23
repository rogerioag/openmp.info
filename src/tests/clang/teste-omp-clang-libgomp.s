	.text
	.file	"teste-omp.c"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	stdout, %rdi
	movq	%rdi, -8(%rbp)          # 8-byte Spill
	callq	pthread_self
	movabsq	$.L.str, %rsi
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movq	-8(%rbp), %rdi          # 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	fprintf
	movq	stdout, %rdi
	movl	%eax, -12(%rbp)         # 4-byte Spill
	movq	%rdi, -24(%rbp)         # 8-byte Spill
	callq	pthread_self
	movabsq	$.L.str.1, %rsi
	xorl	%r8d, %r8d
	movl	%r8d, %edx
	movq	-24(%rbp), %rdi         # 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	fprintf
	movq	stdout, %rdi
	movl	%eax, -28(%rbp)         # 4-byte Spill
	movq	%rdi, -40(%rbp)         # 8-byte Spill
	callq	pthread_self
	movabsq	$.L.str.2, %rsi
	xorl	%r8d, %r8d
	movl	%r8d, %edx
	movq	-40(%rbp), %rdi         # 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	fprintf
	xorl	%r8d, %r8d
	movl	%eax, -44(%rbp)         # 4-byte Spill
	movl	%r8d, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Thread[%lu,%lu]: Antes da Regi\303\243o Paralela.\n"
	.size	.L.str, 45

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"  Thread[%lu,%lu]: Na regi\303\243o paralela.\n"
	.size	.L.str.1, 41

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Thread[%lu,%lu]: Depois da Regi\303\243o Paralela.\n"
	.size	.L.str.2, 46


	.ident	"clang version 3.8.1-24 (tags/RELEASE_381/final)"
	.section	".note.GNU-stack","",@progbits
