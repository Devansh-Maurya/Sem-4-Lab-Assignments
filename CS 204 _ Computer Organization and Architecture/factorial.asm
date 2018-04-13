#MIPS program to calculate factorial of a number 'n'

.data

message1:	.asciiz	"Enter a number: "
factorial:	.asciiz	"the factorial of the number is: "
error:		.asciiz	"Invalid input !"	

.text
.globl main

main:

		li $v0, 4
		la $a0, message1
		syscall

		li $v0, 5
		syscall					#Enter the number whose factorial is to be calculated

		move $t0, $v0

		li $t3, 1				#$t3 will contain the factorial. If $t0 == 0, print 1
		beq $t0, $0, print

		blt	$t0, $0, invalid	# if $t0 < $0 then print invalid input
		

		addi $t0, $t0, 1

		li $t2, 1				#$t2 is the loop counter, also used to calculate factorial

loop:	
		mul $t3, $t3, $t2
		addi $t2, $t2, 1		#Increment $t2 by 1
		bne $t2, $t0, loop		#Check whether to loop or not

print:		
		li $v0, 4
		la $a0, factorial
		syscall
		
		li $v0, 1
		move $a0, $t3
		syscall					#Print factorial

exit:	li $v0, 10
		syscall

invalid:
		li $v0, 4
		la $a0, error
		syscall					#Print invalid input if input is negative
		j exit