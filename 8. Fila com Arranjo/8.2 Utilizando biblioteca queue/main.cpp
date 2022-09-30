#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> fila;

    // Enfileira de 1 a 10
    for (int i = 1; i <= 10; i++)
        fila.push(i);

    // Desenfileira e imprime enquanto existir elementos na fila
    while (!fila.empty())
    {
        cout << fila.front() << " ";
        fila.pop();
    }

    return 0;
}