box* input();
void output(const box* sudoku);

bool valid_row(const box* sudoku, int row);
bool valid_col(const box* sudoku, int col);
bool valid_block(const box* sudoku, int n, int m);
bool valid_sudoku(const box* sudoku);
bool solved(const box* sudoku);

bool row_hasnum(const box* sudoku, int row, int num);
bool col_hasnum(const box* sudoku, int col, int num);
bool block_hasnum(const box* sudoku, int n, int m, int num);
void options_gen(box* sudoku);
void solve(box* sudoku);