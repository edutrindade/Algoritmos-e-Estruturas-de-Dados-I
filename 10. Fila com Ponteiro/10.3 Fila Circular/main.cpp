#include <iostream>
#include "Fila.cpp"

using namespace std;

int main()
{
    cout << "Fila com Ponteiro" << endl;

    TipoFila fila;
    TipoItem item;

    InicializaFilaCircular(&fila);

    item.valor = 10;
    Enfileira(&fila, item);

    item.valor = 20;
    Enfileira(&fila, item);

    item.valor = 30;
    Enfileira(&fila, item);

    ImprimeFila(&fila);

    Desenfileira(&fila, &item);

    cout << "\nDesenfileirou: " << item.valor << endl
         << endl;

    ImprimeFila(&fila);

    return 0;
}