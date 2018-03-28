.data
.text
.globl main

main :

	li $t1, 1
	li $t2, 2
	sltu $t0, $t1, $t2		#shift less than unsigned
	li $t2, 0xffff		#this number will be treated as positive
	li $t3, 0x00000001
	sltu $t0, $t3, $t2

	li $v0, 10
	syscall