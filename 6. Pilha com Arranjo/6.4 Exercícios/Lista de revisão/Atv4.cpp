#include <iostream>
#include <windows.h>
#include <stack>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  stack <int> pilha1;
 
    int r, n;

    cout<<"Digite o número a ser convertido: ";
    cin>>n;
    
    system("cls");

    while(n != 0){
    r = ( n % 2 == 0 ? 0 : 1);
    n /= 2;
    pilha1.push(r);
    }
    
    while(!pilha1.empty()){
    cout<<pilha1.top()<<endl;
    pilha1.pop();
    }
    
  cout << endl;
  return 0;
}