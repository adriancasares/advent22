#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct position {
  int x;
  int y;
};

bool correctPosition(position* head, position* tail) {
    if(abs(head->x - tail->x) <= 1 && abs(head->y - tail->y) <= 1) {
        return true;
    }

      if(head->x == tail->x) {
        if(head->y > tail->y) {
          tail->y += 1;
        } else {
          tail->y -= 1;
        }
    } else if(tail->y == head->y) {
        if(head->x > tail->x) {
          tail->x += 1;
        } else {
          tail->x -= 1;
        }
    } else {
        if(head->x > tail->x) {
          tail->x += 1;
        } else {
          tail->x -= 1;
        }
        if(head->y > tail->y) {
          tail->y += 1;
        } else {
          tail->y -= 1;
        }
    }

    return false;
}
// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 9 PART 2" << endl;

  ifstream input("input.txt");

  string line;

  const int NUM_TAILS = 9;

  position head = {0, 0};
  vector<position*> tails;

    for(int i = 0; i < NUM_TAILS; i++) {
        position* tail = new position();
        tail->x = 0;
        tail->y = 0;
        tails.push_back(tail);
    }

  vector<position> positions;

  while(getline(input, line, '\n')) {
    char direction = line[0];
    int distance = stoi(line.substr(2));

    for(int k = 0; k < distance; k++) {
      if (direction == 'D') {
        head.y--;
      } else if (direction == 'U') {
        head.y++;
      } else if (direction == 'L') {
        head.x--;
      } else if (direction == 'R') {
        head.x++;
      }

      for (int i = 0; i < NUM_TAILS; i++) {
        bool correct = false;

        position *sibling = i == 0 ? &head : tails[i - 1];

        while (!correct) {
          correct = correctPosition(sibling, tails[i]);

          if (i == NUM_TAILS - 1) {
            bool unique = true;

            for (int j = 0; j < positions.size(); j++) {
              if (positions[j].x == tails[i]->x && positions[j].y == tails[i]->y) {
                unique = false;
                break;
              }
            }

            if (unique) {
              positions.push_back(*tails[i]);
            }
          }
        }
      }
    }
  }

  cout << "number of tail positions: " << positions.size() << endl;


}