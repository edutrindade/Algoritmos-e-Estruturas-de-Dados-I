#include <iostream>
#include <windows.h>
#include "ListaDuplamenteEncadeada.cpp"
#include "Funcoes.cpp"
 
using namespace std;
 
int main() {
    // Double-Threaded List
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
 
    TipoLista lista;
   
    CriaListaVazia(&lista);
    
    int opcao_menu;
    do {
        Menu();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu)) {
            cout << "  \n        Digite um valor válido."; 
            cin.clear(); 
            cin.ignore();
            Sleep(1000);
            system ("cls");
            Menu();
        }
        system ("cls");
        switch (opcao_menu) {
              case 1: CadastraTrabalho(&lista); break;   
              case 2: RemoveTrabalho(&lista); break; 
              case 3: ListaTrabalhos(&lista); break;
              case 4: PesquisaTrabalho(&lista); break;
              case 5: ListaTodosTrabalhos(&lista); break;
              case 6: cout << "Aguardamos você em breve novamente\n\n"; break;
         }
    } while (opcao_menu!=6); 

    return 0;
}