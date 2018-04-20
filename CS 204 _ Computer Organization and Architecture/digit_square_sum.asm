
#Question 3
#Don't start the number from 0
#Don't end the number in 0

.data

msg1:	    .asciiz	    "Enter the number: "
msg2:       .asciiz     "The sum of squares of digits is" 
  

.text

.globl main

main:
        li $v0, 4
        la $a0, msg1
        syscall

        li $v0, 5
        syscall

        move $t1, $v0
        li $t5, 0

        li $t0, 10

loop:	
        rem $t4, $t1, $t0
        div $t1, $t1, $t0

        mul $t4, $t4, $t4
        add $t5, $t5, $t4

        bne $t1, $zero, loop
        
print:  la $a0, msg2

        li $v0, 4
        syscall

        li $v0, 1
        move $a0, $t5
        syscall

        li $v0, 10
        syscall 