.data

msg1: .asciiz "Enter first number: "
msg2: .asciiz "Enter second number: "
addmsg: .asciiz "The sum is: "

.text

.globl main

main:

li $v0, 4
la $a0, msg1
syscall

li $v0, 5		#add first value
syscall
move $t0, $v0

li $v0, 4
la $a0, msg2
syscall

li $v0, 5
syscall
move $t1, $v0

add $t2, $t0, $t1

li $v0, 4
la $a0, addmsg
syscall

move $a0, $t2
li $v0, 1 
syscall

li $v0, 10
syscall