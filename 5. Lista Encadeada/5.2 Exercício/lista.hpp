#ifndef LISTA_H
#define LISTA_H

typedef struct TipoData
{
    int dia;
    int mes;
} TipoData;

typedef struct TipoItem
{
    unsigned int id;
    char nome[40];
    char telefone[15];
    char celular[15];
    char email[40];
    TipoData aniversario;
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
} TipoLista;

bool listaCriada = false;
int id = 1;

void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void AtualizaUltimo(TipoLista *lista);
void ImprimeLista(TipoLista lista);
bool PesquisaItem(TipoLista *lista, char nome[]);
bool PesquisaItemPorId(TipoLista *lista, int id);
bool PesquisaItemPorEmail(TipoLista *lista, char email[]);
void ImprimeItem(TipoLista *lista, char nome[]);
void ImprimeItemPorId(TipoLista *lista, int id);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorId(TipoLista *lista, int id);
int TamanhoLista(TipoLista *lista);
int Atualiza(TipoLista *lista, TipoItem item, char nome[], int campo);
int AtualizaAniversario(TipoLista *lista, TipoItem item, int dia, int mes);

#endif