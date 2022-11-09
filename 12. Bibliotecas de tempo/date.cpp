#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t t;
    struct tm *infoTempo;
    char buffer[20];

    time(&t);

    cout << "t (timestamp)= " << t << endl;             // Timestamp
    cout << "Data e hora local: " << ctime(&t) << endl; // Data e hora local

    infoTempo = localtime(&t);

    cout << "Data e hora local: " << asctime(infoTempo) << endl; // Data e hora local

    strftime(buffer, 20, "%d/%m/%y", infoTempo); // Apenas a data

    cout << buffer;

    return 0;
}