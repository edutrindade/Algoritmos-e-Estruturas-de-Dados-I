#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

    int a, b;
    int *pta, *ptb;
    pta = &a;
    ptb = &b;
    cout << "Insira dois valores de numeros inteiros: ";
    cin >> a >> b;
    if (pta > ptb)
    {
        cout << "\nO endereco mais longo e o do primeiro numero: " << pta << endl;
    }
    else
    {
        cout << "O endereco mais longo e o do segundo numero: " << ptb << endl;
    }

    return 0;
}