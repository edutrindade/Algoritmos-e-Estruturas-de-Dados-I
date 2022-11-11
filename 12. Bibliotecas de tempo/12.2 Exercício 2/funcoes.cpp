#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include "lista.hpp"

using namespace std;

void Menu();
void CadastraCarro(Carro *carro);
void RetiraCarro(TipoLista *lista, Carro *carro);
void ListarCarros(TipoLista lista);
bool PesquisaCarro(TipoLista lista, char placa[]);
void CalculaValor(Carro *carro);

void menu()
{
    system("cls");
    cout << "Estacionamento\n\n";
    cout << "1 - Registrar entrada\n";
    cout << "2 - Registrar saída\n";
    cout << "3 - Listar carros estacionados\n";
    cout << "4 - Sair\n";
}

void CadastraCarro(Carro *carro)
{
    cout << "Registro de entrada\n";
    cout << "----------------\n";
    cout << "Placa: ";
    cin >> carro->placa;
    carro->horaChegada = time(NULL);
}

void RetiraCarro(TipoLista *lista, Carro *carro)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Estacionamento vazio!\n";
        Sleep(1000);
    }
    else
    {
        cout << "Registro de saída\n";
        cout << "----------------\n";
        cout << "Placa: ";
        cin >> carro->placa;
        if (PesquisaCarro(*lista, carro->placa))
        {
            carro->horaSaida = time(NULL);
            CalculaValor(carro);
            cout << "Valor a pagar: R$ " << fixed << setprecision(2) << carro->valor << endl;
            Sleep(1000);
            cout << "Deseja retirar o carro? (s/n) ";
            char opcao;
            cin >> opcao;
            if (opcao == 's' || opcao == 'S')
            {
                RemoveCarroPorPlaca(lista, carro->placa);
                cout << "Carro retirado com sucesso!\n";
                Sleep(1000);
            }
            else
            {
                cout << "Carro não retirado!\n";
                Sleep(1000);
            }
        }
        else
        {
            cout << "Carro não encontrado!\n";
            Sleep(1000);
        }
    }
}

bool PesquisaCarro(TipoLista lista, char placa[])
{
    Apontador aux = lista.primeiro;
    while (aux != NULL)
    {
        if (strcmp(aux->item.placa, placa) == 0)
        {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void ListarCarros(TipoLista lista)
{
    cout << "Carros estacionados\n";
    cout << "-------------------\n\n";
    if (VerificaListaVazia(&lista))
    {
        cout << "Nenhum carro estacionado\n";
    }
    else
    {
        Apontador aux;
        aux = lista.primeiro->prox;
        while (aux != NULL)
        {
            cout << "Placa: " << aux->item.placa << endl;
            cout << "Hora de chegada: " << ctime(&aux->item.horaChegada) << endl;
            aux = aux->prox;
        }
    }
}

void CalculaValor(Carro *carro)
{
    double valor;
    int tempo = carro->horaSaida - carro->horaChegada;
    if (tempo <= 3600)
    {
        valor = 2.00;
    }
    else if (tempo > 3600 && tempo <= 7200)
    {
        valor = 4.00;
    }
    else if (tempo > 7200 && tempo <= 10800)
    {
        valor = 8.00;
    }
    else
    {
        valor = 8.00 + (tempo - 10800) * 0.10;
    }
    carro->valor = valor;
}