#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{

    int tam;
    ofstream Matriz;
    Matriz.open("Matriz.xls");
    if (!Matriz.is_open())
    {
        cerr << "ERRO! Nao foi possivel abrir o arquivo";
        Matriz.clear();
    }
    cout << "Arquivo aberto com sucesso\n";
    cout << "Digite a ordem da matriz: ";
    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        int matrix[tam][tam];
        for (int j = 0; j < tam; j++)
        {
            matrix[i][j] = rand() % 101;
            Matriz << matrix[i][j] << "\t";
        }
        Matriz << "\n";
    }
    Matriz.close();

    return 0;
}