#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v1.insert(v1.begin() + 1, 15);
    v1.insert(v1.end() - 1, 25);

    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    return 0;
}