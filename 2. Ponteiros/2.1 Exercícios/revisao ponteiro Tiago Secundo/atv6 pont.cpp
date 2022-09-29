#include <iostream>
#include <windows.h>

// Imprimindo o dobro do valor lido com ponteiros
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int array[5], *pont;


        cout << "\n Digite um número: ";
        cin >> array[1];

        pont = &array[1];

        *pont = *pont * 2;

        cout << "\n Dobro do valor: " << *pont << endl;
        system ("pause");

        system("cls");
        cout << "\n Digite um número: ";
        cin >> array[2];

        pont = &array[2];

        *pont = *pont * 2;

        cout << "\n Dobro do valor: " << *pont << endl;
        system("pause");

        system("cls");
        cout << "\n Digite um número: ";
        cin >> array[3];

        pont = &array[3];

        *pont = *pont * 2;

        cout << "\n Dobro do valor: " << *pont << endl;
        system("pause");

        system("cls");
        cout << "\n Digite um número: ";
        cin >> array[4];

        pont = &array[4];

        *pont = *pont * 2;

        cout << "\n Dobro do valor: " << *pont << endl;
        system("pause");

        system("cls");
        cout << "\n Digite um número: ";
        cin >> array[5];

        pont = &array[5];

        *pont = *pont * 2;

        cout << "\n Dobro do valor: " << *pont << endl;

 
  cout << endl;
  return 0;
}