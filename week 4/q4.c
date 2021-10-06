#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

//   if (x > 46340) {
main__if:  
    if (x <= 46340) 
        goto main__else;
    
    printf("square too big for 32 bits\n");
    
    goto main__endif;
//   } else {
main__else:
    y = x * x;
    printf("%d\n", y);
        
//   }
main__endif:

    return 0;
}