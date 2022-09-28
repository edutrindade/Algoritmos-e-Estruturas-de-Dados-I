#include <iostream>
#include <windows.h>

using namespace std;

void soma(int *p, int *q)
{
    int aux;
    aux = *p + *q;
    *p = aux;
}

int main()
{
    int *p, *q;
    int a = 10, b = 30;
    p = &a;
    q = &b;
    soma(p, q);
    cout << a << "\t" << b;

    return 0;
}