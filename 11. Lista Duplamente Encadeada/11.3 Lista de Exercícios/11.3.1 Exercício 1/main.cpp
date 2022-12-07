#include <iostream>
#include <windows.h>
#include "lista.cpp"
#include "lista.hpp"

using namespace std;

void Menu()
{
    system("cls");
    cout << "------------------------------------\n";
    cout << "     Lista Duplamente Encadeada     \n";
    cout << "------------------------------------\n";
    cout << "1. Concatenar duas listas\n";
    cout << "2. Dividir uma lista em duas\n";
    cout << "3. Intercalar duas listas ordenadas em uma lista ordenada\n";
    cout << "4. Inverter uma lista\n";
    cout << "0. Sair\n\n";
}

void ConcatenarDuasListas(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3)
{
    Apontador aux;
    TipoItem item;
    aux = lista1->primeiro->prox;
    while (aux != NULL)
    {
        item = aux->item;
        InsereListaUltimo(lista3, &item);
        aux = aux->prox;
    }
    aux = lista2->primeiro->prox;
    while (aux != NULL)
    {
        item = aux->item;
        InsereListaUltimo(lista3, &item);
        aux = aux->prox;
    }
}

void DividirUmaListaEmDuas(TipoLista *lista3, TipoLista *lista4, TipoLista *lista5)
{
    Apontador aux;
    TipoItem item;
    aux = lista3->primeiro->prox;
    int tam = TamanhoLista(lista3);
    cout << "Tamanho da lista: " << tam << "\n";

    for (int i = 0; i < tam / 2; i++)
    {
        item = aux->item;
        InsereListaUltimo(lista4, &item);
        aux = aux->prox;
    }

    for (int i = tam / 2; i < tam; i++)
    {
        item = aux->item;
        InsereListaUltimo(lista5, &item);
        aux = aux->prox;
    }
}

void OrdenaLista(TipoLista *lista)
{
    Apontador aux1, aux2;
    TipoItem item;
    aux1 = lista->primeiro->prox;
    while (aux1 != NULL)
    {
        aux2 = aux1->prox;
        while (aux2 != NULL)
        {
            if (aux1->item.id > aux2->item.id)
            {
                item = aux1->item;
                aux1->item = aux2->item;
                aux2->item = item;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
}

void IntercalaListasOrdenadas(TipoLista *lista4, TipoLista *lista5, TipoLista *lista6)
{
    Apontador aux1, aux2;
    TipoItem item;
    OrdenaLista(lista4);
    OrdenaLista(lista5);
    aux1 = lista4->primeiro->prox;
    aux2 = lista5->primeiro->prox;
    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->item.id < aux2->item.id)
        {
            item = aux1->item;
            InsereListaUltimo(lista6, &item);
            aux1 = aux1->prox;
        }
        else
        {
            item = aux2->item;
            InsereListaUltimo(lista6, &item);
            aux2 = aux2->prox;
        }
    }
    while (aux1 != NULL)
    {
        item = aux1->item;
        InsereListaUltimo(lista6, &item);
        aux1 = aux1->prox;
    }
    while (aux2 != NULL)
    {
        item = aux2->item;
        InsereListaUltimo(lista6, &item);
        aux2 = aux2->prox;
    }
}

void InverterLista(TipoLista *lista6, TipoLista *lista7)
{
    Apontador aux;
    TipoItem item;
    aux = lista6->primeiro->prox;
    while (aux != NULL)
    {
        item = aux->item;
        InsereListaPrimeiro(lista7, &item);
        aux = aux->prox;
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista1, lista2, lista3, lista4, lista5, lista6, lista7;
    TipoItem item;

    CriaListaVazia(&lista1); // Lista com 2 elementos
    CriaListaVazia(&lista2); // Lista com 2 elementos
    CriaListaVazia(&lista3); // Lista que receberá a concatenação das listas 1 e 2
    CriaListaVazia(&lista4); // Lista que receberá a primeira metade da lista 3
    CriaListaVazia(&lista5); // Lista que receberá a segunda metade da lista 3
    CriaListaVazia(&lista6); // Lista que receberá a intercalação das listas 4 e 5
    CriaListaVazia(&lista7); // Lista que receberá a inversão da lista 6

    item.id = 1;
    strcpy(item.nome, "Eduardo");
    InsereListaUltimo(&lista1, &item);

    item.id = 2;
    strcpy(item.nome, "Verônica");
    InsereListaUltimo(&lista1, &item);

    item.id = 3;
    strcpy(item.nome, "Maria");
    InsereListaUltimo(&lista2, &item);

    item.id = 4;
    strcpy(item.nome, "João");
    InsereListaUltimo(&lista2, &item);

    int opcao;

    do
    {
        system("cls");
        Menu();
        cout << "Opção: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            system("cls");
            cout << "------------------------------------\n";
            cout << "     Lista Duplamente Encadeada     \n";
            cout << "------------------------------------\n";
            cout << "       Concatenar duas listas       \n\n";
            ConcatenarDuasListas(&lista1, &lista2, &lista3);
            cout << "Lista 1 \n";
            ImprimeLista(lista1);
            cout << "\nLista 2 \n";
            ImprimeLista(lista2);
            cout << "\nLista 3 \n";
            ImprimeLista(lista3);
            break;
        case 2:
            system("cls");
            cout << "------------------------------------\n";
            cout << "     Lista Duplamente Encadeada     \n";
            cout << "------------------------------------\n";
            cout << "     Dividir uma lista em duas       \n\n";
            DividirUmaListaEmDuas(&lista3, &lista4, &lista5);
            cout << "Lista 3 \n";
            ImprimeLista(lista3);
            cout << "\nLista 4 \n";
            ImprimeLista(lista4);
            cout << "\nLista 5 \n";
            ImprimeLista(lista5);
            break;
        case 3:
            system("cls");
            cout << "------------------------------------\n";
            cout << "     Lista Duplamente Encadeada     \n";
            cout << "------------------------------------\n";
            cout << "  Intercalar duas listas ordenadas   \n\n";
            IntercalaListasOrdenadas(&lista4, &lista5, &lista6);
            cout << "Lista 4 \n";
            ImprimeLista(lista4);
            cout << "\nLista 5 \n";
            ImprimeLista(lista5);
            cout << "\nLista 6 \n";
            ImprimeLista(lista6);
            break;
        case 4:
            system("cls");
            cout << "------------------------------------\n";
            cout << "     Lista Duplamente Encadeada     \n";
            cout << "------------------------------------\n";
            cout << "    Inverter uma lista encadeada       \n\n";
            InverterLista(&lista6, &lista7);
            cout << "Lista 6 \n";
            ImprimeLista(lista6);
            cout << "\nLista 7 \n";
            ImprimeLista(lista7);
            break;
        }
    } while (opcao != 0);

    return 0;
}