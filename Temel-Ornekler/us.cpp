#include <iostream>
#include <locale.h>
using namespace std;

// Üs hesaplayan rekürsif fonksiyon
int us(int taban, int ussayi)
{
    if (ussayi == 0)
        return 1;
    else if (ussayi > 0) 
        return taban * us(taban, ussayi - 1);
    else 
    {
        cout << "Negatif üs desteklenmiyor!" << endl;
        return -1; 
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");

    int tabansayi = 4;
    int ust = 3; 
    cout << tabansayi << "^" << ust << " = " << us(tabansayi, ust) << endl;

    return 0;
}
