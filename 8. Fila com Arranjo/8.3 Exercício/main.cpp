#include <iostream>
#include <windows.h>
#include "Fila.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao;

    TipoFila f;
    TipoItem i;

    FazFilaVazia(&f);

    do
    {
        Menu();
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");
            cout << "NOVO ATENDIMENTO\n\n";
            if (VerificaFilaCheia(&f))
            {
                cout << "Fila Cheia.\n";
                Sleep(1000);
                break;
            }
            cin.ignore();
            cout << "Nome: ";
            cin.getline(i.nome, 30);
            cout << "Telefone: ";
            cin.getline(i.telefone, 15);
            cout << "Solicitação: ";
            cin.getline(i.solicitacao, 60);
            Enfileira(&f, i);
            cout << "\nCadastro realizado com sucesso!\n\n";
            Sleep(1000);
            break;
        case 2:
            system("cls");
            cout << "FILA DE ATENDIMENTOS\n\n";
            ExibeFila(&f);
            cout << "TOTAL DE PESSOAS: " << f.tamanho << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "PRÓXIMO ATENDIMENTO\n\n";
            Desenfileira(&f, &i);
            cout << "Nome: " << i.nome << endl;
            cout << "Telefone: " << i.telefone << endl;
            cout << "Solicitação: " << i.solicitacao << endl;
            system("pause");
            cout << "Atendimento realizado com sucesso!\n\n";
            system("pause");
            break;
        default:
            break;
        }
    } while (opcao != 4);

    return 0;
}