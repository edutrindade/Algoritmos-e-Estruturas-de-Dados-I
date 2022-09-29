#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a, b, *aa, *bb;

    cout<<"Insira o valor da primeira variavel: ";
    cin>>a;
    cout<<"Insira o valor da segunda variavel:  ";
    cin>>b;

    aa=&a;
    bb=&b;

    if(*aa>*bb){
        cout<<"Endereço 1:  "<<aa<<endl;
        cout<<"Endereço 2:  "<<bb<<endl;
        cout<<"Variavel 1 e maior: "<<*aa<<endl;
        cout<<"variavel dois:           "<<*bb<<endl;
    }else{
        cout<<"Endereço 1:  "<<aa<<endl;
        cout<<"Endereço 2:  "<<bb<<endl;
        cout<<"Variavel dois e maior: "<<*aa<<endl;
        cout<<"variavel um:           "<<*bb<<endl;
    }
}

