#include <string>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int cals = 0;

    const int SIZE = 3;
    int top[SIZE] = {0, 0, 0};

    while (std::getline(input, line, '\n')) {
        if (line.empty()) {
            int replace = -1;

            for(int i = 0; i < SIZE; i++){
                if (top[i] < cals) {
                    replace = i;
                }
            }

            if (replace != -1) {
                top[replace] = cals;
            }

            cals = 0;
        } else {
            cals += std::stoi(line);
        }
    }

    int total = 0;

    for(int i = 0; i < SIZE; i++){
        total += top[i];
    }

    std::cout << "Calories based on top " << SIZE << " elves: " << total << std::endl;

    return 0;
}