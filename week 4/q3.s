.text
# // print the square of a number
# #include <stdio.h> <- doesnt translate

# int main(void) {
main:
#     int x, y;
#     printf("Enter a number: ");
    # set $a0 to the address of the string
        la  $a0, prompt
        li  $v0, 4
        syscall
    
#     scanf("%d", &x);
	li  $v0, 5
        syscall     # syscall puts the result in $v0
        move $t0, $v0 # we want it in $t0 to use it
    
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
	
	

#     return 0;
        # leave main
        # while returning the value 0
        # set $v0 to 0
        li  $v0, 0
        jr	$ra					# jump to $ra
    
# }

.data
prompt:
.asciiz "Enter a number: "