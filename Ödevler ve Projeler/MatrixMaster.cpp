#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOYUT = 4; // Matris boyutu

// Matris oluşturma fonksiyonu
void matrisOlustur(int matris[BOYUT][BOYUT]) {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            matris[i][j] = rand() % 2; // 0 veya 1 rastgele değer
        }
    }
}

// Matris yazdırma fonksiyonu
void matrisYazdir(const int matris[BOYUT][BOYUT], const string& matrisAdi) {
    cout << "  " << matrisAdi << " Matrisi" << endl;
    for (int i = 0; i < BOYUT; i++) {
        cout << "|";
        for (int j = 0; j < BOYUT; j++) {
            cout << " " << matris[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

// Matrisleri karşılaştırma fonksiyonu
int matrisKarsilastir(const int matrisA[BOYUT][BOYUT], const int matrisB[BOYUT][BOYUT]) {
    int ayni = 0;
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            if (matrisA[i][j] == matrisB[i][j]) {
                ayni++;
            }
        }
    }
    return ayni;
}

// Matris toplama fonksiyonu
void matrisTopla(const int matrisA[BOYUT][BOYUT], const int matrisB[BOYUT][BOYUT], int sonuc[BOYUT][BOYUT]) {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            sonuc[i][j] = matrisA[i][j] + matrisB[i][j];
        }
    }
}

// Matris çarpma fonksiyonu
void matrisCarp(const int matrisA[BOYUT][BOYUT], const int matrisB[BOYUT][BOYUT], int sonuc[BOYUT][BOYUT]) {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            sonuc[i][j] = 0;
            for (int k = 0; k < BOYUT; k++) {
                sonuc[i][j] += matrisA[i][k] * matrisB[k][j];
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");
    srand(time(0));

    int matrisA[BOYUT][BOYUT];
    int matrisB[BOYUT][BOYUT];
    int toplamMatris[BOYUT][BOYUT];
    int carpimMatris[BOYUT][BOYUT];

    // Matrisleri oluştur
    matrisOlustur(matrisA);
    matrisOlustur(matrisB);

    // Matrisleri yazdır
    matrisYazdir(matrisA, "A");
    cout << "--------------------------------" << endl;
    matrisYazdir(matrisB, "B");

    // Matrisleri karşılaştır
    int ayniDegerSayisi = matrisKarsilastir(matrisA, matrisB);
    cout << "--------------------------------" << endl;
    cout << "Aynı olan değer sayısı: " << ayniDegerSayisi << endl;

    // Matrisleri topla
    matrisTopla(matrisA, matrisB, toplamMatris);
    cout << "--------------------------------" << endl;
    matrisYazdir(toplamMatris, "A + B Toplam Matris");

    // Matrisleri çarp
    matrisCarp(matrisA, matrisB, carpimMatris);
    cout << "--------------------------------" << endl;
    matrisYazdir(carpimMatris, "A x B Çarpım Matris");

    return 0;
}
