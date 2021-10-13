# #include <stdio.h>
N_COLS = 12
N_ROWS = 6
    .text

main:
# int main(void) {
    
    li      $t0, 0                     # int row = 0;
main__for_outer:
    bge     $t0, N_ROWS, main__endfor_outer #     for ( row < 6;) {
    
    li      $t1, 0     # int col = 0;
main__for_inner:
    bge     $t1, N_COLS, main__endfor_inner #         for ( col < 12;) {

    # flag[row][col]
    # to get to position (row, col) in 2D array: row*N_COLS*sizeof(element)+col*sizeof(element)
    # col*sizeof(element) -> don't need this because size is 1!!
    # N_COLS*sizeof(element) -> note you can't multiply two constants as theres no instruction to do it
    #   therefore will need to load to a register first.
    mul     $t2, $t0, N_COLS
    add     $t2, $t2, $t1
    lb      $a0, flag($t2)
    li      $v0, 11
    syscall                             #             printf ("%c", flag[row][col]);

    addiu   $t1, $t1, 1               #  col++
    j       main__for_inner
main__endfor_inner:                     # }

    li      $v0, 11
    li      $a0, '\n'
    syscall                             #         printf ("\n");

    addiu   $t0, $t0, 1               #  row++
    j       main__for_outer
main__endfor_outer:                     #     }


    li      $v0, 0
    jr      $ra                         # }

    .data
# char flag[6][12] = {
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
#     {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
#     {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
# };
# mac: shorcut to have more than one typing cursor: cmd + option + shit + arrow key
flag:
    .byte   '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte   '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte   '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte   '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte   '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

    # to get to position in a row: flag_row+index*sizeof(element)
    
    # to jump across a whole row: N_COLS*sizeof(element)
    # to jump across n rows: row_index*N_COLS*sizeof(element) = (start addr of the flag row)
    
    # to get to position (row, col) in 2D array: row*N_COLS*sizeof(element)+col*sizeof(element)
