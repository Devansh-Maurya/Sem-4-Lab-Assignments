.data

side1:	    .asciiz	    "Enter the first side of triangle: "
side2:	    .asciiz	    "Enter the second side of triangle: "
side3:	    .asciiz	    "Enter the third side of triangle: "
true:       .asciiz     "Triangle is right angled"
false:      .asciiz     "Triangle is not right angled"
  
.text

.globl main

main:
                li $v0, 4
                la $a0, side1
                syscall

                li $v0, 5
                syscall

                move $t0, $v0
                
                li $v0, 4
                la $a0, side2
                syscall

                li $v0, 5
                syscall

                move $t1, $v0

                li $v0, 4
                la $a0, side3
                syscall

                li $v0, 5
                syscall

                move $t2, $v0

                mul $t0, $t0, $t0
                mul $t1, $t1, $t1
                mul $t2, $t2, $t2

                add $t3, $t0, $t1
                add $t4, $t1, $t2
                add $t5, $t2, $t0

                beq $t3, $t2, right_angled
                beq $t4, $t0, right_angled
                beq $t5, $t1, right_angled
                j not_right_angled
        
right_angled:   la $a0, true
                li $v0, 4
                syscall
                j exit

not_right_angled:
                la $a0, false
                li $v0, 4
                syscall

exit:           li $v0, 10
                syscall