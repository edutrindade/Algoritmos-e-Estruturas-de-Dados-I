#include <iostream>
#include <windows.h>
#include <stack>

using namespace std;

int GetBigger(stack<int> *pilha)
{
    stack<int> pilhaAux;
    int aux, maior = 0;

    while (!pilha->empty())
    {
        aux = pilha->top();
        pilha->pop();
        pilhaAux.push(aux);

        if (aux > maior)
            maior = aux;
    }

    while (!pilhaAux.empty())
    {
        pilha->push(pilhaAux.top());
        pilhaAux.pop();
    }

    return maior;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    stack<int> pilha;

    pilha.push(1);
    pilha.push(2);
    pilha.push(3);
    pilha.push(4);
    pilha.push(5);

    cout << "O maior valor presente na pilha é: " << GetBigger(&pilha);
}