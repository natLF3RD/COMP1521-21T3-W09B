# // sum 4 numbers using function calls
        .text
# #include <stdio.h>

# int sum4(int a, int b, int c, int d);
# int sum2(int x, int y);

main:                           # int main(void) {
main__prologue:
        addi    $sp, $sp, -4
        sw      $ra, 0($sp)
        
        
#     int z = sum4(11, 13, 17, 19);
        # set up arguments
        li      $a0, 11
        li      $a1, 13
        li      $a2, 17
        li      $a3, 19
        # do function call
        jal     sum4 # z is in $v0 on return 

        move    $a0, $v0
        li      $v0, 1 
        syscall                 #     printf("%d", z);
        li      $a0, '\n'
        li      $v0, 11 
        syscall                 #     printf("\n");

        li      $v0, 0
        
main__epilogue:
        lw      $ra, 0($sp)
        addi    $sp, $sp, 4
        
        jr      $ra             #     return 0;
        
# }

sum4:
sum4__prologue:
        addi    $sp, $sp, -20
        sw      $ra, 0($sp)
        sw      $s0, 4($sp)
        sw      $s1, 8($sp)
        sw      $s2, 12($sp)
        sw      $s3, 16($sp)
        
# int sum4(int a, int b, int c, int d) {a0=a a1=b a2=c a3=d
        # save the arguments that we need after the first sum2 call.
        move    $s2, $a2
        move    $s3, $a3
        
        # args are already set up for this function call
#     int e = sum2(a, b);
        jal     sum2 # return value in $v0
        move    $s0, $v0 # e => s0
        
#     int f = sum2(c, d);
        # can we assume c and d still in a2 / a3?
        # no, because sum2 has the freedom to change them
        move    $a0, $s2
        move    $a1, $s3
        jal     sum2
        move    $s1, $v0 # f => s1

#     return sum2(e, f);
        move    $a0, $s0
        move    $a1, $s1
        jal     sum2
        # remember that v0 stores the return value of sum2, which we are also returning here.
        
        
sum4__epilogue:
        lw      $ra, 0($sp)
        lw      $s0, 4($sp)
        lw      $s1, 8($sp)
        lw      $s2, 12($sp)
        lw      $s3, 16($sp)
        addi    $sp, $sp, 20
        jr      $ra
# }













sum2:
# int sum2(int x, int y) { a0=x a1=y
#     return x + y;
        # return value in v0!
        add     $v0, $a0, $a1
        jr      $ra 
# }

        .data