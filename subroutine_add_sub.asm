.data

str1:	.asciiz	"Enter two numbers: "
str2:	.asciiz	"Computation result: "

sub1:	.asciiz	"Addition: "
sub2:	.asciiz	"Subtraction: "

.text
.globl main

main:
	li $v0, 4
	la $a0, str1
	syscall

	li $v0, 5
	syscall
	move $t0, $v0

	li $v0, 5
	syscall
	move $t1, $v0

	li $v0, 5
	syscall
	move $t2, $v0

	jal addition
	jal subtract

	li $v0, 10
	syscall

addition:	add $t3, $t2, $t1
	add $t4, $t0, $t3
	li $v0, 4
	la $a0, sub1
	syscall

	li $v0, 1
	move $a0, $t4
	syscall
	
	jr $ra

subtract:	sub $t5, $t0, $t1
	sub $t6, $t5, $t2

	li $v0, 4
	la $a0, sub2
	syscall

	li $v0, 1
	move $a0, $t6
	syscall
	jr $ra
