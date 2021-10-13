    .text
#include <stdio.h>

main:
# int main(void) {
#     int i; 
#     int numbers[10] = {0}; -> in .data section

    li      $t0, 0                  #     i = 0;
main__while:
    bge     $t0, 10, main__endwhile #     while (i < 10) {
    
   
    li      $v0, 5                  
    syscall                         #         scanf("d",%
    # result stored in register? $v0
    
    # calculate the offset to get to correct address / byte index
    mul     $t1, $t0, 4
    sw      $v0, numbers($t1)       #               &numbers[i]);                     

    addiu   $t0, $t0, 1             #         i++;
    b		main__while			    # branch to target
main__endwhile:                     #     }

    # return 0;
    li      $v0, 0
    jr		$ra					    # jump to $ra
# }

    .data
numbers:
    .word   0, 0, 0, 0, 0, 0, 0, 0, 0, 0