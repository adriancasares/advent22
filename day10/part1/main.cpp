#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const vector<int> reportCycles = {
    20, 60, 100, 140, 180, 220
};

void reportStrength (vector<int> &strengths, int cycle, int x) {
  // if cycle in report cycles, report strength
    for (int i = 0; i < reportCycles.size(); i++) {
        if (cycle == reportCycles[i]) {
          strengths[i] = cycle * x;
        }
    }
}
// Created by Adrian Casares on 12/9/22.
int main() {
  cout << "DAY 10 PART 1" << endl;

  ifstream input("input.txt");

  string line;

  int cycle = 1;
  int x = 1;



  vector<int> strengths = {
        0, 0, 0, 0, 0, 0
  };

  while(getline(input, line, '\n')) {
    if(line == "noop") {
      reportStrength(strengths, cycle++, x);
    } else {
      string number = line.substr(4, line.length() - 4);

      reportStrength(strengths, cycle++, x);
      reportStrength(strengths, cycle++, x);

      x += stoi(number);
    }
  }

  // sum of strengths
int sum = 0;
for (int i = 0; i < strengths.size(); i++) {
  sum += strengths[i];
}

cout << "Sum of strengths: " << sum << endl;

  return 0;

}