#include <iostream>

using namespace std;

typedef struct Pessoa
{
    string nome;
    string dataNascimento;
    string cpf;
};

void preenchePessoa(Pessoa *pessoa);
void imprimePessoa(Pessoa *pessoa);

int main()
{
    Pessoa pessoa;
    Pessoa *ponteiroPessoa = &pessoa;

    preenchePessoa(ponteiroPessoa);
    cout << "\n";
    imprimePessoa(ponteiroPessoa);

    return 0;
}

void preenchePessoa(Pessoa *pessoa)
{
    cout << "Digite o nome: ";
    getline(cin, pessoa->nome);
    cout << "Digite a data de nascimento: ";
    getline(cin, pessoa->dataNascimento);
    cout << "Digite o CPF: ";
    getline(cin, pessoa->cpf);
}

void imprimePessoa(Pessoa *pessoa)
{
    cout << "Nome: " << pessoa->nome << endl;
    cout << "Data de Nascimento: " << pessoa->dataNascimento << endl;
    cout << "CPF: " << pessoa->cpf << endl;
}