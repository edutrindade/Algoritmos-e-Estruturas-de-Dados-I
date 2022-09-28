#include <iostream>
#include "Fila.cpp"

using namespace std;

int main()
{
    TipoFila fila;
    TipoItem item;

    FazFilaVazia(&fila);

    item.id = 1;
    Enfileira(&fila, item);
    item.id = 2;
    Enfileira(&fila, item);
    item.id = 3;
    Enfileira(&fila, item);

    ExibeFila(&fila);
    cout << "\nTamanho da fila: " << Tamanho(&fila) << endl;

    Desenfileira(&fila, &item);
    cout << "\nValor desenfileirado: " << item.id << endl;

    ExibeFila(&fila);
    cout << "\nTamanho da fila: " << Tamanho(&fila) << endl;

    return 0;
}