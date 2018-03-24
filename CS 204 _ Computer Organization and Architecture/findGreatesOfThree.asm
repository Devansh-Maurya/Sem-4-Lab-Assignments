.data

msg1: .asciiz "Enter first number: "
msg2: .asciiz "Enter second number: "
msg3: .asciiz "Enter third number: "
greatestMsg: .asciiz "The greatest number is: "

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
                        
                        li $v0, 4
                        la $a0, msg3
                        syscall

                        li $v0, 5
                        syscall
                        move $t2, $v0

                        slt $t3, $t1, $t0   #If $t1< $t0, then $t3=1; else $t3= 0
                        blez $t3, t0NotGreaterThant1
                        slt $t3, $t2, $t0   #If $t2< $t0, then $t3=1; else $t3= 0
                        blez $t3, t0NotGreaterThant2
                        move $t4, $t0
                        j printGreatest
t0NotGreaterThant2:     move $t4, $t2
                        j printGreatest
t0NotGreaterThant1:     slt $t3, $t2, $t1   #If $t2< $t1, then $t3=1; else $t3= 0
                        blez $t3, t1GreaterThant2
                        move $t4, $t1
                        j printGreatest
t1GreaterThant2:        move $t4, $t2
                        j printGreatest

printGreatest:           li $v0, 4
                        la $a0, greatestMsg
                        syscall

                        move $a0, $t4
                        li $v0, 1
                        syscall 

                        li $v0, 10
                        syscall




