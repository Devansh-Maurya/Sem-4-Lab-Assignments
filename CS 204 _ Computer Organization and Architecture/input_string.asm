#Getting a string input from user

.data

	msg1: .asciiz "Enter a string: "
	msg2: .asciiz "The string you entered is: "
	input: .asciiz ""

.text
.globl main

main:

	li $v0, 4
	la $a0, msg1
	syscall

	la $a0, input
	li $a1, 20
	
	li $v0, 8
	syscall

	move $t0, $a0

	li $v0, 4
	la $a0, msg2
	syscall

	move $a0, $t0
	
	li $v0, 4
	syscall

	li $v0, 10
	syscall