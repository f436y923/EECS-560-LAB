#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <fstream>
class Node
{
private:
    int m_value;

public:
    Node* m_next;
    Node* m_pre;
    //=====================
    Node(int value);
    void setNext(Node* next);
    void setPre(Node* pre);
    void setValue(int _value);
    int getValue();
    Node* getNext();
    Node* getPre();

    ~Node();
};

#endif