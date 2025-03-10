#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cctype> 

using namespace std;

// Fonksiyon prototipleri
void kisaltmaYap(const string& cumle);
void buyukHarfeCevir(string& cumle);
void rakamlariAyir(string& cumle);
void tersCevir(const string& cumle);
void kelimeDegistir(string& cumle);
void tumunuBuyukHarfeCevir(string& cumle);
void tumunuKucukHarfeCevir(string& cumle);
void rakamlariSay(const string& cumle);
void unluleriSay(const string& cumle);
void kelimeSayisiniBul(const string& cumle);
void rastgeleKelimeUret();

int main() {
    setlocale(LC_ALL, "Turkish");

    int program;
    char karakter;
    string cumle;

    cout << "1. Kısaltma Yapma\n"
         << "2. Küçük Harfleri Büyük Harfe Çevirme\n"
         << "3. Rakamları Ayırma\n"
         << "4. Cümleyi Ters Çevirme\n"
         << "5. Kelime Değiştirme\n"
         << "6. Tümünü Büyük Harfe Çevirme\n"
         << "7. Tümünü Küçük Harfe Çevirme\n"
         << "8. Rakamları Sayma\n"
         << "9. Ünlü Harfleri Sayma\n"
         << "10. Kelime Sayısını Bulma\n"
         << "11. Rastgele Kelime Üretme\n"
         << "----------------------------------------\n";

    do {
        cout << "\nHangi Programa Girmek İstiyorsunuz? ";
        cin >> program;
        cin.ignore(); // Buffer temizleme

        switch (program) {
            case 1:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                kisaltmaYap(cumle);
                break;
            case 2:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                buyukHarfeCevir(cumle);
                break;
            case 3:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                rakamlariAyir(cumle);
                break;
            case 4:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                tersCevir(cumle);
                break;
            case 5:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                kelimeDegistir(cumle);
                break;
            case 6:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                tumunuBuyukHarfeCevir(cumle);
                break;
            case 7:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                tumunuKucukHarfeCevir(cumle);
                break;
            case 8:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                rakamlariSay(cumle);
                break;
            case 9:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                unluleriSay(cumle);
                break;
            case 10:
                cout << "Cümle Giriniz: ";
                getline(cin, cumle);
                kelimeSayisiniBul(cumle);
                break;
            case 11:
                rastgeleKelimeUret();
                break;
            default:
                cout << "Geçersiz seçim!\n";
                break;
        }

        cout << "Devam etmek istiyor musunuz? (e/h): ";
        cin >> karakter;
    } while (karakter == 'e' || karakter == 'E');

    cout << "Programdan çıktınız.\n";
    return 0;
}

// Fonksiyonların tanımları
void kisaltmaYap(const string& cumle) {
    string kisaltma;
    for (size_t i = 0; i < cumle.size(); i++) {
        if (i == 0 || cumle[i - 1] == ' ') {
            kisaltma += toupper(cumle[i]);
        }
    }
    cout << "Kısaltma: " << kisaltma << endl;
}

void buyukHarfeCevir(string& cumle) {
    for (char& c : cumle) {
        if (islower(c)) {
            c = toupper(c);
        }
    }
    cout << "Büyük Harf: " << cumle << endl;
}

void rakamlariAyir(string& cumle) {
    string rakamlar;
    for (size_t i = 0; i < cumle.size(); i++) {
        if (isdigit(cumle[i])) {
            rakamlar += cumle[i];
            cumle.erase(i, 1);
            i--;
        }
    }
    cout << "Rakamlar: " << rakamlar << endl;
    cout << "Rakamsız Cümle: " << cumle << endl;
}

void tersCevir(const string& cumle) {
    string tersCumle;
    for (int i = cumle.size() - 1; i >= 0; i--) {
        tersCumle += cumle[i];
    }
    cout << "Ters Cümle: " << tersCumle << endl;
}

void kelimeDegistir(string& cumle) {
    string aranan, yeni;
    cout << "Aranan Kelime: ";
    getline(cin, aranan);
    cout << "Yeni Kelime: ";
    getline(cin, yeni);

    size_t pos = cumle.find(aranan);
    if (pos != string::npos) {
        cumle.replace(pos, aranan.length(), yeni);
        cout << "Yeni Cümle: " << cumle << endl;
    } else {
        cout << "Kelime bulunamadı!\n";
    }
}

void tumunuBuyukHarfeCevir(string& cumle) {
    for (char& c : cumle) {
        c = toupper(c);
    }
    cout << "Büyük Harf: " << cumle << endl;
}

void tumunuKucukHarfeCevir(string& cumle) {
    for (char& c : cumle) {
        c = tolower(c);
    }
    cout << "Küçük Harf: " << cumle << endl;
}

void rakamlariSay(const string& cumle) {
    int sayac = 0;
    for (char c : cumle) {
        if (isdigit(c)) {
            sayac++;
        }
    }
    cout << "Rakam Sayısı: " << sayac << endl;
}

void unluleriSay(const string& cumle) {
    int sayac = 0;
    for (char c : cumle) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            sayac++;
        }
    }
    cout << "Ünlü Harf Sayısı: " << sayac << endl;
}

void kelimeSayisiniBul(const string& cumle) {
    int sayac = 0;
    for (size_t i = 0; i < cumle.size(); i++) {
        if (cumle[i] != ' ' && (i == 0 || cumle[i - 1] == ' ')) {
            sayac++;
        }
    }
    cout << "Kelime Sayısı: " << sayac << endl;
}

void rastgeleKelimeUret() {
    srand(time(0));
    string rastgeleKelime;
    for (int i = 0; i < 10; i++) {
        rastgeleKelime += rand() % 26 + 'a';
    }
    cout << "Rastgele Kelime: " << rastgeleKelime << endl;
}
