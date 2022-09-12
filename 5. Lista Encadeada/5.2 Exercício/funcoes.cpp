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
        lista->ultimo->prox = NULL;
        listaCriada = true;
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

void AtualizaUltimo(TipoLista *lista)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item)
{
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
    id++;
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
        cout << "Telefone: " << aux->item.telefone << endl;
        cout << "Celular: " << aux->item.celular << endl;
        cout << "Email: " << aux->item.email << endl;
        cout << "Aniversario: " << aux->item.aniversario.dia << "/" << aux->item.aniversario.mes << endl
             << endl;
        aux = aux->prox;
    }
    system("pause");
}

bool PesquisaItem(TipoLista *lista, char nome[])
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.nome, nome) == 0)
        {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

bool PesquisaItemPorId(TipoLista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

bool PesquisaItemPorEmail(TipoLista *lista, char email[])
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.email, email) == 0)
        {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

int Atualiza(TipoLista *lista, TipoItem item, char valor[], int campo)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.nome, item.nome) == 0)
        {
            if (campo == 1)
            {
                strcpy(aux->item.nome, valor);
                return 1;
            }
            else if (campo == 2)
            {
                strcpy(aux->item.telefone, valor);
                return 1;
            }
            else if (campo == 3)
            {
                strcpy(aux->item.celular, valor);
                return 1;
            }
            else if (campo == 4)
            {
                strcpy(aux->item.email, valor);
                return 1;
            }
        }
        aux = aux->prox;
    }
    return 0;
}

int AtualizaAniversario(TipoLista *lista, TipoItem item, int dia, int mes)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.nome, item.nome) == 0)
        {
            aux->item.aniversario.dia = dia;
            aux->item.aniversario.mes = mes;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void ImprimeItem(TipoLista *lista, char nome[])
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.nome, nome) == 0)
        {
            // cout << "Nome: " << aux->item.nome << endl;
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Telefone: " << aux->item.telefone << endl;
            cout << "Celular: " << aux->item.celular << endl;
            cout << "Email: " << aux->item.email << endl;
            cout << "Aniversario: " << aux->item.aniversario.dia << "/" << aux->item.aniversario.mes << endl
                 << endl;
            break;
        }
        aux = aux->prox;
    }
}

void ImprimeItemPorId(TipoLista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Telefone: " << aux->item.telefone << endl;
            cout << "Celular: " << aux->item.celular << endl;
            cout << "Email: " << aux->item.email << endl;
            cout << "Aniversario: " << aux->item.aniversario.dia << "/" << aux->item.aniversario.mes << endl
                 << endl;
            break;
        }
        aux = aux->prox;
    }
}

void RemoveListaPrimeiro(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }

    Apontador aux, anterior, x;

    aux = lista->primeiro->prox;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}
