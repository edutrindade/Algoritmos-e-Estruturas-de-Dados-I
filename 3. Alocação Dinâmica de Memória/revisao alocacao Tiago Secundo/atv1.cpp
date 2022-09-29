#include <iostream>

using namespace std;

void preencheVetor(int *vetor, int n);

int main()
{
    int n;
    cout << "Digite o valor de N: ";
    cin >> n;

    int *vetor = new int[n]; // Aloca na memória

    preencheVetor(vetor, n);

    for (int i = 0; i < n; i++)
    {
        cout << *(vetor + i) << " ";
    }

    delete vetor; // Desaloca o vetor da memória
    return 0;
}

void preencheVetor(int *vetor, int n)
{
    int valor;
    cout << "Preencha o vetor de " << n << " elementos" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> valor;
        *(vetor + i) = valor;
    }
}
