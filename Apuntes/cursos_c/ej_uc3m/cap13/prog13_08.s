	.file	"prog14_06.c"
	.version	"01.01"
gcc2_compiled.:
.section	.rodata
.LC0:
	.string	"Introduzca el valor de a: "
.LC1:
	.string	"%d"
.LC2:
	.string	"El valor de a + 1 es: %d\n"
.text
	.align 4
.globl main
	.type	 main,@function
main:
	pushl %ebp
	movl %esp,%ebp
	subl $24,%esp
	movl $3,-4(%ebp)
	addl $-12,%esp
	pushl $.LC0
	call printf
	addl $16,%esp
	addl $-8,%esp
	leal -4(%ebp),%eax
	pushl %eax
	pushl $.LC1
	call scanf
	addl $16,%esp
	addl $-12,%esp
	leal -4(%ebp),%eax
	pushl %eax
	call incrementar
	addl $16,%esp
	addl $-8,%esp
	movl -4(%ebp),%eax
	pushl %eax
	pushl $.LC2
	call printf
	addl $16,%esp
	xorl %eax,%eax
	jmp .L2
	.p2align 4,,7
.L2:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe1:
	.size	 main,.Lfe1-main
	.align 4
.globl incrementar
	.type	 incrementar,@function
incrementar:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%eax
#APP
		incl (%eax)
	
#NO_APP
.L3:
	movl %ebp,%esp
	popl %ebp
	ret
.Lfe2:
	.size	 incrementar,.Lfe2-incrementar
	.ident	"GCC: (GNU) 2.95.3 19991030 (prerelease)"
