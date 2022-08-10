#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file;

    file.open("hello.txt");

    if (file.fail())
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        file.clear();
        return -1;
    }

    file << "Hello World!";

    file.close();

    return 0;
}