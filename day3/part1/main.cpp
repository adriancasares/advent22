#include <fstream>
#include <iostream>

using namespace std;

// Created by Adrian Casares on 12/3/22.
int main() {
    cout << "DAY 3 PART 1" << endl;

    ifstream input("input.txt");
    string line;

    int totalPoints = 0;

    while (getline(input, line, '\n')) {
      string firstHalf = line.substr(0, line.length() / 2);
      string secondHalf = line.substr(line.length() / 2, line.length() / 2);

      bool done = false;

        for (int i = 0; i < firstHalf.length() && !done; i++) {
            if (secondHalf.find(firstHalf[i]) != string::npos) {
              char c = firstHalf[i];

                if (c >= 'a' && c <= 'z') {
                    totalPoints += c - 'a' + 1;
                } else if (c >= 'A' && c <= 'Z') {
                    totalPoints += c - 'A' + 27;
                }

              done = true;

            }
        }

        cout << endl;

    }

    cout << "Result: " << totalPoints<< endl;
}