#include <iostream>
#include "Fila.hpp"

using namespace std;

void FazFilaVazia(TipoFila *fila)
{
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila)
{
    if (fila->tamanho == 0)
        return true;

    return false;
}

bool VerificaFilaCheia(TipoFila *fila)
{
    if (fila->tamanho == MAXTAM)
        return true;

    return false;
}

void Enfileira(TipoFila *fila, TipoItem item)
{
    if (VerificaFilaCheia(fila))
    {
        cout << "\nFila Cheia.\n";
        return;
    }
    fila->fim++;
    fila->itens[fila->fim] = item;
    fila->tamanho++;
    cout << "\nNovo atendimento registrado com sucesso!" << endl;
}

void Desenfileira(TipoFila *fila, TipoItem *item)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia.\n";
        return;
    }
    *item = fila->itens[fila->inicio];
    fila->inicio++;
    fila->tamanho--;
}

void ExibeFila(TipoFila *fila)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia.\n";
        return;
    }
    for (int i = fila->inicio; i <= fila->fim; i++)
    {
        cout << i + 1 << "º atendimento: \n";
        cout << "Nome: " << fila->itens[i].nome << "\n";
        cout << "Telefone: " << fila->itens[i].telefone << "\n";
        cout << "Solicitação: " << fila->itens[i].solicitacao << "\n";
        cout << "----------------------------------------\n";
    }
}

int Tamanho(TipoFila *fila)
{
    return fila->tamanho;
}

void Menu()
{
    system("cls");
    cout << "MENU PRINCIPAL\n\n";
    cout << "1. NOVO ATENDIMENTO\n";
    cout << "2. LISTAR ATENDIMENTOS\n";
    cout << "3. PRÓXIMO ATENDIMENTO\n";
    cout << "4. SAIR\n\n";
}