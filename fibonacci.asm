.data

str1:	.asciiz 	"Enter the number of positions: "
str2:	.asciiz	"\n"
str3:	.asciiz	"The sum upto that position is: "

.text
.globl main

main:
	li $v0, 4
	la $a0, str1
	syscall

	li $v0, 5			#Enter upto which number
	syscall

	move $t0, $v0

	li $t1, 0			#First number
	li $t2, 1			#Second number
	li $t4, 2			#Loop counter, compensated for the two numbers printed outside the loop

	li $t6, 0			#Sum upto n

	slt $t5, $t0, $0		#Check for negative n
	beq $t5, 1, exit
	beq $t0, $0, exit		#Check if n == 0

	li $v0, 1
	move $a0, $t1
	syscall			#Print first number

	li $v0, 4
	la $a0, str2
	syscall

	add $t6, $t6, $t1		#Add first number to total sum
	beq $t0, 1, exit		#Check if n == 1

	li $v0, 1
	move $a0, $t2
	syscall			#Print second number

	li $v0, 4
	la $a0, str2
	syscall

	add $t6, $t6, $t2		#Add second number to total sum
	beq $t0, 2, exit		#Check if n == 2

	

loop:
	add $t3, $t1, $t2		#Calculate new number

	li $v0, 1
	move $a0, $t3
	syscall			#Print new number

	li $v0, 4
	la $a0, str2
	syscall

	move $t1, $t2		#Set $t1 = $t2
	move $t2, $t3		#Set $t2 = $t3

	addi $t4, $t4, 1		#Increment loop counter

	add $t6, $t6, $t3		#Add new number to total sum

	bne $t4, $t0, loop		#Check when to terminate loop

exit:	
	li $v0, 4
	la $a0, str3
	syscall

	li $v0, 1
	move $a0, $t6
	syscall

	li $v0, 10
	syscall




		