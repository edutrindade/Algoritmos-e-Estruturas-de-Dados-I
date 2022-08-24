#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    ifstream file;
    file.open("soma.txt");

    if (file.fail())
    {
        cerr << "ERRO! Não foi possível abrir o arquivo.";
        file.clear();
    }

    int x;
    file >> x;

    cout << "Valor: " << x;

    cout << endl
         << endl;
    return 0;
}