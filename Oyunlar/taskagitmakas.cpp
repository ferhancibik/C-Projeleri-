#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int boyut = 3;

enum Secim { TAS = 0, KAGIT = 1, MAKAS = 2 };

void matrisiYazdir(char matris[boyut][boyut]) {
    for (int i = 0; i < boyut; ++i) {
        for (int j = 0; j < boyut; ++j) {
            cout << matris[i][j] << " ";
        }
        cout << endl;
    }
}

void sonucuYazdir(int oyuncuSecimi, int bilgisayarSecimi) {
    if (oyuncuSecimi == bilgisayarSecimi) {
        cout << "Berabere! Tekrar deneyin." << endl;
    } else if ((oyuncuSecimi + 1) % boyut == bilgisayarSecimi) {
        cout << "Kaybettiniz. Daha şanslı olabilirsiniz." << endl;
    } else {
        cout << "Kazandınız! Tebrikler." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");
    srand(static_cast<unsigned int>(time(0)));

    char semboller[boyut] = { 'T', 'K', 'M' }; // Semboller dizi olarak yeterli

    int oyuncuSecimi;

    cout << "Taş-kağıt-makas oyununa hoş geldiniz!" << endl;
    cout << "0: Taş, 1: Kağıt, 2: Makas" << endl;
    cout << "Lütfen seçiminizi yapın: ";
    cin >> oyuncuSecimi;

    if (oyuncuSecimi < 0 || oyuncuSecimi >= boyut) {
        cout << "Geçersiz seçim. Programdan çıkılıyor." << endl;
        return 1;
    }

    int bilgisayarSecimi = rand() % boyut;

    cout << "Oyuncunun seçimi: " << semboller[oyuncuSecimi] << endl;
    cout << "Bilgisayarın seçimi: " << semboller[bilgisayarSecimi] << endl;

    sonucuYazdir(oyuncuSecimi, bilgisayarSecimi);

    return 0;
}
