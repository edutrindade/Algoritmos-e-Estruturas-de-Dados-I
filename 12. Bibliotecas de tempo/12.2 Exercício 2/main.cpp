#include <iostream>
#include <windows.h>
#include <ctime>
#include "lista.hpp"
#include "lista.cpp"
#include "funcoes.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    Carro carro;

    AbreEstacionamento(&lista);

    int opcao;
    do
    {
        menu();
        cout << "\nOpção: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            system("cls");
            CadastraCarro(&carro);
            InsereListaUltimo(&lista, &carro);
            cout << "Carro registrado com sucesso!\n";
            system("pause");
            break;
        case 2:
            system("cls");
            RetiraCarro(&lista, &carro);
            system("pause");
            break;
        case 3:
            system("cls");
            ListarCarros(lista);
            system("pause");
            break;
        case 4:
            cout << "Sair\n";
            break;
        default:
            cout << "Opção inválida\n";
            break;
        }
    } while (opcao != 4);

    cout << endl;
    return 0;
}