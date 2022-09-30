#include <iostream>
#include <windows.h>

// impressão de um array com ponteiro

using namespace std;

int funcao( int *pont)
{

    pont = new int [5];

    cout << "\n Digite um número: ";
    cin >> pont[0];
    system("cls");

    cout << "\n Digite um número: ";
    cin >> pont[1];
    system("cls");

    cout << "\n Digite um número: ";
    cin >> pont[2];
    system("cls");

    cout << "\n Digite um número: ";
    cin >> pont[3];
    system("cls");

    cout << "\n Digite um número: ";
    cin >> pont[4];
    system("cls");
    
    
    cout << "\n Vetor na posição 1: " << pont[0];
    cout << "\n Vetor na posição 2: " << pont[1];
    cout << "\n Vetor na posição 3: " << pont[2];
    cout << "\n Vetor na posição 4: " << pont[3];
    cout << "\n Vetor na posição 5: " << pont[4];
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int *pont;

    funcao(pont);

    cout << endl;
    return 0;
}