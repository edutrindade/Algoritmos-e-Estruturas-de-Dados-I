#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

void Menu()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "         Lista Encadeada        \n";
    cout << "--------------------------------\n";
    cout << "1. Criar Lista\n";
    cout << "2. Verifica Lista Vazia\n";
    cout << "3. Insere Item no início da lista\n";
    cout << "4. Insere Item no final da lista\n";
    cout << "5. Insere Item após um elemento X\n";
    cout << "6. Imprime Lista\n";
    cout << "7. Pesquisa Item\n";
    cout << "8. Remove Item do início da lista\n";
    cout << "9. Remove Item do final da lista\n";
    cout << "10. Remove Item por ID\n";
    cout << "11. Tamanho da Lista\n";
    cout << " 0. Sair\n\n";
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    TipoItem item;
    int opcao, ret, id;

    do
    {
        system("cls");
        Menu();
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            CriaListaVazia(&lista);
            break;
        case 2:
            if (VerificaListaVazia(&lista))
                cout << "Lista vazia!";
            else
                cout << "A lista não está vazia ou não foi inicializada.";
            Sleep(1500);
            break;
        case 3:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "ID: ";
            cin >> item.id;
            cout << "Nome: ";
            cin >> item.nome;

            InsereListaPrimeiro(&lista, &item);
            break;
        case 4:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "ID: ";
            cin >> item.id;
            cout << "Nome: ";
            cin >> item.nome;

            InsereListaUltimo(&lista, &item);
            break;
        case 5:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Deseja inserir após qual ID? ";
            cin >> id;
            cout << "\nDados para inserção:\n";
            cout << "ID: ";
            cin >> item.id;
            cout << "Nome: ";
            cin >> item.nome;

            InsereListaAposElemento(&lista, &item, id);
            break;
        case 6:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }

            ImprimeLista(lista);
            break;
        case 7:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Digite o ID do item que deseja pesquisar: ";
            cin >> id;
            ret = PesquisaItem(&lista, id);
            if (ret == -1)
            {
                cout << "Item não encontrado!";
                Sleep(1500);
            }

            ImprimeItem(&lista, ret);
            system("pause");
            break;
        case 8:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }

            RemoveListaPrimeiro(&lista);
            break;
        case 9:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }

            RemoveListaUltimo(&lista);
            break;
        case 10:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Digite o ID do item que deseja remover: ";
            cin >> id;
            ret = PesquisaItem(&lista, id);
            if (ret == -1)
            {
                cout << "Item não encontrado!";
                Sleep(1000);
                break;
            }

            cout << "\n\nRemovendo...";
            RemoveItemPorId(&lista, id);
            Sleep(1000);
            break;
        case 11:
            if (!listaCriada)
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Tamanho da lista: " << TamanhoLista(&lista);
            Sleep(1500);
            break;
        case 0:
            cout << "Saindo...";
            Sleep(1000);
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}
