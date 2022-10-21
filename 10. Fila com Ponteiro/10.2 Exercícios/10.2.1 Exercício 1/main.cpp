#include <iostream>
#include <windows.h>
#include "fila.cpp"

using namespace std;

void menu();
void InsereContato(TipoFila *fila);
void ProximoContato(TipoFila *fila);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    TipoFila f;
    TipoItem i;

    InicializaFila(&f);

    if (VerificaFilaVazia(&f))
    {
        cout << "Fila vazia.\n\n";
    }

    int opcao;
    do
    {
        system("cls");
        menu();
        while ((cout << "Escolha a opção: ") && !(cin >> opcao))
        {
            cout << "Digite uma opção válida.\n\n";
            cin.clear();
            cin.ignore();
        }
        system("cls");
        switch (opcao)
        {
        case 1:
            InsereContato(&f);
            break;
        case 2:
            ProximoContato(&f);
            break;
        case 3:
            system("cls");
            cout << "Fila de Atendimentos:\n\n";
            ImprimeFila(&f);
            system("PAUSE");
            break;
        }
    } while (opcao != 4);

    return 0;
}

void menu()
{
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        �                         CALL CENTER                          �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 1 - INSERIR CONTATO                                          �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 2 - PRÓXIMO CONTATO                                          �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 3 - FILA DE ATENDIMENTOS                                     �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 4 - SAIR                                                     �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������\n\n";
}

void InsereContato(TipoFila *fila)
{
    TipoItem i;
    cout << "***********************************\n";
    cout << "        CADASTRO DE CONTATO        \n";
    cout << "***********************************\n\n";
    cin.ignore();
    cout << "Nome: ";
    cin.getline(i.nome, 20);
    cout << "Telefone: ";
    cin.getline(i.telefone, 15);
    cout << "Solicitação: ";
    cin.getline(i.solicitacao, 100);

    Enfileira(fila, i);

    cout << "\nContato registrado com sucesso!\n\n";
    Sleep(1000);
    system("cls");
}

void ProximoContato(TipoFila *fila)
{
    cout << "***********************************\n";
    cout << "        PRÓXIMO ATENDIMENTO        \n";
    cout << "***********************************\n\n";

    ImprimeProximo(fila);

    system("PAUSE");
    system("cls");
}