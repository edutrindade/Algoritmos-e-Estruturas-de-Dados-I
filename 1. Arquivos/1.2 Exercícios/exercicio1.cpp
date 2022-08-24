#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int soma(int x, int y, int z);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    ofstream file;

    file.open("soma.txt");

    if (file.fail())
    {
        cerr << "ERRO! Não foi possível criar o arquivo.";
        file.clear();
    }
    else
    {
        cout << "Arquivo soma.txt criado com sucesso!\n";
    }

    int resultado = soma(10, 20, 30);

    file << resultado;

    file.close();
    return 0;
}

int soma(int x, int y, int z)
{
    return x + y + z;
}