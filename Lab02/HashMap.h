#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include "LinkedList.h"
#include <iostream>
class HashMap {
private:
  static const int FIXBUCKET = 11;
  LinkedList *array;

public:
  HashMap();
  ~HashMap();

  //==========================================
  int Hashfunction(std::string firstname, int _bucketsize = FIXBUCKET);
  void AddStudent(std::string name, int id);
  bool FindStudent(std::string name);
  void RemoveStudent(std::string name, int id);
  void PrintStudentList();
};

#endif // __HASHMAP_H__