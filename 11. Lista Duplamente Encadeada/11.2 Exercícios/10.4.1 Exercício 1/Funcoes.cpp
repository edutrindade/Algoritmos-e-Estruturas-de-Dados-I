#include <iostream>
#include <windows.h>
#include "ListaDuplamenteEncadeada.hpp"
#include "Menus.cpp"

using namespace std;

// Funções
int CadastraTrabalho(TipoLista *lista);
int RemoveTrabalho(TipoLista *lista);
void RemovePorCodigo(TipoLista *lista);
void PesquisaTrabalho(TipoLista *lista);
void PesquisaPorCodigo(TipoLista *lista);
void PesquisaPorTitulo(TipoLista *lista);
void ListaTrabalhos(TipoLista *lista);
void ImprimePrimeiroTrabalho(TipoLista *lista);
void ImprimeProximoTrabalho(TipoLista *lista, TipoElemento *ptr);
void ImprimeTrabalhoAnterior(TipoLista *lista, TipoElemento *ptr);
void ListaTodosTrabalhos(TipoLista *lista);

int CadastraTrabalho(TipoLista *lista)
{
    system("cls");
    CabecalhoCadastro();

    TipoItem item;

    while ((cout << "\n\n1. Código: ") && !(cin >> item.id))
    {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    cin.ignore();

    cout << "2. Título: ";
    cin.getline(item.titulo, 20);
    cout << "3. Descrição: ";
    cin.getline(item.descricao, 300);
    cout << "4. Data de Entrega: ";
    cin.getline(item.dataEntrega, 10);

    InsereListaUltimo(lista, &item);

    cout << "\nTrabalho cadastrado com sucesso!\n\n";
    system("pause");
    system("cls");
}

int RemoveTrabalho(TipoLista *lista)
{
    system("cls");

    TipoItem item;

    int opcao_menu;
    do
    {
        MenuRemocao();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu))
        {
            cout << "  \n        Digite um valor válido.";
            cin.clear();
            cin.ignore();
            Sleep(1000);
            system("cls");
            MenuRemocao();
        }
        system("cls");
        switch (opcao_menu)
        {
        case 1:
            RemoveListaPrimeiro(lista, &item);
            MenuRemocao();
            cout << "\n\nTrabalho removido com sucesso!\n\n";
            system("pause");
            system("cls");
            break;
        case 2:
            RemoveListaUltimo(lista, &item);
            MenuRemocao();
            cout << "\n\nTrabalho removido com sucesso!\n\n";
            system("pause");
            system("cls");
            break;
        case 3:
            RemovePorCodigo(lista);
            cout << "\n\nTrabalho removido com sucesso!\n\n";
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            break;
        default:
            RemoveTrabalho(lista);
        }
    } while (opcao_menu > 4 && opcao_menu < 1);
}

void RemovePorCodigo(TipoLista *lista)
{
    TipoItem item;
    int cod;
    CabecalhoRemocaoPorCodigo();
    while ((cout << "  \n        Informe o código do trabalho a ser removido: ") && !(cin >> cod))
    {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    RemoveElementoXbyId(lista, &item, cod);
}

void PesquisaTrabalho(TipoLista *lista)
{
    system("cls");

    int opcao_menu;
    do
    {
        MenuPesquisa();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu))
        {
            cout << "  \n        Digite um valor válido.";
            cin.clear();
            cin.ignore();
            Sleep(1000);
            system("cls");
            MenuPesquisa();
        }
        system("cls");
        switch (opcao_menu)
        {
        case 1:
            PesquisaPorCodigo(lista);
            system("pause");
            system("cls");
            break;
        case 2:
            PesquisaPorTitulo(lista);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        default:
            PesquisaTrabalho(lista);
        }
    } while (opcao_menu > 3 && opcao_menu < 1);
}

