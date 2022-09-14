#include <iostream>
#include "Pilha.hpp"

using namespace std;

void FazPilhaVazia(TipoPilha *pilha) {
   pilha->topo = 0;
}

bool VerificaPilhaVazia(TipoPilha *pilha) {
    if (pilha->topo == 0)
        return true;
    return false;
}

bool VerificaPilhaCheia(TipoPilha *pilha) {
    if (pilha->topo == MAXTAM)
        return true;
    return false;
}

void Empilha(TipoPilha *pilha, TipoItem item) {
    if (VerificaPilhaCheia(pilha)) {
        cout << "\nPilha cheia\n";
        return;
    } 
    
    pilha->itens[pilha->topo] = item;
    pilha->topo++;
    //cout << "\nItem empilhado com sucesso!\n";
}

void ExibePilha(TipoPilha *pilha) { 
    for (int i=pilha->topo-1; i>=0; i--) {
        cout << pilha->itens[i].id << "\n";
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *item) {
    if (VerificaPilhaVazia(pilha)) {
        cout << "\nPilha vazia.\n";
        return;
    }

    pilha->topo--;
    *item = pilha->itens[pilha->topo];
}

int Tamanho(TipoPilha *pilha) {
    return pilha->topo;
}