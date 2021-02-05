#include "executive.h"
#include <iostream>

executive::executive(std::string _filename)
{
    std::ifstream input;
    input.open(_filename);
    if (input.is_open())
    {
        while (input >> num)
        {
            links->Insert(num);
        }
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

    while (true)
    {
        std::cout << "Choose one operation from the options below:\n";
        std::cout << "1.IsEmpty\n2.Length\n3.Insert\n4.Delete\n5.Find\n6.FindPrev\
        \n7.AppendList\n8.ForwardTraverse\n9.BackwardTraverse\n10.Exit";
        std::cout << "\nInput your choice: ";
        std::cin >> choice;
        std::cout << "=============================\n";
        if (choice == 1)
        {
            if (links->IsEmpty())
                std::cout << "The list is empty!\n";
            else
                std::cout << "The list is not empty!\n";
            std::cout << "=============================\n";
        }
        else if (choice == 2)
        {
            std::cout << "The length of the list is: " << links->Length() << std::endl;
            std::cout << "=============================\n";
        }
        else if (choice == 3)
        {
            int number;
            std::cout << "Input a number: ";
            std::cin >> number;
            if (std::cin.fail())
            {
                std::cout << "=======================\n";
                std::cout << "ERROR,Please enter a number!\n";
                std::cout << "=======================\n";
                exit(0);
            }
            links->Insert(number);
            std::cout << number << " is inserted!\n";
            std::cout << "=============================\n";
        }
        else if (choice == 4)
        {
            int number = 0;
            std::cout << "Choose a number to be deleted from the list:";
            std::cin >> number;
            if (std::cin.fail())
            {
                std::cout << "=======================\n";
                std::cout << "ERROR,Please enter a number!\n";
                std::cout << "=======================\n";
                exit(0);
            }
            links->Delete(number);
            std::cout << "=============================\n";
        }
        else if (choice == 5)
        {
            int number = 0;
            std::cout << "Enter the number to find:";
            std::cin >> number;
            if (std::cin.fail())
            {
                std::cout << "=======================\n";
                std::cout << "ERROR,Please enter a number!\n";
                std::cout << "=======================\n";
                exit(0);
            }
            if (links->Find(number))
                std::cout << number << " is found in the list!\n";
            else
                std::cout << number << " is not found in the list!\n";
            std::cout << "=============================\n";
        }
        else if (choice == 6)
        {
            int number = 0;
            std::cout << "Enter the number to find its previouselement:";
            std::cin >> number;
            if (std::cin.fail())
            {
                std::cout << "=======================\n";
                std::cout << "ERROR,Please enter a number!\n";
                std::cout << "=======================\n";
                exit(0);
            }
            if (links->Find(number))
                links->FindPrev(number);
            else
                std::cout << "There is no element " << number << " in list. Hence there is no previous element.\n";
            std::cout << "=============================\n";
        }
        else if (choice == 7)
        {

            int number;
            int arr[100];
            int index = 0;
            std::cout << "Please enter some number to add:";
            while (std::cin >> number)
            {

                arr[index++] = number;

                char c = std::cin.get();
                if (c == '\n')
                    break;
            }
            int temp = 0;
            while (temp != index)
            {
                if (links->Find(arr[temp]))
                {
                    std::cout << "Cannot add this list because they container repeat number!\n";
                    exit(0);
                }

                else
                {
                    links->AppendList(arr[temp]);
                }
                temp++;
            }
            std::cout << "list appended!\n";
            std::cout << "=============================\n";
        }
        else if (choice == 8)
        {
            std::cout << "ForwardTraverse:";
            links->ForwardTraverse();
            std::cout << "=============================\n";
        }
        else if (choice == 9)
        {
            std::cout << "BackwardTraverse:";
            links->BackwardTraverse();
            std::cout << "=============================\n";
        }
        else if (choice == 10)
        {
            std::cout << "Program execution completed!\n";
            std::cout << "=============================\n";
            exit(0);
        }
        else
        {
            std::cout << "ERROR, Please input 0-10 to choice!\n";
            std::cout << "=============================\n";
        }
    }
}
