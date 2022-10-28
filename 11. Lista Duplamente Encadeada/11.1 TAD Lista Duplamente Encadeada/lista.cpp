#include <iostream>
#include <windows.h>
#include "lista.hpp"

#define MAXTAM 5

using namespace std;

void CriaListaVazia(TipoLista *lista)
{
    if (!listaCriada)
    {
        lista->primeiro = new TipoElemento;
        lista->ultimo = lista->primeiro;
        lista->primeiro->prox = NULL;
        lista->primeiro->ant = NULL;
        lista->tamanho = 0;
        listaCriada = true;
        cout << "Lista criada com sucesso!";
    }
    else
    {
        cout << "Lista já existe!";
    }
    Sleep(1500);
}

bool VerificaListaVazia(TipoLista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(TipoLista *lista)
{
    return lista->tamanho;
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    aux->prox = lista->primeiro->prox;
    aux->ant = lista->primeiro;
    lista->primeiro->prox = aux;
    if (lista->primeiro == lista->ultimo)
        lista->ultimo = aux;
    else
        aux->prox->ant = aux;
    lista->tamanho++;
}

void AtualizaUltimo(TipoLista *lista)
{
    Apontador aux;
    aux = lista->primeiro;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    aux->prox = NULL;
    aux->ant = lista->ultimo;
    lista->ultimo->prox = aux;
    lista->ultimo = aux;
    lista->tamanho++;
}

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    Apontador aux2 = lista->primeiro->prox;
    while (aux2->item.id != id)
    {
        aux2 = aux2->prox;
    }
    aux->prox = aux2->prox;
    aux->ant = aux2;
    aux2->prox = aux;
    if (aux->prox == NULL)
        lista->ultimo = aux;
    else
        aux->prox->ant = aux;
    lista->tamanho++;
}

void ImprimeLista(TipoLista lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        aux = aux->prox;
    }
    system("PAUSE");
}

int PesquisaItem(TipoLista *lista, int chave)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != chave)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        return aux->item.id;
    }
    else
    {
        return -1;
    }
}

void RemoveListaPrimeiro(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    if (aux->prox != NULL)
    {
        aux->prox->ant = lista->primeiro;
    }
    else
    {
        lista->ultimo = lista->primeiro;
    }
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->ultimo;
    lista->ultimo = aux->ant;
    lista->ultimo->prox = NULL;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != id)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        aux->ant->prox = aux->prox;
        if (aux->prox != NULL)
        {
            aux->prox->ant = aux->ant;
        }
        else
        {
            lista->ultimo = aux->ant;
        }
        delete aux;
        lista->tamanho--;
    }
    else
    {
        cout << "Elemento não encontrado!";
        Sleep(1500);
    }
}

void ImprimeItem(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != id)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        Sleep(1500);
    }
    else
    {
        cout << "Elemento não encontrado!";
        Sleep(1500);
    }
}