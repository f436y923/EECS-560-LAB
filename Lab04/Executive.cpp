#include "Executive.h"
#include <cstdio>
#include <fstream>

Executive::Executive(string filename) {
  ifstream input;
  int data = 0;
  input.open(filename);
  if (input.is_open()) {
    while (!input.eof()) {
      input >> data;
      mybst.Insert(data);
    }
  } else {
    cout << "The files is not open!\n";
    exit(1);
  }
  input.close();
  mybst.Remove(7);
  mybst.Remove(20);
  // cout << "The smallest value is: " << mybst.FindMin() << "\n";
  // cout << "The largerst value is: " << mybst.FindMax() << "\n";

  mybst.LevelOrder();
}

Executive::~Executive() {}
