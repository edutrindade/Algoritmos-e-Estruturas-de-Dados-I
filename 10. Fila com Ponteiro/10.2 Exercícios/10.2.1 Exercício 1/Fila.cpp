#include <iostream>
#include "Fila.hpp"

using namespace std;

void InicializaFila(TipoFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila)
{
    return (fila->inicio == NULL);
}

void Enfileira(TipoFila *fila, TipoItem item)
{
    Apontador novo = new TipoElemento;
    novo->item = item;
    novo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
}

void Desenfileira(TipoFila *fila, TipoItem *item)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    *item = aux->item;
    fila->inicio = aux->prox;
    delete aux;
    fila->tamanho--;
}

void EsvaziaFila(TipoFila *fila)
{
    TipoItem item;
    while (!VerificaFilaVazia(fila))
    {
        Desenfileira(fila, &item);
    }
}

void ImprimeFila(TipoFila *fila)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL)
    {
        cout << "\nNome: " << aux->item.nome;
        cout << "\nTelefone: " << aux->item.telefone;
        cout << "\nSolicitação: " << aux->item.solicitacao << endl
             << endl;
        aux = aux->prox;
    }
    cout << endl;
}

void ImprimeProximo(TipoFila *fila)
{
    TipoItem item;
    if (VerificaFilaVazia(fila))
    {
        cout << "\nFila vazia.\n\n";
    }
    else
    {
        cout << "\nNome: " << fila->inicio->item.nome;
        cout << "\nTelefone: " << fila->inicio->item.telefone;
        cout << "\nSolicitação: " << fila->inicio->item.solicitacao << endl
             << endl;
        Desenfileira(fila, &item);
    }
}