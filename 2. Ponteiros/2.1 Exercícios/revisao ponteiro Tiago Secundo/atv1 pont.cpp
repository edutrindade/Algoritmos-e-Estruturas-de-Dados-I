#include <iostream>

using namespace std;

int main (){
    int a=10, *a1;
    float b=5.0, *b2;
    char c1 ='c', *c3;
    a1 = &a;
    b2 = &b;
    c3 = &c1;
    cout << *a1 << endl << *b2 << endl << *c3<< endl;

    *a1 = 8;
    *b2 = 1.1;
    *c3 = 't';
    cout << *a1 << endl << *b2 << endl << *c3 << endl; 
    return 0;
}