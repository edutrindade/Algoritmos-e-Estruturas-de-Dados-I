#include <iostream>
#include <windows.h>

using namespace std;

class Semaforo
{
public:
    Semaforo(int cor);
    void mudarCor(int cor);
    void mostrarCor();
    void mostraSemaforo();

private:
    int cor;
};

Semaforo::Semaforo(int cor)
{
    this->cor = cor;
}

void Semaforo::mudarCor(int cor)
{
    this->cor = cor;
}

void Semaforo::mostrarCor()
{
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (this->cor)
    {
    case 1:
        SetConsoleTextAttribute(colors, 4);
        cout << "\t________\n";
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        SetConsoleTextAttribute(colors, 15);
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        SetConsoleTextAttribute(colors, 4);
        cout << "\n\tVermelho: PARE!" << endl;
        break;
    case 2:
        SetConsoleTextAttribute(colors, 15);
        cout << "\t________\n";
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        SetConsoleTextAttribute(colors, 14);
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        SetConsoleTextAttribute(colors, 15);
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        SetConsoleTextAttribute(colors, 14);
        cout << "\n\tAmarelo: ATENCAO!" << endl;
        break;
    case 3:
        SetConsoleTextAttribute(colors, 15);
        cout << "\t________\n";
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        SetConsoleTextAttribute(colors, 2);
        cout << "\t|######|\n";
        cout << "\t|######|\n";
        cout << "\t|______|\n";
        cout << "\n\tVerde: SIGA!" << endl;
        break;
    default:
        SetConsoleTextAttribute(colors, 15);
        break;
    }
}

int main()
{
    system("pause");
    system("cls");
    Semaforo semaforo(1);
    semaforo.mostrarCor();
    Sleep(3000);
    system("cls");
    semaforo.mudarCor(3);
    semaforo.mostrarCor();
    Sleep(3000);
    system("cls");
    semaforo.mudarCor(2);
    semaforo.mostrarCor();
    Sleep(3000);
    system("cls");
    semaforo.mudarCor(1);
    semaforo.mostrarCor();

    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 15);
<<<<<<< HEAD

=======
    // cout << "\t________\n";
    // Semaforo semaforo(1);
    // semaforo.mostrarCor();
    // cout << "\t|######|\n";
    // cout << "\t|######|\n";
    // semaforo.mudarCor(4);
    // semaforo.mostrarCor();
    // cout << "\t|______|\n";
    // semaforo.mudarCor(2);
    // semaforo.mostrarCor();
    // cout << "\t|######|\n";
    // cout << "\t|######|\n";
    // semaforo.mudarCor(4);
    // semaforo.mostrarCor();
    // cout << "\t|______|\n";
    // semaforo.mudarCor(3);
    // semaforo.mostrarCor();
    // cout << "\t|######|\n";
    // cout << "\t|######|\n";
    // semaforo.mudarCor(4);
    // semaforo.mostrarCor();
    // cout << "\t|______|\n";

    // cout << endl;

    // cout << "\t________\n";
    // Semaforo semaforo2(1);
    // semaforo2.mostrarCor();
    // cout << "\t|######|\n";
    // cout << "\t|######|\n";
    // semaforo2.mudarCor(4);
    // semaforo2.mostrarCor();
    // cout << "\t|______|\n";
    // cout << "\t|######|\n";
    // cout << "\t|######|\n";
    // cout << "\t|______|\n";
    // cout << "\t|######|\n";
    // cout << "\t|######|\n";
    // cout << "\t|______|\n";
>>>>>>> 180469d5fc02fe06e8b61cda1458110b1be60dcb
    return 0;
}