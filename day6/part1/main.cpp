#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Created by Adrian Casares on 12/3/22.
int main() {
    cout << "DAY 6 PART 1" << endl;

    ifstream input("input.txt");

    char current;

    char prev[4] = {' ', ' ', ' ', ' '};

    int count = 0;
    while(input.get(current)) {
      count++;

      prev[0] = prev[1];
      prev[1] = prev[2];
      prev[2] = prev[3];
      prev[3] = current;

      bool valid = true;
      for (int i = 0; i < 4 && valid; i++) {
        for (int j = i + 1; j < 4 && valid; j++) {
          if (prev[i] == prev[j] || prev[i] == ' ' || prev[j] == ' ') {
            valid = false;
          }
        }
      }

      if(valid) {
        cout << endl << count;
      }
    }
}