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

    TipoPilha caixa;
    TipoItem item;
    int qtd;

    cout << "Quantos livros deseja guardar? ";
    cin >> qtd;

    FazPilhaVazia(&caixa);

    for (int i = 0; i < qtd; i++)
    {
        cout << "Digite o nome do livro: ";
        cin >> item.nome;
        cin.ignore();

        cout << "Digite o nome do autor: ";
        cin >> item.autor;
        cin.ignore();

        cout << "Digite o número de páginas: ";
        cin >> item.numPaginas;
        cin.ignore();

        Empilha(&caixa, item);
    }

    cout << "\nLivros na caixa: " << Tamanho(&caixa) << endl;
    ExibePilha(&caixa);

    return 0;
}