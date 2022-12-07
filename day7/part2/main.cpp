#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct directory {
  string name;
  int size;
  vector<directory> subdirs;
  directory* parent;
};

// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 7 PART 2" << endl;

  ifstream input("input.txt");

  string line;

  getline(input, line, '\n');
  getline(input, line, '\n');

  directory* root = new directory;
  root->name = "root";
  root->size = 0;
  root->subdirs = vector<directory>();
  root->parent = NULL;

  directory* current = root;

  while(getline(input, line, '\n')) {
    // if starts with $, command
    // otherwise, file listing
    // if starts with a number, file
    // if starts with "dir" , directory
    // code:
    if(line.rfind("$ cd ", 0) == 0) {
      // get directory name
      string dirName = line.substr(string("$ cd ").size());

      if(dirName == "..") {
        current = current->parent;
      } else {
        for(int i = 0; i < current->subdirs.size(); i++) {
          if(current->subdirs[i].name == dirName) {
            current = &current->subdirs[i];
            break;
          }
        }
      }
    } else if(line.rfind("$ ls", 0) == 0) {

    } else if(line.rfind("dir ", 0) == 0) {
      string dirName = line.substr(string("dir ").size());
      directory* newDir = new directory;
      newDir->name = dirName;
      newDir->size = 0;
      newDir->subdirs = vector<directory>();
      newDir->parent = current;
      current->subdirs.push_back(*newDir);
    } else {
      int firstSpace = line.find(" ");
      string size = line.substr(0, firstSpace);
      int sizeInt = stoi(size);

      // add size to all parents
      directory* parent = current;
      while(parent != NULL) {
        parent->size += sizeInt;
        parent = parent->parent;
      }
    }
  }

  int totalSize = 70000000;
  int currentSize = root->size;
  int neededSpace = 30000000;
  int needToDelete = neededSpace - (totalSize - currentSize);

  // find smallest directory that would free up enough space
  int smallestSize = 0;

  stack<directory*> dirs;
  dirs.push(root);

    while(!dirs.empty()) {
        directory* current = dirs.top();
        dirs.pop();

        if(current->size >= needToDelete) {
            if(smallestSize == 0 || current->size < smallestSize) {
                smallestSize = current->size;
            }
        }

        for(int i = 0; i < current->subdirs.size(); i++) {
            dirs.push(&current->subdirs[i]);
        }
    }


  cout << "current: " << smallestSize << endl;

}