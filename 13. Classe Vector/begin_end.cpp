#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1, v2;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    v1.swap(v2);

    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    cout << "\nv2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    return 0;
}