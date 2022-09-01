#ifndef LISTA_H
#define LISTA_H

typedef struct TipoItem
{
    int id;
    char nome[30];
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{ // Célula
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

void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaPrimeiro(TipoLista *lista, TipoItem *item);
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void AtualizaUltimo(TipoLista *lista);
void ImprimeLista(TipoLista lista);
int PesquisaItem(TipoLista *lista, int chave);
void ImprimeItem(TipoLista *lista, int id);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorId(TipoLista *lista, int id);
int TamanhoLista(TipoLista *lista);

#endif