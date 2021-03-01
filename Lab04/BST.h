#include "Node.h"
#ifndef __BST_H__
#define __BST_H__
class BST {
private:
  Node *m_root;
  void Insert(int key, Node *root);
  void LevelOrder(Node *root, int level);
  int FindMin(Node *root);
  int FindMax(Node *root);
  // void RemoveMin(Node *root);
  // void RemoveMax(Node *root);
  Node *Remove(int key, Node *root);

public:
  void Insert(int key);        // Insert the given key(Done)
  int FindMin();               // Find minium value in the tree(Done)
  int FindMax();               // Find maxium value in the tree(Done)
  void Remove(int key);        // Remove the given key(Done)
  void RemoveTree(Node *root); // Remove the Tree
  // void RemoveMin();            // Remove the min value
  // void RemoveMax();            // Remove the max value
  void LevelOrder(); // Print the tree levelOrder

  //=============helper method========================
  int GetTreeHight(Node *temp);

  BST();
  ~BST();
};
#endif // __BST_H__