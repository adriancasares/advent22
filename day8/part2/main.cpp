#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 8 PART 2" << endl;

  ifstream input("input.txt");

  string line;

  vector<vector<int>> grid;

  while(getline(input, line, '\n')) {

    vector<int> row;
    for(int i = 0; i < line.size(); i++) {
      row.push_back(line[i] - '0');
    }
    grid.push_back(row);
  }

  int maxScore = 0;

    for(int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        int cell = grid[i][j];

        int viewingDistanceLeft = 0;
        int viewingDistanceRight = 0;
        int viewingDistanceTop = 0;
        int viewingDistanceBottom = 0;

        // go left, stop when you hit the edge or a cell with a value greater than or equal to the current cell
        for(int k = j - 1; k >= 0; k--) {
          viewingDistanceLeft++;
          if(grid[i][k] >= cell) {
            break;
          }
        }

        // go right, stop when you hit the edge or a cell with a value greater than or equal to the current cell
        for(int k = j + 1; k < grid[i].size(); k++) {
          viewingDistanceRight++;
          if(grid[i][k] >= cell) {
            break;
          }
        }

        // go up, stop when you hit the edge or a cell with a value greater than or equal to the current cell
        for(int k = i - 1; k >= 0; k--) {
          viewingDistanceTop++;
          if(grid[k][j] >= cell) {
            break;
          }
        }

        // go down, stop when you hit the edge or a cell with a value greater than or equal to the current cell
        for(int k = i + 1; k < grid.size(); k++) {
          viewingDistanceBottom++;
          if(grid[k][j] >= cell) {
            break;
          }
        }

        int score = viewingDistanceLeft * viewingDistanceRight * viewingDistanceTop * viewingDistanceBottom;

        if(score > maxScore) {
          maxScore = score;
        }
      }
    }


  cout << maxScore << endl;


}