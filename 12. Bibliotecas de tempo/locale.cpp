#include <iostream>
#include <time.h> //necessário para usar localtime() e struct tm

using namespace std;

int main(void)
{
    // ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual;

    // variável do tipo time_t para armazenar o tempo em segundos
    time_t segundos;

    // obtendo o tempo em segundos
    time(&segundos);

    // convertendo de segundos para o tempo local
    data_hora_atual = localtime(&segundos);

    // Acessando dados convertidos para a struct data_hora_atual
    cout << "\nDia..........: " << data_hora_atual->tm_mday;

    // para retornar o mês corretamente devemos adicionar +1
    cout << "\nMes..........: " << data_hora_atual->tm_mon + 1;

    // para retornar o ano corretamente devemos adicionar 1900
    cout << "\nAno..........: " << data_hora_atual->tm_year + 1900;

    cout << "\nDia do ano...: " << data_hora_atual->tm_yday; // dia do ano
    cout << "\nDia da semana: " << data_hora_atual->tm_wday; // dia da semana

    // retornando hora, minuto e segundos
    cout << "\nHora ........: " << data_hora_atual->tm_hour; // hora
    cout << ":" << data_hora_atual->tm_min;                  // minuto
    cout << ":" << data_hora_atual->tm_sec;                  // segundo

    // retornando dia, mês e ano
    cout << "\nData ........: " << data_hora_atual->tm_mday; // dia
    cout << "/" << data_hora_atual->tm_mon + 1;              // mês
    cout << "/" << data_hora_atual->tm_year + 1900;          // ano

    return 0;
}