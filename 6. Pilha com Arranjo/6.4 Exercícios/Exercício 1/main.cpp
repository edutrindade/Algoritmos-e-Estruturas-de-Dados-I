#include <iostream>
#include <windows.h>
#include "Pilha.hpp"
#include "Pilha.cpp"

#define MAXTAM 10

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    TipoPilha p, q;
    int tam;

    FazPilhaVazia(&p);
    FazPilhaVazia(&q);

    Empilha(&p, 'R');
    Empilha(&p, 'O');
    Empilha(&p, 'M');
    Empilha(&p, 'A');

    ExibePilha(&p);

    tam = Tamanho(&p);
    cout << "\nTamanho da Pilha p: " << tam << endl
         << endl;

    for (int i = 0; i < tam; i++)
    {
        char aux = Desempilha(&p);
        Empilha(&q, aux);
    }

    ExibePilha(&q);

    tam = Tamanho(&q);
    cout << "\nTamanho da Pilha q: " << tam << endl;

    return 0;
}