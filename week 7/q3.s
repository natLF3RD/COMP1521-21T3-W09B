    .text
main:
    addi    $sp, $sp, -4
    sw      $ra, 0($sp)
    
    la $a0, arr
    li $a1, 5
    jal max 
    
    move $a0, $v0
    li $v0, 1
    syscall
    li $a0, '\n'
    li $v0, 11
    syscall
    
    lw      $ra, 0($sp)
    addi    $sp, $sp, 4
    jr $ra

max:
    # int max(int a[], int length) {
    # a0 is adress of the array argument
    # a1 contains length
max__prologue:
    addi    $sp, $sp, -8
    sw      $ra, 0($sp)
    sw      $s0, 4($sp)
    

    lw      $s0, ($a0)       #     int first_element = a[0];
    
max__if_length:
    bne     $a1, 1, max__else_length    #     if (length == 1) {
    move    $v0, $s0
    j       max__epilogue               #         return first_element;
    
max__else_length:                       #     } else {
#         // find max value in rest of array
    addi    $a0, $a0, 4                 # &a[1]
    addi    $a1, $a1, -1                # length - 1
    jal     max                         #         int max_so_far = max(&a[1], length - 1);
    # v0 <- max_so_far
    
max__if_max_so_far:
    ble     $s0, $v0, max__endif_max_so_far #         if (first_element > max_so_far) {
    move    $v0, $s0         #             max_so_far = first_element;
max__endif_max_so_far:                  #         }

    #         return max_so_far; -> $v0 is still max_so_far so just fall through to epilogue
max__endif_length:                      #     }
max__epilogue:
    lw      $ra, 0($sp)
    lw      $s0, 4($sp)
    addi    $sp, $sp, 8

    jr      $ra
# }

    .data
arr: .word  1, 4, 5, 7, 3