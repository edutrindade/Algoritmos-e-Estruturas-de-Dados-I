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
    cout << "             EDIÇÃO             \n";
    cout << "--------------------------------\n";
    cout << "1. Nome\n";
    cout << "2. Telefone\n";
    cout << "3. Celular\n";
    cout << "4. E-mail\n";
    cout << "5. Aniversário\n";
    cout << "0. Voltar\n";
}

void Busca()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "       PESQUISAR CONTATO        \n";
    cout << "--------------------------------\n";
    cout << "1. ID\n";
    cout << "2. Nome\n";
    cout << "0. Voltar\n";
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

void Edicao(TipoLista *lista, TipoItem item)
{
    char op;
    cout << "\n--------------------------------\n";
    cout << "Deseja editar o contato? (s/n): ";
    cin >> op;
    int escolher;
    if (op == 'S' || op == 's')
    {
        do
        {
            char nome[30], telefone[15], celular[15], email[40];
            int dia, mes;

            Escolher();
            cout << "Opção: ";
            cin >> escolher;
            switch (escolher)
            {
            case 1:
                cout << "\nNome: " << item.nome << " -> ";
                cin >> nome;
                Atualiza(lista, item, nome, 1);
                cout << "\nNome atualizado com sucesso!\n";
                system("PAUSE");
                break;
            case 2:
                cout << "\nTelefone: " << item.telefone << " -> ";
                cin >> telefone;
                Atualiza(lista, item, telefone, 2);
                cout << "\nTelefone atualizado com sucesso!\n";
                system("PAUSE");
                break;
            case 3:
                cout << "\nCelular: " << item.celular << " -> ";
                cin >> celular;
                Atualiza(lista, item, celular, 3);
                cout << "\nCelular atualizado com sucesso!\n";
                system("PAUSE");
                break;
            case 4:
                cout << "E-mail: " << item.email << " -> ";
                cin >> email;
                Atualiza(lista, item, email, 4);
                cout << "\nE-mail atualizado com sucesso!\n";
                system("PAUSE");
                break;
            case 5:
                cout << "\nData de aniversário\n";
                do
                {
                    cout << "Mês: " << item.aniversario.mes << " -> ";
                    cin >> mes;
                    if (!VerificaMes(mes))
                    {
                        cout << "\nMês inválido!\n";
                        Sleep(1500);
                    }
                } while (!VerificaMes(mes));
                do
                {
                    cout << "Dia: " << item.aniversario.dia << " -> ";
                    cin >> dia;
                    if (!VerificaDia(dia, mes))
                    {
                        cout << "\nO mês " << mes << " não possui o dia " << dia << ".\n";
                        Sleep(1500);
                    }
                } while (!VerificaDia(dia, mes));
                AtualizaAniversario(lista, item, dia, mes);
                cout << "\nData de aniversário atualizada com sucesso!\n";
                system("PAUSE");
                break;
            default:
                break;
            }
        } while (escolher != 0);
    }
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
            item.id = id;
            // strcpy(item.nome, "Eduardo");
            cin >> item.nome;
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
            int opcaoBusca, cod;
            char nome[30];
            do
            {
                Busca();
                cout << "\nOpção: ";
                cin >> opcaoBusca;
                switch (opcaoBusca)
                {
                case 1:
                    cout << "ID: ";
                    cin >> cod;
                    if (PesquisaItemPorId(&lista, cod))
                    {
                        cout << endl;
                        ImprimeItemPorId(&lista, cod);
                        Edicao(&lista, item);
                    }
                    else
                    {
                        cout << "Contato não encontrado!\n";
                        system("PAUSE");
                    }
                    break;
                case 2:
                    cout << "Nome: ";
                    cin >> nome;
                    if (PesquisaItem(&lista, nome))
                    {
                        cout << endl;
                        ImprimeItem(&lista, nome);
                        Edicao(&lista, item);
                    }
                    else
                    {
                        cout << "Contato não encontrado!\n";
                        system("PAUSE");
                    }
                    break;
                default:
                    break;
                }
            } while (opcaoBusca != 0);

            system("PAUSE");
            break;
        case 4:
            system("cls");
            cout << "--------------------------------\n";
            cout << "        AGENDA TELEFÔNICA       \n";
            cout << "--------------------------------\n";
            cout << "Excluir contato\n";
            cout << "--------------------------------\n";
            unsigned int codigo;
            cout << "ID: ";
            cin >> codigo;
            if (PesquisaItemPorId(&lista, codigo))
            {
                ImprimeItemPorId(&lista, codigo);
                cout << "\n--------------------------------\n";
                cout << "Confirma a exclusão do contato? (s/n): ";
                cin >> op;
                if (op == 'S' || op == 's')
                {
                    RemoveItemPorId(&lista, codigo);
                    cout << "\nContato excluído com sucesso!\n";
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