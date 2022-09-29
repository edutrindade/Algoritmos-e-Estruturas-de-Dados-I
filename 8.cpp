#include <iostream>
#include <iomanip>

#define Total 5

using namespace std;

void preencheVetor(char *vetor, char elemento){
    int x=0;
    // while(Total>x){
    //     *vetor+=1;
    //     x++;
    // }
    while(Total>x){
        *vetor=elemento;
        elemento+=1;
        *vetor+=1;
        x++;
    }
};

void imprimeVetor(char *vetor){
    int x=0, i;
    char letra[Total];
    // while(Total>x){
    //     cout<<*vetor;
    //     *vetor+=2;
    //     x++;
    // }
    for(i=0; i<Total; i++){
        cout<<*vetor;
        *vetor+=1;
        // *vetor+=1;
    }
};

int main(){
    char letra[Total]={' '};
    char le;
    int *p = (int*)&letra;
    char *text = (char*)p;

    cout<<"Digite a letra: ";
    cin>>le;
    text=&letra[Total];
    letra[0]=le;

    preencheVetor(text, le);
    imprimeVetor(letra);
}

