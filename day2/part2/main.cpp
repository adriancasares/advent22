#include <fstream>
#include <iostream>

// Created by Adrian Casares on 12/2/22.
int main() {
    std::ifstream input("input.txt");
    std::string line;

    int points = 0;

    const int POINTS_A = 1;
    const int POINTS_B = 2;
    const int POINTS_C = 3;

    const int LOSS_POINTS = 0;
    const int DRAW_POINTS = 3;
    const int WIN_POINTS = 6;

    while (std::getline(input, line, '\n')) {
        std::string first = line.substr(0, 1);
        std::string action = line.substr(2, 1);

        if (first == "A") { // rock
            if (action == "X") {
                points += POINTS_C; // scissors
                points += LOSS_POINTS;
            }
            if (action == "Y") {
                points += POINTS_A; // rock
                points += DRAW_POINTS;
            }
            if (action == "Z") {
                points += POINTS_B; // paper
                points += WIN_POINTS;
            }
        } else if (first == "B") { // paper
            if (action == "X") {
                points += POINTS_A; // rock
                points += LOSS_POINTS;
            }
            if (action == "Y") {
                points += POINTS_B; // paper
                points += DRAW_POINTS;
            }
            if (action == "Z") {
                points += POINTS_C; // scissors
                points += WIN_POINTS;
            }
        } else if (first == "C") { // scissors
            if (action == "X") {
                points += POINTS_B; // paper
                points += LOSS_POINTS;
            }
            if (action == "Y") {
                points += POINTS_C; // scissors
                points += DRAW_POINTS;
            }
            if (action == "Z") {
                points += POINTS_A; // rock
                points += WIN_POINTS;
            }
        }
    }

    std::cout << "Points: " << points << std::endl;
}