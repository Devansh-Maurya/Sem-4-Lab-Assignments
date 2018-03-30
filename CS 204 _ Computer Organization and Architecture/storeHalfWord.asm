.data

	str1:	.asciiz	"Hi how are you !"
	str2:	.asciiz	"I'm fine !"

.text
.globl main

main :

	li $t0, 0x10010000
	lhu $t1, 0($t0)
	lhu $t2, 2($t0)
	lhu $t3, 4($t0)
	lhu $t4, 8($t0)

	li $t5, 0x10020000

	sh $t1, 0($t5)
	sh $t2, 2($t5)
	sh $t3, 4($t5)
	sh $t4, 6($t5)

	li $v0, 10
	syscall