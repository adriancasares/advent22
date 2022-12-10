#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int SCREEN_WIDTH = 40;
const int SCREEN_HEIGHT = 6;

void tick(vector<vector<char>> &screen, int cycle, int x) {
  if(abs((cycle % SCREEN_WIDTH) - (x % SCREEN_WIDTH)) <= 1) {
    screen[cycle / SCREEN_WIDTH][cycle % SCREEN_WIDTH] = '@';
  } else {
    screen[(cycle) / SCREEN_WIDTH][(cycle) % SCREEN_WIDTH] = ' ';
  }
}
// Created by Adrian Casares on 12/9/22.
int main() {
  cout << "DAY 10 PART 2" << endl;

  ifstream input("input.txt");

  string line;

  int cycle = 0;
  int x = 1;



  vector<vector<char>> screen;

    for(int i = 0; i < SCREEN_HEIGHT; i++) {
        vector<char> row;
        for(int j = 0; j < SCREEN_WIDTH; j++) {
        row.push_back('.');
        }
        screen.push_back(row);
    }

  while(getline(input, line, '\n')) {
    if(line == "noop") {
      tick(screen, cycle++, x);
    } else {
      string number = line.substr(4, line.length() - 4);

      tick(screen, cycle++, x);
      tick(screen, cycle++, x);

      x += stoi(number);
    }
  }

    // print screen
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            cout << screen[i][j];
        }
        cout << endl;
    }

  return 0;

}