#include <iostream>
#include <fstream>
#include <windows.h>
 
using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    ifstream arquivo1, arquivo2;
    ofstream arquivo3;

    arquivo1.open("letras.txt");
    arquivo2.open("numeros.txt");

    if (!arquivo1.is_open() || !arquivo2.is_open()) {
        cerr << "ERRO! Não foi possível abrir um dos arquivos.\n";
        arquivo1.clear();
        arquivo2.clear();
    } else {
        cout << "Arquivos abertos com sucesso!\n";
    }

    arquivo3.open("resultado.txt");

    if (!arquivo3.is_open()) {
        cerr << "ERRO! Não foi possível criar o arquivo final.\n";
        arquivo3.clear();
    }

    string conteudo;

    while (!arquivo1.eof()) {
        arquivo1 >> conteudo;
        arquivo3 << conteudo << endl;
    }

    while (!arquivo2.eof()) {
        arquivo2 >> conteudo;
        arquivo3 << conteudo << endl;
    }

    arquivo1.close();
    arquivo2.close();
    arquivo3.close();

    return 0;
}