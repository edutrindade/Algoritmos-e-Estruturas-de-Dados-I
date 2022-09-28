#include <iostream>
#include <windows.h>

using namespace std;

void trocavalor(int *pta, int *ptb)
{
    int aux;
    aux = *pta;
    *pta = *ptb;
    *ptb = aux;
}

int main()
{
    int *pta, *ptb;
    int a, b;
    pta = &a;
    ptb = &b;
    cout << "Entre com valores para a e b: ";
    cin >> a >> b;
    trocavalor(pta, ptb);
    cout << "Os novos valores sao: " << a << "\t" << b;

    return 0;
}