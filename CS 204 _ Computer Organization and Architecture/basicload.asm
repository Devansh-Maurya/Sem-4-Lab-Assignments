.data
.text
.globl main

main:

	li $t0, 1
	li $t1, 2
	li $t2, 3
	li $t3, 4
	li $t0, 5
	li $t1, 6
	li $t2, 7
	li $t3, 8
	li $v0, 10
	syscall
