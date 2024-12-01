/*
1. Initialize variables with the starting node values as follows:

- `x` and `y` are given by the `init` variable values,
- Set the initial cost `g` = 0,
- `h` is given by `Heuristic` function.

2. Add first node to open vector using the `AddToOpen` function by passing the node values: 
  `x`, `y`, `g`, and `h`, along with the `open` and `grid` vectors.

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


enum class State {kEmpty, kObstacle, kClosed};


vector<State> ParseLine(string line) {
	
	int n;
	char c;

	istringstream sline(line);

	vector<State> row;

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


vector<vector<State>> ReadBoardFile(string path) {
	ifstream my_file(path);
	
	vector<vector<State>> board{};
	
	if (my_file) {
		string line;
		while (getline(my_file, line)) {
			board.push_back(ParseLine(line));
		}
	}
	return board;
}


// Calculate the manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}


/** 
 * Add a node to the open list and mark it as open. 
 */
void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& openlist, vector<vector<State>>& grid) {
	openlist.push_back(vector<int> {x, y, g, h});
	grid[x][y] = State::kClosed;
}


/*
 * Implementation of A* search algorithm
*/
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
	// Create the vector of open nodes.
	vector<vector<int>> open {};
	
	// Initialize the starting node.
	int x = init[0];
	int y = init[1];
	int g = 0;
	int h = Heuristic(x, y, goal[0], goal[1]);
	
	// Use AddToOpen to add the starting node to the open vector.
	AddToOpen(x, y, g, h, open, grid);

	cout << "No path found!" << "\n";
	return vector<vector<State>> {};
}


string CellString(State cell) {
	switch (cell) {
		case State::kObstacle: return "⛰️   ";
		default: return "0   ";
	}
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
	TestAddToOpen();
}