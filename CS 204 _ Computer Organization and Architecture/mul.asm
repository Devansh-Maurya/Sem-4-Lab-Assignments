.data

msg1: .asciiz "Enter first number: "
msg2: .asciiz "Enter second number: "
msg3: .asciiz "The sum is: "

.text
.globl main

main:

	li $v0, 4		#Print msg1
	la $a0, msg1
	syscall

	li $v0, 5		#Print first input integer
	syscall
	
	move $t0, $v0		#Move integer into t0

	li $v0, 4		#Print msg1
	la $a0, msg2
	syscall

	li $v0, 5		#Print second input integer
	syscall
	
	move $t1, $v0

	mul $t2, $t0, $t1

	li $v0, 4
	la $a0, msg3
	syscall

	move $a0, $t2

	li $v0, 1
	syscall

	li $v0, 10
	syscall

	 