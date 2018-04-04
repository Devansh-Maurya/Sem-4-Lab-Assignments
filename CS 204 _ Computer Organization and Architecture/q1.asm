#Question 1

.data

msg1:	.asciiz "Enter the value of n: "
ans:	.asciiz "The answer is: "

.text

.globl main

main:
	li $v0, 4
	la $a0, msg1
	syscall

	li $v0, 5
	syscall

	move $t0, $v0

	addi $t0, $t0, 1
	
	li $t1, 1
	li $t2, 0

loop:	mul $t3, $t1, $t1
	add $t2, $t3, $t2
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