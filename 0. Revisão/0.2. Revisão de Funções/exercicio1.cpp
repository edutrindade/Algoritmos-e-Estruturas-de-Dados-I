#include <iostream>
#include <windows.h>
#define P1 4
#define P2 6
#define NUM_ALUNOS 10

using namespace std;

typedef struct Aluno
{
    float nota1, nota2, media;
    char conceito;
};

float mediaPonderada(float nota1, float nota2)
{
    return (nota1 * P1 + nota2 * P2) / (P1 + P2);
}

char calculaConceito(float media)
{
    if (media >= 9.0)
        return 'A';
    if (media >= 7.0)
        return 'B';
    if (media >= 5.0)
        return 'C';
    return 'D';
}

Aluno cadastraAluno()
{
    Aluno aluno;
    cout << "Nota 1: ";
    cin >> aluno.nota1;
    cout << "Nota 2: ";
    cin >> aluno.nota2;
    aluno.media = mediaPonderada(aluno.nota1, aluno.nota2);
    aluno.conceito = calculaConceito(aluno.media);
    return aluno;
}

void imprimeAluno(Aluno aluno)
{
    cout << "Nota 1: " << aluno.nota1 << endl;
    cout << "Nota 2: " << aluno.nota2 << endl;
    cout << "Média: " << aluno.media << endl;
    cout << "Conceito: " << aluno.conceito << endl
         << endl;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++)
    {
        cout << "\nALUNO " << i + 1 << endl;
        alunos[i] = cadastraAluno();
    }

    system("cls");

    for (int i = 0; i < NUM_ALUNOS; i++)
    {
        cout << "ALUNO " << i + 1 << endl;
        imprimeAluno(alunos[i]);
    }
    return 0;
}