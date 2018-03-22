#Calculating sum of two numbers in memory and display it

.data

abc: .word 5
def: .word 7
ghi: .word 0

line: .asciiz "Sum of the numbers is: \n"

.text
.globl main

main:

	lw $t0, abc
	lw $t1, def

	add $t2, $t1, $t0
	sw $t2, ghi
	li $v0, 4
	lw $a0, line
	syscall

	li $v0, 1
	lw $a0, ghi	#use lw, la gives a wrong answer
	syscall

	li $v0, 10
	syscall