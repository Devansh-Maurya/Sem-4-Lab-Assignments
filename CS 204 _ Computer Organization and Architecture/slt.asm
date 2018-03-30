.data
.text
.globl main

main :

	li $t1, 1
	li $t2, 2
	slt $t0, $t1, $t2
	li $t2, 0xf1000000
	li $t3, 0x00000001
	slt $t0, $t3, $t2

	li $v0, 10
	syscall