#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

// Alıcı bilgileri
struct Alici {
    string adSoyad;
    string adres;
    string telefonNo;
};

// Kurye bilgileri
struct Kurye {
    string adSoyad;
    string telefonNo;
};

// Gönderen bilgileri
struct Gonderen {
    string adSoyad;
    string adres;
    string telefonNo;
};

// Gönderi süreci
struct Surec {
    string yolacikis;
    string teslimTarih;
};

// Gönderi bilgileri
struct Gonderi {
    int gonderiNo;
    int agirlik;
    int hacim;
    char garanti;
    int ucret;
    Alici aliciBilgileri;
    Kurye kuryeBilgileri;
    Gonderen gonderenBilgileri;
    Surec surecBilgileri;
};

// Gönderi bilgilerini giren fonksiyon
void gonderiBilgileriniGir(Gonderi& gonderi, int indeks) {
    cout << "---------------------- " << indeks + 1 << ". Gönderi --------------------" << endl;
    cout << "Gönderenin adı soyadı: ";
    cin >> gonderi.gonderenBilgileri.adSoyad;
    cout << "Gönderenin adresi: ";
    cin >> gonderi.gonderenBilgileri.adres;
    cout << "Gönderenin telefon numarası: ";
    cin >> gonderi.gonderenBilgileri.telefonNo;

    cout << "Alıcının adı soyadı: ";
    cin >> gonderi.aliciBilgileri.adSoyad;
    cout << "Alıcının adresi: ";
    cin >> gonderi.aliciBilgileri.adres;
    cout << "Alıcının telefon numarası: ";
    cin >> gonderi.aliciBilgileri.telefonNo;

    cout << "Kuryenin adı soyadı: ";
    cin >> gonderi.kuryeBilgileri.adSoyad;
    cout << "Kuryenin telefon numarası: ";
    cin >> gonderi.kuryeBilgileri.telefonNo;

    cout << "Gönderinin ağırlığı (kg): ";
    cin >> gonderi.agirlik;
    cout << "Gönderinin hacmi (cm³): ";
    cin >> gonderi.hacim;
    cout << "Gönderinin garantisi (E/H): ";
    cin >> gonderi.garanti;
    cout << "Gönderi numarası: ";
    cin >> gonderi.gonderiNo;
    cout << "Gönderi ücreti (TL): ";
    cin >> gonderi.ucret;
    cout << "Yola çıkış tarihi: ";
    cin >> gonderi.surecBilgileri.yolacikis;
    cout << "Teslim tarihi: ";
    cin >> gonderi.surecBilgileri.teslimTarih;
}

// Gönderi bilgilerini gösteren fonksiyon
void gonderiBilgileriniGoster(const Gonderi& gonderi, int indeks) {
    cout << "---------------------- " << indeks + 1 << ". Gönderi --------------------" << endl;
    cout << "Gönderenin adı soyadı: " << gonderi.gonderenBilgileri.adSoyad << endl;
    cout << "Gönderenin adresi: " << gonderi.gonderenBilgileri.adres << endl;
    cout << "Gönderenin telefon numarası: " << gonderi.gonderenBilgileri.telefonNo << endl;

    cout << "Alıcının adı soyadı: " << gonderi.aliciBilgileri.adSoyad << endl;
    cout << "Alıcının adresi: " << gonderi.aliciBilgileri.adres << endl;
    cout << "Alıcının telefon numarası: " << gonderi.aliciBilgileri.telefonNo << endl;

    cout << "Kuryenin adı soyadı: " << gonderi.kuryeBilgileri.adSoyad << endl;
    cout << "Kuryenin telefon numarası: " << gonderi.kuryeBilgileri.telefonNo << endl;

    cout << "Gönderinin ağırlığı: " << gonderi.agirlik << " kg" << endl;
    cout << "Gönderinin hacmi: " << gonderi.hacim << " cm³" << endl;
    cout << "Gönderinin garantisi: " << gonderi.garanti << endl;
    cout << "Gönderi numarası: " << gonderi.gonderiNo << endl;
    cout << "Gönderi ücreti: " << gonderi.ucret << " TL" << endl;
    cout << "Yola çıkış tarihi: " << gonderi.surecBilgileri.yolacikis << endl;
    cout << "Teslim tarihi: " << gonderi.surecBilgileri.teslimTarih << endl;
}

int main() {
    setlocale(LC_ALL, "Turkish");

    const int urunSayisi = 1;
    Gonderi gonderiler[urunSayisi];

    // Gönderi bilgilerini alma
    for (int i = 0; i < urunSayisi; i++) {
        gonderiBilgileriniGir(gonderiler[i], i);
    }

    // Gönderi bilgilerini gösterme
    for (int i = 0; i < urunSayisi; i++) {
        gonderiBilgileriniGoster(gonderiler[i], i);
    }

    system("pause");
    return 0;
}
