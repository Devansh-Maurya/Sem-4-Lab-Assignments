.data

msg1: .asciiz "Enter first number: "
msg2: .asciiz "Enter second number: "
msg3: .asciiz "Enter third number: "
greatestMsg: .asciiz "The greatest number is: "

.text

.globl main

main:

                        li $v0, 4                       #Enter first number
                        la $a0, msg1
                        syscall

                        li $v0, 5
                        syscall
                        move $t0, $v0

                        li $v0, 4                       #Enter second number
                        la $a0, msg2
                        syscall

                        li $v0, 5
                        syscall
                        move $t1, $v0
                        
                        li $v0, 4                       #Enter third number
                        la $a0, msg3
                        syscall

                        li $v0, 5
                        syscall
                        move $t2, $v0

                        slt $t3, $t1, $t0               #if($t1< $t0)
                        blez $t3, t0NotGreaterThant1    #{
                        slt $t3, $t2, $t0               #   if($t2< $t0)
                        blez $t3, t0NotGreaterThant2    #   {
                        move $t4, $t0                   #       greatest= $t0;
                        j printGreatest                 #       printf("Greatest= %d\n", greatest);}
t0NotGreaterThant2:     move $t4, $t2                   #   else{ greatest= $t2;
                        j printGreatest                 #       printf("Greatest= %d\n", greatest);}}
t0NotGreaterThant1:     slt $t3, $t2, $t1               #else if($t2< $t1)   
                        blez $t3, t1GreaterThant2       #{
                        move $t4, $t1                   #   greatest= $t0;
                        j printGreatest                 #   printf("Greatest= %d\n", greatest);}
t1GreaterThant2:        move $t4, $t2                   #else{ greatest= $t2;
                        j printGreatest                 #   printf("Greatest= %d\n", greatest);}

printGreatest:           li $v0, 4
                        la $a0, greatestMsg
                        syscall

                        move $a0, $t4
                        li $v0, 1
                        syscall 

                        li $v0, 10
                        syscall