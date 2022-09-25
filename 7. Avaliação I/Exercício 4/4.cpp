#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float altura;
    char telefone[15];
};

int main()
{
    Pessoa amigos[5];

    ofstream arquivo;
    arquivo.open("amigos.txt", ios::out);

    // Salvar em arquivo a cada inserção com fluxo ios::app
    for (int i = 0; i < 3; i++)
    {
        cout << "Nome: ";
        cin >> amigos[i].nome;
        cout << "Idade: ";
        cin >> amigos[i].idade;
        cout << "Altura: ";
        cin >> amigos[i].altura;
        cout << "Telefone: ";
        cin >> amigos[i].telefone;

        arquivo << amigos[i].nome << endl;
        arquivo << amigos[i].idade << endl;
        arquivo << amigos[i].altura << endl;
        arquivo << amigos[i].telefone << endl
                << endl;
    }
    return 0;
}