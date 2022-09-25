#include <iostream>

using namespace std;

void sub(int *x, int y)
{
    *x = 3;
    y = *x + 1;
}
int main()
{
    int a, b, z;
    a = 1;
    b = 2;
    sub(&a, b);
    z = a + b;
    cout << z; // 5
    return 0;
}