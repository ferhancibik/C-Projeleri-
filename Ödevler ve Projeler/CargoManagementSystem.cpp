#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
using namespace std;

struct Gonderen {
    string adSoyad;
    string adres;
    string telefon;
};

struct Alici {
    string adSoyad;
    string adres;
    string telefon;
};

struct Kurye {
    string adSoyad;
    string telefon;
};

struct KargoSureci {
    string cikisTarihi;
    string teslimTarihi;
};

struct Gonderi {
    int gonderiNo;
    float agirlik;
    float hacim;
    string garanti;
    float ucret;
    Alici alici;
    Kurye kurye;
    Gonderen gonderen;
    KargoSureci surec;
};

// Gonderi bilgilerini dosyaya kaydetme
void gonderiKaydet(Gonderi gonderi) {
    ofstream dosya("Gonderiler.txt", ios::app);
    if (!dosya) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    dosya << gonderi.gonderiNo << " " << gonderi.agirlik << " " << gonderi.hacim << " " << gonderi.garanti << " " << gonderi.ucret << " "
          << gonderi.gonderen.adSoyad << " " << gonderi.gonderen.adres << " " << gonderi.gonderen.telefon << " "
          << gonderi.alici.adSoyad << " " << gonderi.alici.adres << " " << gonderi.alici.telefon << " "
          << gonderi.kurye.adSoyad << " " << gonderi.kurye.telefon << " "
          << gonderi.surec.cikisTarihi << " " << gonderi.surec.teslimTarihi << endl;

    dosya.close();
    cout << "Gönderi bilgileri başarıyla kaydedildi!" << endl;
}

// Dosyadan tüm gönderileri listeleme
void gonderileriListele() {
    ifstream dosya("Gonderiler.txt");
    if (!dosya) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    Gonderi gonderi;
    cout << "Gönderi No\tAğırlık\tHacim\tGaranti\tÜcret\tGönderen\tGönderen Adres\tGönderen Telefon\tAlıcı\tAlıcı Adres\tAlıcı Telefon\tKurye\tKurye Telefon\tÇıkış Tarihi\tTeslim Tarihi" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    while (dosya >> gonderi.gonderiNo >> gonderi.agirlik >> gonderi.hacim >> gonderi.garanti >> gonderi.ucret
                >> gonderi.gonderen.adSoyad >> gonderi.gonderen.adres >> gonderi.gonderen.telefon
                >> gonderi.alici.adSoyad >> gonderi.alici.adres >> gonderi.alici.telefon
                >> gonderi.kurye.adSoyad >> gonderi.kurye.telefon
                >> gonderi.surec.cikisTarihi >> gonderi.surec.teslimTarihi) {
        cout << gonderi.gonderiNo << "\t" << gonderi.agirlik << "\t" << gonderi.hacim << "\t" << gonderi.garanti << "\t" << gonderi.ucret << "\t"
             << gonderi.gonderen.adSoyad << "\t" << gonderi.gonderen.adres << "\t" << gonderi.gonderen.telefon << "\t"
             << gonderi.alici.adSoyad << "\t" << gonderi.alici.adres << "\t" << gonderi.alici.telefon << "\t"
             << gonderi.kurye.adSoyad << "\t" << gonderi.kurye.telefon << "\t"
             << gonderi.surec.cikisTarihi << "\t" << gonderi.surec.teslimTarihi << endl;
    }

    dosya.close();
}

// Ana menü
void menuGoster() {
    cout << "----------------------------------" << endl;
    cout << "--------- Kargo Yönetim Sistemi ---------" << endl;
    cout << "1. Gönderi Ekle" << endl;
    cout << "2. Gönderileri Listele" << endl;
    cout << "3. Çıkış" << endl;
    cout << "----------------------------------" << endl;
    cout << "Seçiminizi girin: ";
}

int main() {
    setlocale(LC_ALL, "Turkish"); // Türkçe karakter desteği
    int secim;

    while (true) {
        menuGoster();
        cin >> secim;

        switch (secim) {
            case 1: {
                Gonderi gonderi;
                cout << "Gönderi Numarası: ";
                cin >> gonderi.gonderiNo;
                cout << "Ağırlık: ";
                cin >> gonderi.agirlik;
                cout << "Hacim: ";
                cin >> gonderi.hacim;
                cout << "Garanti: ";
                cin >> gonderi.garanti;
                cout << "Ücret: ";
                cin >> gonderi.ucret;

                cout << "Gönderen Adı Soyadı: ";
                cin >> gonderi.gonderen.adSoyad;
                cout << "Gönderen Adresi: ";
                cin >> gonderi.gonderen.adres;
                cout << "Gönderen Telefon Numarası: ";
                cin >> gonderi.gonderen.telefon;

                cout << "Alıcı Adı Soyadı: ";
                cin >> gonderi.alici.adSoyad;
                cout << "Alıcı Adresi: ";
                cin >> gonderi.alici.adres;
                cout << "Alıcı Telefon Numarası: ";
                cin >> gonderi.alici.telefon;

                cout << "Kurye Adı Soyadı: ";
                cin >> gonderi.kurye.adSoyad;
                cout << "Kurye Telefon Numarası: ";
                cin >> gonderi.kurye.telefon;

                cout << "Çıkış Tarihi: ";
                cin >> gonderi.surec.cikisTarihi;
                cout << "Teslim Tarihi: ";
                cin >> gonderi.surec.teslimTarihi;

                gonderiKaydet(gonderi);
                break;
            }
            case 2:
                gonderileriListele();
                break;
            case 3:
                cout << "Çıkış yapılıyor..." << endl;
                return 0;
            default:
                cout << "Geçersiz seçim! Lütfen tekrar deneyin." << endl;
        }
    }
}
