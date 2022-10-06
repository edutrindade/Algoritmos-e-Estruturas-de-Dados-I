#include <iostream>
#include <windows.h>
#include <stack>
#include <queue>

using namespace std;

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    stack <int> P;
    queue <int> F;
    int aux;

    F.push(1);
    F.push(2);
    F.push(3);
    F.push(4);
    F.push(5);

    cout<<"FILA "<<endl;

   while(!F.empty()){
    cout<<F.front()<<endl;
    aux = F.front();
    P.push(aux);
    F.pop();
   }
    cout<<"\nPILHA ";

   while(!P.empty()){
    cout<<"\n"<<P.top();
    aux = P.top();
    F.push(aux);
    P.pop();
   }

     cout<<"\n\nFILA INVERTIDA";
    while(!F.empty()){
        cout<<"\n"<<F.front();
        F.pop();
    }
return 0;
}
