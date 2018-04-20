.data

str1:	.asciiz	"How are you ?\n"
str2:	.ascii	"I am fine !"
str3:	.ascii	"What about you?"

.text
.globl main

main:
	li $v0, 4
	la $a0, str1
	syscall
L1:
	li $v0, 4
	la $a0, str2
	syscall

	j L1

	li $v0, 4
	la $a0, str3
	syscall
	li $v0, 10
	syscall	