#include <iostream>
#include "Pilha.hpp"

using namespace std;

void FazPilhaVazia(TipoPilha *pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

bool VerificaPilhaVazia(TipoPilha *pilha)
{
    return (pilha->topo == NULL);
}

void Empilha(TipoPilha *pilha, TipoItem item)
{
    Apontador aux;

    aux = new TipoElemento; // Aloca memória para o novo elemento (célula)
    aux->item = item;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void Desempilha(TipoPilha *pilha, TipoItem *item)
{
    Apontador aux;

    if (VerificaPilhaVazia(pilha))
    {
        cout << "Pilha vazia!" << endl;
        return;
    }

    aux = pilha->topo;
    *item = aux->item;
    pilha->topo = aux->prox;
    delete aux;
    pilha->tamanho--;
}

void ExibePilha(TipoPilha *pilha)
{
    Apontador aux;

    if (VerificaPilhaVazia(pilha))
    {
        cout << "Pilha vazia!" << endl;
        return;
    }

    aux = pilha->topo;
    while (aux != NULL)
    {
        cout << aux->item.id << " - " << aux->item.nome << endl;
        aux = aux->prox;
    }
}

int Tamanho(TipoPilha *pilha)
{
    return pilha->tamanho;
}