#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 5 PART 2" << endl;

  ifstream input("input.txt");
  string line;

  int countOverlap = 0;

  stack<char>* rows = new stack<char>[9];

  for (int i = 0; i < 9; i++) {
    rows[i] = stack<char>();
  }

  stack<string> lines = stack<string>();

  while (getline(input, line, '\n')) {
    if (line.find("[") == string::npos) {
      getline(input, line, '\n');
      break;
    }

    lines.push(line);
  }

  while(lines.size() > 0) {
    string line = lines.top();

    lines.pop();

    for(int i = 0; i < line.length(); i += 4) {
      string letter = line.substr(i + 1, 1);

      int rowIndex = i / 4;

      if(letter == " ") {
        continue;
      }

      rows[rowIndex].push(letter[0]);
    }
  }



  while(getline(input, line, '\n')) {
    int firstNumberPos = 5;
    string firstNumber = line.substr(firstNumberPos, line.find(" ", firstNumberPos) - firstNumberPos);
    int moveQuantity = stoi(firstNumber);

    int secondNumberPos = line.find(" from ") + 6;
    string secondNumber = line.substr(secondNumberPos, line.find(" ", secondNumberPos) - secondNumberPos);
    int moveFrom = stoi(secondNumber) - 1;

    int thirdNumberPos = line.find(" to ") + 4;
    string thirdNumber = line.substr(thirdNumberPos, line.find(" ", thirdNumberPos) - thirdNumberPos);
    int moveTo = stoi(thirdNumber) - 1;

    stack<char> tempStack = rows[moveFrom];
    char* tempArray = new char[moveQuantity];

    for(int i = 0; i < moveQuantity; i++) {
      char letter = rows[moveFrom].top();
      rows[moveFrom].pop();
      tempArray[i] = letter;
    }

    for(int i = moveQuantity - 1; i >= 0; i--) {
      rows[moveTo].push(tempArray[i]);
    }
  }

  for(int i = 0; i < 9; i++) {
    cout << rows[i].top();
  }

}