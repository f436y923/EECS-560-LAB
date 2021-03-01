
#include <iostream>
using namespace std;
#include <string>
#ifndef __NODE_H__
#define __NODE_H__
class Node {
private:
  Node *m_left, *m_right;
  int value;

public:
  void SetLeft(Node *temp);
  void SetRight(Node *temp);
  Node *GetLeft();
  Node *GetRight();

  void SetValue(int temp);
  int GetValue();

  Node();
  Node(int value);
  ~Node();
};

#endif // __NODE_H__
