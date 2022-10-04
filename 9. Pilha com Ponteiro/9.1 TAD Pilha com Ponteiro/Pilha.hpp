#ifndef PILHA_H
#define PILHA_H

// Item para armazenar os dados contidos na pilha
typedef struct TipoItem
{
    int id;
    char nome[50];
} TipoItem;

// Ponteiro para o elemento da pilha
typedef struct TipoElemento *Apontador;

// Elemento (célula) da pilha
typedef struct TipoElemento
{
    TipoItem item;
    Apontador prox;
} TipoElemento;

// Estrutura da pilha
typedef struct TipoPilha
{
    Apontador topo;
    int tamanho;
} TipoPilha;

// Funções da pilha
void FazPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaVazia(TipoPilha *pilha);
void Empilha(TipoPilha *pilha, TipoItem item);
void Desempilha(TipoPilha *pilha, TipoItem *item);
void ExibePilha(TipoPilha *pilha);
int Tamanho(TipoPilha *pilha);

#endif