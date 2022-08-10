#include <iostream>
#include <fstream>

using namespace std;

void ler_arquivo()
{
    ifstream arquivo;
    arquivo.open("extra.txt");
    char lista[300];

    if (!arquivo.is_open())
    {
        cerr << "ERRO! Não foi possível abrir o arquivo.\n";
    }

    while (!arquivo.eof())
    {
        arquivo.getline(lista, 300);
        cout << lista << endl;
    }
}

void escreve_arquivo()
{
    ofstream arquivo;
    arquivo.open("extra.txt");

    if (!arquivo.is_open())
    {
        cerr << "ERRO! Não foi possível abrir o arquivo.\n";
    }

    for (int i = 0; i < 10; i++)
    {
        arquivo << "Linha " << i << endl;
    }
}

int main()
{
    escreve_arquivo();
    ler_arquivo();

    return 0;
}