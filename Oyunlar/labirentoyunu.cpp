#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOYUT = 5;
char labirent[BOYUT][BOYUT];
int hareketSayisi = 20; 
int sure = 60; // Oyun süresi (saniye)
int puan = 0;

void labirentOlustur() {
    srand(time(0));
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            if (i == 0 && j == 0) {
                labirent[i][j] = 'S'; // Başlangıç
            } else if (i == BOYUT - 1 && j == BOYUT - 1) {
                labirent[i][j] = 'C'; // Çıkış
            } else {
                int rastgele = rand() % 3;
                if (rastgele == 0) {
                    labirent[i][j] = '#'; // Duvar
                } else {
                    labirent[i][j] = '.'; // Boş alan
                }
            }
        }
    }
}

void labirentGoster() {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            cout << labirent[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int x = 0, y = 0;
    char hareket;
    time_t baslangicZamani = time(0);

    cout << "MazeEscape'a Hoş Geldiniz!" << endl;
    cout << "Amacınız, " << sure << " saniye ve " << hareketSayisi << " hareket içinde labirentten çıkmak!" << endl;
    cout << "S: Başlangıç, C: Çıkış, #: Duvar, .: Boş alan, P: Oyuncu" << endl;

    labirentOlustur();
    labirent[x][y] = 'P'; 

    while (true) {
        time_t simdikiZaman = time(0);
        if (simdikiZaman - baslangicZamani >= sure) {
            cout << "Süre bitti! Labirentten çıkamadınız." << endl;
            break;
        }

        labirentGoster();
        cout << "Kalan hareket: " << hareketSayisi << " | Kalan süre: " << sure - (simdikiZaman - baslangicZamani) << " saniye" << endl;

        cout << "Hareket (W: Yukarı, S: Aşağı, A: Sol, D: Sağ): ";
        cin >> hareket;

        int yeniX = x, yeniY = y;

        switch (hareket) {
            case 'W': yeniX--; break;
            case 'S': yeniX++; break;
            case 'A': yeniY--; break;
            case 'D': yeniY++; break;
            default: cout << "Geçersiz hareket!" << endl; continue;
        }

        if (yeniX < 0 || yeniX >= BOYUT || yeniY < 0 || yeniY >= BOYUT || labirent[yeniX][yeniY] == '#') {
            cout << "Geçersiz hareket! Duvar veya sınır dışı." << endl;
        } else {
            labirent[x][y] = '.';
            x = yeniX;
            y = yeniY;
            labirent[x][y] = 'P'; // Oyuncunun konumu
            hareketSayisi--;

            if (x == BOYUT - 1 && y == BOYUT - 1) {
                puan = 100 - (simdikiZaman - baslangicZamani); // Süreye göre puan
                cout << "Tebrikler, çıkışa ulaştınız! Puanınız: " << puan << endl;
                break;
            }

            if (hareketSayisi == 0) {
                cout << "Hareket hakkınız bitti! Labirentten çıkamadınız." << endl;
                break;
            }
        }
    }

    return 0;
}
