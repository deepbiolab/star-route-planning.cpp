/*
1. In the main function, declare a variable board as a vector of vectors of ints: vector<vector<int>>.
2. Assign this data to the board variable:
	{{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0}}

Author: Tim Lin
Date: November 27, 2024
*/

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
	vector<vector<int>> board{
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0}
	};

	// for now, just ignore below code, we will learn how to print vectors later
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}