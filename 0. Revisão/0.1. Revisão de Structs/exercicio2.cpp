#include <iostream>
#include <windows.h>
using namespace std;

typedef struct Pessoa
{
    float salario;
    int idade;
    int nFilhos;
    int sexo; // 0 -> masculino, 1 -> feminino
};

const int totalPessoas = 3; // Constante -> alternativa ao DEFINE

Pessoa cadastraPessoa()
{
    Pessoa pessoa;
    cout << "Salário: ";
    cin >> pessoa.salario;
    cout << "Idade: ";
    cin >> pessoa.idade;
    cout << "Número de filhos: ";
    cin >> pessoa.nFilhos;
    do
    {
        cout << "Sexo (0 -> M, 1 -> F): ";
        cin >> pessoa.sexo;
    } while (pessoa.sexo != 0 && pessoa.sexo != 1);
    return pessoa;
}

void coletaDados(Pessoa p[])
{
    cout << "CADASTRO DE DADOS DO MUNICÍPIO\n\n";
    for (int i = 0; i < totalPessoas; i++)
    {
        cout << "\nPessoa n -> " << (i + 1) << endl;
        p[i] = cadastraPessoa();
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
