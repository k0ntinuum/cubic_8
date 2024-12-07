void shuffle(int* f, int l) {
    int j = 0;int t = 0;
    for (int i = l - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        t = f[i];f[i] = f[j];f[j] = t;
    }
}

void permutize(int* f, int l) {
    for (int i = 0; i < l; i++) f[i] = i;
    shuffle(f, l);
}

int index(int* f, int k, int l) {
    for (int i = 0; i < l; i++)
        if (f[i] == k ) return i;
    return -1;
}
void invert(int* f, int* g, int l) {
    for (int i = 0; i < l; i++) g[i] = index(f, i, l);
}
void compose(int* f, int* g, int* h, int l) {
    for (int i = 0; i < l; i++) h[i] = f[g[i]];
}

void randomize(int X[S][S][S]) {
    for (int s = 0; s < S; s++)
        for (int i = 0; i < S; i++) 
            for (int j = 0; j < S; j++)
                X[s][i][j] = arc4random_uniform(B);
}
void seed(int X[S][S][S]) {
    for (int s = 0; s < S; s++)
        for (int i = 0; i < S; i++) 
            for (int j = 0; j < S; j++)
                X[s][i][j] = 0;
}


