#include <iostream>
#include <iomanip>

using namespace std;

int soma(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b+aux;
    
}

int main(){
    int a, b;

    cout<<"Digite os numeros: ";
    cin>>a>>b;


    soma(&a, &b);

    cout<<"Valor a somado com b: "<<a<<endl;
    cout<<"Valor b:              "<<b<<endl;

}

