.text
# #include <stdio.h>

# int main(void) {
main:
#     int x, y;
#     printf("Enter a number: ");
        la  $a0, prompt
        li  $v0, 4
        syscall
    
#     scanf("%d", &x);
	li  $v0, 5
        syscall     # syscall puts the result in $v0
        move $t0, $v0 # we want it in $t0 to use it

main__if:
#     if (x > 46340) {
        ble $t0, 46340, main__else
        
#         printf("square too big for 32 bits\n");
        la $a0, error_msg
        li $v0, 4
        syscall
        
        j main__endif
#     } else {
main__else:
#     y = x * x;
	mul $t1, $t0, $t0
	
#     printf("%d\n", y);
	# need to split it
	# printf("%d", y);
	move $a0, $t1
	li $v0, 1
	syscall
	# printf("\n");
	# la is for addresses only!
	li $a0, '\n'
	li $v0, 11
	syscall
#     }
main__endif:

#     return 0;
        li $v0, 0
        jr $ra
# }

.data
prompt:
        .asciiz "Enter a number: "
error_msg:
        .asciiz "square too big for 32 bits\n"
