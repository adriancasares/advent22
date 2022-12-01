#include <string>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int max = 0;
    int cals = 0;

    while (std::getline(input, line, '\n')) {
        if (line.empty()) {
            if (cals > max) {
                max = cals;
            }
            cals = 0;
        } else {
            cals += std::stoi(line);
        }
    }

    std::cout << "Max calories: " << max << std::endl;

    return 0;
}