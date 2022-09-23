#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

string binario(int n)
{
    string r;
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}

int main()
{

    ofstream decimalbinario;
    decimalbinario.open("Exercicio3.txt");
    int vetor[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Insira um valor: ";
        cin >> vetor[i];
        decimalbinario << vetor[i] << "\t" << binario(vetor[i]) << endl;
    }
    decimalbinario.close();
    return 0;
}