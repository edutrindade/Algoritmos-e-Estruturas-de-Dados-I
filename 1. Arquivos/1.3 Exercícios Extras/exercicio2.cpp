#include <iostream>
#include <fstream>
#include <windows.h>
 
using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    int vogais = 0, consoantes = 0, caracteres_especiais = 0;

    ifstream arquivo;
    arquivo.open("cores.txt");

    if (!arquivo.is_open()) {
        cerr << "ERRO! Não foi possível abrir o arquivo.\n";
        arquivo.clear();
    } else {
        cout << "Arquivo aberto com sucesso!\n";
    }

    while (!arquivo.eof()) {
        char letra;
        arquivo >> letra;

        if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            vogais++;
        } else if (letra != '#') {
            consoantes++;
        } else {
            caracteres_especiais++;
        }
    }

    arquivo.close();

    cout << "\nRESULTADO\n\n";
    cout << "Vogais: " << vogais << endl;
    cout << "Consoantes: " << consoantes << endl;
    cout << "Caracteres especiais: " << caracteres_especiais << endl;

    cout << endl;
    return 0;
}