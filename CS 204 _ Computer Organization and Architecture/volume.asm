#Calculate volume of a cuboid

.data

	length: .word 2
	breadth: .word 3
	height: .word 4
	volume: .word 0
	answer: .asciiz "The  volume is: \n"

.text
.globl main

main:

	lw $t0, length
	lw $t1, breadth
	mul $t2, $t0, $t1
	lw $t0, height
	mul $t3, $t2, $t0
	sw $t3, volume

	li $v0, 4
	la $a0,	answer
	syscall

	li $v0, 1
	lw $a0, volume
	syscall

	li $v0, 10
	syscall