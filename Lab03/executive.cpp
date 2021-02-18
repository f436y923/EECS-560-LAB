#include "executive.h"
#include "HashMap.h"
#include <string>

executive::executive(std::string _filename) {
  std::ifstream input;
  int temp;
  input.open(_filename);
  if (input.is_open()) {
    while (input >> temp) {
      int id = temp;
      MyHashMap.Add(id);
    }
  } else {
    std::cout << "Cannot open the files!\n";
  }
  input.close();
  ShowMeun();
}

executive::~executive() {}

void executive::ShowMeun() {
  int choice = 5;
  do {
    std::cout
        << "Please choose one of the following commands:\n1-Insert\n2-Delete\n\
3-Find\n4-Print\n5-Exit\n";
    std::cout << "Input:";
    std::cin >> choice;
    std::cout << "==========================================\n";
    if (choice == 1) {
      int integer;
      std::cout << "Choose a number to be inserted:\n";
      std::cin >> integer;
      if (std::cin.fail()) {
        std::cout << "Please enter a integer!\n";
        std::cout << "==========================================\n";
        exit(0);
      }
      MyHashMap.Add(integer);
      std::cout << "==========================================\n";
      std::cout << "Quadratic Probing: \n";
      std::cout << integer << " has been Inserted\n\n";
      std::cout << "Double Hashing: \n";
      std::cout << integer << " has been Inserted\n";
      std::cout << "==========================================\n";
    } else if (choice == 2) {
      int number;
      std::cout << "Choose a number to be deleted:\n";
      std::cin >> number;
      std::cout << "==========================================\n";
      if (std::cin.fail()) {
        std::cout << "Please enter a integer!\n";
        std::cout << "==========================================\n";
        exit(0);
      }
      if (MyHashMap.Find(number)) {
        MyHashMap.Delete(number);
        std::cout << "Quadratic Probing:\n";
        std::cout << number << " has been deleted!\n\n";
        std::cout << "Double Hashing:\n";
        std::cout << number << " has been deleted!\n";
        std::cout << "==========================================\n";
      } else {
        std::cout << "Quadratic Probing:\n";
        std::cout << number << " is not found!\n\n";
        std::cout << "Double Hashing:\n";
        std::cout << number << " is not found!\n";
        std::cout << "==========================================\n";
      }
    } else if (choice == 3) {
      int number;
      std::cout << "Choose a number to find:\n";
      std::cin >> number;
      std::cout << "==========================================\n";
      if (std::cin.fail()) {
        std::cout << "Please enter a integer!\n";
        std::cout << "==========================================\n";
        exit(0);
      }
      if (MyHashMap.Find(number)) {
        std::cout << "Quadratic Probing:\n";
        std::cout << number << " is found!\n\n";
        std::cout << "Double Hashing:\n";
        std::cout << number << " is found!\n";
        std::cout << "==========================================\n";
      } else {
        std::cout << "Quadratic Probing:\n";
        std::cout << number << " is not found!\n\n";
        std::cout << "Double Hashing:\n";
        std::cout << number << " is not found!\n";
        std::cout << "==========================================\n";
      }
    } else if (choice == 4) {
      MyHashMap.PrintTable();
    } else if (choice == 5) {
      std::cout << "Bye bye~~~!\n";
      std::cout << "==========================================\n";
      break;
    } else {
      std::cout << "Please enter number from 0-5\n";
      std::cout << "==========================================\n";
    }
  } while (true);
}