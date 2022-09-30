#include <iostream>
#include <windows.h>
#include <queue>
#include <cstring>
 
using namespace std;

#define MAXTAM 2

typedef struct{
    int idade;
    char g, nome[30];
    bool gestante = false;
}Cliente;

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  Cliente cliente;

  queue<Cliente> Fila, FilaP;

  int tamanho;
  
  for(int i = 0; i < MAXTAM; i++){
    cout<<"Digite seu nome: ";
    cin.getline(cliente.nome, 30);
    cout<<"Digite sua idade: ";
    cin>>cliente.idade;
    cout<<"Você é gestante (S/N)? ";
    cin>>cliente.g;
    
    if(cliente.g == 'S' || cliente.g == 's'){
        FilaP.push(cliente);
    }
    else if(cliente.idade > 60){
        FilaP.push(cliente);
    }
    else{
        Fila.push(cliente);
    }
    cin.ignore();

  }
  system("cls");
 
 tamanho = Fila.size();
 for(int i = 0; i < tamanho; i++){
    cout<<"Fila"<<endl;
    cout<<Fila.back().nome<<endl;
 }

  cout<<endl;
 tamanho = FilaP.size();
 for(int i = 0; i < tamanho; i++){
    cout<<"Fila Prioritária"<<endl;
    cout<<FilaP.back().nome<<endl;
 }

 
  cout << endl;
  return 0;
}