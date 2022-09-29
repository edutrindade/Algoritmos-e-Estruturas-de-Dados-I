#include <iostream>
#include <iomanip>

using namespace std;

int troca(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

int main(){
    int a=10, b=20;

    cout<<"Valor a: "<<a<<"Valor b: "<<b<<" Antes da troca!"<<endl;

    troca(&a, &b);

    cout<<"Valor a: "<<a<<" Valor b: "<<b<<" depois da troca!"<<endl;

}

