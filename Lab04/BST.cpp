#include "BST.h"
#include <cmath>
#include <ctime>
//============ Print left or right side ============
void BST::LeftSideView() { LeftSideView(m_root); }

void BST::LeftSideView(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->GetValue() << " ";
  LeftSideView(root->GetLeft());
}

void BST::RightSideView() { RightSideView(m_root); }

void BST::RightSideView(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->GetValue() << " ";
  RightSideView(root->GetRight());
}

//============ SpiralLevelOrder ==================
void BST::SpiralLevelOrder() {
  // TODO:need to finish
}

//============ ExperimentalProfiling ==============
void BST::ExperimentalProfiling() {

  // decleartion
  int m = 100003; // BSTsize
  clock_t startBuildBST, finishBuildBST;
  clock_t startFindMinBST, finishFindMinBST;
  clock_t startFindMaxBST, finishFindMaxBST;
  clock_t startDeleteMinBST, finishDeleteMinBST;
  clock_t startDeleteMaxBST, finishDeleteMaxBST;

  // //============ matrix to store some info
  int index = 1;
  // string demension[6][6];
  // demension[0][0] = "Input size";
  // demension[0][1] = "10,000";
  // demension[0][2] = "20,000";
  // demension[0][3] = "30,000";
  // demension[0][4] = "40,000";
  // demension[0][5] = "50,000";
  // demension[1][0] = "Build(s)";
  // demension[2][0] = "FindMin(s)";
  // demension[3][0] = "FindMax(s)";
  // demension[4][0] = "DeleteMin(s)";
  // demension[5][0] = "DeleteMax(s)";

  // =============== for loop from 0.1 to 0.5
  for (double i = 0.1; i <= 0.5; i = i + 0.1) {
    int inputSize = m * i;
    int num; /*initialize random seed*/
    srand(time(NULL));
    int max = 5 * m;
    //======= Step 1 ===================
    startBuildBST = clock();
    for (int i = 0; i < 1; i++) {
      num = rand() % max + 1;
      Insert(num);
    }
    // Insert(123);

    // finishBuildBST = clock();
    // string storeRecordTime = doubleToString(
    //     (double)(finishBuildBST - startBuildBST) / CLOCKS_PER_SEC);
    // cout << endl;
    // demension[1][index] = storeRecordTime;

    // //======= Step 2 ===================
    // startFindMinBST = clock();
    // FindMin();
    // finishFindMinBST = clock();
    // string storeRecordTime01 = doubleToString(
    //     (double)(finishFindMinBST - startFindMinBST) / CLOCKS_PER_SEC);
    // demension[2][index] = storeRecordTime01;

    // //======= Step 3 ===================
    // startFindMaxBST = clock();
    // FindMax();
    // finishFindMaxBST = clock();
    // string storeRecordTime02 = doubleToString(
    //     (double)(finishFindMaxBST - startFindMaxBST) / CLOCKS_PER_SEC);
    // demension[3][index] = storeRecordTime02;

    // //======= Step 4 ===================
    // startDeleteMinBST = clock();
    // RemoveMin();
    // finishDeleteMinBST = clock();
    // string storeRecordTime03 = doubleToString(
    //     (double)(finishDeleteMinBST - startDeleteMinBST) / CLOCKS_PER_SEC);
    // demension[4][index] = storeRecordTime03;

    // //======= Step 5 ===================
    // startDeleteMaxBST = clock();
    // RemoveMin();
    // finishDeleteMaxBST = clock();
    // string storeRecordTime04 = doubleToString(
    //     (double)(finishDeleteMaxBST - startDeleteMaxBST) / CLOCKS_PER_SEC);
    // demension[5][index] = storeRecordTime04;

    // index++;
    // RemoveTree(m_root);
  }

  // ========  final step(Print) ================
  // for (int i = 0; i < 6; i++) {
  //   for (int j = 0; j < 6; j++) {
  //     cout << demension[i][j] << "    ";
  //   }
  //   cout << endl << endl << endl;
  // }
}

//============= Successor ====================
int BST::Successor(int key) {
  Node *cur = FindGivenValue(key);

  if (cur->GetRight() != nullptr) {
    cur = cur->GetRight();
    if (cur->GetLeft() == nullptr) {
      return cur->GetValue();
    } else {
      while (cur->GetLeft() != nullptr)
        cur = cur->GetLeft();
      return cur->GetValue();
    }
  }
  while (cur->GetParent() != nullptr && cur->GetParent()->GetRight() == cur)
    cur = cur->GetParent();
  return cur->GetParent()->GetValue();
}

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
        temp->SetParent(root);
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
        temp->SetParent(root);
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
      temp->SetParent(root);
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
void BST::RemoveMin() { RemoveMin(m_root); }

void BST::RemoveMax() { RemoveMax(m_root); }

void BST::RemoveMin(Node *root) {
  if (m_root == nullptr) {
    // No Tree
    return;
  } else {
    int minValue = FindMin();
    Remove(minValue);
  }
}

void BST::RemoveMax(Node *root) {
  if (m_root == nullptr) {
    // No Tree
    return;
  } else {
    int maxValue = FindMax();
    Remove(maxValue);
  }
}

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
        root->SetParent(nullptr);
        root->GetRight()->SetParent(presite);
      } else {
        presite->SetLeft(root->GetRight());
        root->SetParent(nullptr);
        root->GetRight()->SetParent(presite);
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

Node *BST::FindGivenValue(int key) {
  Node *cur = m_root;
  while (cur->GetValue() != key && cur != nullptr) {
    if (key > cur->GetValue())
      cur = cur->GetRight();
    else
      cur = cur->GetLeft();
  }
  if (cur != nullptr)
    return cur;
  else {
    return nullptr;
  }
}

string BST::doubleToString(double temp) {
  string storeRecordTime = to_string(temp);
  return storeRecordTime;
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
