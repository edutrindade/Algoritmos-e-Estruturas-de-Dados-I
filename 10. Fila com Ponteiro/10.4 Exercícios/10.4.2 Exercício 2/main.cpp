#include <iostream>
#include "Fila.cpp"

using namespace std;

int main()
{
    cout << "Fila com Prioridade" << endl;

    TipoFila fila;
    TipoItem item;

    InicializaFila(&fila);

    item.valor = 1;
    Enfileira(&fila, item);

    item.valor = 2;
    Enfileira(&fila, item);

    item.valor = 3;
    item.prioridade = true;
    EnfileiraPrioridade(&fila, item);

    item.valor = 4;
    Enfileira(&fila, item);

    item.valor = 5;
    item.prioridade = true;
    EnfileiraPrioridade(&fila, item);

    ImprimeFila(&fila);

    return 0;
}