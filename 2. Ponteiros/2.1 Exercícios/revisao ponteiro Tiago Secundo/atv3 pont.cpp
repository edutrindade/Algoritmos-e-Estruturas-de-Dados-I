#include <iostream> 

using namespace std;

int main (){
int a1=0, b2 = 0, *a, *b;
cin >> a1;
cin >> b2;
a = &a1;
b = &b2;

cout << a << endl << b << endl;

if (&a > &b)
cout<<  *a << endl;

else if (&b > &a)
cout << *b << endl;

    return 0;
}