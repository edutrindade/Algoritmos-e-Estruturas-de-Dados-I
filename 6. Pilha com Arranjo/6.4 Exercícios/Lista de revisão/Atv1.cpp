#include <iostream>
#include <windows.h>
#include <stack>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  stack <char> pilha1, pilhaux;
  int tam;
  char aux, guarda;

    pilha1.push('a');
    pilha1.push('b');
    pilha1.push('c');
    pilha1.push('d');
    pilha1.push('e');
    pilha1.push('f');

    cout<<"PILHA COMPLETA"<<endl;
    while(pilha1.size() != 0){
      cout<<pilha1.top()<<endl;
      aux = pilha1.top();
      pilhaux.push(aux);
      pilha1.pop();
      cout<<endl;
    }

    cout<<"PILHA SEM O ITEM"<<endl;
    while(pilhaux.size() != 0){
      if(pilhaux.top() == 'c'){
            guarda = pilhaux.top();
            pilhaux.pop();
            pilha1.pop();
        }

        aux = pilhaux.top();
        pilha1.push(aux);
        pilhaux.pop();
        
      cout<<pilha1.top() << endl; 
          
    }
    cout<<endl<<"Item retirado: "<<guarda;
    
  cout << endl;
  return 0;
}