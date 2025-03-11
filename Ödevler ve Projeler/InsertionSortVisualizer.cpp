#include <iostream>
using namespace std;

// Diziyi ekrana yazdıran fonksiyon
void diziYazdir(int dizi[], int boyut) {
    for(int i = 0; i < boyut; i++) {
        cout << dizi[i] << " ";
    }
    cout << endl;
}

// Insertion Sort algoritması
void insertionSort(int dizi[], int boyut) {
    int eleman;
    for(int i = 1; i < boyut; i++) {
        eleman = dizi[i];
        int j = i - 1;
        
        while(j >= 0 && dizi[j] > eleman) {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = eleman;
        
        // Her adımda diziyi ekrana yazdır
        cout << "Adim " << i << ": ";
        diziYazdir(dizi, boyut);
    }
}

int main() {
    int dizi[] = {2, 5, 1, 6, 8, 4, 13};
    int diziBoyutu = sizeof(dizi) / sizeof(dizi[0]);
    
    cout << "Baslangic Dizisi: ";
    diziYazdir(dizi, diziBoyutu);
    
    cout << "------ Insertion Sort Algoritmasi -----" << endl;
    insertionSort(dizi, diziBoyutu);
    
    cout << "Siralanmis Dizi: ";
    diziYazdir(dizi, diziBoyutu);
    
    return 0;
}
