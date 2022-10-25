#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

typedef struct Registro
{
    string nome;
    char telefone[11];
} Registro;

int main()
{
    ofstream tabela;
    tabela.open("Exercicio2.csv");
    Registro registro[300];
    int continuar = 1;
    int n = 0;

    if (!tabela.is_open())
    {
        cerr << "ERRO! O arquivo nao pode ser aberto.\n\n";
        tabela.clear();
    }
    else
    {
        cout << "Arquivo aberto com sucesso!\n";
        do
        {
            cout << "Insira o nome da pessoa: ";
            cin >> registro[n].nome;
            cout << "Insira o numero de telefone da pessoa: ";
            cin >> registro[n].telefone;
            tabela << registro[n].nome << "," << registro[n].telefone << endl;
            n++;
            cout << "Deseja continuar? 1 - sim | 0 - nao" << endl;
            cin >> continuar;
        } while (continuar);
    }
    tabela.close();
    return 0;
}