#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <locale.h>
using namespace std;

// Ürün bilgileri yapısı
struct Urun {
    string seriNo;
    string urunAdi;
    string musteriAdi;
    string talepTarihi;
    string talepTuru; // "iade" veya "garanti"
    string durum; // "beklemede", "onaylandı", "reddedildi"
    string garantiBitisTarihi;
    string iadeBitisTarihi;
};

const string TALEP_DOSYASI = "talepler.txt";

// Tarih kontrol fonksiyonu
bool tarihGecmismi(string tarih) {
    time_t simdi = time(0);
    tm *ltm = localtime(&simdi);

    int gun = stoi(tarih.substr(0, 2));
    int ay = stoi(tarih.substr(3, 2));
    int yil = stoi(tarih.substr(6, 4));

    if (yil < 1900 + ltm->tm_year) return true;
    if (yil == 1900 + ltm->tm_year && ay < 1 + ltm->tm_mon) return true;
    if (yil == 1900 + ltm->tm_year && ay == 1 + ltm->tm_mon && gun < ltm->tm_mday) return true;
    return false;
}

// Talep ekleme fonksiyonu
void talepEkle() {
    ofstream dosya(TALEP_DOSYASI, ios::app);
    Urun yeniTalep;

    cout << "Seri No: ";
    cin >> yeniTalep.seriNo;

    cout << "Ürün Adı: ";
    cin.ignore();
    getline(cin, yeniTalep.urunAdi);

    cout << "Müşteri Adı: ";
    getline(cin, yeniTalep.musteriAdi);

    cout << "Talep Tarihi (GG/AA/YYYY): ";
    getline(cin, yeniTalep.talepTarihi);

    cout << "Talep Türü (iade/garanti): ";
    getline(cin, yeniTalep.talepTuru);

    if (yeniTalep.talepTuru == "garanti") {
        cout << "Garanti Bitiş Tarihi (GG/AA/YYYY): ";
        getline(cin, yeniTalep.garantiBitisTarihi);
        yeniTalep.iadeBitisTarihi = "Yok";
    } else if (yeniTalep.talepTuru == "iade") {
        cout << "İade Bitiş Tarihi (GG/AA/YYYY): ";
        getline(cin, yeniTalep.iadeBitisTarihi);
        yeniTalep.garantiBitisTarihi = "Yok";
    }

    yeniTalep.durum = "beklemede";

    // Talebi dosyaya kaydet
    dosya << yeniTalep.seriNo << " | " << yeniTalep.urunAdi << " | " << yeniTalep.musteriAdi << " | "
          << yeniTalep.talepTarihi << " | " << yeniTalep.talepTuru << " | " << yeniTalep.durum << " | "
          << yeniTalep.garantiBitisTarihi << " | " << yeniTalep.iadeBitisTarihi << endl;

    cout << "Talep başarıyla eklendi!" << endl;
    dosya.close();
}

// Talepleri listeleme fonksiyonu
void talepleriListele() {
    ifstream dosya(TALEP_DOSYASI);
    Urun talep;

    cout << setw(15) << "Seri No" << setw(20) << "Ürün Adı" << setw(20) << "Müşteri Adı"
         << setw(15) << "Talep Tarihi" << setw(10) << "Tür" << setw(15) << "Durum"
         << setw(20) << "Garanti Bitiş" << setw(20) << "İade Bitiş" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    string satir;
    while (getline(dosya, satir)) {
        cout << satir << endl;
    }

    dosya.close();
}

// Talep durumunu güncelleme fonksiyonu
void talepDurumGuncelle() {
    ifstream okumaDosyasi(TALEP_DOSYASI);
    ofstream yedekDosya("yedek.txt");
    string seriNo, yeniDurum;

    cout << "Durumunu güncellemek istediğiniz talebin seri numarasını girin: ";
    cin >> seriNo;

    cout << "Yeni durumu girin (onaylandı/reddedildi): ";
    cin >> yeniDurum;

    string satir;
    bool bulundu = false;

    while (getline(okumaDosyasi, satir)) {
        if (satir.find(seriNo) != string::npos) {
            size_t pos = satir.find_last_of("|");
            satir.replace(pos + 2, string::npos, yeniDurum);
            bulundu = true;
        }
        yedekDosya << satir << endl;
    }

    if (bulundu) {
        cout << "Talep durumu güncellendi!" << endl;
    } else {
        cout << "Talep bulunamadı!" << endl;
    }

    okumaDosyasi.close();
    yedekDosya.close();

    remove(TALEP_DOSYASI.c_str());
    rename("yedek.txt", TALEP_DOSYASI.c_str());
}

// Garanti ve iade süresi kontrol fonksiyonu
void sureKontrol() {
    ifstream dosya(TALEP_DOSYASI);
    string satir;

    cout << "Garanti ve İade Süresi Kontrolü:" << endl;
    cout << "--------------------------------" << endl;

    while (getline(dosya, satir)) {
        size_t pos1 = satir.find_last_of("|");
        string iadeBitisTarihi = satir.substr(pos1 + 2);
        string garantiBitisTarihi = satir.substr(satir.find_last_of("|", pos1 - 1) + 2, pos1 - (satir.find_last_of("|", pos1 - 1) + 2));

        if (garantiBitisTarihi != "Yok" && tarihGecmismi(garantiBitisTarihi)) {
            cout << "Garanti süresi dolmuş ürün: " << satir << endl;
        }
        if (iadeBitisTarihi != "Yok" && tarihGecmismi(iadeBitisTarihi)) {
            cout << "İade süresi dolmuş ürün: " << satir << endl;
        }
    }

    dosya.close();
}

// Ana menü fonksiyonu
void anaMenu() {
    char secim;

    do {
        cout << "\n><(((º> *TEKNOLOJİ İADE VE GARANTİ OTOMASYONU* <º)))><" << endl;
        cout << "1. Yeni Talep Ekle" << endl;
        cout << "2. Talepleri Listele" << endl;
        cout << "3. Talep Durumunu Güncelle" << endl;
        cout << "4. Garanti ve İade Süresi Kontrolü" << endl;
        cout << "5. Çıkış" << endl;

        cout << "Seçiminizi yapın: ";
        cin >> secim;

        switch (secim) {
            case '1': talepEkle(); break;
            case '2': talepleriListele(); break;
            case '3': talepDurumGuncelle(); break;
            case '4': sureKontrol(); break;
            case '5': cout << "Programdan çıkılıyor..." << endl; break;
            default: cout << "Geçersiz seçim! Lütfen 1-5 arasında bir seçim yapın." << endl;
        }

        if (secim != '5') {
            cout << "Ana menüye dönmek ister misiniz? (E/H): ";
            cin >> secim;
        }
    } while (secim == 'e' || secim == 'E');
}

int main() {
    setlocale(LC_ALL, "Turkish");
    anaMenu();
    return 0;
}
