#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include <iostream>
#include "Node.h"
class HashMap
{
private:
    static const int FIXBUCKET = 5;//TODO(need to change bucketsize to 11)
    Node* HashTable[FIXBUCKET];//TODO(need to change bucketsize to 11)

public:
    HashMap(/* args */);
    ~HashMap();


    //==========================================
    int Hashfunction(std::string firstname, int _bucketsize = 5);//TODO(need to change bucketsize to 11)
    void AddStudent(Node* temp);
    bool FindStudent(std::string name);
    bool RemoveStudent(Node* temp);
    void PrintStudentList();
};



#endif // __HASHMAP_H__