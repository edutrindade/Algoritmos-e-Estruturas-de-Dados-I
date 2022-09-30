#include <iostream>

using namespace std;

#define MAX_TAM 5

void preencheVetor(char *vetor, char elemento);
void imprimeVetor(char *vetor);

int main()
{
    char vetor[MAX_TAM];

    preencheVetor(vetor, 'a');
    imprimeVetor(vetor);

    return 0;
}

void preencheVetor(char *vetor, char elemento)
{
    for (int i = 0; i < MAX_TAM; i++)
    {
        int numeroElemento = ((int)elemento) + i; // Transforma o character em ascii e acrescenta o valor 'i' pra dar seguimento no ascii
        *(vetor + i) = numeroElemento;            // Envia o ascii pro elemento e o converte automaticamente para char
    }
}

void imprimeVetor(char *vetor)
{
    for (int i = 0; i < MAX_TAM; i++)
    {
        cout << *(vetor + i) << " ";
    }
}
