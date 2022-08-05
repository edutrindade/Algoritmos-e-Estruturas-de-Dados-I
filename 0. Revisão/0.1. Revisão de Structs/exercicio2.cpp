#include <iostream>
#include <windows.h>
using namespace std;

typedef struct Pessoa
{
    float salario;
    int idade;
    int nFilhos;
    int sexo; //0 -> masculino, 1 -> feminino
};

const int totalPessoas = 3; // Constante -> alternativa ao DEFINE

void coletaDados(Pessoa p[])
{  
    cout << "CADASTRO DE DADOS DO MUNICÍPIO\n\n";
    for (int i = 0; i < totalPessoas; i++)
    {
        cout << "\nPessoa n -> " << (i + 1) << endl;
        cout << "Salário: ";
        cin >> p[i].salario;
        cout << "Idade: ";
        cin >> p[i].idade;
        cout << "Número de filhos: ";
        cin >> p[i].nFilhos;
        do {
            cout << "Sexo (0 -> M, 1 -> F): ";
            cin >> p[i].sexo;
        } while (p[i].sexo != 0 && p[i].sexo != 1);
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    Pessoa pessoas[totalPessoas];
    coletaDados(pessoas);

    int qtdMulheres;
    float mediaSalario = 0, mediaFilhos = 0, maiorSalario = 0, qtdMulheresMaiorQue1000 = 0;
    for (int i = 0; i < totalPessoas; i++)
    {
        mediaSalario += pessoas[i].salario;
        mediaFilhos += pessoas[i].nFilhos;
        if (pessoas[i].salario > maiorSalario)
        {
            maiorSalario = pessoas[i].salario;
        }
        if (pessoas[i].sexo == 1)
        {
            qtdMulheres++;
            if (pessoas[i].salario > 1000)
            {
                qtdMulheresMaiorQue1000++;
            }
        }
    }
    
    mediaSalario /= totalPessoas;
    mediaFilhos /= totalPessoas;

    cout << "\nMedia salario: " << mediaSalario;
    cout << "\nMedia Filhos: " << mediaFilhos;
    cout << "\nMaior Salario: " << maiorSalario;
    cout << "\nPercentual mulheres com salario maior que 1000: " << endl
         << "\t" << qtdMulheresMaiorQue1000 / totalPessoas * 100 << "% da populacao" << endl
         << "\t" << qtdMulheresMaiorQue1000 / qtdMulheres * 100 << "% das mulheres" << endl;

    return 0;
}
