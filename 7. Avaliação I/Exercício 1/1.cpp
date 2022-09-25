#include <iostream>

using namespace std;

int main()
{
    int a, b, *p1, *p2;

    a = 4;
    b = 3;
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;

    cout << "a = " << a << endl;    // 8
    cout << "b = " << b << endl;    // 21
    cout << "p1 = " << *p1 << endl; // 21
    cout << "p2 = " << *p2 << endl; // 8

    return 0;
}