void PesquisaPorCodigo(TipoLista *lista)
{
    TipoItem item;
    int cod;
    CabecalhoPesquisaPorCodigo();
    while ((cout << "  \n\n        Informe o código do trabalho a ser pesquisado: ") && !(cin >> cod))
    {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    if (PesquisaElementoXbyId(lista, &item, cod))
    {
        cout << endl
             << endl
             << "Código: " << item.id << endl;
        cout << "Título: " << item.titulo << endl;
        cout << "Descrição: " << item.descricao << endl;
        cout << "Data de Entrega: " << item.dataEntrega << endl
             << endl;
    }
    else
    {
        cout << "\n\nCódigo não encontrado.\n\n";
    }
}

void PesquisaPorTitulo(TipoLista *lista)
{
    TipoItem item;
    char titulo[20];
    CabecalhoPesquisaPorTitulo();
    cin.ignore();
    cout << "  \n\n        Informe o título do trabalho a ser pesquisado: ";
    cin.getline(titulo, 20);

    if (PesquisaElementoXbyTitulo(lista, &item, titulo))
    {
        cout << endl
             << endl
             << "Código: " << item.id << endl;
        cout << "Título: " << item.titulo << endl;
        cout << "Descrição: " << item.descricao << endl;
        cout << "Data de Entrega: " << item.dataEntrega << endl
             << endl;
    }
    else
    {
        cout << "\n\nTítulo não encontrado.\n\n";
    }
}

void ListaTrabalhos(TipoLista *lista)
{
    system("cls");
    char nav;
    CabecalhoListagemCompleta();

    if (VerificaListaVazia(lista))
    {
        cout << "Nenhum trabalho cadastrado.\n\n";
        system("pause");
        system("cls");
        return;
    }

    ImprimePrimeiroTrabalho(lista);
    while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav))
    {
        cout << "Digite um valor válido.\n";
        cin.clear();
        cin.ignore();
    }

    if (nav == 'p')
    {
        Apontador p = lista->primeiro->prox->prox;
        ImprimeProximoTrabalho(lista, p);
    }
    else if (nav == 'a')
    {
        Apontador p = lista->primeiro;
        ImprimeTrabalhoAnterior(lista, p);
    }
    else
    {
        system("cls");
        return;
    }
}

void ImprimePrimeiroTrabalho(TipoLista *lista)
{
    Apontador x;

    x = lista->primeiro->prox;

    cout << "Código: " << x->item.id << endl;
    cout << "Título: " << x->item.titulo << endl;
    cout << "Descrição: " << x->item.descricao << endl;
    cout << "Data de Entrega: " << x->item.dataEntrega << endl
         << endl;
}

void ImprimeProximoTrabalho(TipoLista *lista, TipoElemento *ptr)
{
    Apontador p;
    char nav;

    for (p = ptr; p != NULL; p = p->prox)
    {
        system("cls");
        CabecalhoListagemCompleta();
        cout << "Código: " << p->item.id << endl;
        cout << "Título: " << p->item.titulo << endl;
        cout << "Descrição: " << p->item.descricao << endl;
        cout << "Data de Entrega: " << p->item.dataEntrega << endl
             << endl;
        while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav))
        {
            cout << "Digite um valor válido.\n";
            cin.clear();
            cin.ignore();
        }
        if (nav == 'p')
        {
            continue;
        }
        else if (nav == 'a')
        {
            ImprimeTrabalhoAnterior(lista, p->ant);
        }
        else
        {
            system("cls");
            return;
        }
    }

    if (p == NULL)
    {
        cout << "\nNão há mais trabalhos cadastrados.\n\n";
        system("pause");
        system("cls");
        return;
    }
}

void ImprimeTrabalhoAnterior(TipoLista *lista, TipoElemento *ptr)
{
    Apontador p;
    char nav;

    if (ptr == lista->primeiro)
    {
        cout << "\nNão há trabalhos cadastrados anteriores a este.\n\n";
        system("pause");
        system("cls");
        return;
    }

    for (p = ptr; p != NULL; p = p->ant)
    {
        system("cls");
        CabecalhoListagemCompleta();
        cout << "Código: " << p->item.id << endl;
        cout << "Título: " << p->item.titulo << endl;
        cout << "Descrição: " << p->item.descricao << endl;
        cout << "Data de Entrega: " << p->item.dataEntrega << endl
             << endl;
        while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav))
        {
            cout << "Digite um valor válido.\n";
            cin.clear();
            cin.ignore();
        }
        if (nav == 'a')
        {
            if (p == lista->primeiro->prox)
            {
                return;
            }
            else
            {
                continue;
            }
        }
        else if (nav == 'p')
        {
            ImprimeProximoTrabalho(lista, p->prox);
        }
        else
        {
            system("cls");
            return;
        }
    }
}

void ListaTodosTrabalhos(TipoLista *lista)
{
    system("cls");
    CabecalhoListagemCompleta();

    if (VerificaListaVazia(lista))
    {
        cout << "Nenhum trabalho cadastrado.\n\n";
        system("pause");
        system("cls");
        return;
    }

    ImprimeLista(lista);

    cout << endl
         << endl;
    system("pause");
    system("cls");
}