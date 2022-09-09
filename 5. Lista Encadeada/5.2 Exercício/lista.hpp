#ifndef LISTA_H
#define LISTA_H

typedef struct TipoData
{
    int dia;
    int mes;
} TipoData;

typedef struct TipoItem
{
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

void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void AtualizaUltimo(TipoLista *lista);
void ImprimeLista(TipoLista lista);
bool PesquisaItem(TipoLista *lista, char nome[]);
void ImprimeItem(TipoLista *lista, char nome[]);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorNome(TipoLista *lista, char nome[]);
int TamanhoLista(TipoLista *lista);
int Atualiza(TipoLista *lista, TipoItem item, char nome[]);

#endif