#include <array>
using Board = std::array<std::array<int, 9>, 9>;


extern const Board ORIGINAL_PROMPT_PUZZLE;
void drawBoard(const Board&, int, int);
void handleMoveKey(int, int&, int&);
void interactiveSudokuInput(Board&);
void getSudokuInput(Board&);

void printBoard(const Board&);
bool isValid(const Board&, int, int, int);
bool solveSudoku(Board&);


#include <iostream>


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