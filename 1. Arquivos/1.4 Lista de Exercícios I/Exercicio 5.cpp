#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    int total = 0;
    int x;
    ifstream arquivo;
    string texto;

    arquivo.open("Exercicio5.txt");
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo! ";
        exit(1);
    }

    while (arquivo >> texto >> x)
    {
        cout << x << endl;
        total += x;
    }
    if (arquivo.eof())
    {
        cout << "Todo o arquivo foi lido!" << endl;
    }
    else
    {
        cout << "Nao foi possivel ler todo o arquivo!" << endl;
    }
    arquivo.close();
    cout << "Total = " << total << endl;
    cin.get();
    return 0;
}