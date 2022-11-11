#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int quantidadeDePrimos(int n)
{
    int quantidade = 0;
    for (int i = 2; i <= n; i++)
    {
        bool primo = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                primo = false;
                break;
            }
        }
        if (primo)
        {
            quantidade++;
        }
    }
    return quantidade;
}

int totalPrimos(int n)
{
    int i, j, cont = 0;
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            cont++;
        }
    }
    return cont;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    time_t inicio = time(NULL);

    cout << "Quantidade de números primos: " << totalPrimos(2000) << endl;

    time_t fim = time(NULL);
    cout << "Tempo de execução: " << difftime(fim, inicio) << " segundos" << endl;
    cout << endl;
    return 0;
}