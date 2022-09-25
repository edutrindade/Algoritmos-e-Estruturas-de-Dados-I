#include <iostream>
#include <stack>

using namespace std;

bool VerifyEquality(stack<int> *pilha1, stack<int> *pilha2)
{
    if (pilha1->size() != pilha2->size())
        return false;

    stack<int> pilhaAux1, pilhaAux2;
    int aux1, aux2;

    while (!pilha1->empty())
    {
        aux1 = pilha1->top();
        pilha1->pop();
        pilhaAux1.push(aux1);

        aux2 = pilha2->top();
        pilha2->pop();
        pilhaAux2.push(aux2);

        if (aux1 != aux2)
            return false;
    }

    while (!pilhaAux1.empty())
    {
        pilha1->push(pilhaAux1.top());
        pilhaAux1.pop();
    }

    while (!pilhaAux2.empty())
    {
        pilha2->push(pilhaAux2.top());
        pilhaAux2.pop();
    }

    return true;
}

int main()
{
    stack<int> jogador1, jogador2;

    jogador1.push(1);
    jogador2.push(1);
    jogador1.push(2);
    jogador2.push(2);
    // jogador2.push(3); // Descomente para testar a função com pilhas diferentes

    if (VerifyEquality(&jogador1, &jogador2))
        cout << "As pilhas sao iguais" << endl;
    else
        cout << "As pilhas sao diferentes" << endl;
}