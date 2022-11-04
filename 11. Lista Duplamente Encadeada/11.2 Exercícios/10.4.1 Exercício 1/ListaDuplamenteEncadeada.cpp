#include <iostream>
#include <string.h>
#include "ListaDuplamenteEncadeada.hpp"

using namespace std;

void CriaListaVazia(TipoLista *lista)
{
    lista->primeiro = new TipoElemento;
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
}

bool VerificaListaVazia(TipoLista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new TipoElemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    aux->ant = lista->primeiro->prox;
    lista->primeiro->prox->ant = lista->primeiro;
}

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int idEleX)
{
    Apontador aux, x, itemAnterior;
    x = lista->primeiro; // Célula cabeça

    while (x->prox != NULL)
    {
        if (x->prox->item.id == idEleX)
        {
            itemAnterior = x->prox;
            break;
        }
        x = x->prox;
    }

    aux = itemAnterior->prox;
    itemAnterior->prox = new TipoElemento;
    itemAnterior->prox->item = *item;
    itemAnterior->prox->prox = aux;
    aux->ant = itemAnterior->prox;
    aux->ant->ant = itemAnterior;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item)
{
    Apontador aux;
    aux = lista->ultimo;
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->ultimo->ant = aux;
}

void RemoveListaPrimeiro(TipoLista *lista, TipoItem *item)
{
    Apontador aux;

    if (VerificaListaVazia(lista))
    {
        return;
    }
    *item = lista->primeiro->prox->item;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    lista->primeiro->prox->ant = lista->primeiro;
    free(aux);
}

void RemoveListaUltimo(TipoLista *lista, TipoItem *item)
{
    Apontador aux, anterior, x;

    if (VerificaListaVazia(lista))
    {
        return;
    }

    x = lista->primeiro;
    while (x != NULL)
    {
        if (x->prox == lista->ultimo)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }

    aux = lista->ultimo;
    lista->ultimo = anterior;
    *item = aux->item;
    lista->ultimo->prox = NULL;
    free(aux);
}

void RemoveElementoXbyId(TipoLista *lista, TipoItem *item, int idEle)
{
    Apontador aux, anterior, x;

    if (VerificaListaVazia(lista))
    {
        return;
    }

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == idEle)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    *item = aux->item;
    free(aux);
}

bool PesquisaElementoXbyId(TipoLista *lista, TipoItem *item, int idEle)
{
    Apontador x;

    if (VerificaListaVazia(lista))
    {
        return false;
    }

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == idEle)
        {
            *item = x->prox->item;
            return true;
        }
        x = x->prox;
    }
    return false;
}

bool PesquisaElementoXbyTitulo(TipoLista *lista, TipoItem *item, char titulo[])
{
    Apontador x;

    if (VerificaListaVazia(lista))
    {
        return false;
    }

    x = lista->primeiro;

    while (x != NULL)
    {
        if (strcmpi(x->prox->item.titulo, titulo) == 0)
        {
            *item = x->prox->item;
            return true;
        }
        x = x->prox;
    }
    return false;
}

void ImprimeLista(TipoLista *lista)
{
    Apontador x;

    x = lista->primeiro->prox;

    while (x != NULL)
    {
        cout << "Código: " << x->item.id << endl;
        cout << "Título: " << x->item.titulo << endl;
        cout << "Descrição: " << x->item.descricao << endl;
        cout << "Data de Entrega: " << x->item.dataEntrega << endl
             << endl;
        x = x->prox;
    }
}