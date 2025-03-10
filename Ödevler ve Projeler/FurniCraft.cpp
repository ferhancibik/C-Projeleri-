#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

// Kumaş yapısı
struct Kumas {
    string iplikTipi;
    int dm2Agirlik;
    string dokumaTipi;
    string renk;
    int miktar;
};

// İskelet yapısı
struct Iskelet {
    string malzeme;
    string birlestirme;
    string tarz;
    string boyut;
    int miktar;
};

// Mobilya yapısı
struct Mobilya {
    Kumas kaplama;
    Iskelet iskelet;
    int fiyat;
    int adet;
};

// Ürün bilgilerini giren fonksiyon
void urunBilgileriniGir(Mobilya& urun) {
    cout << "dm2 ağırlık: ";
    cin >> urun.kaplama.dm2Agirlik;

    cout << "Kumaş dokuma tipi: ";
    cin >> urun.kaplama.dokumaTipi;

    cout << "Kumaş iplik tipi: ";
    cin >> urun.kaplama.iplikTipi;

    cout << "Kumaş miktar: ";
    cin >> urun.kaplama.miktar;

    cout << "Kumaş rengi: ";
    cin >> urun.kaplama.renk;

    cout << "İskelet birleştirme: ";
    cin >> urun.iskelet.birlestirme;

    cout << "İskelet boyut: ";
    cin >> urun.iskelet.boyut;

    cout << "İskelet malzeme: ";
    cin >> urun.iskelet.malzeme;

    cout << "İskelet miktar: ";
    cin >> urun.iskelet.miktar;

    cout << "İskelet tarz: ";
    cin >> urun.iskelet.tarz;

    cout << "Ürün adet: ";
    cin >> urun.adet;

    cout << "Ürün fiyat: ";
    cin >> urun.fiyat;
}

// Ürün bilgilerini gösteren fonksiyon
void urunBilgileriniGoster(const Mobilya& urun, int indeks) {
    cout << indeks + 1 << ". dm2 ağırlık: " << urun.kaplama.dm2Agirlik << endl;
    cout << indeks + 1 << ". Kumaş dokuma tipi: " << urun.kaplama.dokumaTipi << endl;
    cout << indeks + 1 << ". Kumaş iplik tipi: " << urun.kaplama.iplikTipi << endl;
    cout << indeks + 1 << ". Kumaş miktar: " << urun.kaplama.miktar << endl;
    cout << indeks + 1 << ". Kumaş rengi: " << urun.kaplama.renk << endl;
    cout << indeks + 1 << ". İskelet birleştirme: " << urun.iskelet.birlestirme << endl;
    cout << indeks + 1 << ". İskelet boyut: " << urun.iskelet.boyut << endl;
    cout << indeks + 1 << ". İskelet malzeme: " << urun.iskelet.malzeme << endl;
    cout << indeks + 1 << ". İskelet miktar: " << urun.iskelet.miktar << endl;
    cout << indeks + 1 << ". İskelet tarz: " << urun.iskelet.tarz << endl;
    cout << indeks + 1 << ". Ürün adet: " << urun.adet << endl;
    cout << indeks + 1 << ". Ürün fiyat: " << urun.fiyat << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");

    const int urunSayisi = 1;
    Mobilya urunler[urunSayisi];
    int toplamFiyat = 0;

    // Ürün bilgilerini alma
    for (int i = 0; i < urunSayisi; i++) {
        cout << i + 1 << ". ürün bilgilerini girin:" << endl;
        urunBilgileriniGir(urunler[i]);
        toplamFiyat += urunler[i].fiyat * urunler[i].adet;
    }

    // Ürün bilgilerini gösterme
    cout << "---------------------------- ÜRÜN BİLGİLERİ ------------------------" << endl;
    for (int j = 0; j < urunSayisi; j++) {
        urunBilgileriniGoster(urunler[j], j);
    }

    cout << "TOPLAM FİYAT: " << toplamFiyat << " TL" << endl;

    system("pause");
    return 0;
}
