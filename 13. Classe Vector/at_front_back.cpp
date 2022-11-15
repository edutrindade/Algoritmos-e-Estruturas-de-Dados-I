#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    int tam = v1.size();

    cout << "Primeiro valor de v1: " << v1.front() << endl;
    cout << "Ultimo valor de v1: " << v1.back() << endl;
    cout << "Valor do meio de v1: " << v1.at(tam / 2) << endl;

    return 0;
}