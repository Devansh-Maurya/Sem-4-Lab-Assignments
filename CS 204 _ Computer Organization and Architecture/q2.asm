#Question 2

.data

ans:	.asciiz	"The answer is: "
.text
.globl main

main:
	li $t0, 11
	li $t1, 1
	li $t2, 0

loop:	add $t2, $t1, $t2
	addi $t1, $t1, 1
	bne $t1, $t0, loop

	li $v0, 4
	la $a0, ans
	syscall

	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 10
	syscall