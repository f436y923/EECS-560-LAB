#ifndef __EXECUTIVE_H__
#define __EXECUTIVE_H__

#include "BST.h"
#include <fstream>
class Executive {
private:
  BST mybst;

public:
  void PrintMeun();
  Executive(string filename);
  ~Executive();
};
#endif // __EXECUTIVE_H__