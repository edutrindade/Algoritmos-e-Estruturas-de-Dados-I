#include <iostream>
#include <windows.h>
#include <queue>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  queue<string> FilaPrincipal, FilaAux;
  int tamanho;
  string nome, aux;

  cout<<"Digite a quantidade de pessoas que tem na fila: ";
  cin>>tamanho;
  system("cls");

  for(int i = 0; i < tamanho; i++){
    cout<<"Digite seu nome: ";
    cin>>nome;

    FilaPrincipal.push(nome);
  }
  system("cls");

    aux = FilaPrincipal.back();

    cout<<"Fila sem o FURA FILA"<<endl;

    for(int i = 0; i < tamanho; i++){

        cout<<FilaPrincipal.front()<<endl;
        FilaAux.push(FilaPrincipal.front());
        FilaPrincipal.pop();
    }

    FilaPrincipal.push(aux);
    
    cout<<"\n\nFila com o FURA FILA" << endl;

    for(int i = 0; i < tamanho; i++){
    
        FilaPrincipal.push(FilaAux.front());
        FilaAux.pop();
        cout<<FilaPrincipal.front()<<endl;
        FilaPrincipal.pop();
    }

  cout << endl;
  return 0;
}