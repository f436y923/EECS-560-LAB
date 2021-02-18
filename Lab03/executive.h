#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "HashMap.h"
#include <fstream>
#include <iostream>
// #include "LinkedList.h"
class executive {
private:
public:
  executive(std::string _filename);
  ~executive();
  void ShowMeun();
  HashMap MyHashMap;
  //====================================
};

#endif