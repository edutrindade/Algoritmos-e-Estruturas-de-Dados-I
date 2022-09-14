#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <string> jogador1, jogador2;

    jogador1.push("7 de Copas");
    jogador2.push("Rei de Ouros");
    jogador1.push("4 de paus");
    jogador2.push("As de espadas");

    cout << jogador1.top();
    
    jogador1.swap(jogador2);
    cout << endl;

    cout << jogador1.top();
}