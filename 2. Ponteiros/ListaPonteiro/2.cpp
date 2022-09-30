#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a, b, *aa, *bb;

    aa=&a;
    bb=&b;

    if(aa>bb){
        cout<<"Endereço um e maior: "<<aa<<endl;
        cout<<"Endereço dois:       "<<bb<<endl;
    }else{
        cout<<"Endereço dois e maior: "<<aa<<endl;
        cout<<"Endereço um:           "<<bb<<endl;
    }
}

