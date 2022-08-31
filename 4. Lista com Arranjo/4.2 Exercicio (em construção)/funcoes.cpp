#include <iostream>
#include <windows.h>
#include "lista.hpp"

#define MAXTAM 5

using namespace std;

void menu()
{
        cout << "Turmas \n\n";
        cout << "1. Criar Turma\n";
        cout << "2. Verifica Turma Vazia\n";
        cout << "3. Verifica Turma Cheia\n";
        cout << "4. Cadastro de Aluno\n";
        cout << "5. Imprime Turma\n";
        cout << "6. Pesquisa Aluno\n";
        cout << "7. Remove Aluno\n";
        cout << "0. Sair\n\n";    
}
void CriaListaVazia(TipoLista *lista)
{
    if (!listaCriada)
    {
        lista->tamanho = 0;
        lista->Primeiro = 0;
        lista->Ultimo = lista->Primeiro;
        cout << "Lista criada com sucesso!";
        listaCriada = true;
    }
    else
    {
        cout << "Lista já existe!";
    }
    Sleep(1500);
}

int VerificaListaVazia(TipoLista *lista)
{
    return (lista->Primeiro == lista->Ultimo);
}

int VerificaListaCheia(TipoLista *lista)
{
    return (lista->Ultimo == MAXTAM);
}

int TamanhoLista(TipoLista *lista)
{
    return lista->tamanho;
}

int InsereItem(TipoLista *lista, TipoItem item)
{
    if (VerificaListaCheia(lista))
    {
        return -1;
    }
    lista->Item[lista->Ultimo].chave = item.chave;
    lista->tamanho++;
    lista->Ultimo++;
    return 1; 
}

void ImprimeLista(TipoLista lista)
{
    if (listaCriada)
    {
        int Aux;
        for (Aux = lista.Primeiro; Aux <= (lista.Ultimo - 1); Aux++)
        {
            cout << "Chave: " << lista.Item[Aux].chave << endl;
        }
        cout << endl;
        system("Pause");
    }
    else
    {
        cout << "Crie a lista primeiramente.";
        Sleep(1000);
    }
}

int PesquisaItem(TipoLista *lista, int chave)
{
    for (int i = lista->Primeiro; i < lista->Ultimo; i++)
    {
        if (chave == lista->Item[i].chave)
        {
            return i; // Retorna posição do item encontrado
        }
    }
    return -1;
}

void RetiraItem(TipoApontador p, TipoLista *lista, TipoItem *item)
{
    int Aux;

    if (VerificaListaVazia(lista) || p > lista->Ultimo)
    {
        cout << "Erro: Posição não existe na lista\n";
        return;
    }

    *item = lista->Item[p];

    for (Aux = p; Aux <= lista->Ultimo; Aux++)
    {
        lista->Item[Aux] = lista->Item[Aux + 1];
    }

    lista->Ultimo--;
    lista->tamanho--;
}
