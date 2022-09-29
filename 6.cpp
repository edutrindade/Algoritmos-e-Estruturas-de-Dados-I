#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int vetor[5]={1, 2, 3, 4, 5};
    int *p, x=0;

    while(x<5){
        p=&vetor[x];
        cout<<*p+*p<<"\n";
        x++;
    }


}

