#include <iostream>
#include <windows.h>
#include "Pilha.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    TipoItem item;
    TipoPilha pilha, pilha2;

    FazPilhaVazia(&pilha);
    FazPilhaVazia(&pilha2);

    item.id = 3;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 5;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 6;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 1;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    if (VerificaIgualdade(&pilha, &pilha2))
        cout << "As pilhas são iguais" << endl;
    else
        cout << "As pilhas são diferentes" << endl;

    return 0;
}