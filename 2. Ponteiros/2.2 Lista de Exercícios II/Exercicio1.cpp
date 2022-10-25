#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int *p;
    int b = 5;
    p = &b;
    double *a;
    double c = 3.14562;
    a = &c;
    char *d;
    char e;
    e = 'p';
    d = &e;
    cout << "Valor da variavel de numero inteiro e: " << *p << endl;
    cout << "Valor da variavel de numero real e: " << *a << endl;
    cout << "Valor da variavel de caractere e: " << *d << endl;
    system("pause");
    cout << "Apos modificar as variaveis usando ponteiros os valores sao" << endl;
    *p = 30;
    *a = 6.90832;
    *d = 'G';
    cout << "Valor da variavel de numero inteiro e: " << *p << endl;
    cout << "Valor da variavel de numero real e: " << *a << endl;
    cout << "Valor da variavel de caractere e: " << *d << endl;
    return 0;
}