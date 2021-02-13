#include "HashMap.h"

//Find the Bucketindex
//firstname: key
//bucketsize = 10 cannot change
int HashMap::Hashfunction(std::string firstname, int _bucketsize)
{
    int ASCII = 0;
    int ascii = 0;
    int index = 0;
    int length = firstname.length();
    const char* read = firstname.c_str();
    for (int i = 0; i < length; i++)
    {
        ASCII = read[i];
        ascii += ASCII;
    }

    index = ascii % _bucketsize;
    return index;
}

void HashMap::AddStudent(Node* temp)
{
    std::string name = temp->GetName();
    int id = temp->GetID();
    int index = Hashfunction(name);
    if (HashTable[index]->getNext() == nullptr && HashTable[index]->GetID() == 0 && HashTable[index]->GetName() == "")
    {
        HashTable[index]->SetID(id);
        HashTable[index]->SetName(name);
        HashTable[index]->SetNext(nullptr);
    }
    else if (HashTable[index]->getNext() == nullptr && HashTable[index]->GetID() != 0 && HashTable[index]->GetName() != "")
    {
        HashTable[index]->SetNext(temp);
    }
    else if (HashTable[index]->getNext() == nullptr && HashTable[index]->GetID() != 0 && HashTable[index]->GetName() != "") {
        Node* point = HashTable[index];
        while (point->getNext() != nullptr)
        {
            point = point->getNext();
        }
        point->SetNext(temp);
    }
    delete temp;
}

void HashMap::PrintStudentList()
{
    Node* print = nullptr;
    for (int i = 0; i < 5; i++)//TODO(need to change bucketsize to 11)
    {
        print = HashTable[i];
        std::cout << i << ":";
        if (print->GetName() == "" && print->GetID() == 0)
        {
            continue;
        }
        else if (print->getNext() != nullptr)
        {
            while (print->getNext())
            {
                std::cout << " => " << print->GetID() << " " << print->GetName();
                print = print->getNext();
            }
            std::cout << " => " << print->GetID() << " " << print->GetName();
        }
        else if (print->getNext() == nullptr)
        {
            std::cout << " => " << print->GetID() << " " << print->GetName();
        }
        std::cout << "\n";
    }
    delete print;
    std::cout << "===========================\n";
}

bool HashMap::FindStudent(std::string name)
{
    bool find = false;
    int index = Hashfunction(name);
    Node* Find = HashTable[index];
    if (HashTable[index]->GetName() == name)
    {
        find = true;
    }
    else if (HashTable[index]->GetName() != name && HashTable[index]->getNext() != nullptr)
    {
        while (Find)
        {
            if (Find->GetName() == name)
            {
                find = true;
                break;
            }
            else
            {
                Find = Find->getNext();
            }
        }
    }
    return find;
}

bool HashMap::RemoveStudent(Node* temp)
{
    bool isRemove = false;
    std::string name = temp->GetName();
    int index = Hashfunction(name);
    if (FindStudent(name))
    {
        Node* remove = HashTable[index];
        if (HashTable[index]->getNext() == nullptr)
        {
            HashTable[index]->SetID(0);
            HashTable[index]->SetName("");
            isRemove = true;
        }
        else if (HashTable[index]->getNext() != nullptr)
        {
            while (remove)
            {
                if (remove->GetName() == name)
                {
                    break;
                }
                remove = remove->getNext();
            }
            if (remove == HashTable[index])
            {
                remove = remove->getNext();
                if (remove->getNext() != nullptr)
                {
                    HashTable[index]->SetID(remove->GetID());
                    HashTable[index]->SetName(remove->GetName());
                    HashTable[index]->SetNext(remove->getNext());
                    delete remove;
                    isRemove = true;
                }
                else
                {
                    HashTable[index]->SetID(remove->GetID());
                    HashTable[index]->SetName(remove->GetName());
                    HashTable[index]->SetNext(nullptr);
                    delete remove;
                    isRemove = true;
                }
            }
            else if (remove == HashTable[index]->getNext())
            {
                if (remove->getNext() == nullptr)
                {
                    HashTable[index]->SetNext(nullptr);
                    delete remove;
                    isRemove = true;
                }
                else
                {
                    HashTable[index]->SetNext(remove->getNext());
                    remove->SetNext(nullptr);
                    delete remove;
                    isRemove = true;
                }
            }
            else if (remove != HashTable[index] && remove != HashTable[index]->getNext())
            {
                if (remove->getNext() == nullptr)
                {
                    Node* temp = HashTable[index];
                    while (temp->getNext() == remove)
                    {
                        temp = temp->getNext();
                    }
                    temp->SetNext(remove);
                    delete remove;
                    isRemove = true;
                }
                else
                {
                    Node* temp = HashTable[index];
                    while (temp->getNext() == remove)
                    {
                        temp = temp->getNext();
                    }
                    temp->SetNext(remove->getNext());
                    remove->SetNext(nullptr);
                    delete remove;
                    isRemove = true;
                }
            }
        }
    }
    else
    {
        std::cout << "No record found\n";
    }
    return isRemove;
}




HashMap::HashMap()
{
    for (int i = 0; i < FIXBUCKET; i++)
    {
        HashTable[i] = new Node("", 0);
    }
}

HashMap::~HashMap()
{
    // for (int i = 0; i < FIXBUCKET; i++)
    // {
    //     while (HashTable[i] != nullptr)
    //     {
    //         RemoveStudent(HashTable[i]->getNext());
    //     }
    //     HashTable[i] = nullptr;
    //     delete HashTable[i];
    // }


}
