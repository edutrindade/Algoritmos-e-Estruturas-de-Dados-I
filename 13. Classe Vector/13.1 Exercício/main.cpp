#include <iostream>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    vector<int> v1, v2;

    // Sorteia 20 números entre 0 e 9 e armazena em v1
    for (int i = 0; i < 20; i++)
        v1.push_back(rand() % 10);

    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    // Remove os pares e multiplica os ímpares pelo tamanho de v1
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] % 2 == 0)
        {
            v1.erase(v1.begin() + i);
            i--;
        }
        else
            v1[i] *= v1.size();
    }

    cout << "\nv1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    // Encontra o maior e o menor valor de v1
    int max = *max_element(v1.begin(), v1.end()); // max_element retorna um iterador
    int min = *min_element(v1.begin(), v1.end()); // max_element retorna um iterador

    cout << "\n\nMaior: " << max << "\nMenor: " << min << endl;

    // Encontra as posições do max e min
    int pos_max = find(v1.begin(), v1.end(), max) - v1.begin();
    int pos_min = find(v1.begin(), v1.end(), min) - v1.begin();

    cout << "\nPosição do maior: " << pos_max << "\nPosição do menor: " << pos_min << endl;

    // Identifica se a posição do maior valor vem antes ou depois do menor valor para inserir os valores entre eles em v2
    if (pos_max > pos_min)
    {
        for (int i = pos_min; i <= pos_max; i++)
            v2.push_back(v1[i]);
    }
    else
    {
        for (int i = pos_max; i <= pos_min; i++)
            v2.push_back(v1[i]);
    }

    cout << "\nv2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    sort(v2.begin(), v2.end());

    cout << "\nv2 ordenado: ";

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    return 0;
}
