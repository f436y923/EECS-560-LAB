#include "Node.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#ifndef __BST_H__
#define __BST_H__
class BST {
private:
  Node *m_root;
  void Insert(int key, Node *root);                        //(Done)
  void LevelOrder(Node *root, int level);                  //(Done)
  int FindMin(Node *root);                                 //(Done)
  int FindMax(Node *root);                                 //(Done)
  void RemoveMin(Node *root);                              //(Done)
  void RemoveMax(Node *root);                              //(Done)
  Node *Remove(int key, Node *root);                       //(Done)
  void LeftSideView(Node *root);                           //(Done)
  void RightSideView(Node *root);                          //(Done)
  void SpiralLevelOrder(Node *root, int level, bool FLAG); //(Done)
  //=========================

public:
  void Insert(int key);        // Insert the given key(Done)
  int FindMin();               // Find minium value in the tree(Done)
  int FindMax();               // Find maxium value in the tree(Done)
  void Remove(int key);        // Remove the given key(Done)
  void RemoveTree(Node *root); // Remove the Tree (Done)
  void RemoveMin();            // Remove the min value (Done)
  void RemoveMax();            // Remove the max value (Done)
  void LevelOrder();      // Print the tree levelOrder (Done) //TODO:ERROR PRINT
  int Successor(int key); //(Done)
  void LeftSideView();    //(Done)
  void RightSideView();   //(Done)
  void SpiralLevelOrder();      // (Done)
  void ExperimentalProfiling(); //(Done)
  //=============helper method========================
  int GetTreeHight(Node *temp);       //(Done)
  Node *FindGivenValue(int key);      //(Done)
  string doubleToString(double temp); //(Done)

  BST();  //(Done)
  ~BST(); //(Done)
};
#endif // __BST_H__
