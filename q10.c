#include <stdio.h>

// // for loops from while loops.
// void for_loop() {
//     int i;
//     for (; ;) {
//         printf("%d\n", i);
//     }
//     printf("%d\n", i);
//     printf("hello");
    
//     for (; i < 20; i++) {
//         printf("%d\n", i);
        
//     }
//     printf("%d\n", i);
//     // initialise variable for condition
//     // int i = 0;
//     // while (i<10) { // condition
    
//     //     // change some variable for condition
//     //     i++;
//     // }

// }

// recursive function to print out the array
void recurse_print(int *nums, int current_index) {
    // three main steps. in any order really.
    // 1. a way to exit the recursion -> generally returning from the function somehow.
    // 2. a way to actually recurse -> call self (recurse_print)
    // 3. a way to change the state -> reach the way to exit recursion / change some variable.
    
    // exiting condition
    if ( current_index >= 10 || current_index < 0) return;
    
    printf("%d\n", nums[current_index]);
    // recurse
    printf("curr=%d\n", current_index);
    int i = ++current_index;
    int j = current_index++;
    printf("i=%d j=%d\n", i ,j);
    recurse_print(nums, ++i);
    

}


int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int i=0;
    for ( i = 0; i < 10; ++i) {
        printf("%d\n", nums[i]);
    }
    
        printf("%d\n\n\n", nums[i]);
    
    
    recurse_print(nums, 0);
    return 0;
}


// recursive sum on the array





