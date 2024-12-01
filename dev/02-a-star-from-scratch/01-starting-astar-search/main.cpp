/*
1. Write a std::vector<vector<State>> Search function stub which takes a board grid and two arrays of size 2 as arguments. 
   The int arrays will represent the start and goal coordinates for the search. 
2. The function should print ""No path found!" and return an empty std::vector<vector<State>>. 
3. The function will later return the board with a path from the start to the goal.
4. In main(), call Search with a start of {0, 0} and a goal of {4, 5}. Store the results in the variable solution.
5. Pass solution to PrintBoard.

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


// Write the Search function stub here.
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


int main() {
  // Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  int init[]{0, 0};
  int goal[]{4, 5};
  auto board = ReadBoardFile("1.board");
  
  // Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  auto solution = Search(board, init, goal);

  PrintBoard(solution);
}