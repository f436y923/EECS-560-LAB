#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include "Node.h"
#include <stdexcept>
class DoubleLinkList
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoubleLinkList();
    ~DoubleLinkList();

    bool IsEmpty();
    int Length();
    void Insert(int value);
    void Delete(int value);
    bool Find(int value);
    void FindPrev(int value);
    void AppendList(int value);
    void ForwardTraverse();
    void BackwardTraverse();
};

#endif