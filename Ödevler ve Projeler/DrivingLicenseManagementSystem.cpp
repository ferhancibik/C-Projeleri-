#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale.h> // Türkçe karakter desteği için

using namespace std;

struct kisiBilgileri {
    string ad;
    string soyad;
    int yas;
    string tc;
    string ehliyetBilgisi;
    string saglikRaporu;
    float fiyat;
    string gozluklu;
};

// Kişi bilgilerini dosyaya yazdırma
void kisiYazdir() {
    ofstream bilgiler("KisiBilgileri.txt", ios::app);
    if (!bilgiler) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    kisiBilgileri kisi;
    cout << "Adını Girin: ";
    cin >> kisi.ad;
    cout << "Soyad Girin: ";
    cin >> kisi.soyad;
    cout << "Yaşını Girin: ";
    cin >> kisi.yas;
    cout << "TC Girin: ";
    cin >> kisi.tc;
    cout << "Almak İstediğiniz Ehliyeti Girin (A, A1, A2, B, F, vb.): ";
    cin >> kisi.ehliyetBilgisi;
    cout << "Sağlık Raporu Var mı? (Evet/Hayır): ";
    cin >> kisi.saglikRaporu;
    cout << "Gözlüklü mü? (Evet/Hayır): ";
    cin >> kisi.gozluklu;

    // Ehliyet türüne göre fiyatlandırma
    if (kisi.ehliyetBilgisi == "A" || kisi.ehliyetBilgisi == "A1" || kisi.ehliyetBilgisi == "A2" || kisi.ehliyetBilgisi == "F")
        kisi.fiyat = 1960;
    else if (kisi.ehliyetBilgisi == "B")
        kisi.fiyat = 3624.90;
    else
        kisi.fiyat = 5289.70;

    // Dosyaya yazdırma
    bilgiler << kisi.ad << setw(15) << kisi.soyad << setw(10) << kisi.yas << setw(15) << kisi.tc << setw(10)
             << kisi.ehliyetBilgisi << setw(10) << kisi.saglikRaporu << setw(10) << kisi.gozluklu << setw(10) << kisi.fiyat << endl;
    bilgiler.close();
    cout << "Kişi bilgileri başarıyla kaydedildi!" << endl;
}

// Kişi bilgilerini silme
void kisiSil() {
    ifstream okunacak("KisiBilgileri.txt");
    ofstream gecici("yedek.txt", ios::app);
    if (!okunacak || !gecici) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    kisiBilgileri kisi;
    string kontrolTc;
    cout << "Silmek İstediğiniz Kişinin TC'sini Girin: ";
    cin >> kontrolTc;

    bool bulundu = false;
    while (okunacak >> kisi.ad >> kisi.soyad >> kisi.yas >> kisi.tc >> kisi.ehliyetBilgisi >> kisi.saglikRaporu >> kisi.gozluklu >> kisi.fiyat) {
        if (kisi.tc == kontrolTc) {
            bulundu = true;
            cout << "Kişi bilgileri silindi: " << kisi.ad << " " << kisi.soyad << endl;
        } else {
            gecici << kisi.ad << setw(15) << kisi.soyad << setw(10) << kisi.yas << setw(15) << kisi.tc << setw(10)
                   << kisi.ehliyetBilgisi << setw(10) << kisi.saglikRaporu << setw(10) << kisi.gozluklu << setw(10) << kisi.fiyat << endl;
        }
    }

    if (!bulundu) {
        cout << "Belirtilen TC'ye sahip kişi bulunamadı!" << endl;
    }

    okunacak.close();
    gecici.close();
    remove("KisiBilgileri.txt");
    rename("yedek.txt", "KisiBilgileri.txt");
}

