.data
.text
.globl main

main:
	li $t0,0x1000
	li $t1,0x1010
	sub $t2,$t0,$t1
	li $v0, 10
	syscall