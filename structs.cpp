#include <iostream>
#include <windows.h>
#include <cstring>

typedef struct TipoItem{
    int id;
    char titulo[60];
    char descricao[200];
    char data[9];
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{
    TipoItem item;
    struct TipoElemento *prox;
    struct TipoElemento *ant;
} TipoElemento;

typedef struct TipoLista
{
    Apontador primeiro;
    Apontador ultimo;
} TipoLista;

