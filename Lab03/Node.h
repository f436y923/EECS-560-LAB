#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <string>
class Node {
private:
  int m_id = 0;

public:
  Node *m_next = nullptr;
  //=====================
  Node(int id);
  Node();
  void SetNext(Node *next);
  void SetID(int id);
  int GetID();
  Node *getNext();
  ~Node();
};

#endif