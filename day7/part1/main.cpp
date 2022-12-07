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

int count_size(directory* dir) {
  int size = 0;

  if(dir->size < 100000) {
    size += dir->size;
  }

  for (int i = 0; i < dir->subdirs.size(); i++) {
    int subdirsSize = count_size(&dir->subdirs[i]);

      size += subdirsSize;
  }

  return size;
}

// Created by Adrian Casares on 12/3/22.
int main() {
  cout << "DAY 7 PART 1" << endl;

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

  int totalSize = 0;

  // get total size of directories with total size < 100000

  current = root;

  cout << "root size: " << count_size(current) << endl;

  cout << "current: " << current->name << endl;

}