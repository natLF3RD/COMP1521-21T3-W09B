#include <stdio.h>

int main () {
    union _all {
       int   ival;
       char cval;
       char  sval[4];
       float fval;
       unsigned int uval;
    } var;
    
    var.uval = 0x00313233;
    
    printf("%x\n", var.uval);
    printf("%d\n", var.ival);
    printf("%x\n", var.cval); // note endianness.
    printf("%s\n", var.sval);
    printf("%f\n", var.fval);
    printf("%e\n", var.fval);
}