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
	subq	$64, %rsp
	movabsq	$.L__unnamed_1, %rdi
	callq	__kmpc_global_thread_num
	movq	stdout, %rdi
	movl	%eax, -4(%rbp)          # 4-byte Spill
	movq	%rdi, -16(%rbp)         # 8-byte Spill
	callq	omp_get_thread_num
	movslq	%eax, %rdx
	movq	%rdx, -24(%rbp)         # 8-byte Spill
	callq	pthread_self
	movabsq	$.L.str, %rsi
	movq	-16(%rbp), %rdi         # 8-byte Reload
	movq	-24(%rbp), %rdx         # 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	fprintf
	movabsq	$.L__unnamed_1, %rdi
	movl	$4, %edx
	movl	-4(%rbp), %esi          # 4-byte Reload
	movl	%eax, -28(%rbp)         # 4-byte Spill
	callq	__kmpc_push_num_threads
	movabsq	$.L__unnamed_1, %rdi
	xorl	%esi, %esi
	movabsq	$.omp_outlined., %rcx
	movq	%rcx, %rdx
	movb	$0, %al
	callq	__kmpc_fork_call
	movq	stdout, %rdi
	movq	%rdi, -40(%rbp)         # 8-byte Spill
	callq	omp_get_thread_num
	movslq	%eax, %rdx
	movq	%rdx, -48(%rbp)         # 8-byte Spill
	callq	pthread_self
	movabsq	$.L.str.3, %rsi
	movq	-40(%rbp), %rdi         # 8-byte Reload
	movq	-48(%rbp), %rdx         # 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	fprintf
	xorl	%r8d, %r8d
	movl	%eax, -52(%rbp)         # 4-byte Spill
	movl	%r8d, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.align	16, 0x90
	.type	.omp_outlined.,@function
.omp_outlined.:                         # @.omp_outlined.
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	stdout, %rdi
	movq	%rdi, -24(%rbp)         # 8-byte Spill
	callq	omp_get_thread_num
	movslq	%eax, %rdx
	movq	%rdx, -32(%rbp)         # 8-byte Spill
	callq	pthread_self
	movabsq	$.L.str.1, %rsi
	movq	-24(%rbp), %rdi         # 8-byte Reload
	movq	-32(%rbp), %rdx         # 8-byte Reload
	movq	%rax, %rcx
	movb	$0, %al
	callq	fprintf
	movl	%eax, -36(%rbp)         # 4-byte Spill
	addq	$48, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	.omp_outlined., .Lfunc_end1-.omp_outlined.
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
	.asciz	";unknown;unknown;0;0;;"
	.size	.L.str.2, 23

	.type	.L__unnamed_1,@object   # @0
	.section	.rodata,"a",@progbits
	.align	8
.L__unnamed_1:
	.long	0                       # 0x0
	.long	2                       # 0x2
	.long	0                       # 0x0
	.long	0                       # 0x0
	.quad	.L.str.2
	.size	.L__unnamed_1, 24

	.type	.L.str.3,@object        # @.str.3
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.3:
	.asciz	"Thread[%lu,%lu]: Depois da Regi\303\243o Paralela.\n"
	.size	.L.str.3, 46


	.ident	"clang version 3.8.1-24 (tags/RELEASE_381/final)"
	.section	".note.GNU-stack","",@progbits
