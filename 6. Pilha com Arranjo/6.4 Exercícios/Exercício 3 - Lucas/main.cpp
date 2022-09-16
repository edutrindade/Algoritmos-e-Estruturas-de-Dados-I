#include <iostream>
#include <time.h>

#include "TAD_PilhaArranjo.hpp"

using namespace std;

struct ListaCartas {
    Carta Carta[52];
    int tamanho;
};

void criaListaVazia(ListaCartas *lista) {
    lista->tamanho = 0;
}

bool insereItem(ListaCartas *lista, Carta Carta) {
    lista->Carta[lista->tamanho] = Carta;
    lista->tamanho++;
    return true;
}

Carta removeItem(ListaCartas *lista, int posicao) {
    Carta carta = lista->Carta[posicao];
    for(int i = posicao; i < lista->tamanho; i++) {
        lista->Carta[i] = lista->Carta[i+1];
    }
    lista->tamanho--;
    return carta;
}

void defineBaralho(ListaCartas* listaCartas) {
    criaListaVazia(listaCartas);
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 13; j++) {
            Carta carta;
            carta.naipe = i;
            if(j > 10) {
                carta.valor = 10;
            } else {
                carta.valor = j;
            }
            
            insereItem(listaCartas, carta);
        }
    }
}

void preencheBaralho(Pilha* baralho, ListaCartas* listaCartas) {
    criaPilhaVazia(baralho);
    srand(time(NULL));
    int posicao;
    for(int i = 0; i < 52; i++) {
        posicao = rand() % listaCartas->tamanho;
        empilha(baralho, removeItem(listaCartas, posicao));
    }
}

int main() {
    ListaCartas listaCartas;
    defineBaralho(&listaCartas);

    Pilha baralho;
    preencheBaralho(&baralho, &listaCartas);

    imprimePilha(baralho);

    int jogador1 = 0;
    int jogador2 = 0;
    for(int i = 0; i < 2; i++) {
        jogador1 += desempilha(&baralho).valor;
    }
    
    for(int i = 0; i < 2; i++) {
        jogador2 += desempilha(&baralho).valor;
    }

    int vez = 1, nao = 0;
    bool ganhador = false;
    char opcao;

    while(!ganhador) {

        do {  
            cout << "Pontos jogador 1: " << jogador1 << endl << "Pontos jogador 2: " << jogador2 << endl;
            cout << "Jogador " << vez << " pedir uma carta?(s/n): ";
            cin >> opcao;
            system("cls");
        } while(opcao != 's' && opcao != 'n');

        if(opcao == 's') {
            nao = 0;
            if(vez == 1) {
                jogador1 += desempilha(&baralho).valor;
            } else {
                jogador2 += desempilha(&baralho).valor;
            }

            if(jogador1 == 21) {
                cout << "Vitoria do jogador 1";
                ganhador = true;
            } else if(jogador2 == 2) {
                cout << "Vitoria do jogador 2";
                ganhador = true;
            }

            else if(jogador1 > 21) {
                cout << "Vitoria do jogador 2";
                ganhador = true;
            } else if(jogador2 > 21) {
                cout << "Vitoria do jogador 1";
                ganhador = true;
            }

            
        } else {
            nao++;
            if(vez == 1) {
                vez = 2;
            } else {
                vez = 1;
            }
            if(nao == 2) {
                if(jogador1 > jogador2) {
                    cout << "Vitoria do jogador 1";
                    ganhador = true;
                } else if(jogador2 > jogador1) {
                    cout << "Vitoria do jogador 2";
                    ganhador = true;
                } else {
                    cout << "Empate";
                    ganhador = true;
                }
            }
        }
    }
    cout << endl << "Pontos jogador 1: " << jogador1 << endl << "Pontos jogador 2: " << jogador2 << endl;
    return 0;
}