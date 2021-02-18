#ifndef __HASHMAP_H__
#define __HASHMAP_H__
// #include "LinkedList.h"

#include "Node.h"
#include <cmath>
#include <iostream>
class HashMap {
private:
  int bucketSize = 11;
  int numberOfElement = 0;
  Node *array_Quadratic;
  Node *array_Double;
  //==========================================
public:
  //===================
  HashMap();
  ~HashMap();
  //===================
  void Add(int integer);
  bool Find(int integer);
  void Delete(int id);
  void PrintTable();
  void PrintDouble();
  void PrintQuadratic();
  //================================
  bool NeedReHash(int numberOfElement, int numberOfBucket);
  int Hashfunction(int integer, int _bucketsize);
  void SetSize(int _size);
  int GetSize();
  bool isPrime(int _number);
  int Resize(int _size);
  void ReHashQuadratic(int _newBucket);
  void ReHashDouble(int _newBucket);
  //================================
  void QuadraticProbing(int integer); // first way deal with collision
  void DoubleHash(int integer);       // second way deal with collision
};

#endif // __HASHMAP_H__