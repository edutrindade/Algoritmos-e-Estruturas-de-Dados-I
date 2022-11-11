#ifndef LISTA_H
#define LISTA_H

typedef struct Carro
{
    char placa[7];
    time_t horaChegada;
    time_t horaSaida;
    double valor;
};

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{
    Carro item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
} TipoLista;

bool listaCriada = false;

void AbreEstacionamento(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaUltimo(TipoLista *lista, Carro *carro);
void ImprimeLista(TipoLista lista);
int TamanhoLista(TipoLista *lista);
void RemoveCarroPorPlaca(TipoLista *lista, char placa[]);

#endif