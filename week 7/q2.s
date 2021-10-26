        .text
main:
        jr $ra
        
        .data
v0: # int v0;
        .space 4

v1: # int v1 = 42;
        .word 42

v2: # char v2;
        .space 1

v3: # char v3 = 'a';
        .byte 'a'

v4: # double v4;
        .space 8

v5: # int v5[20];
# use .space since we're not assigning anything to the array yet
        .space 80

v6: # int v6[10][5];
        .space 200

v7: # struct { int x; int y; } v7;
        .space 8

v8: # struct { int x; int y; } v8[4];
        .space 32

v9: # struct { int x; int y; } *v9[4];
# pointers are always 4 bytes in our versions of c
        .space 16
