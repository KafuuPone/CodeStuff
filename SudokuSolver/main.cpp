#include <iostream>
#include "classes.h"
#include "func.h"

using namespace std;

int main() {
    box* sudoku = input(); // sudoku = array of boxes

    if(valid_sudoku(sudoku)) {
        solve(sudoku);
        if(solved(sudoku)) 
            cout << "Solved!" << endl;
        else
            cout << "Stuck.." << endl;
        output(sudoku);
    }
    else
        cout << "Invalid sudoku." << endl;

    return 0;
}