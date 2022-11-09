#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    long int t = chrono::system_clock::to_time_t(chrono::system_clock::now()); // Timestamp

    cout << "Timestamp (t): " << t << endl;
    cout << "Data atual: " << ctime(&t) << endl; // Data e hora local

    return 0;
}