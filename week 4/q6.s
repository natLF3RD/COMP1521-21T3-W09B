.text# #include <stdio.h>

main:
# int main(void) {
#     int x = 24;
        li $t0, 24
main__while:
# if (x >= 42) goto main__endwhile;
        bge $t0, 42, main__endwhile
#       printf("%d\n", x);
        # printf("%d", x);
		move $a0, $t0
		li $v0, 1
		syscall
		
main__while:
		# printf("\n");
		# la is for addresses only!
		li $a0, '\n'
		li $v0, 11
		syscall
		
#         x += 3;
        addi $t0, $t0, 3
        
#         goto main__while;
		j main__while
main__endwhile:
#     return 0;
        li $v0, 0
        jr $ra
# }
