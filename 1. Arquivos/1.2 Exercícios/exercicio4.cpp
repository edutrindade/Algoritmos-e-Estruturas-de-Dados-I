#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    cout << "--- TIPO ---|--- BYTES ---\n";
    cout << "char .......:  " << sizeof(char) << " bytes\n";
    cout << "short ......:  " << sizeof(short) << " bytes\n";
    cout << "int ........:  " << sizeof(int) << " bytes\n";
    cout << "long .......:  " << sizeof(long) << " bytes\n";
    cout << "float ......:  " << sizeof(float) << " bytes\n";
    cout << "double .....:  " << sizeof(double) << " bytes\n";
    cout << "long double :  " << sizeof(long double) << " bytes\n";

    cout << endl;
    return 0;
}