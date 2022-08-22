#include <iostream>
#include <windows.h>
#define NUM_CONTAS 5

using namespace std;

typedef struct Banco
{
    int num;
    char titular[35];
    float saldo;
};

Banco cadastraConta()
{
    Banco conta;
    cout << "Número da conta: ";
    cin >> conta.num;
    cout << "Titular: ";
    cin >> conta.titular;
    cout << "Saldo: ";
    cin >> conta.saldo;
    cout << "\n";
    return conta;
}

void preencheContas(Banco contas[])
{
    for (int i = 0; i < NUM_CONTAS; i++)
    {
        contas[i] = cadastraConta();
    }
}

Banco encontraMaior(Banco contas[])
{
    Banco maior = contas[0];
    for (int i = 0; i < NUM_CONTAS; i++)
    {
        if (contas[i].saldo > maior.saldo)
        {
            maior = contas[i];
        }
    }
    return maior;
}

Banco encontraMenor(Banco contas[])
{
    Banco menor = contas[0];
    for (int i = 0; i < NUM_CONTAS; i++)
    {
        if (contas[i].saldo < menor.saldo)
        {
            menor = contas[i];
        }
    }
    return menor;
}

void imprimeConta(Banco conta)
{
    cout << "Conta: " << conta.num << endl;
    cout << "Titular: " << conta.titular << endl;
    cout << "Saldo: R$ " << conta.saldo << endl;
    cout << "\n";
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    Banco contas[NUM_CONTAS];

    preencheContas(contas);

    Banco maior_conta, menor_conta;
    maior_conta = encontraMaior(contas);
    menor_conta = encontraMenor(contas);

    system("cls");

    cout << "Conta com o maior saldo:" << endl;
    imprimeConta(maior_conta);
    cout << "Conta com o menor saldo:" << endl;
    imprimeConta(menor_conta);
    return 0;
}