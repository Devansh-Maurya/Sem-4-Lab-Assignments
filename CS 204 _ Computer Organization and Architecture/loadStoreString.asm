.data

	str1:	.asciiz	"Hi how are you !"
	str2:	.asciiz	"I'm fine !"

.text
.globl main

main :

	li $t0, 0x10010000
	lb $t1, 0($t0)
	lb $t2, 1($t0)
	lb $t3, 2($t0)
	lb $t4, 3($t0)

	li $t5, 0x10020000

	sb $t1, 0($t5)
	sb $t2, 1($t5)
	sb $t3, 2($t5)
	sb $t4, 3($t5)

	li $v0, 10
	syscall