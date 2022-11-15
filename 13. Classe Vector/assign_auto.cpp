#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1, v2, v3;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 = ";
    for (auto &v : v1)
    {
        cout << v << " ";
    }
    cout << endl;

    v2.assign(v1.begin(), v1.end()); // copia todo o conteudo de v1 para v2
    cout << "v2 = ";
    for (auto &v : v2)
    {
        cout << v << " ";
    }
    cout << endl;

    v3.assign(7, 4); // atribui 7 valores 4 para v3
    cout << "v3 = ";
    for (auto &v : v3)
    {
        cout << v << " ";
    }
    cout << endl;

    v3.assign({5, 6, 7}); // atribui os valores 5, 6 e 7 para v3
    cout << "v3 = ";
    for (auto &v : v3)
    {
        cout << v << " ";
    }
    cout << endl;
}