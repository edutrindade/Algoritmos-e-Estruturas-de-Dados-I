#include <iostream>
#include <windows.h>
#include <time.h>
 
using namespace std;

void preenche(int *vetor, int tamanho) {
    for (int i=0; i<tamanho; i++) {
        vetor[i] = rand()%5;
    }
}

int pesquisa(int *vetor, int tamanho, int numero) {
    for (int i=0; i<tamanho; i++) {
        if (numero == vetor[i]) {
            return 1;
        }
    }
    return 0;
}

void imprime(int *vetor, int tamanho) {
    for (int i=0; i<tamanho; i++) {
        cout << vetor[i] << " ";
    }
}
 
int main() {
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

    if (pesquisa(vetor, tamanho, numero) == 1) {
        cout << "Número encontrado.\n\n";
    } else {
        cout << "Número não encontrado.\n\n";
    }

    imprime(vetor, tamanho);
    cout << endl;
    return 0;
}