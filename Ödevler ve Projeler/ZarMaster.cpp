#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

// Zar atma fonksiyonu
int zarAt() {
    return rand() % 6 + 1;
}

// Oyunu başlatan fonksiyon
void zarOyunu() {
    setlocale(LC_ALL, "Turkish");
    srand(time(0));

    char devam = 'E';
    int toplamPuan = 0;

    cout << "ZarMaster Oyununa Hoş Geldiniz!" << endl;
    cout << "Bilgisayarın attığı zarı tahmin etmeye çalışın." << endl;

    while (devam == 'E' || devam == 'e') {
        int bilgisayarZari = zarAt();
        int tahmin = 0;
        int sayac = 0;

        cout << "\nBilgisayar zarını attı. Tahmininizi yapın (1-6): ";
        cin >> tahmin;

        while (tahmin < 1 || tahmin > 6) {
            cout << "Geçersiz tahmin! Lütfen 1 ile 6 arasında bir sayı girin: ";
            cin >> tahmin;
        }

        while (true) {
            int kullaniciZari = zarAt();
            sayac++;
            cout << sayac << ". deneme: " << kullaniciZari << endl;

            if (kullaniciZari == bilgisayarZari) {
                cout << "Tebrikler! " << sayac << ". denemede bilgisayarın zarını buldunuz." << endl;
                cout << "Bilgisayarın zarı: " << bilgisayarZari << endl;
                toplamPuan += 10 - sayac; // Puanlama sistemi
                break;
            }

            if (sayac == 10) {
                cout << "Maalesef 10 denemede bilemediniz. Bilgisayarın zarı: " << bilgisayarZari << endl;
                break;
            }
        }

        cout << "Toplam Puanınız: " << toplamPuan << endl;
        cout << "Devam etmek istiyor musunuz? (E/H): ";
        cin >> devam;
    }

    cout << "\nOyun bitti. Toplam Puanınız: " << toplamPuan << endl;
    cout << "ZarMaster'ı oynadığınız için teşekkür ederiz!" << endl;
}

int main() {
    zarOyunu();
    return 0;
}
