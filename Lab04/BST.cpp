#include "BST.h"

//==============Insert================================
void BST::Insert(int key) { Insert(key, m_root); }

void BST::Insert(int key, Node *root) {
  if (m_root == nullptr) {
    m_root = new Node(key);
  } else if (m_root != nullptr) {
    if (root->GetValue() > key) { // check left child
      if (root->GetLeft() == nullptr) {
        Node *temp = new Node(key);
        root->SetLeft(temp);
        temp = nullptr;
        delete temp;
        return;
      } else if (root->GetLeft() != nullptr) {
        Insert(key, root->GetLeft());
      }
      // end of check left child
    } else if (root->GetValue() < key) { // check right child
      if (root->GetRight() == nullptr) {
        Node *temp = new Node(key);
        root->SetRight(temp);
        temp = nullptr;
        delete temp;
        return;
      } else if (root->GetRight() != nullptr) {
        Insert(key, root->GetRight());
      }
      // end of check right child
    } else if (root->GetValue() == key) {
      Node *temp = new Node(key);
      root->SetRight(temp);
      temp = nullptr;
      delete temp;
      return;
    }
  }
}

//================Find the max and min value===========================
int BST::FindMin() { return (FindMin(m_root)); }

int BST::FindMin(Node *root) {
  while (root->GetLeft() != nullptr) {
    root = root->GetLeft();
  }
  return root->GetValue();
}

int BST::FindMax() { return (FindMax(m_root)); }

int BST::FindMax(Node *root) {
  while (root->GetRight() != nullptr) {
    root = root->GetRight();
  }
  return root->GetValue();
}

//==============Delete the max or min======================
// void BST::RemoveMin() { RemoveMin(m_root); }

// void BST::RemoveMax() { RemoveMax(m_root); }

// void BST::RemoveMin(Node *root) {
//   Node *min = root;
//   Node *rootMin = root;
//   while (min->GetLeft() != nullptr) {
//     min = min->GetLeft();
//   }
//   while (rootMin->GetLeft() != min) {
//     rootMin = rootMin->GetLeft();
//   }
//   cout << "rootMin = " << rootMin->GetValue() << "\n";
//   if (min->GetRight() == nullptr) {
//     rootMin->SetLeft(nullptr);
//     delete min;
//   } else if (min->GetRight() != nullptr) {
//     rootMin->SetLeft(min->GetRight());
//     min->SetRight(nullptr);
//     delete min;
//   }
// }

// void BST::RemoveMax(Node *root) {
//   Node *max = root;
//   Node *rootMax = root;
//   while (max->GetRight() != nullptr) {
//     max = max->GetRight();
//   }
//   while (rootMax->GetRight() != max) {
//     rootMax = rootMax->GetRight();
//   }
//   if (max->GetLeft() == nullptr) {
//     rootMax->SetRight(nullptr);
//     delete max;
//   } else if (max->GetLeft() != nullptr) {
//     rootMax->SetLeft(max->GetLeft());
//     max->SetRight(nullptr);
//     delete max;
//   }
// }

//==============Print the tree method=======================

void BST::LevelOrder(Node *root, int level) {
  if (root == nullptr)
    return;
  if (level == 1)
    cout << root->GetValue() << " ";
  else if (level > 1) {
    LevelOrder(root->GetLeft(), level - 1);
    LevelOrder(root->GetRight(), level - 1);
  }
}

void BST::LevelOrder() {
  int height = GetTreeHight(m_root);
  int i;
  for (i = 1; i <= height; i++)
    LevelOrder(m_root, i);
}

//============ Remove =============================
void BST::Remove(int key) { Remove(key, m_root); }

Node *BST::Remove(int key, Node *root) {
  Node *newroot = root;
  Node *presite = root;
  int pos = 0;
  while (root != nullptr) {
    if (root->GetValue() > key) {
      presite = root;
      root = root->GetLeft();
      pos = -1;
    } else if (root->GetValue() < key) {
      presite = root;
      root = root->GetRight();
      pos = 1;
    } else {
      break;
    }
  }
  if (root == nullptr) {
  } else {
    if (root->GetLeft() != nullptr && root->GetRight() != nullptr) {
      Node *Lmax = root->GetLeft();
      Node *PreLmax = root;
      while (Lmax->GetRight() != nullptr) {
        PreLmax = Lmax;
        Lmax = Lmax->GetRight();
      }
      root->SetValue(Lmax->GetValue());
      if (PreLmax->GetLeft() == Lmax) {
        PreLmax->SetLeft(Lmax->GetLeft());
      } else {
        PreLmax->SetRight(Lmax->GetLeft());
      }
      delete Lmax;
      Lmax = nullptr;
    } else if (root->GetLeft() == nullptr && root->GetRight() != nullptr) {
      if (0 == pos) {
        newroot = root->GetRight();
      } else if (1 == pos) {
        presite->SetRight(root->GetRight());

      } else {
        presite->SetLeft(root->GetRight());
      }
      delete root;
      root = nullptr;
    }

    else if (root->GetRight() == nullptr && root->GetLeft() != nullptr) {
      if (0 == pos) {
        newroot = root->GetLeft();
      } else if (1 == pos) {
        presite->SetRight(root->GetLeft());
      } else {
        presite->SetLeft(root->GetLeft());
      }
      delete root;
      root = nullptr;
    } else {
      if (0 == pos) {
        delete root;
        root = nullptr;
      } else if (1 == pos) {
        presite->SetRight(nullptr);
        delete root;
        root = nullptr;
      } else {
        presite->SetLeft(nullptr);

        delete root;
        root = nullptr;
      }
    }
  }
  return newroot;
}

//============= helper method=======================
int BST::GetTreeHight(Node *temp) {
  if (temp == nullptr)
    return 0;
  else {
    int lheight = GetTreeHight(temp->GetLeft());
    int rheight = GetTreeHight(temp->GetRight());

    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

//================================
BST::BST() { m_root = nullptr; }

BST::~BST() { RemoveTree(m_root); }

void BST::RemoveTree(Node *root) {
  if (!root)
    return;
  RemoveTree(root->GetLeft());
  RemoveTree(root->GetRight());
  delete root;
  root = nullptr;
  return;
}
//================================