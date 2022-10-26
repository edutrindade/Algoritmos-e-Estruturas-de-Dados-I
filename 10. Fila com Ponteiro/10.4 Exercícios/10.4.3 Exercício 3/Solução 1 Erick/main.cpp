#include "functions.hpp"

#define EXIT_OPTION 3

int main(int argc, char const *argv[])
{
    UINT UTF8 = 65001;
    SetConsoleOutputCP(UTF8);

    Queue queue;
    int option;
    do
    {
        menu();
        std::cin >> option;

        switch (option)
        {
        case 1:
            addPerson(queue);
            break;

        case 2:
            nextPerson(queue);
            break;
        }
    } while (option != EXIT_OPTION);

    return 0;
}