/*
1. Write an `int` Heuristic function which takes four `int`s as arguments. The `int`s represent two pairs of 2D coordinates:
	(x_1, y_1, x_2, y_2)
2. The function should return an int which is the Manhattan Distance from one coordinate to the other: 
	|x_2 - x_1| + |y_2 - y_1|

Note: In general, any admissible function can be used for the heuristic, 
but for this project, we will write one that takes a pair of 2D coordinates on the grid 
and returns the Manhattan Distance from one coordinate to the other.


Author: Tim Lin
Date: December 1, 2024
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
using std::abs;


enum class State {kEmpty, kObstacle};


// Write the Heuristic function by calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}


vector<vector<State>> Search(const vector<vector<State>>& grid, const int init[2], const int goal[2]) {
	cout << "No path found!" << "\n";
	return vector<vector<State>> {};
}


string CellString(const State& cell) {

	switch (cell) {
		case State::kObstacle: return "⛰️   ";
		default: return "0   ";
	}
}


vector<State> ParseLine(const string& line) {
	vector<State> row;
	int n;
	char c;

	istringstream sline(line);
	while (sline >> n >> c && c == ',') {
		if (n == 0) {
			row.push_back(State::kEmpty);
		}
		else {
			row.push_back(State::kObstacle);
		}
		
	}
	return row;
}


vector<vector<State>> ReadBoardFile(const string& path) {
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


void PrintBoard(const vector<vector<State>>& board) {
	for (const auto& row : board) {
		for (const auto& col : row) {
			cout << CellString(col);
		}
		cout << "\n";
	}
}

#include "test.cpp" // For testing solution

int main() {
  // Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[]{0, 0};
  int goal[]{4, 5};
  auto board = ReadBoardFile("1.board");
  
  // Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  auto solution = Search(board, init, goal);

  PrintBoard(solution);
// Tests
  TestHeuristic();
}