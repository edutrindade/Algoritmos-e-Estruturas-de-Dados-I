#include <iostream>
#include <windows.h>
#include "lista.hpp"

#define MAXTAM 5

using namespace std;

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

    strcpy(lista->Item[lista->Ultimo].matricula, item.matricula);
    strcpy(lista->Item[lista->Ultimo].nome, item.nome);
    lista->Item[lista->Ultimo].turma = item.turma;
    lista->Item[lista->Ultimo].p1 = item.p1;
    lista->Item[lista->Ultimo].p2 = item.p2;
    lista->Item[lista->Ultimo].p3 = item.p3;
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
            cout << "Matricula: " << lista.Item[Aux].matricula << endl;
            cout << "Nome: " << lista.Item[Aux].nome << endl;
            cout << "Turma: " << lista.Item[Aux].turma << endl;
            cout << "P1: " << lista.Item[Aux].p1 << endl;
            cout << "P2: " << lista.Item[Aux].p2 << endl;
            cout << "P3: " << lista.Item[Aux].p3 << endl;
            cout << endl;
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

int PesquisaItem(TipoLista *lista, char matricula[])
{
    for (int i = lista->Primeiro; i < lista->Ultimo; i++)
    {
        if (strcmp(matricula, lista->Item[i].matricula) == 0)
        {
            return i;
        }
    }
    return -1;
}

void ImprimeItem(TipoLista *lista, int posicao)
{
    if (posicao != -1)
    {
        cout << "\nMatricula: " << lista->Item[posicao].matricula << endl;
        cout << "Nome: " << lista->Item[posicao].nome << endl;
        cout << "Turma: " << lista->Item[posicao].turma << endl;
        cout << "P1: " << lista->Item[posicao].p1 << endl;
        cout << "P2: " << lista->Item[posicao].p2 << endl;
        cout << "P3: " << lista->Item[posicao].p3 << endl
             << endl;
    }
    else
    {
        cout << "Aluno não encontrado.";
    }
    system("Pause");
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

void ImprimeTurma(TipoLista *lista, char turma)
{
    if (listaCriada)
    {
        int Aux;
        for (Aux = lista->Primeiro; Aux <= (lista->Ultimo - 1); Aux++)
        {
            if (lista->Item[Aux].turma == turma)
            {
                cout << "Matricula: " << lista->Item[Aux].matricula << endl;
                cout << "Nome: " << lista->Item[Aux].nome << endl;
                cout << "Turma: " << lista->Item[Aux].turma << endl;
                cout << "Média: " << (lista->Item[Aux].p1 + lista->Item[Aux].p2 + lista->Item[Aux].p3) / 3 << endl;
                cout << endl;
            }
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