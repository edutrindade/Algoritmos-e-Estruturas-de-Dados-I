#include <iostream>
#include <stack>
#include <time.h>
#include "functions.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int option = menu();

    switch (option)
    {
    case 1:
        play();
        break;
    }
    return 0;
}
