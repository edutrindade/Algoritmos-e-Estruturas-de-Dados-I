#include <iostream>
#include <windows.h>

using namespace std;

class Pessoa
{
public:
    Pessoa(string nome, int idade, float altura);
    void mostrarDados();

private:
    string nome;
    int idade;
    float altura;
};

Pessoa::Pessoa(string nome, int idade, float altura)
{
    this->nome = nome;
    this->idade = idade;
    this->altura = altura;
}

void Pessoa::mostrarDados()
{
    cout << "\nNome: " << this->nome << endl;
    cout << "Idade: " << this->idade << endl;
    cout << "Altura: " << this->altura << endl;
}

int main()
{
    Pessoa pessoa1("Joao", 20, 1.75);
    pessoa1.mostrarDados();
    Pessoa pessoa2("Maria", 18, 1.65);
    pessoa2.mostrarDados();
    return 0;
}