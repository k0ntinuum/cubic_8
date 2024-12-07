

void process_row(int X[S][S][S], int r, int s, int f[P]) {
	int found_value = 0;
	int new_value = 0;
	for (int c = 0 ; c < S ; c++) found_value += place_value[c]*X[s][r][c];
	new_value = f[found_value];
	for (int c = 0 ; c < S ; c++) {
		X[s][r][c] = new_value/place_value[c];
		new_value -= X[s][r][c]*place_value[c];
	}
}
void process_rows(int X[S][S][S],int f[P]) {
	for (int s = 0; s < S; s++) for (int r = 0; r < S; r++) process_row(X, r, s, f);
}
void process_col(int X[S][S][S], int c, int s, int f[P]) {
	int found_value = 0;
	int new_value = 0;
	for (int r = 0 ; r < S ; r++) found_value += place_value[r]*X[s][r][c];
	new_value = f[found_value];
	for (int r = 0 ; r < S ; r++) {
		X[s][r][c] = new_value/place_value[r];
		new_value -= X[s][r][c]*place_value[r];
	}
}
void process_cols(int X[S][S][S],int f[P]) {
	for (int s = 0; s < S; s++) for (int c = 0; c < S; c++) process_col(X, c, s, f);
}
void process_stack(int X[S][S][S], int r, int c, int f[P]) {
	int found_value = 0;
	int new_value = 0;
	for (int s = 0 ; s < S ; s++) found_value += place_value[s]*X[s][r][c];
	new_value = f[found_value];
	for (int s = 0 ; s < S ; s++) {
		X[s][r][c] = new_value/place_value[s];
		new_value -= X[s][r][c]*place_value[s];
	}
}
void process_stacks(int X[S][S][S],int f[P]) {
	for (int r = 0; r < S; r++) for (int c = 0; c < S; c++) process_stack(X, r, c, f);
}


void copy_matrix_src_tar(int src[S][S][S],int tar[S][S][S]) {
	for (int s = 0; s < S; s++) for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) tar[s][i][j] = src[s][i][j];
}




