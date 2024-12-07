#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "shuffle.c"
#include "compute.c"
#include "text.c"
#include "print.c"

int main() {
    int M[S][S][S];int M_orig[S][S][S];
    int row_f[P], row_f_inv[P];
    int col_f[P], col_f_inv[P];
    int stk_f[P], stk_f_inv[P];
    randomize(M);
    copy_matrix_src_tar(M, M_orig);
    permutize(row_f,P);permutize(col_f,P);permutize(stk_f,P);
    invert(row_f,row_f_inv,P);invert(col_f,col_f_inv,P);invert(stk_f,stk_f_inv,P);
    int delay = 100000;
    int T = 10;
    hide_cursor();
    cls();
    //print_matrix(M);
    for (int i = 0; i < T ; i++) {
        //cursor_to(0,0);
        print_matrix(M);
        process_rows(M, row_f);
        process_cols(M, col_f);
        process_stacks(M, stk_f);
        usleep(delay);
    }
    for (int i = 0; i < T ; i++) { 
        process_stacks(M, stk_f_inv);
        process_cols(M, col_f_inv);
        process_rows(M, row_f_inv);
        //cursor_to(0,0);
        print_matrix(M);
        usleep(delay);
    }
    cursor_to(15,1);
    printf("\n%d decoding errors \n", h_dist(M,M_orig));
    show_cursor();
    //print_matrix(M_orig);
}
      