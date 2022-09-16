#include <iostream>
#include "Pilha.hpp"

using namespace std;

void FazPilhaVazia(TipoPilha *pilha)
{
    pilha->topo = 0;
}

bool VerificaPilhaVazia(TipoPilha *pilha)
{
    if (pilha->topo == 0)
    {
        return true;
    }
    else
        return false;
}

void Empilha(TipoPilha *pilha, TipoItem item)
{
    if (pilha->topo == MAXTAM)
    {
        cout << "\nCaixa cheia\n";
    }
    else
    {
        pilha->itens[pilha->topo] = item;
        pilha->topo++;
        // cout << "\nItem empilhado com sucesso!\n";
    }
}

void ExibePilha(TipoPilha *pilha)
{
    for (int i = pilha->topo - 1; i >= 0; i--)
    {
        cout << "\nNome: " << pilha->itens[i].nome;
        cout << "\nAutor: " << pilha->itens[i].autor;
        cout << "\nNúmero de páginas: " << pilha->itens[i].numPaginas << endl;
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *item)
{
    if (VerificaPilhaVazia(pilha))
    {
        cout << "\nCaixa vazia.\n";
        return;
    }

    pilha->topo--;
    *item = pilha->itens[pilha->topo];
}

int Tamanho(TipoPilha *pilha)
{
    return pilha->topo;
}