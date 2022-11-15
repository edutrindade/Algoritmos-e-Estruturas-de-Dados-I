#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1(5, 10); // 5 elementos com valor 10

    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    v1.resize(10, 0);           // aumenta o tamanho para 10 elementos com valor 0
    v1.emplace(v1.begin(), 15); // insere 15 no inicio do vetor

    cout << "\nv1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    cout << "\nTamanho de v1: " << v1.size() << endl;
    cout << "\nTamanho maximo de v1: " << v1.max_size() << endl;

    return 0;
}