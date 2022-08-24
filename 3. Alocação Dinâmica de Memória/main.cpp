#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void preenche(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 5;
    }
}

bool pesquisa(int *vetor, int tamanho, int numero)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (numero == vetor[i])
        {
            return true;
        }
    }
    return false;
}

void imprime(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << " ";
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    int tamanho, numero, *vetor;

    cout << "Tamanho do vetor: ";
    cin >> tamanho;

    vetor = new int[tamanho];

    preenche(vetor, tamanho);

    cout << "Número a ser pesquisado: ";
    cin >> numero;

    cout << (pesquisa(vetor, tamanho, numero) ? "Número encontrado." : "Número não encontrado.") << "\n\n";

    imprime(vetor, tamanho);
    cout << endl;
    return 0;
}