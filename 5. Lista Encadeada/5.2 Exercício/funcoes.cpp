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
}

// void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id)
// {
//     Apontador aux, pAux, x;
//     bool find = false;
//     pAux = lista->primeiro->prox;
//     while (pAux != NULL)
//     {
//         if (pAux->item.id == id)
//         {
//             find = true;
//             x = pAux;
//             aux = x->prox;
//             x->prox = new TipoElemento;
//             x->prox->prox = aux;
//             x->prox->item = *item;
//             break;
//         }
//         pAux = pAux->prox; /* próxima célula */
//     }
//     if (find)
//     {
//         cout << "Item inserido com sucesso!";
//         AtualizaUltimo(lista);
//         lista->tamanho++;
//     }
//     else
//     {
//         cout << "Elemento anterior não encontrado na lista.";
//     }
// }

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
        cout << "Nome: " << aux->item.nome << endl;
        cout << "Telefone: " << aux->item.telefone << endl;
        cout << "Celular: " << aux->item.celular << endl;
        cout << "Email: " << aux->item.email << endl;
        cout << "Aniversario: " << aux->item.aniversario.dia << "/" << aux->item.aniversario.mes << endl;
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

int Atualiza(TipoLista *lista, TipoItem item, char nome[])
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.nome, item.nome) == 0)
        {
            strcpy(aux->item.nome, nome);
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
            cout << "Telefone: " << aux->item.telefone << endl;
            cout << "Celular: " << aux->item.celular << endl;
            cout << "Email: " << aux->item.email << endl;
            cout << "Aniversario: " << aux->item.aniversario.dia << "/" << aux->item.aniversario.mes << endl;
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

void RemoveItemPorNome(TipoLista *lista, char nome[])
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
        if (strcmp(aux->item.nome, nome) == 0)
        {
            anterior->prox = aux->prox;
            delete aux;
            lista->tamanho--;
            break;
        }
        x = x->prox;
    }
}
