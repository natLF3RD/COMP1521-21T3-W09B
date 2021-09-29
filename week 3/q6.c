/* We have a number stored in the middle six bits of a uint16_t variable.
 * Write a function to print out what this number is.
 * Eg:
 * Given value 0x0240 = 0b0000 0010 0100 0000
 *   We want these six bits:    XXX XXX 
 * Extracted : 010 010 = 18
*/

#include <stdint.h>
#include <stdio.h>

uint16_t extract_secret(uint16_t secret) {
    uint16_t result = (secret & 0x07E0) >> 5;
    //  0b0100 0010 0100 0000
    // &  0000 0111 1110 0000
    //    0000 0010 0100 0000
    return result;
}

int main () {
    uint16_t secret = 0x0240;
    printf("%d\n", extract_secret(secret));
}