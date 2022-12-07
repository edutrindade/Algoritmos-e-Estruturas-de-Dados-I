#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

class Grupo
{
public:
    string nome;
    void mostraGrupo();
    void setTime(string team, int pos);

private:
    string times[4];
};

void Grupo::mostraGrupo()
{
    cout << "\nGrupo " << nome << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << times[i] << endl;
    }
}

// Salva um time no grupo
void Grupo::setTime(string team, int pos)
{
    times[pos] = team;
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    Grupo grupoA, grupoB, grupoC, grupoD, grupoE, grupoF, grupoG, grupoH;
    grupoA.nome = "A", grupoB.nome = "B", grupoC.nome = "C", grupoD.nome = "D", grupoE.nome = "E", grupoF.nome = "F", grupoG.nome = "G", grupoH.nome = "H";

    cout << "FIFA WORLD CUP 2022" << endl;

    ifstream file("teams.txt");

    if (file.is_open())
    {
        string line;
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoA.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoB.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoC.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoD.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoE.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoF.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoG.setTime(line, i);
        }
        for (int i = 0; i < 4; i++)
        {
            getline(file, line);
            grupoH.setTime(line, i);
        }

        file.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo.";
    }

    grupoA.mostraGrupo();
    grupoB.mostraGrupo();
    grupoC.mostraGrupo();
    grupoD.mostraGrupo();
    grupoE.mostraGrupo();
    grupoF.mostraGrupo();
    grupoG.mostraGrupo();
    grupoH.mostraGrupo();

    cout << endl;
    return 0;
}