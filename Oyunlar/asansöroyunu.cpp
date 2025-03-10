#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // sleep fonksiyonu için
using namespace std;

int main() {
    srand(time(0));
    int kat = 0;
    int hedefKat;
    char secim;
    int puan = 0;
    int sure = 30; // Oyun süresi (saniye)
    time_t baslangicZamani = time(0);

    cout << "Elevator Challenge'a Hoş Geldiniz!" << endl;
    cout << "Amacınız, " << sure << " saniye içinde en fazla sayıda kata ulaşmak!" << endl;
    cout << "Her başarılı hedef kat için 10 puan kazanırsınız." << endl;
    cout << "Dikkat! Rastgele engellerle karşılaşabilirsiniz." << endl;

    while (true) {
        time_t simdikiZaman = time(0);
        if (simdikiZaman - baslangicZamani >= sure) {
            cout << "Süre bitti! Toplam puanınız: " << puan << endl;
            break;
        }

        cout << "\nŞu anki kat: " << kat << endl;
        cout << "Hedef katı girin (0-9 arası, çıkmak için 'q'): ";
        cin >> secim;

        if (secim == 'q') {
            cout << "Oyundan çıkılıyor..." << endl;
            break;
        }

        hedefKat = secim - '0';

        if (hedefKat < 0 || hedefKat > 9) {
            cout << "Geçersiz kat! Lütfen 0 ile 9 arasında bir kat girin." << endl;
            continue;
        }

        cout << "Asansör hareket ediyor..." << endl;

        // Rastgele engel olasılığı (%20)
        if (rand() % 5 == 0) {
            cout << "Engel! Asansör arızalandı, 3 saniye bekleniyor..." << endl;
            sleep(3);
            continue;
        }

        if (hedefKat > kat) {
            while (kat < hedefKat) {
                kat++;
                cout << "Şu anki kat: " << kat << endl;
                sleep(1); // Her kat için 1 saniye bekle
            }
        } else if (hedefKat < kat) {
            while (kat > hedefKat) {
                kat--;
                cout << "Şu anki kat: " << kat << endl;
                sleep(1); // Her kat için 1 saniye bekle
            }
        }

        puan += 10;
        cout << "Hedef kata ulaşıldı: " << kat << " | Toplam puan: " << puan << endl;
    }

    return 0;
}
