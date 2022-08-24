#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int sumNumbers()
{
    int sum[3];
    int total = 0;

    ifstream file;
    file.open("numeros.txt");

    if (!file.is_open())
    {
        cerr << "ERRO! Não foi possível abrir o arquivo.\n";
        file.clear();
    }

    cout << "Números lidos do arquivo numeros.txt: \n";
    for (int i = 0; i < 3; i++)
    {
        file >> sum[i];
        cout << sum[i] << endl;
        total += sum[i];
    }
    return total;
}

void printResult(int sum)
{
    ofstream file;
    file.open("soma.dat");

    if (file.is_open())
    {
        cout << "\nArquivo soma.dat criado com sucesso!\n";
    }

    file << sum;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int sum = 0;
    const int rows = 3;

    sum = sumNumbers();

    cout << "\nSoma dos números: " << sum;

    printResult(sum);
    return 0;
}
