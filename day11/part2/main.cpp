#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct item {
  long worry;
};

struct monkey {
  vector<item*> items;
  long numInteractions;
  int moduloTest;
  int testPassDestination;
  int testFailDestination;
  int worryOperation;
  string worryOperationType;
};

// Created by Adrian Casares on 12/11/22.
int main() {
  const int NUM_MONKEYS = 8;

  cout << "DAY 11 PART 2" << endl;

  ifstream input("input.txt");

  vector<monkey*> monkeys;

  for(int i = 0; i < NUM_MONKEYS; i++) {
    monkey* m = new monkey();
    m->items = vector<item*>();
    monkeys.push_back(m);
  }

  string line;

  int monkeyNum = 0;

  while(getline(input, line, '\n')) {
    monkey* m = monkeys[monkeyNum];

    string startingLine;
    getline(input, startingLine, '\n');
    stringstream startingLineStream(startingLine.substr(18));
    string currentItemWorry;

    while(getline(startingLineStream, currentItemWorry, ',')) {
      item* i = new item();
      i->worry = stoi(currentItemWorry);
      m->items.push_back(i);
    }

    string operationLine;
    getline(input, operationLine, '\n');
    operationLine = operationLine.substr(23);

    if(operationLine.find("old") != string::npos) {
      m->worryOperationType = "power";
      m->worryOperation = 2;
    } else {
      m->worryOperation = stoi(operationLine.substr(2));
      if(operationLine[0] == '+') {
        m->worryOperationType = "add";
      } else if(operationLine[0] == '*') {
        m->worryOperationType = "multiply";
      }
    }

    string moduloTestLine;
    getline(input, moduloTestLine, '\n');

    m->moduloTest = stoi(moduloTestLine.substr(21));

    string testPassDestinationLine;
    getline(input, testPassDestinationLine, '\n');
    m->testPassDestination = stoi(testPassDestinationLine.substr(29));

    string testFailDestinationLine;
    getline(input, testFailDestinationLine, '\n');
    m->testFailDestination = stoi(testFailDestinationLine.substr(30));

    getline(input, line, '\n');

    monkeyNum++;
  }

  int MODULO_TEST = 1;

    for(int i = 0; i < NUM_MONKEYS; i++) {
      if(monkeys[i]->moduloTest != 0) {
        MODULO_TEST *= monkeys[i]->moduloTest;
      }
    }


  const int NUM_TURNS = 10000;

  for(int i = 0; i < NUM_TURNS; i++) {
    for(int j = 0; j < NUM_MONKEYS; j++) {
      monkey* m = monkeys[j];

      for(int k = 0; k < m->items.size(); k++) {
        m->numInteractions++;
        item* currentItem = m->items[k];

        if(m->worryOperationType == "power") {
          currentItem->worry = currentItem->worry * currentItem->worry;
        } else if(m->worryOperationType == "add") {
          currentItem->worry += m->worryOperation;
        } else if(m->worryOperationType == "multiply") {
          currentItem->worry *= m->worryOperation;
        }

        currentItem->worry = currentItem->worry % MODULO_TEST;

        if(currentItem->worry % m->moduloTest == 0) {
          monkeys[m->testPassDestination]->items.emplace_back(currentItem);
        } else {
          monkeys[m->testFailDestination]->items.emplace_back(currentItem);
        }

      }
      m->items.clear();


    }
  }

  long max1 = 0;
  long max2 = 0;

  for(int i = 0; i < NUM_MONKEYS; i++) {
    monkey* m = monkeys[i];

    cout << m->numInteractions << endl;
    if(m->numInteractions > max1) {
      max2 = max1;
      max1 = m->numInteractions;
    } else if(m->numInteractions > max2) {
      max2 = m->numInteractions;
    }
  }

  cout << "Product of monkeys with two highest number of interactions: " << max1 * max2 << endl;
  return 0;

}