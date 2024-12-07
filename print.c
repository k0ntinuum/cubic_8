
void print_perm(int* f, int l) {
	for (int i = 0; i < l; i++)  {
        if (i % 16 == 0 ) printf("\n");
        printf("%03d ", f[i]);
        
    }
    printf("\n");
}
void print_matrix(int X[S][S][S]) {
    for (int s = 0; s < S; s++) {
        for (int r = 0; r < S; r++) {
            for (int c = 0; c < S; c++) {
                cursor_to(1+ r, 1+ 10*s + c);
                switch (X[s][r][c]) {
                    case 0 : rgb(255,255,255);printf("O ");break;
                    case 1 : rgb(255,255,255);printf("| ");break;
                    case 2 : rgb(255,255,255);printf("  ");break;
                    default : printf("? ");break;
                }
            }
        }
    }
}

int h_dist(int X[S][S][S], int Y[S][S][S]) {
    int e = 0;
    for (int s = 0; s < S; s++) for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) if (X[s][i][j] != Y[s][i][j]) e++;
    return e; 
}
