#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

void Menu()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "        Cadastro de Alunos       \n";
    cout << "--------------------------------\n";
    cout << "1. Criar Lista\n";
    cout << "2. Verifica Lista Vazia\n";
    cout << "3. Verifica Lista Cheia\n";
    cout << "4. Cadastro de Aluno\n";
    cout << "5. Imprime por Turma\n";
    cout << "6. Pesquisa Aluno\n";
    cout << "7. Remove Aluno\n";
    cout << "0. Sair\n\n";
}

void Cadastro(TipoItem *aluno)
{
    cout << "Nome: ";
    cin >> aluno->nome;
    cout << "Matricula: ";
    cin >> aluno->matricula;
    cout << "Turma: ";
    cin >> aluno->turma;
    cout << "P1: ";
    cin >> aluno->p1;
    cout << "P2: ";
    cin >> aluno->p2;
    cout << "P3: ";
    cin >> aluno->p3;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    TipoItem aluno;
    int opcao, ret;
    char turma;

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
            if (VerificaListaCheia(&lista))
                cout << "Lista cheia!";
            else
                cout << "A lista não está cheia ou não foi inicializada.";
            Sleep(1500);
            break;
        case 4:
            // Função de cadastro
            Cadastro(&aluno);
            ret = InsereItem(&lista, aluno);
            if (ret == 1)
            {
                cout << "Aluno cadastrado com sucesso!";
                Sleep(500);
            }
            else if (ret == -1)
            {
                cerr << "ERRO ao cadastrar o aluno. Lista cheia.";
                Sleep(1000);
            }
            else
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
            }
            break;
        case 5:
            if (listaCriada)
            {
                char turma;
                cout << "Turma: ";
                cin >> turma;
                ImprimeTurma(&lista, turma);
            }
            else
            {
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
            }
            break;
        case 6:
            if (listaCriada)
            {
                char matricula[12];
                cout << "Matricula: ";
                cin >> matricula;
                ret = PesquisaItem(&lista, matricula);
                if (ret >= 0)
                {
                    cout << "Matrícula encontrada na posição " << ret << endl;
                    Sleep(1000);
                    ImprimeItem(&lista, ret);
                }
                else
                {
                    cout << "A matrícula não está cadastrada.";
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
                char matricula[12];
                cout << "Matricula: ";
                cin >> matricula;
                ret = PesquisaItem(&lista, matricula);
                if (ret >= 0)
                {
                    cout << "Matrícula encontrada na posição " << ret;
                    Sleep(1000);
                    cout << "\n\nRemovendo...";
                    RetiraItem(ret, &lista, &aluno);
                    Sleep(1000);
                }
                else
                {
                    cout << "A matrícula não está cadastrada.";
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
