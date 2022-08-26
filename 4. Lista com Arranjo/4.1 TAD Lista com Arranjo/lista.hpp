#ifndef LISTA_H
#define LISTA_H

#define MAXTAM 5

typedef int TipoApontador;

typedef struct TipoItem
{
    int chave;
};

typedef struct TipoLista
{
    TipoItem Item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
    int tamanho;
};

bool listaCriada = false;

void CriaListaVazia(TipoLista *lista);                              // Cria uma lista vazia
int VerificaListaVazia(TipoLista *lista);                           // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
int VerificaListaCheia(TipoLista *lista);                           // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
int InsereItem(TipoLista *lista, TipoItem item);                    // Insere ITEM (chave) na lista TipoLista
void ImprimeLista(TipoLista lista);                                 // Imprime a lista
int PesquisaItem(TipoLista *lista, int chave);                      // Pesquisa um ITEM (chave) na lista TipoLista
void RetiraItem(TipoApontador p, TipoLista *lista, TipoItem *item); // Remove um item da lista pela sua posição
int TamanhoLista(TipoLista *lista);                                 // Retorna o número de itens da lista

#endif