#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "DoubleLinkList.h"
class executive
{
private:
    int num;
    DoubleLinkList *links = new DoubleLinkList();

public:
    //Load the Input.txt
    executive(std::string _filename);
    ~executive();
    void ShowMeun();
};

#endif