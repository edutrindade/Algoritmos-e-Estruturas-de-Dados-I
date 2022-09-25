#include <iostream>
#include <windows.h>
#include "Pilha.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoItem item;
    TipoPilha pilha;

    FazPilhaVazia(&pilha);

    item.id = 3;
    Empilha(&pilha, item);

    item.id = 5;
    Empilha(&pilha, item);

    item.id = 6;
    Empilha(&pilha, item);

    item.id = 1;
    Empilha(&pilha, item);

    cout << "O maior valor presente na pilha é: " << VerificaMaior(&pilha);

    return 0;
}