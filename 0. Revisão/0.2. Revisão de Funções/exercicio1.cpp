#include <iostream>
#include <windows.h>
#define P1 4
#define P2 6
#define NUM_ALUNOS 10

using namespace std;

typedef struct Aluno {
    float nota1, nota2, media;
    char conceito;
};

float mediaPonderada(float nota1, float nota2) {
    return (nota1 * P1 + nota2 * P2) / (P1 + P2); 
}

char calculaConceito(float media) {
    if (media >= 9.0)
        return 'A';
    if (media >= 7.0)
        return 'B';
    if (media >= 5.0)
        return 'C';
    return 'D';    
}
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
   
    Aluno alunos[NUM_ALUNOS];

    for (int i=0; i<NUM_ALUNOS; i++) {
        cout << "\nALUNO " << i+1 << endl;
        cout << "Nota 1: " ;
        cin >> alunos[i].nota1;
        cout << "Nota 2: ";
        cin >> alunos[i].nota2;
        alunos[i].media = mediaPonderada(alunos[i].nota1, alunos[i].nota2);
        alunos[i].conceito = calculaConceito(alunos[i].media);
    }

    system("cls");

    for (int i=0; i<NUM_ALUNOS; i++) {
        cout << "ALUNO " << i+1 << endl;
        cout << "Nota 1: " << alunos[i].nota1 << endl;
        cout << "Nota 2: " << alunos[i].nota2 << endl;
        cout << "Média: " << alunos[i].media << endl;
        cout << "Conceito: " << alunos[i].conceito << endl << endl;
    }

    return 0;
}