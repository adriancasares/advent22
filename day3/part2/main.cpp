#include <fstream>
#include <iostream>

using namespace std;

// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 3 PART 2" << endl;

  ifstream input("input.txt");
  string line;

  int totalPoints = 0;

  while (getline(input, line, '\n')) {
    string firstLine = line;
    string secondLine;
    string thirdLine;

    getline(input, secondLine, '\n');
    getline(input, thirdLine, '\n');

    bool done = false;

    for (int i = 0; i < firstLine.length() && !done; i++) {
      if (secondLine.find(firstLine[i]) != string::npos && thirdLine.find(firstLine[i]) != string::npos) {
        char c = firstLine[i];

        if (c >= 'a' && c <= 'z') {
          totalPoints += c - 'a' + 1;
        } else if (c >= 'A' && c <= 'Z') {
          totalPoints += c - 'A' + 27;
        }

        done = true;

      }
    }

  }

  cout << "Result: " << totalPoints<< endl;
}