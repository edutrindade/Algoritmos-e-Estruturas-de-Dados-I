#include <iostream>
#include <windows.h>

#define MAXTAM 10
 
using namespace std;

typedef struct {
    int Item[MAXTAM]; // i: 0, 1, 2, 3... 8, 9
    int Topo;
} TPilha;

/* Funções básicas de verificação: 
   [x] Inicializar a pilha: necessária para criação da struct TPilha
   [x] Verificar se a Pilha está Vazia: necessária ao Desempilhar um Item[i] 
   [x] Verificar se a Pilha está Cheia: necessária ao Empilhar um novo Item[i]
*/

void TPilha_Inicializa(TPilha *p) {
    p->Topo = -1; // Indica que a pilha está inicializada e vazia
}

int TPilha_Vazia(TPilha *p) {
    if (p->Topo == -1) {
        return 1; // Retorno verdadeiro, a pilha está vazia
    } else {
        return 0; // Retorno falso, a pilha não está vazia
    }
}

int TPilha_Cheia(TPilha *p) {
    if (p->Topo == MAXTAM-1) {
        return 1; // Retorno verdadeiro, a pilha está cheia: 0 a 9 preenchidos
    } else {
        return 0; // Retorno falso, a pilha não está cheia
    }
}

/* Funções básicas de manipulação: 
   [x] Empilhar um item no topo da pilha: necessário verificar se há espaço
   [x] Desempilhar um item do topo da pilha: necessário verificar se há item na pilha 
*/

void TPilha_Empilha(TPilha *p, int x) {
    if (TPilha_Cheia(p) == 1) {
        cout << "\nPilha cheia\n";
    } else {
        p->Topo++; 
        p->Item[p->Topo] = x;
        cout << "Valor empilhado: " << x << endl;
    }
}

int TPilha_Desempilha(TPilha *p) {
   int aux; // Receber o valor da pilha que será desempilhado
   if (TPilha_Vazia(p) == 1) {
        cout << "\nImpossível desempilhar. Pilha vazia\n";
   } else {
        aux = p->Item[p->Topo];
        p->Topo--;
        return aux;
   }
}

/* Funções complementares: 
   [x] Imprimir a pilha
   [x] Tamanho da pilha 
*/

void TPilha_Imprime(TPilha *p) {
    if (TPilha_Vazia(p) == 1) {
        cout << "\nPilha vazia\n";
        return;
    }
    for (int i = p->Topo; i >= 0; i--) {
        if (i == p->Topo) {
            cout << "\nTopo -> " << p->Item[i] << "\n";
        } else {
            cout << "\t " << p->Item[i] << "\n";
        }
    }
}

int TPilha_Tamanho(TPilha *p) {
    return p->Topo+1;
}
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    TPilha p;
    int aux, tam;

    TPilha_Inicializa(&p);

    TPilha_Empilha(&p, 5);
    TPilha_Empilha(&p, 7);
    TPilha_Empilha(&p, 11);

    /*aux = TPilha_Desempilha(&p);
    cout << "\nValor desempilhado: " << aux << endl;

    aux = TPilha_Desempilha(&p);
    cout << "Valor desempilhado: " << aux << endl;

    aux = TPilha_Desempilha(&p);
    cout << "Valor desempilhado: " << aux << endl;*/

    TPilha_Imprime(&p);

    tam = TPilha_Tamanho(&p);
    cout << "\nTamanho da Pilha: " << tam << endl;

    return 0;
}