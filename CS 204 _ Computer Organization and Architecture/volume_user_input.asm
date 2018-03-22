#Calculate volume of a cuboid by taking input from user

.data

	msg1: .asciiz "Enter length: "
	msg2: .asciiz "Enter breadth: "
	msg3: .asciiz "Enter height: "
	answer: .asciiz "Your answer is: "

.text
.globl main

main:

	li $v0, 4
	la $a0, msg1
	syscall

	li $v0, 5
	syscall

	move $t0, $v0
	
	li $v0, 4
	la $a0, msg2
	syscall

	li $v0, 5
	syscall

	move $t1, $v0

	li $v0, 4
	la $a0, msg3
	syscall

	li $v0, 5
	syscall

	move $t2, $v0

	mul $t3, $t0, $t1
	mul $t1, $t3, $t2

	li $v0, 4
	la $a0, answer
	syscall

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 10
	syscall
	 