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
    TipoPilha pilha;

    FazPilhaVazia(&pilha);

    item.id = 1;
    strcpy(item.nome, "João");
    Empilha(&pilha, item);

    item.id = 2;
    strcpy(item.nome, "Maria");
    Empilha(&pilha, item);

    item.id = 3;
    strcpy(item.nome, "José");
    Empilha(&pilha, item);

    ExibePilha(&pilha);

    cout << "\nTamanho da Pilha: " << Tamanho(&pilha) << endl;
    cout << "\nTopo da Pilha: " << pilha.topo->item.id << " - " << pilha.topo->item.nome << endl;

    Desempilha(&pilha, &item);

    cout << "\nDesempilhado: " << item.id << " - " << item.nome << endl
         << endl;

    ExibePilha(&pilha);

    cout << "\nTamanho da Pilha: " << Tamanho(&pilha) << endl;
    cout << "\nTopo da Pilha: " << pilha.topo->item.id << " - " << pilha.topo->item.nome << endl;

    return 0;
}