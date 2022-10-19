#include <iostream>
#include "Pilha.cpp"

using namespace std;

int main()
{
    TipoPilha pilha;
    TipoItem binario;

    int numerador, resto;

    FazPilhaVazia(&pilha);

    cout << "Digite um numero inteiro: ";
    cin >> numerador;

    while (numerador > 0)
    {
        resto = numerador % 2;
        numerador = numerador / 2;
        binario.valor = resto;
        Empilha(&pilha, binario);
    }

    ExibePilha(&pilha);

    return 0;
}