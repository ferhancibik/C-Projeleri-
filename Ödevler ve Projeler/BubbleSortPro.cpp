#include <iostream>
using namespace std;

// Diziyi ekrana yazdıran fonksiyon
void diziYazdir(int dizi[], int boyut) {
    for(int i = 0; i < boyut; i++) {
        cout << " " << dizi[i];
    }
    cout << endl;
}

// BubbleSort algoritmasını uygulayan fonksiyon
void bubbleSort(int dizi[], int boyut) {
    int yedek;
    for(int i = 0; i < boyut; i++) {
        for(int j = 0; j < boyut-1; j++) {
            if(dizi[j] > dizi[j+1]) {
                yedek = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = yedek;
            }
        }
    }
}

int main() {
    int sayilar[] = {5, 21, 12, 3, 66, 52, 7};
    int diziBoyutu = sizeof(sayilar) / sizeof(sayilar[0]);

    cout << "Orjinal Dizi:" << endl;
    diziYazdir(sayilar, diziBoyutu);

    // BubbleSort algoritmasını uygula
    bubbleSort(sayilar, diziBoyutu);

    cout << "-------- BubbleSort Sonrasi Dizi --------" << endl;
    diziYazdir(sayilar, diziBoyutu);

    return 0;
}
