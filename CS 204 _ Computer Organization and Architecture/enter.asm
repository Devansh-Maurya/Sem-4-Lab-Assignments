.data

msg1: .asciiz "Enter a number: "
msg2: .asciiz "The number you entered is "
msg3: .asciiz "\nEnter a string: "
msg4: .asciiz "The string you entered is "
address: .asciiz ""

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

li $v0, 1
move $a0, $t0
syscall

li $v0, 4
la $a0, msg3
syscall

la $a0, address
li $a1, 10

li $v0, 8
syscall

move $t0, $a0

li $v0, 4
la $a0, msg4
syscall

move $a0, $t0

li $v0, 4
syscall


li $v0, 10
syscall



