#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    while (!v1.empty()) // Enquanto v1 não estiver vazio
    {
        cout << "\nv1: ";
        for (int i = 0; i < v1.size(); i++)
            cout << v1[i] << " ";

        v1.erase(v1.end() - 1); // remove o ultimo elemento
    }

    v1.clear(); // limpa o vector (se existir algum elemento)
    return 0;
}