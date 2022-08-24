#include <iostream>
#include <windows.h>

using namespace std;

void order(int *p, int *q, int *r)
{
    int aux;
    if (*p < *q && *q < *r)
        return;
    if (*q < *p)
    {
        aux = *p;
        *p = *q;
        *q = aux;
    }
    if (*r < *p)
    {
        aux = *p;
        *p = *r;
        *r = aux;
    }
    if (*r < *q)
    {
        aux = *q;
        *q = *r;
        *r = aux;
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int a = 2, b = 1, c = 3;
    int *p, *q, *r;
    p = &a;
    q = &b;
    r = &c;

    order(p, q, r);

    cout << a << " " << b << " " << c;
    cout << endl;
    return 0;
}