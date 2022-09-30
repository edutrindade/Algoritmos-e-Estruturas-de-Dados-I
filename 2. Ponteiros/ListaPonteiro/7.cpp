#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int vetor[5]={1, 2, 3, 90, 5};
    int *p, x=0;

    p=&vetor[0];
    cout<<*p<<"\n";
    p=p+1;
    cout<<*p<<"\n";
    p=p+1;
    cout<<*p<<"\n";
    p=p+1;
    cout<<*p<<"\n";
    p=p+1;
    cout<<*p<<"\n";


}

