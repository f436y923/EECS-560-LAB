#include "executive.h"

executive::executive(std::string _filename)
{
    std::ifstream input;
    input.open(_filename);
    if (input.is_open())
    {
        //Load data and shore into Double list
        while (input >> num)
        {
            links->Insert(num);
        }

        std::cout << "=======================\n";

        std::cout << "The doublie LinkList'Length:";
        std::cout << links->Length() << std::endl;
        std::cout << "The 110 is in the list:";
        std::cout << links->Find(110) << std::endl;
        std::cout << "The ForwardTraverse:";
        links->ForwardTraverse();
        links->Delete(45);
        links->Insert(110);
        links->FindPrev(110);
        std::cout << "The 110 is in the list:";
        std::cout << links->Find(110) << std::endl;
        std::cout << "The ForwardTraverse after remove:";
        links->ForwardTraverse();
        std::cout << "The BackwardTraverse:";
        links->BackwardTraverse();

        std::cout << "=======================\n";
    }
    else
    {
        std::cout << "Cannot open the files!\n";
    }
    input.close();
    ShowMeun();
}

executive::~executive()
{
}

void executive::ShowMeun()
{
    int choice;
    std::cout << "Choose one operation from the options below:\n";
    std::cout << "1.IsEmpty\n2.Length\n3.Insert\n4.Delete\n5.Find\n6.FindPrev\
    \n7.AppendList\n8.ForwardTraverse\n9.BackwardTraverse\n10.Exit";
    std::cout << "\nInput your choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        /* code */
        break;
    case 6:
        std::cout << "==================\n";
        break;
    case 10:
        exit(0);
        break;
    default:
        break;
    }
}