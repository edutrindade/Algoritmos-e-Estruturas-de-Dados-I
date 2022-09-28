#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

    int a = 50, b = 30;
    int *pt1, *pt2;
    cout << "O endereco dos dois ponteiros e: " << pt1 << "||" << pt2 << endl;
    cout << "O ponteiro com maior endereco e: ";
    if (pt1 > pt2)
    {
        cout << pt1;
    }
    else
    {
        cout << pt2;
    }

    return 0;
}