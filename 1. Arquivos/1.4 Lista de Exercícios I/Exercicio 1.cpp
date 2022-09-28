#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    char vetor[300];
    ifstream leitura;
    string arquivo;
    cout << "Insira o nome do arquivo: ";
    cin >> arquivo;
    leitura.open(arquivo);
    if (leitura)
    {
        cout << "O arquivo existe";
    }
    else
    {
        cout << "O arquivo nao existe";
    }
    return 0;
}