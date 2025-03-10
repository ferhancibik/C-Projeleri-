#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // sleep fonksiyonu için
using namespace std;

int main() {
    srand(time(0));
    int puan = 0;
    int soruSayisi = 10;
    int sure = 30; // Oyun süresi (saniye)
    int zorluk = 1; // 1: Kolay, 2: Orta, 3: Zor
    time_t baslangicZamani = time(0);

    cout << "MathRush'a Hoş Geldiniz!" << endl;
    cout << "Amacınız, " << sure << " saniye içinde mümkün olduğunca çok matematik sorusunu doğru cevaplamak!" << endl;
    cout << "Zorluk seviyesi seçin (1: Kolay, 2: Orta, 3: Zor): ";
    cin >> zorluk;

    if (zorluk < 1 || zorluk > 3) {
        cout << "Geçersiz zorluk seviyesi! Varsayılan olarak kolay seçildi." << endl;
        zorluk = 1;
    }

    cout << "Oyun başlıyor! Hazır olun..." << endl;
    sleep(2);

    while (true) {
        time_t simdikiZaman = time(0);
        if (simdikiZaman - baslangicZamani >= sure) {
            cout << "Süre bitti! Toplam puanınız: " << puan << endl;
            break;
        }

        int sayi1, sayi2;
        switch (zorluk) {
            case 1:
                sayi1 = rand() % 10 + 1;
                sayi2 = rand() % 10 + 1;
                break;
            case 2:
                sayi1 = rand() % 50 + 1;
                sayi2 = rand() % 50 + 1;
                break;
            case 3:
                sayi1 = rand() % 100 + 1;
                sayi2 = rand() % 100 + 1;
                break;
        }

        int islem = rand() % 3; // 0: Toplama, 1: Çıkarma, 2: Çarpma
        int dogruCevap, kullaniciCevap;

        switch (islem) {
            case 0:
                cout << "Soru: " << sayi1 << " + " << sayi2 << " = ";
                dogruCevap = sayi1 + sayi2;
                break;
            case 1:
                cout << "Soru: " << sayi1 << " - " << sayi2 << " = ";
                dogruCevap = sayi1 - sayi2;
                break;
            case 2:
                cout << "Soru: " << sayi1 << " * " << sayi2 << " = ";
                dogruCevap = sayi1 * sayi2;
                break;
        }

        cin >> kullaniciCevap;

        if (kullaniciCevap == dogruCevap) {
            cout << "Doğru! +10 puan" << endl;
            puan += 10;
        } else {
            cout << "Yanlış! Doğru cevap: " << dogruCevap << endl;
        }
    }

    cout << "Oyun bitti. Toplam puanınız: " << puan << endl;
    if (puan >= 80) {
        cout << "Harika bir performans! Matematik dehasısınız." << endl;
    } else if (puan >= 50) {
        cout << "İyi bir performans! Biraz daha pratik yapmalısınız." << endl;
    } else {
        cout << "Daha çok çalışmalısınız! Pes etmeyin." << endl;
    }

    return 0;
}
