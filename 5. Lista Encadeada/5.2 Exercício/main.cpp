#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

void Menu()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "        AGENDA TELEFÔNICA       \n";
    cout << "--------------------------------\n";
    cout << "1. Novo contato\n";
    cout << "2. Listar contatos\n";
    cout << "3. Buscar contato\n";
    cout << "4. Excluir contato\n";
    cout << "0. Sair\n";
}

void Escolher()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "        Opção editar      \n";
    cout << "--------------------------------\n";
    cout << "1. Nome\n";
    cout << "2. Telefone\n";
    cout << "3. Celular\n";
    cout << "4. Email\n";
    cout << "5. Aniversário\n";
    cout << "0. Sair\n";
}

bool VerificaMes(int mes)
{
    if (mes < 1 || mes > 12)
    {
        return false;
    }
    return true;
}

bool VerificaDia(int dia, int mes)
{
    if (dia < 1 || dia > 31)
    {
        return false;
    }
    if (mes == 2 && dia > 28)
    {
        return false;
    }
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        return false;
    }
    return true;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    TipoItem item;
    int opcao, ret;
    char op;

    CriaListaVazia(&lista);

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
            cout << "--------------------------------\n";
            cout << "        AGENDA TELEFÔNICA       \n";
            cout << "--------------------------------\n";
            cout << "Novo contato\n";
            cout << "--------------------------------\n";
            cout << "Nome: ";
            strcpy(item.nome, "Eduardo");
            // cin >> item.nome;
            cout << "Telefone: ";
            strcpy(item.telefone, "(38)999705297");
            // cin >> item.telefone;
            cout << "Celular: ";
            strcpy(item.celular, "(38)999705297");
            // cin >> item.telefone;
            cout << "E-mail: ";
            strcpy(item.email, "eduardo.trindade@ifmg.edu.br");
            // cin >> item.email;
            cout << "\nData de aniversário\n";
            do
            {
                cout << "Mês: ";
                cin >> item.aniversario.mes;
                if (!VerificaMes(item.aniversario.mes))
                {
                    cout << "\nMês inválido!\n";
                    Sleep(1500);
                }
            } while (!VerificaMes(item.aniversario.mes));
            do
            {
                cout << "Dia: ";
                cin >> item.aniversario.dia;
                if (!VerificaDia(item.aniversario.dia, item.aniversario.mes))
                {
                    cout << "\nO mês " << item.aniversario.mes << " não possui o dia " << item.aniversario.dia << ".\n";
                    Sleep(1500);
                }
            } while (!VerificaDia(item.aniversario.dia, item.aniversario.mes));
            InsereListaUltimo(&lista, &item);
            break;
        case 2:
            system("cls");
            cout << "--------------------------------\n";
            cout << "        AGENDA TELEFÔNICA       \n";
            cout << "--------------------------------\n";
            cout << "Listar contato(s)\n";
            cout << "--------------------------------\n";
            ImprimeLista(lista);
            break;
        case 3:
            system("cls");
            cout << "--------------------------------\n";
            cout << "        AGENDA TELEFÔNICA       \n";
            cout << "--------------------------------\n";
            cout << "Buscar contato\n";
            cout << "--------------------------------\n";
            cout << "Nome: ";
            cin >> item.nome;
            if (PesquisaItem(&lista, item.nome))
            {
                ImprimeItem(&lista, item.nome);
                cout << "\n--------------------------------\n";
                cout << "Deseja editar o contato? (s/n): ";
                cin >> op;
                if (op == 'S' || op == 's')
                {
                    char nome[30];
                    int escolher;
                    Escolher();
                    cout << "Opção: ";
                    cin >> escolher;
                    switch (escolher)
                    {
                    case 1:
                        cout << "Nome: ";
                        cin >> nome;
                        Atualiza(&lista, item, nome);
                        break;

                    default:
                        break;
                    }
                }
            }
            else
            {
                cout << "Contato não encontrado!\n";
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            cout << "--------------------------------\n";
            cout << "        AGENDA TELEFÔNICA       \n";
            cout << "--------------------------------\n";
            cout << "Excluir contato\n";
            cout << "--------------------------------\n";
            cout << "Nome: ";
            cin >> item.nome;
            if (PesquisaItem(&lista, item.nome))
            {
                ImprimeItem(&lista, item.nome);
                cout << "\n--------------------------------\n";
                cout << "Confirma a exclusão do contato? (s/n): ";
                cin >> op;
                if (op == 'S' || op == 's')
                {
                    RemoveItemPorNome(&lista, item.nome);
                    cout << "\nContato excluído com sucesso!\n";
                    system("PAUSE");
                }
            }
            else
            {
                cout << "Contato não encontrado!\n";
            }
            system("PAUSE");
            break;
        }
    } while (opcao != 0);
}