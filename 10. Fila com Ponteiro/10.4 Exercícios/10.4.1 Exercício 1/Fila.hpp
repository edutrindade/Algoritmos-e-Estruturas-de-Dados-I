#ifndef FILA_H
#define FILA_H

// Item para armazenar os dados contidos na fila
typedef struct TipoItem
{
    char nome[20];
    char telefone[15];
    char solicitacao[100];
} TipoItem;

// Ponteiro para o elemento da fila
typedef struct TipoElemento *Apontador;

// Elemento (célula) da fila
typedef struct TipoElemento
{
    TipoItem item;
    Apontador prox;
} TipoElemento;

// Estrutura da fila
typedef struct TipoFila
{
    Apontador inicio, fim;
    int tamanho;
} TipoFila;

// Funções da fila
void InicializaFila(TipoFila *fila);
bool VerificaFilaVazia(TipoFila *fila);
void Enfileira(TipoFila *fila, TipoItem item);
void Desenfileira(TipoFila *fila, TipoItem *item);
void EsvaziaFila(TipoFila *fila);
void ImprimeFila(TipoFila *fila);

#endif