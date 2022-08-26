#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    TipoItem item;
    int opcao, ret;

    do
    {
        system("cls");
        cout << "TAD Lista com Vetor \n";
        cout << "1. Criar Lista\n";
        cout << "2. Verifica Lista Vazia\n";
        cout << "3. Verifica Lista Cheia\n";
        cout << "4. Insere Item\n";
        cout << "5. Imprime Lista\n";
        cout << "6. Pesquisa Item\n";
        cout << "7. Retira Item\n";
        cout << "0. Sair\n\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            if (!listaCriada)
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
            if (VerificaListaCheia(&lista))
                cout << "Lista cheia!";
            else
                cout << "A lista não está cheia ou não foi inicializada.";
            Sleep(1500);
            break;
        case 4:
            cout << "Chave: ";
            cin >> item.chave;
            ret = InsereItem(&lista, item);
            if (ret == 1)
            {
                cout << "Número inserido com sucesso!";
                Sleep(500);
            }
            else if (ret == -1)
            {
                cerr << "ERRO ao inserir o número. Lista cheia.";
                Sleep(1000);
            }
            else
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
            }
            break;
        case 5:
            ImprimeLista(lista);
            break;
        case 6:
            if (listaCriada)
            {
                cout << "Chave: ";
                cin >> item.chave;
                ret = PesquisaItem(&lista, item.chave);
                if (ret >= 0)
                {
                    cout << "Número encontrado na posição " << ret;
                    Sleep(1000);
                }
                else
                {
                    cout << "O número não está na lista.";
                    Sleep(1000);
                }
            }
            else
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
            }
            break;
        case 7:
            if (listaCriada)
            {
                cout << "Chave: ";
                cin >> item.chave;
                ret = PesquisaItem(&lista, item.chave);
                if (ret >= 0)
                {
                    cout << "Número encontrado na posição " << ret;
                    Sleep(1000);
                    cout << "\n\nRemovendo...";
                    RetiraItem(ret, &lista, &item);
                    Sleep(1000);
                }
                else
                {
                    cout << "O número não está na lista.";
                    Sleep(1000);
                }
            }
            else
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
            }
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}
