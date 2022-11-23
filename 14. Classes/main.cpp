#include <iostream>

using namespace std;

class Data
{
public:
    void define(int d, int m, int a);
    void exibe(void);

private:
    unsigned int data;
};

void Data::define(int d, int m, int a)
{
    data = (a << 9) | (m << 5) | d;
}

void Data::exibe(void)
{
    cout << (data & 0x1F) << "/" << ((data >> 5) & 0x0F) << "/" << (data >> 9) << endl;
}

int main()
{
    Data data;

    data.define(18, 11, 2022);
    data.exibe();

    return 0;
}