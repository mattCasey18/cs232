//This will be input file, meanining accepting input, reading input, displaying input. 

/*
    Big questions:
        How can I make inputing the puzzle easier?
            options:
                Displaying a blank puzzle and allowing clicking and entering of numbers in individual cells. 
                reading a puzzle from a file
*/
#include "input.h"
#include <array>
#include <iostream>
#include <conio.h>   
#include <cstdlib>   
using namespace std;

using Board = array<array<int, 9>, 9>;
// 0 = empty cell.
const Board ORIGINAL_PROMPT_PUZZLE = {{
    {{5,3,4, 0,7,0, 9,1,2}},
    {{6,0,0, 1,9,5, 0,0,8}},
    {{0,9,8, 0,0,0, 0,6,0}},

    {{8,0,0, 0,6,0, 0,0,3}},
    {{4,0,0, 8,0,3, 0,0,1}},
    {{7,0,0, 0,2,0, 0,0,6}},

    {{0,6,0, 0,0,0, 2,8,4}},
    {{2,8,7, 4,1,9, 0,0,5}},
    {{3,4,5, 0,8,0, 0,7,9}}
}};

void drawBoard(const Board& board, int selRow, int selCol) {
    system("cls");
    cout << flush;
    cout << "Sudoku Input (Windows console)\n";
    cout << "Arrow keys or W/A/S/D to move\n";
    cout << "Digits 1-9 to fill, 0 to clear\n";
    cout << "Q = finish input\n\n";

    for (int r = 0; r < 9; ++r) {
        if (r % 3 == 0) cout << " - - - - - - - - - - - - - - - - \n";
        else            cout << " - - - - - - - - - - - - - - - - \n";

        for (int c = 0; c < 9; ++c) {
            if (c % 3 == 0) cout << "| ";

            bool selected = (r == selRow && c == selCol);

            if (selected) cout << "[";
            else          cout << " ";

            if (board[r][c] == 0) cout << ".";
            else cout << board[r][c];

            if (selected) cout << "]";
            else          cout << " ";

            if (c == 8) cout << "|";
        }
        cout << "\n";
    }

    cout << " - - - - - - - - - - - - - - - - \n";
    cout.flush();
}

void handleMoveKey(int ch, int& selRow, int& selCol) {
    if (ch == 224) {
        int arrow = _getch();
        if (arrow == 72 && selRow > 0) selRow--;     
        if (arrow == 80 && selRow < 8) selRow++;     
        if (arrow == 75 && selCol > 0) selCol--;     
        if (arrow == 77 && selCol < 8) selCol++;     
    } else {
        if ((ch == 'w' || ch == 'W') && selRow > 0) selRow--;
        if ((ch == 's' || ch == 'S') && selRow < 8) selRow++;
        if ((ch == 'a' || ch == 'A') && selCol > 0) selCol--;
        if ((ch == 'd' || ch == 'D') && selCol < 8) selCol++;
    }
}

void interactiveSudokuInput(Board& board) {
    int selRow = 0;
    int selCol = 0;

    while (true) {
        drawBoard(board, selRow, selCol);
        int ch = _getch(); 
        if (ch == 'q' || ch == 'Q') {           
            break;
        }

        handleMoveKey(ch, selRow, selCol);

        if (ch >= '0' && ch <= '9') {
            board[selRow][selCol] = ch - '0'; 
        }
    }
}

void getSudokuInput(Board& board) {
    system("cls");
    cout << "How do you want to input the Sudoku puzzle?\n";
    cout << "1. Use hard-coded original prompt puzzle\n";
    cout << "2. Enter puzzle interactively\n";
    cout << "\nPress 1 or 2: ";

    char ch = _getch();
    int choice = ch - '0';

    if (choice == 1) {
        board = ORIGINAL_PROMPT_PUZZLE;
    } 
    else if (choice == 2) {

        while (_kbhit()) _getch();

        board = Board{};   
        interactiveSudokuInput(board);
    } 
    else {
        cout << "Invalid choice, defaulting to hard-coded puzzle.\n";
        board = ORIGINAL_PROMPT_PUZZLE;
    }
}