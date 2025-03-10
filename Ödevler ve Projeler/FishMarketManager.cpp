#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h>
#include <conio.h>
using namespace std;

// Balık bilgileri yapısı
struct Balik {
    string isim;
    float stok;
    float fiyat;
};

// Satış bilgileri yapısı
struct Satis {
    Balik satilanBalik;
    int adet;
    float toplamFiyat;
};

// Dosya adları
const string BALIK_DOSYASI = "balik.txt";
const string SATIS_DOSYASI = "satis.txt";

// Balık ekleme fonksiyonu
void balikEkle() {
    ofstream dosya(BALIK_DOSYASI, ios::app);
    char secim;
    int sayac = 0;
    Balik balik;

    do {
        cout << "Balık ismi giriniz: ";
        cin >> balik.isim;

        cout << "Lütfen " << balik.isim << " balığının stoğunu giriniz: ";
        cin >> balik.stok;

        cout << "Lütfen " << balik.isim << " balığının fiyatını giriniz: ";
        cin >> balik.fiyat;

        dosya << endl << balik.isim << setw(15) << balik.stok << setw(15) << balik.fiyat;

        cout << "Başka balık girişi yapmak ister misiniz? (E/H): ";
        secim = getche();
        cout << endl;
        sayac++;
    } while (secim == 'e' || secim == 'E');

    cout << sayac << " adet balık girişi yapıldı." << endl;
    dosya.close();
}

// Balık listeleme fonksiyonu
void balikListele() {
    Balik balik;
    ifstream dosya(BALIK_DOSYASI);

    cout << setw(15) << "BALIK" << setw(15) << "STOK" << setw(15) << "FIYAT" << endl;
    while (dosya >> balik.isim >> balik.stok >> balik.fiyat) {
        cout << setw(15) << balik.isim << setw(15) << balik.stok << setw(15) << balik.fiyat << endl;
    }
    dosya.close();
}

// Balık arama fonksiyonu
void balikAra() {
    Balik balik;
    ifstream dosya(BALIK_DOSYASI);
    string arananBalik;

    cout << "Hangi balığı görmek istiyorsunuz?: ";
    cin >> arananBalik;

    cout << setw(15) << "BALIK" << setw(15) << "STOK" << setw(15) << "FIYAT" << endl;
    bool bulundu = false;

    while (dosya >> balik.isim >> balik.stok >> balik.fiyat) {
        if (balik.isim == arananBalik) {
            cout << setw(15) << balik.isim << setw(15) << balik.stok << setw(15) << balik.fiyat << endl;
            bulundu = true;
            break;
        }
    }

    if (!bulundu) {
        cout << "Böyle bir balık bulunamadı!" << endl;
    }
    dosya.close();
}

// Balık satış fonksiyonu
void balikSat() {
    Balik balik;
    Satis satis;
    ifstream okuma(BALIK_DOSYASI);
    ofstream yedek("yedek.txt");
    ofstream satisDosyasi(SATIS_DOSYASI, ios::app);
    char secim;

    do {
        balikListele();
        cout << "Hangi balığı satmak istiyorsunuz?: ";
        string satilacakBalik;
        cin >> satilacakBalik;

        bool bulundu = false;
        while (okuma >> balik.isim >> balik.stok >> balik.fiyat) {
            if (balik.isim == satilacakBalik) {
                cout << "Kaç kg satmak istiyorsunuz?: ";
                cin >> satis.adet;

                if (satis.adet <= balik.stok) {
                    balik.stok -= satis.adet;
                    satis.toplamFiyat = satis.adet * balik.fiyat;
                    satisDosyasi << endl << balik.isim << setw(15) << balik.fiyat << setw(15) << satis.adet << setw(15) << satis.toplamFiyat;
                    cout << "Toplam ödenecek tutar: " << satis.toplamFiyat << " TL" << endl;
                } else {
                    cout << "Yeterli stok yok! Mevcut stok: " << balik.stok << " kg" << endl;
                }
                bulundu = true;
            }
            yedek << endl << balik.isim << setw(15) << balik.stok << setw(15) << balik.fiyat;
        }

        if (!bulundu) {
            cout << "Böyle bir balık bulunamadı!" << endl;
        }

        cout << "Başka satış yapmak ister misiniz? (E/H): ";
        secim = getche();
        cout << endl;
    } while (secim == 'e' || secim == 'E');

    okuma.close();
    yedek.close();
    satisDosyasi.close();

    remove(BALIK_DOSYASI.c_str());
    rename("yedek.txt", BALIK_DOSYASI.c_str());
}

// Satış listeleme fonksiyonu
void satisListele() {
    Satis satis;
    ifstream dosya(SATIS_DOSYASI);
    float toplamKazanc = 0;

    cout << setw(15) << "BALIK" << setw(15) << "FIYAT" << setw(15) << "ADET" << setw(15) << "TOPLAM" << endl;
    while (dosya >> satis.satilanBalik.isim >> satis.satilanBalik.fiyat >> satis.adet >> satis.toplamFiyat) {
        cout << setw(15) << satis.satilanBalik.isim << setw(15) << satis.satilanBalik.fiyat << setw(15) << satis.adet << setw(15) << satis.toplamFiyat << endl;
        toplamKazanc += satis.toplamFiyat;
    }

    cout << "Toplam Kazanç: " << toplamKazanc << " TL" << endl;
    dosya.close();
}

// Ana menü fonksiyonu
void anaMenu() {
    char secim;

    do {
        system("cls");
        cout << "><(((º> *BALIKÇI OTOMASYONU* <º)))><" << endl;
        cout << "1. Balık Ekle" << endl;
        cout << "2. Balık Listele" << endl;
        cout << "3. Balık Ara" << endl;
        cout << "4. Balık Sat" << endl;
        cout << "5. Satışları Listele" << endl;
        cout << "6. Çıkış" << endl;

        cout << "Seçiminizi yapın: ";
        secim = getche();
        cout << endl;

        switch (secim) {
            case '1': balikEkle(); break;
            case '2': balikListele(); break;
            case '3': balikAra(); break;
            case '4': balikSat(); break;
            case '5': satisListele(); break;
            case '6': cout << "Programdan çıkılıyor..." << endl; break;
            default: cout << "Geçersiz seçim! Lütfen 1-6 arasında bir seçim yapın." << endl;
        }

        if (secim != '6') {
            cout << "Ana menüye dönmek ister misiniz? (E/H): ";
            secim = getche();
            cout << endl;
        }
    } while (secim == 'e' || secim == 'E');
}

int main() {
    setlocale(LC_ALL, "Turkish");
    anaMenu();
    return 0;
}
