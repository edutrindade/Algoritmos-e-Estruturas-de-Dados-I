#include <iostream>
#include <windows.h>
#include "Queue.cpp"

void menu()
{
    system("cls");
    std::cout << "#################################################################" << std::endl;
    std::cout << "#                         Election System                       #" << std::endl;
    std::cout << "#################################################################" << std::endl;
    std::cout << "#                                                               #" << std::endl;
    std::cout << "#                         1 - Add Person                        #" << std::endl;
    std::cout << "#                                                               #" << std::endl;
    std::cout << "#                         2 - Next Person                       #" << std::endl;
    std::cout << "#                                                               #" << std::endl;
    std::cout << "#                         3 - Exit                              #" << std::endl;
    std::cout << "#                                                               #" << std::endl;
    std::cout << "#################################################################" << std::endl;
}

void addPerson(Queue &queue)
{
    Element person;
    std::cout << "Enter name: ";
    std::cin >> person.name;
    std::cin.ignore();
    int hasPriority;
    do
    {
        system("cls");
        menu();
        std::cout << "Has priority?" << std::endl;
        std::cout << "1-Yes" << std::endl;
        std::cout << "2-No" << std::endl;

        std::cin >> hasPriority;
        if (hasPriority == 1)
        {
            std::cout << "Enter the dregree of priority: ";
            std::cin >> person.priority;
        }
    } while (hasPriority < 1 || hasPriority > 2);
    queue.push(person);
}

void nextPerson(Queue &queue)
{
    if (queue.empty())
    {
        std::cout << "Queue is empty" << std::endl;
        Sleep(1000);
        return;
    }

    Element nextElement = queue.pop();
    std::cout << "Name: " << nextElement.name << std::endl;
    std::cout << "Zone: " << queue.getZone() << std::endl;
    std::cout << "Section: " << queue.getSection() << std::endl;
    system("pause");
}