.data

msg1 : .asciiz  "My name is Devansh Maurya\n"
msg2 : .ascii  "I am a student of CSE branch"

.text
.globl main

main:

li $v0, 4
la $a0, msg1
syscall

li $v0, 4
la $a0, msg2
syscall

li $v0, 10
syscall 
