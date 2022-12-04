#include <fstream>
#include <iostream>

using namespace std;

struct assignment {
    int start;
    int end;
};
// Created by Adrian Casares on 12/3/22.
int main() {
    cout << "DAY 4 PART 1" << endl;

    ifstream input("input.txt");
    string line;

    int countOverlap = 0;

    while (getline(input, line, '\n')) {
        string firstPart = line.substr(0, line.find(','));
        string secondPart = line.substr(line.find(',') + 1);

        int firstStart = stoi(firstPart.substr(0, firstPart.find('-')));
        int firstEnd = stoi(firstPart.substr(firstPart.find('-') + 1));

        int secondStart = stoi(secondPart.substr(0, secondPart.find('-')));
        int secondEnd = stoi(secondPart.substr(secondPart.find('-') + 1));

        if(firstStart <= secondStart && firstEnd >= secondEnd) {
            countOverlap++;
        } else if (secondStart <= firstStart && secondEnd >= firstEnd) {
            countOverlap++;
        }
    }

    cout << "Result: " << countOverlap << endl;
}