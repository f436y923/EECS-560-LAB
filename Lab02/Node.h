#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <string>
class Node {
private:
  std::string m_name = "";
  int m_id = 0;

public:
  Node *m_next = nullptr;
  //=====================
  Node(std::string name, int id);
  void SetNext(Node *next);
  void SetID(int id);
  void SetName(std::string name);
  int GetID();
  std::string GetName();
  Node *getNext();
  ~Node();
};

#endif