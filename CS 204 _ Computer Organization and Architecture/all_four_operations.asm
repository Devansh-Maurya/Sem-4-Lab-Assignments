.data

msg1:       .asciiz	"Enter first number: "
msg2:       .asciiz "Enter second number: "
addition:   .asciiz "\nOn adding first number to the second number, following result was obtained: "
subtract:   .asciiz "\nOn subtracting second number from the first number, following result was obtained: " 
multiply:   .asciiz "\nOn multiplying first number by the second number, following result was obtained: " 
divide:     .asciiz "\nOn dividing first number by the second number, following quotient was obtained: " 

.text

.globl main

main:
        li $v0, 4
        la $a0, msg1
        syscall

        li $v0, 5
        syscall

        move $t0, $v0

        li $v0, 4
        la $a0, msg2
        syscall

        li $v0, 5
        syscall

        move $t1, $v0

        add $t2, $t0, $t1
        sub $t3, $t0, $t1
        mul $t4, $t0, $t1
    	div $t5, $t0, $t1

        li $v0, 4
        la $a0, addition
        syscall

        li $v0, 1
        move $a0, $t2
        syscall

        li $v0, 4
        la $a0, subtract
        syscall

        li $v0, 1
        move $a0, $t3
        syscall

        li $v0, 4
        la $a0, multiply
        syscall

        li $v0, 1
        move $a0, $t4
        syscall

        li $v0, 4
        la $a0, divide
        syscall

        li $v0, 1
        move $a0, $t5
        syscall

        li $v0, 10
        syscall 