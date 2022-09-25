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
        return true;
    return false;
}

bool VerificaPilhaCheia(TipoPilha *pilha)
{
    if (pilha->topo == MAXTAM)
        return true;
    return false;
}

void Empilha(TipoPilha *pilha, TipoItem item)
{
    if (VerificaPilhaCheia(pilha))
    {
        cout << "\nPilha cheia\n";
        return;
    }

    pilha->itens[pilha->topo] = item;
    pilha->topo++;
    // cout << "\nItem empilhado com sucesso!\n";
}

void ExibePilha(TipoPilha *pilha)
{
    for (int i = pilha->topo - 1; i >= 0; i--)
    {
        cout << pilha->itens[i].id << "\n";
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *item)
{
    if (VerificaPilhaVazia(pilha))
    {
        cout << "\nPilha vazia.\n";
        return;
    }

    pilha->topo--;
    *item = pilha->itens[pilha->topo];
}

int Tamanho(TipoPilha *pilha)
{
    return pilha->topo;
}

bool VerificaIgualdade(TipoPilha *pilha1, TipoPilha *pilha2)
{
    if (Tamanho(pilha1) != Tamanho(pilha2))
        return false;

    TipoItem item1, item2;
    TipoPilha pilhaAux1, pilhaAux2;
    FazPilhaVazia(&pilhaAux1);
    FazPilhaVazia(&pilhaAux2);

    while (!VerificaPilhaVazia(pilha1))
    {
        Desempilha(pilha1, &item1);
        Desempilha(pilha2, &item2);
        if (item1.id != item2.id)
            return false;
        Empilha(&pilhaAux1, item1);
        Empilha(&pilhaAux2, item2);
    }

    while (!VerificaPilhaVazia(&pilhaAux1))
    {
        Desempilha(&pilhaAux1, &item1);
        Desempilha(&pilhaAux2, &item2);
        Empilha(pilha1, item1);
        Empilha(pilha2, item2);
    }

    return true;
}