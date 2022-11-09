#include <iostream>
#include <windows.h> // Sleep()
#include <ctime>     // time.h

using namespace std;

int main()
{
    clock_t t; // Variável para armazenar o tempo

    t = clock(); // Registro do tempo inicial

    Sleep(3000); // Espera de 3 segundos

    t = clock() - t; // Registro do tempo final

    cout << "Tempo em milissegundos: " << t << endl;               // Tempo em milissegundos
    cout << "Tempo em segundos: " << (t) / CLOCKS_PER_SEC << endl; // Tempo em segundos

    return 0;
}