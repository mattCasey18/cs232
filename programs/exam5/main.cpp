#include <iostream>
#include "input.h"
#include "sudoku.h"

using namespace std;

int main() {
    Board puzzle;

    // Let user choose hard-coded or interactive entry
    getSudokuInput(puzzle);

    cout << "\nUnsolved Board:\n";
    printBoard(puzzle);

    if (solveSudoku(puzzle)) {
        cout << "\nSolved Board:\n";
        printBoard(puzzle);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}