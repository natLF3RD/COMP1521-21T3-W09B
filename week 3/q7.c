#include <stdio.h>
#include <stdint.h>

int main () {
    struct {
        char a; // sizeof char = 1 byte
        float b; // sizeof float = 4 byte
    } x1;
    union {
        int a;
        float b;
    } x2; 
    
    unsigned long diff1 = (unsigned long) (&x1.b) - (unsigned long) (&x1.a);
    printf("sizeof x1.a=%lu sizeof x1.b=%lu sizeof x1=%lu\n", sizeof x1.a, sizeof x1.b, sizeof x1);
    printf("&x1=%p &(x1.a)=%p &(x1.b)=%p diff=%ld\n", &x1, &(x1.a), &(x1.b), diff1);
    unsigned long diff2 = (unsigned long) (&x2.b) - (unsigned long) (&x2.a);
    printf("sizeof x2.a=%lu sizeof x2.b=%lu sizeof x2=%lu\n", sizeof x2.a, sizeof x2.b, sizeof x2);
    printf("&x2=%p &(x2.a)=%p &(x2.b)=%p diff=%ld\n", &x2, &(x2.a), &(x2.b), diff2);
}