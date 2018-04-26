.data

msq1:   .asciiz         "Enter the number of row: "
star:   .asciiz         "*"
newline: .asciiz        "\n"

.text
.globl main

main:
        
        li $v0, 4
        la $a0, msq1
        syscall

        li $v0, 5
        syscall

        move $t0, $v0
        blez $t0, exit
        
        li $t1, 0               #Outer loop counter
        li $t2, 0               #Inner loop counter

loop:


        li $v0, 4
        la $a0, star
        syscall                 #Print *

        addi $t2, $t2, 1
        ble $t2, $t1, loop      #Inner loop

        li $v0, 4
        la $a0, newline
        syscall                 #Print new line

        li $t2, 0

        addi $t1, $t1, 1
        blt $t1, $t0, loop      #Inner loop

exit:
        li $v0, 10
        syscall
