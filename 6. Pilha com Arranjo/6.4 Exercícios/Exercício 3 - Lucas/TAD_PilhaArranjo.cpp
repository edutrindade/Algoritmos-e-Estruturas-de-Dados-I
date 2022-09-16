#define MAX_TAM 52

#include <iostream>

using namespace std;

struct Carta {
    int naipe;
    int valor;
};

struct Pilha {
    Carta Carta[MAX_TAM];
    int tamanho;
};

bool criaPilhaVazia(Pilha* pilha) {
    if(pilha->tamanho == 0) {
        return false;
    }
    pilha->tamanho = 0;
    return true;
}

bool verificaPilhaVazia(Pilha* pilha) {
    if(pilha->tamanho == 0) {
        return true;
    }
    return false;
}

bool verificaPilhaCheia(Pilha* pilha) {
    if(pilha->tamanho == MAX_TAM) {
        return true;
    }
    return false;
}

bool empilha(Pilha* pilha, Carta Carta) {
    if(verificaPilhaCheia(pilha)) {
        return false;
    }
    pilha->Carta[pilha->tamanho] = Carta;
    pilha->tamanho++;
    return true;
}

Carta desempilha(Pilha* pilha) {
    Carta Carta;
    Carta = pilha->Carta[pilha->tamanho - 1];
    pilha->Carta[pilha->tamanho - 1] = pilha->Carta[pilha->tamanho];
    pilha->tamanho--;
    return Carta;
}

void imprimePilha(Pilha pilha) {
    for(int i = 0; i < pilha.tamanho; i++) {
        cout << pilha.Carta[i].naipe << " ";
        cout << pilha.Carta[i].valor << endl;
    }
}

int getTamanho(Pilha* pilha) {
    return pilha->tamanho;
}