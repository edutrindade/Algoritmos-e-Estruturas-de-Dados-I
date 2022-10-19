#include <iostream>
#include <cstring>
#include "Pilha.cpp"

using namespace std;

void Menu()
{
    cout << "1. Exibe Pilha" << endl;
    cout << "2. Consulta por ID" << endl;
    cout << "3. Consulta por Nome" << endl;
    cout << "4. Sair" << endl;
    cout << "\nOpcao: ";
}

int main()
{
    TipoItem item;
    TipoPilha pilha;
    int opcao, id;

    FazPilhaVazia(&pilha);

    item.id = 1;
    strcpy(item.nome, "Joao");
    Empilha(&pilha, item);

    item.id = 2;
    strcpy(item.nome, "Maria");
    Empilha(&pilha, item);

    item.id = 3;
    strcpy(item.nome, "Jose");
    Empilha(&pilha, item);

    do
    {
        system("cls");
        Menu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << endl;
            ExibePilha(&pilha);
            cout << endl;
            system("PAUSE");
            break;
        case 2:
            cout << "Digite o ID: ";
            cin >> id;
            cout << endl;
            ConsultaPorID(&pilha, id);
            cout << endl;
            system("PAUSE");
            break;
        case 3:
            cout << "Digite o Nome: ";
            cin.ignore();
            cin.getline(item.nome, 50);
            cout << endl;
            ConsultaPorNome(&pilha, item.nome);
            cout << endl;
            system("PAUSE");
            break;
        case 4:
            cout << "Saindo..." << endl;
            break;
        }
    } while (opcao != 4);

    return 0;
}