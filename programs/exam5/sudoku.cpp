/*
    solve portion must accept input from input section
    options for algorithms
        backtracking
        brute force
    
    possible ways to solve:
        by 3x3 segement
        brute force
        column and row
*/

#include "sudoku.h"
#include <iostream>
using namespace std;

void printBoard(const Board& board) {
    for (int r = 0; r < 9; ++r) {
        if (r % 3 == 0) cout << " - - - - - - - - - - -  \n";

        for (int c = 0; c < 9; ++c) {
            if (c % 3 == 0) cout << "| ";

            if (board[r][c] == 0) cout << ".";
            else cout << board[r][c];

            if (c == 8) cout << "|";
            cout << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

bool isValid(const Board& board, int row, int col, int num) {
    for (int c = 0; c < 9; c++)
        if (board[row][c] == num) return false;

    for (int r = 0; r < 9; r++)
        if (board[r][col] == num) return false;

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (board[boxRow + r][boxCol + c] == num)
                return false;

    return true;
}

bool solveSudoku(Board& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {

                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board))
                            return true;

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
