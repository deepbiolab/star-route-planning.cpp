/*
1. Write a void PrintBoard function. The function should accept the board as an argument. 
   The function should print each row of the board with a newline "\n".
2. When we have written our PrintBoard function, call it from within main() to print the board.
3. result should look like:
    010000
    010000
    010000
    010000
    000010

Author: Tim Lin
Date: November 28, 2024
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;


void PrintBoard(const vector<vector<int>> &board) {
    for (const auto &row : board) {
        for (const auto &col: row) {
            cout << col;
        }
        cout << "\n";
    }
}


int main() {
    vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0}};
    PrintBoard(board);
    return 0;
}