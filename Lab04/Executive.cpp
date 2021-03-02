#include "Executive.h"
#include <cstdio>
#include <fstream>
#include <string>

Executive::Executive(string filename) {
  ifstream input;
  int data = 0;
  input.open(filename);
  if (input.is_open()) {
    while (!input.eof()) {
      input >> data;
      mybst.Insert(data);
    }
  } else {
    cout << "The files is not open!\n";
    exit(1);
  }
  input.close();
  PrintMeun();
  // mybst.Insert(2);
  // mybst.Insert(3);
  // mybst.Insert(4);
  // mybst.Remove(8);
  // mybst.SpiralLevelOrder();
  // cout << endl;
  // mybst.LevelOrder();
  // cout << endl;
  // cout << mybst.Successor(9);
  // cout << endl;
  // cout << mybst.Successor(9);
  // cout << "The smallest value is: " << mybst.FindMin() << "\n";
  // cout << "The largerst value is: " << mybst.FindMax() << "\n";
  // mybst.RemoveMin();
  // mybst.RemoveMax();
  // mybst.RightSideView();
  // mybst_Experiment.ExperimentalProfiling();
}

Executive::~Executive() {}

void Executive::PrintMeun() {
  while (true) {
    cout << "Please choose one of the following "
            "commands:\n\n1.AddItem\n2.DeleteItem\n3.FindMin\n4.FindMax\n5."
            "DeleteMin\n6.DeleteMax\n7.InorderSuccessor\n8.LevelOrder\n9."
            "SpiralLevelOrder\n10.LeftSideView\n11.RightSideView\n12."
            "ExperimentalProfiling\n13.Exit\n";
    cout << "Please enter your choice from (1 to 13):";
    int choice;
    cin >> choice;
    cout << endl;
    cout << "==================================\n";
    if (choice == 1) {
      cout << "Enter the element to be added:";
      int number = 0;
      cin >> number;
      if (cin.fail()) {
        cout << "ERROR Input!\n ";
        cout << "==================================\n\n";
        exit(0);
      } else {
        mybst.Insert(number);
        cout << "Element " << number << " was successfully added.\n";
      }
      cout << "==================================\n\n";
    } else if (choice == 13) {
      cout << "bye~Bye!\n";
      cout << "==================================\n\n";
      break;
    } else if (choice == 2) {
      cout << "Enter the element to be deleted:";
      int number = 0;
      cin >> number;
      if (cin.fail()) {
        cout << "ERROR Input!\n ";
        cout << "==================================\n\n";
        exit(0);
      } else {
        mybst.Remove(number);
        cout << "Element " << number << " was successfully deleted.\n";
      }
      cout << "==================================\n";
    } else if (choice == 3) {
      cout << "Smallest element in the tree is:" << mybst.FindMin() << endl;
      cout << "==================================\n\n";
    } else if (choice == 4) {
      cout << "Largest element in the tree is:" << mybst.FindMax() << endl;
      cout << "==================================\n\n";
    } else if (choice == 5) {
      mybst.RemoveMin();
      cout << "Smallest element was successfully deleted from the tree.\n";
      cout << "==================================\n\n";
    } else if (choice == 6) {
      mybst.RemoveMax();
      cout << "Largest element was successfully deleted from the tree.\n";
      cout << "==================================\n\n";
    } else if (choice == 7) {
      cout << "Enter the element to which you want to know the inorder "
              "successor:";
      int number;
      cin >> number;
      if (cin.fail()) {
        cout << "ERROR Input!\n ";
        cout << "==================================\n\n";
        exit(0);
      } else {
        int temp = mybst.Successor(number);
        cout << "The inorder successor of " << number << " is " << temp << endl;
        cout << "==================================\n\n";
      }
    } else if (choice == 8) {
      cout << "Level Order: ";
      mybst.LevelOrder();
      cout << endl;
    } else if (choice == 9) {
      cout << "Spiral Level Order:";
      mybst.SpiralLevelOrder();
    } else if (choice == 10) {
      cout << "Left SideView: ";
      mybst.LeftSideView();
      cout << endl;
    } else if (choice == 11) {
      cout << "Right SideView: ";
      mybst.RightSideView();
      cout << endl;
    } else if (choice == 12) {
      mybst_Experiment.ExperimentalProfiling();
    }
  }
}
