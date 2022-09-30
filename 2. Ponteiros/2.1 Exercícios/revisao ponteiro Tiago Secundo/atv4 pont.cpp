#include <iostream>
#include <windows.h>

// troca de valores com ponteiros
 
using namespace std;

void troca(int x, int y)
{
    int *pont1, *pont2, aux;

    pont1 = &x; // ponteiro1 recebendo o endereço de valor1.
    pont2 = &y;

    aux = *pont1; 
    *pont1 = *pont2; 
    *pont2 = aux;

    cout << endl;
    cout << "\n Primeiro após a troca: " << *pont1;
    cout << "\n Segundo após a troca: " << *pont2; 
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int valor1, valor2;

  cout << "\n Digite o primeiro valor: ";
  cin >> valor1;
  cout << endl;
  cout << " Digite o segundo valor: ";
  cin >> valor2;

  cout << "\n Valor do primeiro: " << valor1;
  cout << "\n Valor do segundo: " << valor2;

  troca(valor1, valor2);


 
 
  cout << endl;
  return 0;
}