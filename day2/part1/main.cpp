#include <fstream>
#include <iostream>

// Created by Adrian Casares on 12/2/22.
int main() {
    std::ifstream input("input.txt");
    std::string line;

    int max = 0;
    int points = 0;

    const int POINTS_X = 1;
    const int POINTS_Y = 2;
    const int POINTS_Z = 3;

    while (std::getline(input, line, '\n')) {
        std::string first = line.substr(0, 1);
        std::string second = line.substr(2, 1);

        if (second == "X") { // rock
            points += POINTS_X;
        }

        if (second == "Y") { // paper
            points += POINTS_Y;
        }

        if (second == "Z") { // scissors
            points += POINTS_Z;
        }

        // draw
        if(first == "A" && second == "X" || first == "B" && second == "Y" || first == "C" && second == "Z"){) {
            points += 3;
        }

        // second wins
        if (first == "A" && second == "Y" || first == "B" && second == "Z" || first == "C" && second == "X") {
            points += 6;
        }
    }

    std::cout << "Points: " << points << std::endl;
}