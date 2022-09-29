#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;

typedef struct Livros{
char titulo[40], autor[40], ISBN[20];
int ano, paginas;
}Livros;

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  stack <Livros> pilha1;
 
  Livros livros;
  
  for(int i = 0; i < 5; i++){
    
    cout<<"Digite o titulo do livro: ";
    cin.getline(livros.titulo,40);

    cout<<"Digite o nome do autor: ";
    cin.getline(livros.autor, 40);

    cout<<"Digite o codigo IBSN: ";
    cin.getline(livros.ISBN, 20);

    cout<<"Digite o ano do livro: ";
    cin>>livros.ano;

    cout<<"Digite a quantidade de paginas do livro: ";
    cin>>livros.paginas;
    cin.ignore();

    cout<<livros.titulo<<endl;
    pilha1.push(livros);

  }

  while(!pilha1.empty()){
    
    cout<<"\nTitulo do livro: "<<livros.titulo<<"\nNome do autor: "<<livros.autor<<"\nCodigo IBSN: "<<livros.ISBN;
    cout<<"\nAno do livro: "<<livros.ano<<"\nQuantidade de paginas: "<<livros.paginas<<endl;
    pilha1.pop();
    
    if(pilha1.empty()){
        cout<<"\nPILHA VAZIA";
    }
  }
 
  cout << endl;
  return 0;
}
