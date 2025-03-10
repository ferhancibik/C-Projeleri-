#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Halı yapısı
struct Halilar {
    int en;               // (cm)
    int uzunluk;          // (cm)
    int desenNo;          // (4 basamaklı sayı)
    string iplikCinsi;    // (pamuk, yün, polyester)
    int ilmekSayi;        // (5 basamaklı sayı)
    char kalite;          // ('A', 'B')
};

// Halı bilgilerini oluşturan fonksiyon
void halilariOlustur(Halilar stok[], int boyut) {
    srand(time(NULL));
    for (int i = 0; i < boyut; i++) {
        stok[i].en = rand() % (300 - 100 + 1) + 100;
        stok[i].uzunluk = rand() % (400 - 200 + 1) + 200;
        stok[i].desenNo = rand() % (9999 - 1000 + 1) + 1000;
        stok[i].ilmekSayi = rand() % (99999 - 10000 + 1) + 10000;

        int rastgeleSayi = rand() % 3 + 1;
        if (rastgeleSayi == 1)
            stok[i].iplikCinsi = "pamuk";
        else if (rastgeleSayi == 2)
            stok[i].iplikCinsi = "yün";
        else
            stok[i].iplikCinsi = "polyester";

        int rastgeleSayi1 = rand() % 2 + 1;
        stok[i].kalite = (rastgeleSayi1 == 1) ? 'A' : 'B';
    }
}

// Halı bilgilerini yazdıran fonksiyon
void halilariYazdir(const Halilar stok[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        cout << "--------------------------" << endl;
        cout << "Halı #" << i + 1 << endl;
        cout << "En: " << stok[i].en << " cm" << endl;
        cout << "Uzunluk: " << stok[i].uzunluk << " cm" << endl;
        cout << "Desen No: " << stok[i].desenNo << endl;
        cout << "İlmek Sayısı: " << stok[i].ilmekSayi << endl;
        cout << "İplik Cinsi: " << stok[i].iplikCinsi << endl;
        cout << "Kalite: " << stok[i].kalite << " Sınıfı" << endl;
    }
}

// Belirli uzunluktaki halıları filtreleyen fonksiyon
void halilariFiltrele(const Halilar stok[], int boyut, int girilenUzunluk) {
    bool bulundu = false;
    for (int i = 0; i < boyut; i++) {
        if (stok[i].uzunluk == girilenUzunluk) {
            cout << "--------------------------" << endl;
            cout << "Halı #" << i + 1 << endl;
            cout << "En: " << stok[i].en << " cm" << endl;
            cout << "Uzunluk: " << stok[i].uzunluk << " cm" << endl;
            cout << "Desen No: " << stok[i].desenNo << endl;
            cout << "İlmek Sayısı: " << stok[i].ilmekSayi << endl;
            cout << "İplik Cinsi: " << stok[i].iplikCinsi << endl;
            cout << "Kalite: " << stok[i].kalite << " Sınıfı" << endl;
            bulundu = true;
        }
    }
    if (!bulundu) {
        cout << "Belirtilen uzunlukta halı bulunamadı." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");

    const int stokBoyutu = 500;
    Halilar stok[stokBoyutu];

    // Halıları oluştur
    halilariOlustur(stok, stokBoyutu);

    // Tüm halıları yazdır
    cout << "Tüm Halıların Listesi:" << endl;
    halilariYazdir(stok, stokBoyutu);

    // Kullanıcıdan uzunluk bilgisi al
    int girilenUzunluk;
    cout << "Listelemek istediğiniz halıların uzunluğunu girin (cm): ";
    cin >> girilenUzunluk;

    // Belirli uzunluktaki halıları filtrele ve yazdır
    cout << "\nBelirtilen Uzunluktaki Halılar:" << endl;
    halilariFiltrele(stok, stokBoyutu, girilenUzunluk);

    return 0;
}
