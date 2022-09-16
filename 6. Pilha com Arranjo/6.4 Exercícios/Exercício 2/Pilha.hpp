#ifndef PILHA_H
#define PILHA_H

#define MAXTAM 5

typedef struct TipoItem
{
    char nome[30];
    char autor[20];
    int numPaginas;
} TipoItem;

typedef struct Pilha
{
    TipoItem itens[MAXTAM];
    int topo;
} TipoPilha;

void FazPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaVazia(TipoPilha *pilha);
void Empilha(TipoPilha *pilha, TipoItem item);
void Desempilha(TipoPilha *pilha, TipoItem *item);
void ExibePilha(TipoPilha *pilha);
int Tamanho(TipoPilha *pilha);

#endif