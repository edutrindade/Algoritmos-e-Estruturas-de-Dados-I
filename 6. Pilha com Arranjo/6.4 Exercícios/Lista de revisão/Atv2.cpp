#include <iostream>
#include <windows.h>
#include <stack>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  stack <int> pilhapar, pilhaimpar, pilhadescarte;
    
    int v[10], aux1, aux2, tam;

    for(int i = 0; i < 10; i++){
        cout<<"Digite um valor: ";
        cin>>v[i];
    
        if(v[i] == 0){
            aux1 = pilhapar.top();
            aux2 = pilhaimpar.top();
            
            pilhadescarte.push(aux1);
            pilhadescarte.push(aux2);
            
            pilhapar.pop();
            pilhaimpar.pop();
        }

        else if(v[i] % 2 == 0){
            pilhapar.push(v[i]);
        }
       
        else if(v[i] % 2 == 1){
            pilhaimpar.push(v[i]);
        }
        
    }
    system("cls");
    
    tam = pilhapar.size();
    cout<<"PILHA PAR";

    for(int i = 0; i < tam; i++){
        
            cout<<"\n"<<pilhapar.top()<<endl;
            pilhapar.pop();

    }

    tam = pilhaimpar.size();
    cout<<"PILHA IMPAR";

    for(int i = 0; i < tam; i++){
        cout<<"\n"<<pilhaimpar.top()<<endl;
        pilhaimpar.pop();
    }    
    
    tam = pilhadescarte.size();
    cout<<"PILHA DE DESCARTE";
    for(int i = 0; i < tam; i++){
        
        cout<<"\n"<<pilhadescarte.top()<<endl;
        pilhadescarte.pop();
    }
 
  cout << endl;
  return 0;
}