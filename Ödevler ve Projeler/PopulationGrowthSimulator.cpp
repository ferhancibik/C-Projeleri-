#include <iostream>
#include <iomanip> // setprecision için
#include <vector>  // Nüfus verilerini saklamak için
using namespace std;

// Nüfus artışını hesaplayan fonksiyon
vector<long> nufusHesapla(long baslangicNufus, float artisOrani, int yil) {
    vector<long> nufusVerileri;
    long nufus = baslangicNufus;
    for (int i = 1; i <= yil; i++) {
        nufus += (artisOrani * nufus);
        nufusVerileri.push_back(nufus); // Her yılın nüfusunu kaydet
    }
    return nufusVerileri;
}

// Nüfus verilerini tablo şeklinde gösteren fonksiyon
void nufusTablosuGoster(const vector<long>& nufusVerileri) {
    cout << "\nYıl\tNüfus" << endl;
    cout << "-----------------" << endl;
    for (size_t i = 0; i < nufusVerileri.size(); i++) {
        cout << i + 1 << "\t" << fixed << setprecision(0) << nufusVerileri[i] << endl;
    }
}

int main() {
    long baslangicNufus;
    float artisOrani;
    int yil;

    cout << "Population Growth Simulator'a Hoş Geldiniz!" << endl;
    cout << "Başlangıç nüfusunu girin: ";
    cin >> baslangicNufus;

    cout << "Yıllık nüfus artış oranını girin (örneğin 0.03): ";
    cin >> artisOrani;

    cout << "Hesaplanacak yıl sayısını girin: ";
    cin >> yil;

    vector<long> nufusVerileri = nufusHesapla(baslangicNufus, artisOrani, yil);

    nufusTablosuGoster(nufusVerileri);
    cout << "\n" << yil << " yıl sonraki tahmini nüfus: " << nufusVerileri.back() << endl;

    return 0;
}
