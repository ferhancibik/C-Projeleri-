#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

// Araba yapısı
struct Otomobil {
    string marka;
    string model;
    int yil;
    char yakit;
    int km;
    float fiyat;
};

// Araba bilgilerini gösteren fonksiyon
void arabaBilgileriniGoster(const Otomobil& araba, const string& tip) {
    cout << "\n-- " << tip << " Araç Bilgileri --" << endl;
    cout << "Marka: " << araba.marka << endl;
    cout << "Model: " << araba.model << endl;
    cout << "Yıl: " << araba.yil << endl;
    cout << "Yakıt: " << araba.yakit << endl;
    cout << "Km: " << araba.km << endl;
    cout << "Fiyat: " << araba.fiyat << " TL" << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");

    // Araba tipleri
    Otomobil binek, suv, ticari;

    // Binek araba bilgileri
    binek = {"Ford", "Mustang", 2019, 'B', 45000, 3500000};

    // SUV araba bilgileri
    suv = {"Mercedes-Benz", "G 63 AMG", 2021, 'B', 20000, 12000000};

    // Ticari araba bilgileri
    ticari = {"Volkswagen", "Crafter", 2025, 'D', 120000, 1500000};

    // Kullanıcıdan araba tipi seçimi
    string arabaTipi;
    cout << "Lütfen Araba Tipini Girin (Binek, Suv, Ticari): ";
    cin >> arabaTipi;

    // Seçime göre bilgileri göster
    if (arabaTipi == "Binek" || arabaTipi == "binek") {
        arabaBilgileriniGoster(binek, "Binek");
    } else if (arabaTipi == "Suv" || arabaTipi == "suv") {
        arabaBilgileriniGoster(suv, "SUV");
    } else if (arabaTipi == "Ticari" || arabaTipi == "ticari") {
        arabaBilgileriniGoster(ticari, "Ticari");
    } else {
        cout << "Yanlış Araba Tipi Seçtiniz!" << endl;
    }

    return 0;
}
