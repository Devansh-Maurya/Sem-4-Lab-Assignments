.data

	name: 		.ascii 	"CS ECE "
	address:	.ascii 	"Hi I am fine "
	abc: 		.ascii 	"Hello\n"
	def:     	.asciiz "Fine\n"
	ghi:            .ascii  "Bye"

.text

.globl main

main:

	li $v0,4
	la $a0,name
	syscall

	li $v0,4
	la $a0,address
	syscall

	li $v0,4
	la $a0,abc
	syscall

	li $v0,4
	la $a0,def
	syscall

	li $v0,4
	la $a0,ghi
	syscall

	li $v0,10
	syscall