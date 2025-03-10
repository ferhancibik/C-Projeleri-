#include <iostream>

using namespace std;

int main() {
    // Veri seti örneði
    int veriSeti[] = {4, 7, 8, 12, 15, 8, 4, 7, 8, 21, 15, 8, 4, 21, 21};
    int boyut = sizeof(veriSeti) / sizeof(veriSeti[0]);

    // Verilerin frekanslarýný hesaplama ve ekrana yazdýrma
    for (int i = 0; i < boyut; ++i) {
        int frekans = 0;
        for (int j = 0; j < boyut; ++j) {
            if (veriSeti[i] == veriSeti[j]) {
                frekans++;
            }
        }
        // Veri setinde daha önce iþlenmiþse tekrar yazdýrmama kontrolü
        bool yazdir = true;
        for (int k = i - 1; k >= 0; --k) {
            if (veriSeti[i] == veriSeti[k]) {
                yazdir = false;
                break;
            }
        }
        if (yazdir) {
            cout << veriSeti[i] << ": " << frekans << " adet" << endl;
        }
    }

    return 0;
}

