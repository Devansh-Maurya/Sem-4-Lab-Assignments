#Calculating the sum of bits in a numerator

.data

num1 : 	.asciiz 	"Enter the number whose sum you want to calculate: "
num2:	.asciiz	"The bit sum of the number is: "

.text
.globl main

main:
	li $v0, 4
	la $a0, num1
	syscall

	li $v0, 5
	syscall
	move $t0, $v0

	li $t1, 0
	li $t2, 0

loop:
	rem $t1, $t0, 2
	div $t0, $t0, 2
	add $t2, $t2, $t1
	bne $t0, 0, loop

	li $v0, 4
	la $a0, num2
	syscall

	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 10
	syscall 