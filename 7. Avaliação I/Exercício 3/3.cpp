#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int v[5];

    // Recebe 5 números inteiros
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }

    // Imprime endereço dos pares
    for (int i = 0; i < 5; i++)
    {
        if (v[i] % 2 == 0)
        {
            cout << &v[i] << " ";
        }
    }

    cout << endl;
    return 0;
}