/*
1. Write a function CellString which accepts a State as input and returns the following string:
	"⛰️ " if the input equals a kObstacle
	"0 " otherwise.
2. Follow the Upate comments in the main file below, and update the program to store a board of State variables. 
3. Call CellString on each object in the board before printing: CellString(board[i][j]).

Author: Tim Lin
Date: November 30, 2024
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


enum class State {kEmpty, kObstacle};


// Update: Modify the function signature below to accept
// cells with State type instead of int type.
string CellString(const State& cell) {

	switch (cell) {
		case State::kObstacle: return "⛰️   ";
		default: return "0   ";
	}
}

// Update: Change the return type to use auto or
// explicitly indicate vector<State>
vector<State> ParseLine(const string& line) {
	// Upate: Change the variable type for row
    // to be a vector<State>
	vector<State> row;
	int n;
	char c;

	istringstream sline(line);
	while (sline >> n >> c && c == ',') {
		// Upate: Modify the line below to push_back
		// a State::kEmpty if n is 0, and push_back
		// a State::kObstacle otherwise.
		if (n == 0) {
			row.push_back(State::kEmpty);
		}
		else {
			row.push_back(State::kObstacle);
		}
		
	}
	return row;
}

// Upate: Modify the return type here as well. Just
// as above, the board will contain State objects
// instead of ints.
vector<vector<State>> ReadBoardFile(const string& path) {
	// Upate: Modify the board declarationto store 
  	// State objects instead of ints.
	vector<vector<State>> board;
	
	ifstream my_file(path);
	string line;
	if (my_file) {
		while (getline(my_file, line)) {
			board.push_back(ParseLine(line));
		}
	}
	return board;
}


// Upate: Modify the input type here as well. Just
// as above, the board will contain State objects
// instead of ints.
void PrintBoard(const vector<vector<State>>& board) {
	for (const auto& row : board) {
		for (const auto& col : row) {
			// Upate: Modify the line below to call CellString
      		// on each element of the board before streaming to cout.
			cout << CellString(col);
		}
		cout << "\n";
	}
}


int main() {
	
	auto board = ReadBoardFile("./1.board");
	
	PrintBoard(board);
}
