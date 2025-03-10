#include <iostream>
#include <locale.h>
using namespace std;

// Seri ve paralel eşdeğer direnç hesaplama (referans ile)
void esdegerDirencHesapla(int& seri, float& paralel, float sayi1, float sayi2, float sayi3) {
    seri = sayi1 + sayi2 + sayi3;
    paralel = 1 / (1 / sayi1 + 1 / sayi2 + 1 / sayi3);
}

// Seri ve paralel eşdeğer direnç hesaplama (geri değer döndürerek)
int esdegerDirencHesapla(float& paralel, float sayi1, float sayi2, float sayi3) {
    int seri = sayi1 + sayi2 + sayi3;
    paralel = 1 / (1 / sayi1 + 1 / sayi2 + 1 / sayi3);
    return seri;
}

int main() {
    setlocale(LC_ALL, "Turkish");

    float direnc1, direnc2, direnc3;

    // Kullanıcıdan direnç değerlerini al
    cout << "1. direnci giriniz: ";
    cin >> direnc1;
    cout << "2. direnci giriniz: ";
    cin >> direnc2;
    cout << "3. direnci giriniz: ";
    cin >> direnc3;

    int seriReferans;
    float paralelReferans;

    // Referans ile hesaplama
    esdegerDirencHesapla(seriReferans, paralelReferans, direnc1, direnc2, direnc3);
    cout << "-------------------------Geri Değer Döndürmeyen--------------" << endl;
    cout << "Seri Eşdeğer Direnç: " << seriReferans << " ohm" << endl;
    cout << "Paralel Eşdeğer Direnç: " << paralelReferans << " ohm" << endl;

    // Geri değer döndürerek hesaplama
    cout << "--------------------------Geri Değer Döndüren----------------" << endl;
    int seri = esdegerDirencHesapla(paralelReferans, direnc1, direnc2, direnc3);
    cout << "Seri Eşdeğer Direnç: " << seri << " ohm" << endl;
    cout << "Paralel Eşdeğer Direnç: " << paralelReferans << " ohm" << endl;

    return 0;
}