// Kişi bilgilerini güncelleme
void kisiGuncelle() {
    ifstream okunacak("KisiBilgileri.txt");
    ofstream gecici("yedek.txt", ios::app);
    if (!okunacak || !gecici) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    kisiBilgileri kisi;
    string kontrolTc;
    cout << "Güncellemek İstediğiniz Kişinin TC'sini Girin: ";
    cin >> kontrolTc;

    bool bulundu = false;
    while (okunacak >> kisi.ad >> kisi.soyad >> kisi.yas >> kisi.tc >> kisi.ehliyetBilgisi >> kisi.saglikRaporu >> kisi.gozluklu >> kisi.fiyat) {
        if (kisi.tc == kontrolTc) {
            bulundu = true;
            cout << "Yeni Adını Girin: ";
            cin >> kisi.ad;
            cout << "Yeni Soyad Girin: ";
            cin >> kisi.soyad;
            cout << "Yeni Yaşını Girin: ";
            cin >> kisi.yas;
            cout << "Yeni TC Girin: ";
            cin >> kisi.tc;
            cout << "Yeni Ehliyet Türü Girin: ";
            cin >> kisi.ehliyetBilgisi;
            cout << "Yeni Sağlık Raporu Durumu (Evet/Hayır): ";
            cin >> kisi.saglikRaporu;
            cout << "Yeni Gözlük Durumu (Evet/Hayır): ";
            cin >> kisi.gozluklu;

            // Fiyatı güncelle
            if (kisi.ehliyetBilgisi == "A" || kisi.ehliyetBilgisi == "A1" || kisi.ehliyetBilgisi == "A2" || kisi.ehliyetBilgisi == "F")
                kisi.fiyat = 1960;
            else if (kisi.ehliyetBilgisi == "B")
                kisi.fiyat = 3624.90;
            else
                kisi.fiyat = 5289.70;

            cout << "Kişi bilgileri güncellendi!" << endl;
        }
        gecici << kisi.ad << setw(15) << kisi.soyad << setw(10) << kisi.yas << setw(15) << kisi.tc << setw(10)
               << kisi.ehliyetBilgisi << setw(10) << kisi.saglikRaporu << setw(10) << kisi.gozluklu << setw(10) << kisi.fiyat << endl;
    }

    if (!bulundu) {
        cout << "Belirtilen TC'ye sahip kişi bulunamadı!" << endl;
    }

    okunacak.close();
    gecici.close();
    remove("KisiBilgileri.txt");
    rename("yedek.txt", "KisiBilgileri.txt");
}

// Kişi bilgilerini listeleme
void kisiListele() {
    ifstream okunacak("KisiBilgileri.txt");
    if (!okunacak) {
        cerr << "Dosya açılamadı!" << endl;
        return;
    }

    kisiBilgileri kisi;
    cout << "Ad" << setw(15) << "Soyad" << setw(10) << "Yaş" << setw(15) << "TC" << setw(10)
         << "Ehliyet" << setw(10) << "Sağlık" << setw(10) << "Gözlük" << setw(10) << "Fiyat" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    while (okunacak >> kisi.ad >> kisi.soyad >> kisi.yas >> kisi.tc >> kisi.ehliyetBilgisi >> kisi.saglikRaporu >> kisi.gozluklu >> kisi.fiyat) {
        cout << kisi.ad << setw(15) << kisi.soyad << setw(10) << kisi.yas << setw(15) << kisi.tc << setw(10)
             << kisi.ehliyetBilgisi << setw(10) << kisi.saglikRaporu << setw(10) << kisi.gozluklu << setw(10) << kisi.fiyat << endl;
    }
    okunacak.close();
}

// Ana menü
void menuGoster() {
    cout << "----------------------------------" << endl;
    cout << "--------- Ehliyet Kayıt Sistemi ---------" << endl;
    cout << "1. Kişi Ekle" << endl;
    cout << "2. Kişi Listele" << endl;
    cout << "3. Kişi Güncelle" << endl;
    cout << "4. Kişi Sil" << endl;
    cout << "5. Çıkış" << endl;
    cout << "----------------------------------" << endl;
    cout << "Seçim Girin: ";
}

int main() {
    setlocale(LC_ALL, "turkish"); // Türkçe karakter desteği
    char secim;

    while (true) {
        menuGoster();
        cin >> secim;

        switch (secim) {
            case '1':
                kisiYazdir();
                break;
            case '2':
                kisiListele();
                break;
            case '3':
                kisiGuncelle();
                break;
            case '4':
                kisiSil();
                break;
            case '5':
                cout << "Çıkış yapılıyor..." << endl;
                return 0;
            default:
                cout << "Geçersiz seçim! Lütfen tekrar deneyin." << endl;
        }
    }
}
