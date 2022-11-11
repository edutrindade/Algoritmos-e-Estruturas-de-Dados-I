#include <iostream>
#include <windows.h>
#include <ctime>
#include "lista.hpp"

using namespace std;

void AbreEstacionamento(TipoLista *lista)
{
    if (!listaCriada)
    {
        lista->primeiro = new TipoElemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        cout << "Estacionamento aberto com sucesso!";
        listaCriada = true;
    }
    else
    {
        cout << "Estacionamento já aberto!";
    }
    Sleep(1000);
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
    aux = lista->primeiro;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(TipoLista *lista, Carro *item)
{
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
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
        cout << "Placa: " << aux->item.placa << endl;
        cout << "Hora de chegada: " << ctime(&aux->item.horaChegada);
        int tempo_estacionado = aux->item.horaSaida - aux->item.horaChegada;
        cout << "Tempo de permanência: " << tempo_estacionado / 60 << " minutos" << endl;
        aux = aux->prox;
    }
    system("pause");
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

void RemoveCarroPorPlaca(TipoLista *lista, char placa[])
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux, aux2;
    aux = lista->primeiro->prox;
    aux2 = lista->primeiro;
    while (aux != NULL)
    {
        if (strcmp(aux->item.placa, placa) == 0)
        {
            aux2->prox = aux->prox;
            delete aux;
            lista->tamanho--;
            break;
        }
        aux2 = aux;
        aux = aux->prox;
    }
    AtualizaUltimo(lista);
}
