#include "Executive.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {

  string filename = argv[1];
  Executive exec(filename);
  return 0;
}