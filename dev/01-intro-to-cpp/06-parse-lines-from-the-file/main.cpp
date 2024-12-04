/*
1. Write a vector<int> ParseLine function which accepts a string as an argument. 
   Use std::istringstream to parse the line by comma chars, and store the ints in a vector<int>. 
   ParseLine should return the vector after parsing.
2. Update ReadBoardFile to use ParseLine and return the board as a vector<vector<int>>. 
3. Update the main function to pass the results of ReadBoardFile to the PrintBoard function.

Author: Tim Lin
Date: November 29, 2024
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::ifstream;
using std::istringstream;


vector<int> ParseLine(const string& line) {
	vector<int> row;
	int n;
	char c;

	istringstream sline(line);
	while (sline >> n >> c && c == ',') {
		row.push_back(n);
	}
	return row;
}


vector<vector<int>> ReadBoardFile(const string& path) {
	vector<vector<int>> board;
	
	ifstream my_file(path);
	string line;
	if (my_file) {
		while (getline(my_file, line)) {
			board.push_back(ParseLine(line));
		}
	}
	return board;
}


void PrintBoard(const vector<vector<int>>& board) {
	for (const auto& row : board) {
		for (const auto& col : row) {
			cout << col;
		}
		cout << "\n";
	}
}

#include "test.cpp"

int main() {
	TestParseLine();
	
	auto board = ReadBoardFile("./1.board");
	
	PrintBoard(board);
}


