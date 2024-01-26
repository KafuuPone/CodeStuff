#include <iostream>
#include "classes.h"

#include "func.h"

using namespace std;

// Sudoku: 0-8
// when input, auto convert to n-1 for each value
box* input() {
    box* sudoku = (box*)malloc(81*(sizeof(box))); // create sudoku, i.e. array of 81 boxes
    cout << "Input Sudoku (0 when empty): " << endl;
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            //Input value
            int n; cin >> n;
            (sudoku[i*9+j]).val = n-1;
        }
    return sudoku;
}

// output sudoku
void output(const box* sudoku) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << sudoku[i*9+j].val+1 << " ";
            if(j==2 || j==5)
                cout << "| ";
        }
        cout << endl;
        if(i==2 || i==5)
            cout << "---------------------" << endl;
    }
}

// check whether row is valid(only checks for duplicates)
bool valid_row(const box* sudoku, int row) {
    // if same number appears more than once, return false, else return true
    // checks for every num
    int i = row;
    for(int num=0; num<9; num++) {
        int count = 0;
        for(int j=0; j<9; j++) {
            if(sudoku[i*9+j].val == num)
                count++;
            if(count >= 2)
                return false;
        }
    }
    return true;
}

// check whether col is valid(only checks for duplicates)
bool valid_col(const box* sudoku, int col) {
    // if same number appears more than once, return false, else return true
    // checks for every num
    int j = col;
    for(int num=0; num<9; num++) {
        int count = 0;
        for(int i=0; i<9; i++) {
            if(sudoku[i*9+j].val == num)
                count++;
            if(count >= 2)
                return false;
        }
    }
    return true;
}

// check whether block (n, m) is valid(only check for duplicates)
/*
Block coords:
0, 0 | 0, 1 | 0, 2
1, 0 | 1, 1 | 1, 2
2, 0 | 2, 1 | 2, 2
*/
bool valid_block(const box* sudoku, int n, int m) {
    // if same number appears more than once, return false, else return true
    // checks for every num
    for(int num=0; num<9; num++) {
        int count = 0;
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                // if it is in the block mentioned
                if(i/3==n && j/3==m) {
                    if(sudoku[i*9+j].val == num)
                        count++;
                    if(count >= 2)
                        return false;
                }
    }
    return true;
}

// check if whole sudoku is valid
bool valid_sudoku(const box* sudoku) {
    //check rows
    for(int i=0; i<9; i++)
        if(valid_row(sudoku, i) == false)
            return false;
    //check cols
    for(int j=0; j<9; j++)
        if(valid_col(sudoku, j) == false)
            return false;
    //check blocks
    for(int n=0; n<3; n++)
        for(int m=0; m<3; m++)
            if(valid_block(sudoku, n, m) == false)
                return false;
    return true;
}

// check whether sudoku is solved(it is valid and it has no empty)
bool solved(const box* sudoku) {
    //check empty
    for(int n=0; n<81; n++)
        if(sudoku[n].val == -1)
            return false;
    //check validity
    return valid_sudoku(sudoku);
}

// check if row has said num, true if has
bool row_hasnum(const box* sudoku, int row, int num) {
    int i = row;
    for(int j=0; j<9; j++)
        if(sudoku[i*9+j].val == num)
            return true;
    return false;
}

// check if col has num, true if has
bool col_hasnum(const box* sudoku, int col, int num) {
    int j = col;
    for(int i=0; i<9; i++)
        if(sudoku[i*9+j].val == num)
            return true;
    return false;
}

// check if block has num, true if has, (n, m) being the block coords
bool block_hasnum(const box* sudoku, int n, int m, int num) {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            //it is in the block and has num
            if(i/3==n && j/3==m)
                if(sudoku[i*9+j].val==num)
                    return true;
    return false;
}

// generate options of numbers for each box that isnt solved
void options_gen(box* sudoku) {
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            // only for those that isnt solved
            if(sudoku[i*9+j].val == -1)
                // iterate through all numbers
                for(int n=0; n<9; n++) {
                    // skip if number there is invalid
                    if(row_hasnum(sudoku, i, n)||col_hasnum(sudoku, j, n)||block_hasnum(sudoku, i/3, j/3, n))
                        (sudoku[i*9+j].options)[n] = 0;
                    else
                        (sudoku[i*9+j].options)[n] = 1;
                }
}

