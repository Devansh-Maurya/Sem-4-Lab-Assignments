.data
.text
.globl main

main :

	li $t0, 0xffff
	sll $t0, $t0, 1
	sll $t0, $t0, 1
	
	li $v0, 10
	syscall