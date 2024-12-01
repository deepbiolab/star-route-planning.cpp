/*
1. Add a kStart and kFinish to the State enum.
2. Set the grid cell to kStart for the initial coordinates and kFinish for the goal coordinates. 
   This will happen in the Search function.
3. In CellString, add cases to return "🚦 " for kStart and "🏁 " for kFinish.

Author: Tim Lin
Date: December 1, 2024
*/



#include <algorithm>  // for sort
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


// TODO: Add kStart and kFinish enumerators to the State enum.
enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


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


/**
 * Compare the F values of two cells.
 */
bool Compare(vector<int> a, vector<int> b) {
    int f1 = a[2] + a[3]; // f1 = g1 + h1
    int f2 = b[2] + b[3]; // f2 = g2 + h2
    if (f1 > f2) {
        return true;
    } else {
        return false;
    }
}


/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}


/** 
 * Check that a cell is valid: on the grid, not an obstacle, and clear. 
 */
bool CheckValidCell(int x, int y, vector<vector<State>> grid) {
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());
    if (on_grid_x && on_grid_y) {
        return grid[x][y] == State::kEmpty;
    }
    return false;
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


/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
void ExpandNeighbors(const vector<int>& current, 
                     int goal[2],
                     vector<vector<int>>& openlist, 
                     vector<vector<State>>& grid) {

    // Get current node's data.
    // Since we only need current node's information instead of change it
    // So we use const keyword and reference of current node which avoid modify and copy.
    int x = current[0];
    int y = current[1];
    int g = current[2];

    // Loop through current node's potential neighbors.
    for (int i = 0; i < 4; i++) {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        if (CheckValidCell(x2, y2, grid)) {
            
            // Increment g value, compute h value, and add neighbor to open list.
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);

            // We need to make sure openlist, grid same as before, 
            // so we need `pass by reference` in this function.
            AddToOpen(x2, y2, g2, h2, openlist, grid);
        }
    }
}

/** 
 * Implementation of A* search algorithm
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open {};
  
  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0],goal[1]);
  AddToOpen(x, y, g, h, open, grid);

  // while open vector is non empty {
  while (open.size() > 0) {
    
    // Sort the open list using CellSort, and get the current node.
    CellSort(&open);
    vector<int> current = open.back();
    open.pop_back();
    
    // Get the x and y values from the current node,
    // and set grid[x][y] to kPath.
    int x = current[0]; 
    int y = current[1];
    grid[x][y] = State::kPath;
    
    // Check if you've reached the goal. If so, return grid.
    if (x == goal[0] && y == goal[1]) {
		// TODO: Set the init grid cell to kStart, and 
      	// set the goal grid cell to kFinish before returning the grid.
		grid[init[0]][init[1]] = State::kStart;
		grid[goal[0]][goal[1]] = State::kFinish;
        return grid;
    }
    
    // If we're not done, expand search to current node's neighbors.
    ExpandNeighbors(current, goal, open, grid);
  
  }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  
  // We've run out of new nodes to explore and haven't found a path.
  cout << "No path found!" << "\n";
  return std::vector<vector<State>>{};
}


string CellString(State cell) {
    switch (cell) {
        case State::kObstacle: return "⛰️   ";
        case State::kPath: return "🚗   ";
		// TODO: Add cases to return "🚦   " for kStart
		case State::kStart: return "🚦   ";
		// and "🏁   " for kFinish.
		case State::kFinish: return "🏁   ";
    	
        default: return " 0   ";
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
    TestCompare();
    TestSearch();
    TestCheckValidCell();
    TestExpandNeighbors();
}

