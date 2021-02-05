#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

DoubleLinkList::~DoubleLinkList()
{
    if (head == tail && head == nullptr)
    {
        delete head;
        delete tail;
    }
}

bool DoubleLinkList::IsEmpty()
{
    if (length == 0)
        return true;
    if (head == nullptr)
        return true;
    else
        return false;
}

int DoubleLinkList::Length()
{
    return length;
}

void DoubleLinkList::Insert(int value)
{
    if (Find(value))
    {
        std::cout << "Cannot insert repeat number!\n";
        return;
    }
    if (length == 0)
    {
        head = new Node(value);
        tail = head;
    }
    else if (length == 1)
    {
        Node* temp = new Node(value);
        head->setNext(temp);
        temp->setPre(head);
        tail = temp;
    }
    else if (length > 1)
    {
        Node* temp = new Node(value);
        tail->setNext(temp);
        temp->setPre(tail);
        tail = temp;
    }
    length++;
}

void DoubleLinkList::ForwardTraverse()
{

    Node* current = nullptr;
    if (length == 0)
        throw "Cannot ForwardTraverse because The list is empty!\n";
    else if (length != 0)
    {
        std::cout << "ForwardTraverse: ";
        current = head;
        while (current != tail)
        {

            std::cout << current->getValue() << " ";
            current = current->getNext();
        }
        std::cout << current->getValue() << std::endl;
    }
}

void DoubleLinkList::BackwardTraverse()
{
    Node* current = nullptr;
    if (length == 0)
        throw "Cannot BackwardTraverse because The list is empty!\n";
    else if (length > 0)
    {
        current = tail;
        while (current != head)
        {
            std::cout << current->getValue() << " ";
            current = current->getPre();
        }
        std::cout << current->getValue() << std::endl;
    }
}

bool DoubleLinkList::Find(int value)
{
    Node* find = nullptr;
    // bool isFind = false;
    find = head;
    while (find != nullptr)
    {
        if (find->getValue() == value)
        {
            return true;
        }
        else
            find = find->getNext();
    }
    return false;
}

void DoubleLinkList::FindPrev(int value)
{

    Node* find = nullptr;
    find = head;
    while (find != nullptr)
    {
        if (find->getValue() == value)
        {
            if (find == head)
            {
                std::cout << find->getPre()->getValue() << " is previous None\n ";
            }
            else
            {
                std::cout << find->getPre()->getValue() << " is previous " << value << std::endl;
            }
            break;
        }
        else
            find = find->getNext();
    }
}

void DoubleLinkList::AppendList(int value)
{
    Insert(value);
}

void DoubleLinkList::Delete(int value)
{
    if (!Find(value))
    {
        std::cout << "Cannot find the value in the list!\n";
        return;
    }
    else
    {
        bool IsFind = false;
        Node* remove = nullptr;
        remove = head;
        while (remove != nullptr)
        {
            if (remove->getValue() == value)
            {
                if (remove == head)
                {
                    head = head->getNext();
                    head->setPre(nullptr);
                    delete remove;
                }
                else if (remove == tail)
                {
                    tail = tail->getPre();
                    tail->setNext(nullptr);
                    delete remove;
                }
                else
                {
                    remove->getPre()->setNext(remove->getNext());
                    remove->getNext()->setPre(remove->getPre());
                    delete remove;
                }
                IsFind = true;
                break;
            }
            else
                remove = remove->getNext();
        }
        if (IsFind)
            std::cout << value << " has been deleted from the list!\n";
        else
            std::cout << "Cannot find the value in the list!\n";
        length--;
    }

}