// solving the sudoku, if false means no options left, if true means solved
void solve(box* sudoku) {
    // generate options from existing board
    options_gen(sudoku);

    // minimum options for each check option
    int min_box[3] = {9, 0, 0}; // {option_num, row, col}
    int min_row[3] = {9, 0, 0}; // {option_num, row, num}
    int min_col[3] = {9, 0, 0}; // {option_num, col, num}
    int min_blk[4] = {9, 0, 0, 0}; // {option_num, crd1(n), crd2(m), num}

    // check box
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(sudoku[i*9+j].val == -1) {
                int option_count = 0;
                // counting number of options for the box
                for(int n=0; n<9; n++)
                    if((sudoku[i*9+j].options)[n] == 1)
                        option_count++;
                // check with global min
                if(option_count <= min_box[0]) {
                    min_box[0] = option_count;
                    min_box[1] = i;
                    min_box[2] = j;
                    // if(option_count == 0) cout << i << ' ' << j << endl;
                }
            }

    // check row for number of appearances of n
    for(int i=0; i<9; i++)
        // n being the number checked
        for(int n=0; n<9; n++) {
            int num_count = 0;
            for(int j=0; j<9; j++)
                if(sudoku[i*9+j].val == -1)
                    if((sudoku[i*9+j].options)[n] == 1)
                        num_count++;
            if(num_count<=min_row[0] && num_count!=0) {
                min_row[0] = num_count;
                min_row[1] = i;
                min_row[2] = n;
            }
        }

    // check col for number of appearances of n
    for(int j=0; j<9; j++)
        // n being the number checked
        for(int n=0; n<9; n++) {
            int num_count = 0;
            for(int i=0; i<9; i++)
                if(sudoku[i*9+j].val == -1)
                    if((sudoku[i*9+j].options)[n] == 1)
                        num_count++;
            if(num_count<=min_col[0] && num_count!=0) {
                min_col[0] = num_count;
                min_col[1] = j;
                min_col[2] = n;
            }
        }

    // check blk for number of appearances of temp_n
    for(int n=0; n<3; n++)
        for(int m=0; m<3; m++)
            //decide number for the block, temp_n
            for(int temp_n=0; temp_n<9; temp_n++) {
                int temp_n_count = 0;
                //iterate through all boxes in the block
                for(int i=0; i<9; i++)
                    for(int j=0; j<9; j++)
                        if(i/3==n && j/3==m)
                            if(sudoku[i*9+j].val == -1)
                                if((sudoku[i*9+j].options)[temp_n] == 1)
                                    temp_n_count++;
                if(temp_n_count<=min_blk[0] && temp_n_count!=0) {
                    min_blk[0] = temp_n_count;
                    min_blk[1] = n; min_blk[2] = m;
                    min_blk[3] = temp_n;
                }
            }

    // determine minimum
    int min_list[] = {min_box[0], min_row[0], min_col[0], min_blk[0]};
    int minimum = 9, index = 0;
    for(int i=0; i<4; i++)
        if(min_list[i] <= minimum) {
            minimum = min_list[i];
            index = i;
        }

    // no other options
    if(minimum == 0)
        return;
    // list out possibilities and step() all of them until solved(one of them) = true
    else {
        // array of possible sudokus
        box** psb = (box**)malloc(minimum*(sizeof(box*)));

        // generate possibilities
        if(index == 0) {
            // min is box
            int min = min_box[0];
            int i = min_box[1], j = min_box[2];
            int k = 0; // index of psb
            // generate possibility for the possible options
            for(int n=0; n<9; n++)
                // if the number n is a possibility
                if(sudoku[i*9+j].options[n] == 1) {
                    // copy a whole sudoku and edit
                    psb[k] = (box*)malloc(81*(sizeof(box))); // create sudoku, i.e. array of 81 boxes
                    for(int i=0; i<9; i++)
                        for(int j=0; j<9; j++) {
                            //Input value
                            ((psb[k])[i*9+j]).val = (sudoku[i*9+j]).val;
                            for(int n=0; n<9; n++)
                                (((psb[k])[i*9+j]).options)[n] = ((sudoku[i*9+j]).options)[n];
                        }
                    (psb[k])[i*9+j].val = n; // update value
                    for(int n_temp=0; n_temp<9; n_temp++) // clear options
                        ((psb[k])[i*9+j].options)[n_temp] = 0;
                    k++;
                }
        }
        else if(index == 1) {
            // min is row
            int min = min_row[0];
            int i = min_row[1], n = min_row[2];
            int k = 0; // index of psb
            // generate possibility of the possible options
            for(int j=0; j<9; j++)
                // if coord has n as option
                if(sudoku[i*9+j].options[n] == 1) {
                    // copy a whole sudoku and edit
                    psb[k] = (box*)malloc(81*(sizeof(box))); // create sudoku, i.e. array of 81 boxes
                    for(int i=0; i<9; i++)
                        for(int j=0; j<9; j++) {
                            //Input value
                            ((psb[k])[i*9+j]).val = (sudoku[i*9+j]).val;
                            for(int n=0; n<9; n++)
                                (((psb[k])[i*9+j]).options)[n] = ((sudoku[i*9+j]).options)[n];
                        }
                    (psb[k])[i*9+j].val = n; // update value
                    for(int n_temp=0; n_temp<9; n_temp++) // clear options
                        ((psb[k])[i*9+j].options)[n_temp] = 0;
                    psb[k] = (psb[k]);
                    k++;
                }
        }
        else if(index == 2) {
            // min is col
            int min = min_col[0];
            int j = min_col[1], n = min_col[2];
            int k = 0; // index of psb
            // generate possibility of the possible options
            for(int i=0; i<9; i++)
                // if coord has n as option
                if(sudoku[i*9+j].options[n] == 1) {
                    // copy a whole sudoku and edit
                    psb[k] = (box*)malloc(81*(sizeof(box))); // create sudoku, i.e. array of 81 boxes
                    for(int i=0; i<9; i++)
                        for(int j=0; j<9; j++) {
                            //Input value
                            ((psb[k])[i*9+j]).val = (sudoku[i*9+j]).val;
                            for(int n=0; n<9; n++)
                                (((psb[k])[i*9+j]).options)[n] = ((sudoku[i*9+j]).options)[n];
                        }
                    (psb[k])[i*9+j].val = n; // update value
                    for(int n_temp=0; n_temp<9; n_temp++) // clear options
                        ((psb[k])[i*9+j].options)[n_temp] = 0;
                    k++;
                }
        }
        else if(index == 3) {
            // min is blk
            int min = min_blk[0];
            int n = min_blk[1], m = min_blk[2], num = min_blk[3];
            int k = 0; // index of psb
            // generate possibility of the possible options
            for(int i=0; i<9; i++)
                for(int j=0; j<9; j++)
                    if(i/3==n && j/3==m) 
                        if(sudoku[i*9+j].options[num] == 1) {
                            // copy a whole sudoku and edit
                            psb[k] = (box*)malloc(81*(sizeof(box))); // create sudoku, i.e. array of 81 boxes
                            for(int i=0; i<9; i++)
                                for(int j=0; j<9; j++) {
                                    //Input value
                                    ((psb[k])[i*9+j]).val = (sudoku[i*9+j]).val;
                                    for(int n=0; n<9; n++)
                                        (((psb[k])[i*9+j]).options)[n] = ((sudoku[i*9+j]).options)[n];
                                }
                            (psb[k])[i*9+j].val = num; // update value
                            for(int n_temp=0; n_temp<9; n_temp++) // clear options
                                ((psb[k])[i*9+j].options)[n_temp] = 0;
                            k++;
                        }
        }

        // solve the possibilities
        for(int k=0; k<minimum; k++) {
            if(solved(psb[k])==false)
                solve(psb[k]);

            if(solved(psb[k])) {
                for(int i=0; i<9; i++)
                    for(int j=0; j<9; j++) {
                        //Input value
                        (sudoku[i*9+j]).val = ((psb[k])[i*9+j]).val;
                        for(int n=0; n<9; n++)
                            ((sudoku[i*9+j]).options)[n] = (((psb[k])[i*9+j]).options)[n];
                    }
                break;
            }
        }
    }
}