.data
.text
.globl main

main :

		li $t0, 3
l1:		addi $t0, $t0, -1
		nop			#No operation
		bne $t0, $zero, l1		#$zero == zero register

		li $t1, 5
l2: 		addi $t0, $t0, 1
		nop
		bne $t0, $t1, l2		#Branch not equal

		li $v0, 10
		syscall