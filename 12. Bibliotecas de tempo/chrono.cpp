#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    steady_clock::time_point t1 = steady_clock::now(); // Registro do tempo inicial

    cout << "Imprimindo 1.000.000 de estrelas..." << endl;

    for (int i = 0; i < 1000000; i++)
        cout << "*";

    steady_clock::time_point t2 = steady_clock::now(); // Registro do tempo final

    cout << "\n\nTempo em milissegundos: " << duration_cast<milliseconds>(t2 - t1).count() << endl;
    cout << "Tempo em segundos: " << duration_cast<seconds>(t2 - t1).count() << endl;

    return 0;
}