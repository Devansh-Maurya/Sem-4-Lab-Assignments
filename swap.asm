.data

.text

.globl main

main:

	li $t0, 1
	sw $t0, 0($gp)		#global pointer, 28th register

	li $t1, 5
	sw $t1, 4($gp)

	jal swap1			#jump and link

	li $v0, 10
	syscall

swap:
	lw $t3, 0($gp)
	sw $t1, 0($gp)
	sw $t3, 4($gp)
	jr $ra

swap1:	sw $t1, 0($gp)		#mine
	sw $t0, 4($gp)
	jr $ra