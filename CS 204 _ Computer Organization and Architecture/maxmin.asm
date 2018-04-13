#MIPS program to find maximum and minimum of 'n' numbers

.data

msg1:		.asciiz	"Enter the total number of elements: "
msg2:		.asciiz	"Enter first number: "
msg3:		.asciiz	"Enter another number:"
largeest:	.asciiz	"The largest number is: "
smallest:	.asciiz	"\nThe smallest number is"

.text
.globl main

main:

		li $v0,4
		la $a0,msg1
		syscall

		li $v0,5
		syscall				#Input total numbers

		move $t0,$v0

		li $v0,4
		la $a0,msg2
		syscall

		li $v0,5
		syscall				#Enter first number

		move $t1,$v0

		move $t4, $t1		#$t4 stores max, initially set to $t1, the first value
		move $t5, $t1		#$t5 stores min, initially set to $t1, the first value


		li $t2,1			#Loop counter

loop:		
		addi $t2, $t2, 1	#Increment loop counter

		li $v0,4
		la $a0,msg3
		syscall

		li $v0,5
		syscall

		move $t1,$v0		#Take the next number as input

		slt $t6, $t4, $t1	#If new number is greater, move it to $t4 
		bgtz $t6, greater

		slt $t7, $t1, $t5	#If new number is smaller, move it to $t5
		bgtz $t7, lesser

		bne $t0, $t2, loop	#Check if to terminate loop or not. Will be executed if no other top condition at the top is true
		j endloop			#Jump to print the min. and max.

greater: 

		move $t4, $t1		#Move new number to $t4
	 	bne $t0, $t2, loop	#Check if to terminate loop or not.
	 	j endloop			#Jump to print the min. and max.

lesser:	 

		move $t5, $t1		#Move new number to $t5
	 	bne $t0, $t2, loop	#Check if to terminate loop or not.
	 	j endloop			#Jump to print the min. and max.

endloop: 
	
		li $v0,4
		la $a0, largest
		syscall

		li $v0, 1
		move $a0, $t4
		syscall				#Print max

		li $v0,4
		la $a0, smallest
		syscall

		li $v0, 1
		move $a0, $t5
		syscall				#Print min

		li $v0, 10
		syscall				#Exit