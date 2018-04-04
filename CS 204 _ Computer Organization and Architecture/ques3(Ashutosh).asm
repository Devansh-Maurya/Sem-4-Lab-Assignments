.data
msg1:.asciiz "Enter the number: "
msg2:.asciiz "The reverse order of digits is: "
msg3:.asciiz "Enter the number of digits: "
val:.word 0

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
	la $a0, msg3
	syscall

	li $v0, 5
	syscall
	move $t4, $v0
	
	li $t1, 10
	li $t5, 0


	#li $t0, 123
	#li $t1, 10
	#rem $t2, $t0, $t1
	#sw $t2, val


	li $v0, 4
	la $a0, msg2
	syscall
	
	
loop:	rem $t2, $t0, $t1
	sw $t2, val
	li $v0, 1
	lw $a0, val
	syscall
	div $t0, $t0, $t1
	addi $t5, $t5, 1
	bne $t4, $t5, loop



	li $v0, 10
	syscall