#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 8 PART 1" << endl;

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

  int total = 0;
  // for every cell, add to total if all cells to left, right, top, or bottom are less than it

  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[i].size(); j++) {
      int cell = grid[i][j];

      bool isMaxLeft = true;
      bool isMaxRight = true;
        bool isMaxTop = true;
        bool isMaxBottom = true;


      // check all cells to left
        for(int k = 0; k < j; k++) {
            if(grid[i][k] >= cell) {
            isMaxLeft = false;
            break;
            }
        }

            for(int k = j + 1; k < grid[i].size(); k++) {
                if(grid[i][k] >= cell) {
                    isMaxRight = false;
                    break;
                }
            }

            // check all cells above
            for(int k = 0; k < i; k++) {
                if(grid[k][j] >= cell) {
                    isMaxTop = false;
                    break;
                }
        }

            // check all cells below
            for(int k = i + 1; k < grid.size(); k++) {
                if(grid[k][j] >= cell) {
                    isMaxBottom = false;
                    break;
            }
        }

        if(isMaxLeft || isMaxRight || isMaxTop || isMaxBottom) {
            total++;
        }
    }
  }

    cout << total << endl;


}