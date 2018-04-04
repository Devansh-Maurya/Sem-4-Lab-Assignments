#Question 3
#Work in progress

.data

msq1:	.asciiz	"Enter the number: "
ans:	.asciiz	"The reversed number is: "
msq2:	.asciiz	"Enter the number of digits: "

.text

.globl main

main:
	li $v0, 4
	la $a0, msq1
	syscall

	li $v0, 5
	syscall

	li $v0, 4
	la $a0, msq2
	syscall

	li $v0, 5
	syscall

	move $t5, $v0

	move $t1, $v0
	li $t6, 0

	li $t0, 10

loop:	div $t3, $t1, $t0
	rem $t4, $t1, $t0

	li $v0, 1
	move $a0, $t4
	syscall

	mul $t2, $t2, $t0
	add $t2, $t2, $t4
	move $t1, $t3
	addi $t6 $t6, 1
	bne $t1, $zero, loop
	addi $t1, $t1, -1
	j branch

print:	li $v0, 5
	li $a0, 0
branch:	addi $t6, $t6, 1
	bne $t6, $t5, print
	

	

	li $v0, 10
	syscall 



	
