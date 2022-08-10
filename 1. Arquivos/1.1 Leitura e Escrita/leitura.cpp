#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file;
    string text;

    file.open("hello.txt");

    if (!file.is_open())
    {
        cerr << "ERRO! Não foi possível abrir o arquivo. O programa será encerrado.\n";
        file.clear();
        return -1;
    }

    while (!file.eof())
    {
        getline(file, text);
        cout << text << endl;
    }

    return 0;
}