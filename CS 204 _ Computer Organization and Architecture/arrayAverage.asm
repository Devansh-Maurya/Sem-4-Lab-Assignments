.data

array:	.word	1, 2, 3, 4, 5
size:	.word	5
msg1:	.asciiz	"Following are the array elements"
msg2:	.asciiz	" "
sum:	.asciiz	"\nThe average is: "

.text
.globl main

main:
	li $v0, 4
	la $a0, msg1
	syscall

	la $t2, size
	lw $t2, ($t2)

	la $t0, array

	li $t3, 0
	li $t4, 0

	li $v0, 4
	la $a0, msg2
	syscall

loop:	
	lw $t1, ($t0)
	
	add $t4, $t4, $t1

	addi $t0, $t0, 4

	addi $t3, $t3, 1

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 4
	la $a0, msg2
	syscall

	bne $t3, $t2, loop

	div $t4, $t4, $t2
	
	li $v0, 4
	la $a0, sum
	syscall

	li $v0, 1
	move $a0, $t4
	syscall

	li $v0, 10
	syscall