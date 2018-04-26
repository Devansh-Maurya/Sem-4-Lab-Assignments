.data

msg1:           .asciiz "Enter a: "
msg2:           .asciiz "Enter b: "
msg3:           .asciiz "b times a is: "
indeterminate:  .asciiz "Expression evaluates to an undefined value !"

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

    li $t2, 1

    beq $t0, 1, print       #a == 1, answer will be 1

    beq $t0, -1, loop       #a == -1, jump to loop

    beqz $t0, t0Is0         #a == 0, answer will depend on b

    li $t2, 0
    blez $t1, print         #b <= 0, answer will be 0, as a != 1

    li $t2, 1
    beqz $t1, print         #b == 0, answer will be 1
    
loop:

        beqz $t1, print     #If b == 0 and a == -1, answer will be 1

        mul $t2, $t2, $t0   #$t2 has the answer

        addi $t1, $t1, -1
        bgtz $t1, loop

print:
        li $v0, 4
        la $a0, msg3
        syscall

        li $v0, 1
        move $a0, $t2
        syscall

        j exit

t0Is0:
        blez $t1, t1IsLessOrEqualToZero     #If b <= 0, answer will be undefined
        j loop                              #Else answer will be 0

t1IsLessOrEqualToZero:
        
        li $v0, 4                           #If b <= 0, answer will be undefined
        la $a0, indeterminate
        syscall
        j exit

exit:

        li $v0, 10
        syscall