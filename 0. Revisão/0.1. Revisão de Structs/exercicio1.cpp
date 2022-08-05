#include <iostream>
#include <windows.h>
#define NUM_CONTAS 5

using namespace std;

typedef struct Banco {
    int num;
    char titular[35];
    float saldo;
};

void preencheContas(Banco conta[]) {
    for (int i=0; i<NUM_CONTAS; i++) {
        cout << "Número da conta: ";
        cin >> conta[i].num;
        cout << "Titular: ";
        cin >> conta[i].titular;
        cout << "Saldo: ";
        cin >> conta[i].saldo;
    }
}

int encontraMaior(Banco conta[]) {
    int maior = 0;
    for (int i=0; i<NUM_CONTAS; i++) {
        if (conta[i].saldo > conta[maior].saldo) {
            maior = i;
        }
    }
    return maior;
}

int encontraMenor(Banco conta[]) {
    int menor = 0;
    for (int i=0; i<NUM_CONTAS; i++) {
        if (conta[i].saldo < conta[menor].saldo) {
            menor = i;
        }
    }
    return menor;
}

void imprimeContas(Banco conta[], int i) {
    cout << "Conta: " << conta[i].num << endl;
    cout << "Titular: " << conta[i].titular << endl;
    cout << "Saldo: R$ " << conta[i].saldo << endl;
}
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    Banco conta[NUM_CONTAS];
    int indice_maior=0, indice_menor=0;

    preencheContas(conta);

    indice_maior = encontraMaior(conta);
    indice_menor = encontraMenor(conta);

    system("cls");
    
    cout << "Conta com o maior saldo: \n\n";
    imprimeContas(conta, indice_maior);
    cout << "Conta com o menor saldo: \n\n";
    imprimeContas(conta, indice_menor);
    return 0;
}