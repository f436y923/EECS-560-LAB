#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <fstream>
#include "HashMap.h"
class executive
{
private:

public:
    HashMap MyHashMap;
    //Load the Input.txt
    executive(std::string _filename);
    ~executive();
    void ShowMeun();
    void checkValidKey(std::string& key);
    void checkValidID(std::string value);
    void FindTheIDAndValue(std::string temp);
};

#endif  