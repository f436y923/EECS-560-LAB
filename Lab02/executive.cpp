#include "executive.h"
#include "Node.h"

executive::executive(std::string _filename)
{
    std::string temp = "";
    bool readID = true;
    std::string ID = "";
    int id;
    Node* temp07 = nullptr;
    std::string NAME = "";
    std::ifstream input;
    input.open(_filename);
    if (input.is_open())
    {

        while (!input.eof())
        {
            input >> temp;
        }

        int length = temp.length();
        int i = 0;
        for (i = 0; i < length; i++)
        {
            if (temp[i] != ':' && readID)
            {
                ID += temp[i];
            }
            else if ((temp[i] == ':' && readID))
            {
                readID = false;
            }
            else if ((temp[i] != ',' && readID == false))
            {
                NAME += temp[i];
            }
            else if (temp[i] == ',' && readID == false && i != length - 1)
            {
                checkValidID(ID);
                checkValidKey(NAME);
                id = std::stoi(ID);
                temp07 = new Node(NAME, id);
                MyHashMap.AddStudent(temp07);
                readID = true;
                ID = "";
                NAME = "";

            }
            if (i == length - 1 && readID == false)
            {

                checkValidID(ID);
                checkValidKey(NAME);
                id = std::stoi(ID);
                Node* temp04 = new Node(NAME, id);
                MyHashMap.AddStudent(temp04);
            }
        }
    }
    else
    {
        std::cout << "Cannot open the files!\n";
    }
    input.close();
    temp07 = nullptr;
    ShowMeun();
}

executive::~executive()
{

}

void executive::checkValidKey(std::string& key)
{
    int length = key.length();
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]))
        {
            key[i] = tolower(key[i]);
        }
        else
        {
            std::cout << "====================================\n";
            std::cout << "Invalid Name: " << key << "\nPlease change the Name from the files!\n";
            std::cout << "Or check the input!\n";
            std::cout << "====================================\n";
            exit(0);
        }
    }
}

void executive::checkValidID(std::string value)
{
    if (value.length() != 5)
    {
        std::cout << "====================================\n";
        std::cout << "Invalid Length of ID: " << value << "\nPlease change the ID from the files!\n";
        std::cout << "====================================\n";
        exit(0);
    }
}


//14567: chris

void executive::ShowMeun()
{
    int choice;

    while (true)
    {
        std::cout << "Please choose one of the following commands:\n1-AddStudent\n2-RemoveStudent\n\
3-PrintStudentList\n4-FindStudent\n5-Exit\n";
        std::cout << "Input:";
        std::cin >> choice;
        std::cout << "==========================================\n";
        if (choice == 1) {
            std::string temp;
            int id;
            std::string NAME = "";
            std::cout << "Enter the record to be inserted:(makesure follow the fomat ID:NAME)\n";
            std::cin >> temp;
            std::cout << "==========================================\n";
            bool readID = true;
            std::string ID = "";
            int length = temp.length();
            int i = 0;
            for (i = 0; i < length; i++)
            {
                if (temp[i] != ':' && readID)
                {
                    ID += temp[i];
                }
                else if ((temp[i] == ':' && readID))
                {
                    readID = false;
                }
                else if ((temp[i] != ',' && readID == false))
                {
                    NAME += temp[i];
                }
                else if ((temp[i] == ',' && readID == false))
                {
                    checkValidID(ID);
                    checkValidKey(NAME);
                    id = std::stoi(ID);
                    readID = true;
                    ID = "";
                    NAME = "";
                }
                if (i == length - 1 && readID == false)
                {
                    checkValidID(ID);
                    checkValidKey(NAME);
                    id = std::stoi(ID);
                }
            }
            Node* temp01 = new Node(NAME, id);
            MyHashMap.AddStudent(temp01);
            std::cout << "Record is successfully inserted.\n";
            std::cout << "==========================================\n";
        }
        else if (choice == 2) {
            int id;
            std::string NAME = "";
            std::string temp;
            std::cout << "Enter arecord to be removed:(makesure follow the fomat ID:NAME)\n";
            std::cin >> temp;
            bool readID = true;
            std::string ID = "";
            int length = temp.length();
            int i = 0;
            for (i = 0; i < length; i++)
            {
                if (temp[i] != ':' && readID)
                {
                    ID += temp[i];
                }
                else if ((temp[i] == ':' && readID))
                {
                    readID = false;
                }
                else if ((temp[i] != ',' && readID == false))
                {
                    NAME += temp[i];
                }
                else if ((temp[i] == ',' && readID == false))
                {
                    checkValidID(ID);
                    checkValidKey(NAME);
                    id = std::stoi(ID);
                    readID = true;
                    ID = "";
                    NAME = "";
                }
                if (i == length - 1 && readID == false)
                {
                    checkValidID(ID);
                    checkValidKey(NAME);
                    id = std::stoi(ID);
                }
            }

            Node* temp02 = new Node(NAME, id);
            if (!MyHashMap.RemoveStudent(temp02))
            {
                std::cout << "No record found!\n";
                std::cout << "==========================================\n";
            }
            else
            {
                std::cout << "Recordhas been removed from the hash table.\n";
                std::cout << "==========================================\n";
            }


            delete temp02;
        }
        else if (choice == 3) {
            MyHashMap.PrintStudentList();
        }
        else if (choice == 4) {
            std::string name;
            std::cout << "Enter the student to be found:(Input a name)\n";
            std::cin >> name;
            std::cout << "==========================================\n";
            checkValidKey(name);
            if (MyHashMap.FindStudent(name))
            {

                std::cout << "Record found at index " << MyHashMap.Hashfunction(name) << std::endl;;
                std::cout << "======================================================\n";
            }
            else
            {
                std::cout << "Record not found!\n";
                std::cout << "======================================================\n";
            }
        }
        else if (choice == 5) {
            std::cout << "Bye bye!\n";
            std::cout << "==========================================\n";
            exit(0);
        }
        else {
            std::cout << "Please enter a valid choice!\n";
            std::cout << "==========================================\n";
            exit(0);
        }
    }

}