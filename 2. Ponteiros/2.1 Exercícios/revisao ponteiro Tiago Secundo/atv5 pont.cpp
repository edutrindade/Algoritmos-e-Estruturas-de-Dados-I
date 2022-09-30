#include <iostream>
#include <windows.h>

// Modificando valor com soma e ponteiros

using namespace std;

void soma(int x, int y)
{
    int *pont, aux;

    aux = x + y;

    pont = &aux;

    x = *pont;

    cout << "\n A apÃ³s a soma: " << x;
    cout << "\n B: " << y;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int a, b;

    cout << "\n Digite o valor de a: ";
    cin >> a;

    cout << "\n Digite o valor de b: ";
    cin >> b;

    soma(a, b);

    cout << endl;
    return 0;
}