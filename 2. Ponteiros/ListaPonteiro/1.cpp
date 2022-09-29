#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int x=10, *px;
    char c='t', *pc;
    float a=10, *pa;

    px=&x;
    pc=&c;
    pa=&a;

    cout<<"Int:   "<<x<<endl;
    cout<<"char:  "<<c<<endl;
    cout<<"float: "<<a<<endl;

    cout<<"\nNovo int:    ";
    cin>>*px;
    cout<<"\nNovo char:   ";
    cin>>*pc;
    cout<<"\nNovo float:  ";
    cin>>*pa;

    cout<<"Int:   "<<x<<endl;
    cout<<"char:  "<<c<<endl;
    cout<<"float: "<<a<<endl;

}

