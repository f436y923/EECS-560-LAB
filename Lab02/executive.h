#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <fstream>
#include "HashMap.h"
// #include "LinkedList.h"
class executive
{
private:

public:
    HashMap MyHashMap;
    executive(std::string _filename);
    ~executive();
    void ShowMeun();
    void checkValidKey(std::string& key);
    void checkValidID(std::string value);
    void FindTheIDAndValue(std::string temp);
};

#endif  