#Question 3
#Don't start the number from 0
#Don't end the number in 0

.data

msq1:	.asciiz	"Enter the number: "
ans:	.asciiz	"The reversed number is: "

.text

.globl main

main:
	li $v0, 4
	la $a0, msq1
	syscall

	li $v0, 5
	syscall

	move $t1, $v0

	li $t0, 10

loop:	div $t3, $t1, $t0
	rem $t4, $t1, $t0
	mul $t2, $t2, $t0
	add $t2, $t2, $t4
	move $t1, $t3
	bne $t1, $zero, loop

	li $v0, 4
	la $a0, ans
	syscall

	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 10
	syscall 



	
