/*
1. Write a function void ReadBoardFile which reads lines from a file. 
   Write each line to cout, followed by a newline character "\n". 
   The function should accept a string argument, which represents the path to the file.
   For now, since ReadBoardFile does not need to return anything, use a void return type.
2. Call ReadBoardFile from main using the argument "1.board".

Author: Tim Lin
Date: November 28, 2024
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::vector;
using std::string;
using std::ifstream;


void PrintBoard(const vector<vector<int>> &board) {
	for (const auto &row : board) {
		for (const auto &col : row) {
			cout << col;
		}
		cout << "\n";
	}
}


void ReadBoardFile(const string &path) {
	ifstream my_file(path);
	if (my_file) {
		string line;
		while (getline(my_file, line)) {
			cout << line << "\n";
		}
	}
}


int main() {
	string path = "./1.board";
	ReadBoardFile(path);
	// PrintBoard(board);
}