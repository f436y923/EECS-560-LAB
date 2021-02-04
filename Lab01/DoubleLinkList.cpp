#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

bool DoubleLinkList::IsEmpty()
{
    if (length == 0)
        return true;
    if (head->getNext() == nullptr)
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
    if (true)
    {
        //TODO(除去重复的数字)
    }
    if (length == 0)
    {
        head = new Node(value);
        tail = head;
    }
    else if (length == 1)
    {
        Node *temp = new Node(value);
        head->setNext(temp);
        temp->setPre(head);
        tail = temp;
    }
    else if (length > 1)
    {
        Node *temp = new Node(value);
        tail->setNext(temp);
        temp->setPre(tail);
        tail = temp;
    }
    length++;
}

void DoubleLinkList::ForwardTraverse()
{

    Node *current = nullptr;
    // std::cout << "==========================\n";
    // std::cout << "Enter the ForwardTraverse function!\n";
    // std::cout << "==========================\n";
    if (length == 0)
        throw "Cannot ForwardTraverse because The list is empty!\n";
    else if (length != 0)
    {
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
    Node *current = nullptr;
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
    Node *find = nullptr;
    // bool isFind = false;
    find = head;
    while (find != nullptr)
    {
        if (find->getValue() == value)
        {
            std::cout << value << " is found in the list!\n";

            return true;
        }
        else
            find = find->getNext();
    }
    std::cout << value << "is not found in the list!\n";
    return false;
}

void DoubleLinkList::FindPrev(int value)
{
    if (Find(value) == false)
    {
        std::cout << "There is no element " << value << " in list. Hence there is no previouselement.";
    }
    else
    {
        Node *find = nullptr;
        // bool isFind = false;
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
}

void DoubleLinkList::AppendList()
{
}

void DoubleLinkList::Delete(int value)
{
    bool IsFind = false;
    Node *remove = nullptr;
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
        std::cout << "The " << value << " is remove!\n";
    else
        std::cout << "Cannot find the value in the list!\n";
}