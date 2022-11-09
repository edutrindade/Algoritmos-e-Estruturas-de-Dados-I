#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    time_t t1 = time(NULL); // Registro do tempo inicial

    Sleep(3000); // Espera de 3 segundos

    time_t t2 = time(NULL); // Registro do tempo final

    cout << "t1 = " << t1 << endl; // Timestamp
    cout << "t2 = " << t2 << endl; // Timestamp

    cout << "\nDiferença de tempo em minutos: " << difftime(t2, t1) / 60 << endl;
    cout << "Diferença de tempo em segundos: " << difftime(t2, t1) << endl;
    cout << "Diferença de tempo em milisegundos: " << difftime(t2, t1) * 1000 << endl;

    if (difftime(t2, t1) >= 3)
        cout << "\nO tempo de espera foi de pelo menos 3 segundos." << endl;
    else
        cout << "\nO tempo de espera foi menor que 3 segundos." << endl;

    return 0;
}