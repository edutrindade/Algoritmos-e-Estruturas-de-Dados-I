#ifndef FILA_H
#define FILA_H

#define MAXTAM 10

typedef struct TipoItem
{
    int id;
    char nome[30];
    char telefone[15];
    char solicitacao[60];
} TipoItem;

typedef struct Fila
{
    TipoItem itens[MAXTAM];
    int inicio, fim, tamanho;
} TipoFila;

void FazFilaVazia(TipoFila *fila);
bool VerificaFilaVazia(TipoFila *fila);
bool VerificaFilaCheia(TipoFila *fila);
void Enfileira(TipoFila *fila, TipoItem item);
void Desenfileira(TipoFila *fila, TipoItem *item);
void ExibeFila(TipoFila *fila);
int Tamanho(TipoFila *fila);
void Menu();

#endif