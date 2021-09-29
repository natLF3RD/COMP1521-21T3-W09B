#include <stdio.h>

int main () {
    // a = 
    union { int a; int b; } u1;
    printf("a = %lu\n", sizeof u1);
    // b =
    union { unsigned short a; char b; } u2;
    printf("b = %lu\n", sizeof u2);
    // c = 
    union { int a; char b[12]; } u3;
    printf("c = %lu\n", sizeof u3);
    // d = 
    union { int a; char b[14]; } u4;
    printf("d = %lu\n", sizeof u4);
    // e = 
    union { unsigned int a; int b; struct { int x; int y; } c; } u5;
    printf("e = %lu\n", sizeof u5);
}