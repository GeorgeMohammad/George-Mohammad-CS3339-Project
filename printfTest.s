#gcc printfTest.s -fno-pie -no-pie
#The above command properly compiles printfTest.s

.section .rodata
str:
	.asciz "tesT\n"

format:
	.asciz "%20ld\n"
.globl main

main: 
	pushq %rdi
	pushq %r8
	movq %rsp, %rbp
	movq $str, %rdi
	xorq %rax, %raX	
	#movq $str, %rax
	#pushq %rax
	call printf
	#xorl %eax, %eax
	#movq %rbp, %rsp
	#popq %rbp
	#call exit
	#pushq %rax
	#pushq %rbp
	#xorl %edi, %edi
	#leal format(%rip), %edi
	#call fflush
	#xorq %rax, %rax
	#must use a different register, %ebx instead of %edi.
	movq %rax, %r8

	xorl %eax, %eax
	call printf

	xorq %rax, %rax
	#popq %rax
	#popq %rbx
	#call exit
	mov $0, %ebx
	#to reuse registers they must first be popped
	popq %rdi
	pushq %rdi
	movq $str, %rdi
	call printf
	call exit
	popq %rdi
	popq %r8
	ret
