#include "executive.h"
#include "Node.h"
#include <string>

executive::executive(std::string _filename) {
  std::ifstream input;
  std::string str;
  input.open(_filename);
  if (input.is_open()) {
    while (!input.eof()) {
      getline(input, str, ',');
      int pos = str.find(":");
      if (pos == -1) {
        std::cout << "Error format in input.txt!\n";
        exit(0);
      }
      std::string id = str.substr(0, pos);
      std::string NAME = str.substr(pos + 1, str.length());
      int ID = std::stoi(id);
      MyHashMap.AddStudent(NAME, ID);
      if (input.fail())
        break;
    }
  } else {
    std::cout << "Cannot open the files!\n";
  }
  input.close();

  ShowMeun();
}

executive::~executive() {}

void executive::checkValidKey(std::string &key) {
  int length = key.length();
  for (int i = 0; i < length; i++) {
    if (isalpha(key[i])) {
      key[i] = tolower(key[i]);
    } else {
      std::cout << "====================================\n";
      std::cout << "Invalid Name: " << key
                << "\nPlease change the Name from the files!\n";
      std::cout << "Or check the input!\n";
      std::cout << "====================================\n";
      exit(0);
    }
  }
}

void executive::checkValidID(std::string value) {
  if (value.length() != 5) {
    std::cout << "====================================\n";
    std::cout << "Invalid Length of ID: " << value
              << "\nPlease make sure the Length is 5!\n";
    std::cout << "====================================\n";
    exit(0);
  }
}

void executive::ShowMeun() {

  int choice = 5;
  do {
    std::cout
        << "Please choose one of the following commands:\n1-AddStudent\n2-RemoveStudent\n\
3-PrintStudentList\n4-FindStudent\n5-Exit\n";
    std::cout << "Input:";
    std::cin >> choice;
    std::cout << "==========================================\n";
    if (choice == 1) {
      std::string name;
      std::string ID;
      std::string temp;
      std::cout << "Enter the record to be inserted:(format ID:NAME)\n";
      std::cin >> temp;
      int pos = temp.find(":");
      ID = temp.substr(0, pos);
      checkValidID(ID);
      name = temp.substr(pos + 1, temp.length());
      checkValidKey(name);
      int id = std::stoi(ID);
      MyHashMap.AddStudent(name, id);
      std::cout << "Record is successfully inserted.\n";
      std::cout << "==========================================\n";
    } else if (choice == 2) {
      std::string name;
      std::string ID;
      std::string temp;
      std::cout << "Enter a record to be removed:(format ID:NAME)\n";
      std::cin >> temp;
      int pos = temp.find(":");
      ID = temp.substr(0, pos);
      checkValidID(ID);
      name = temp.substr(pos + 1, temp.length());
      checkValidKey(name);
      int id = std::stoi(ID);
      MyHashMap.RemoveStudent(name, id);
      std::cout << "==========================================\n";
    } else if (choice == 3) {
      MyHashMap.PrintStudentList();
    } else if (choice == 4) {
      std::string name;
      std::cout << "Enter the student to be found:\n";
      std::cin >> name;
      if (MyHashMap.FindStudent(name)) {
        std::cout << "Record found at index " << MyHashMap.Hashfunction(name)
                  << std::endl;
        std::cout << "==========================================\n";
      } else {
        std::cout << "No Records found!\n";
        std::cout << "==========================================\n";
      }
    }
  } while (choice != 5);
}