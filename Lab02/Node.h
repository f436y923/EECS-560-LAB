#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <fstream>
class Node
{
private:
    std::string m_name;
    int m_id;

public:
    Node* m_next;
    //=====================
    Node(std::string name, int id);
    void SetNext(Node* next);
    void SetID(int id);
    void SetName(std::string name);
    int GetID();
    std::string GetName();
    Node* getNext();
    ~Node();
};

#endif