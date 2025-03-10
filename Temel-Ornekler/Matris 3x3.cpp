#include <iostream>

using namespace std;

const int BOYUT = 3;

void matrisToplama(int A[][BOYUT], int B[][BOYUT], int C[][BOYUT]) {
    for (int i = 0; i < BOYUT; ++i) {
        for (int j = 0; j < BOYUT; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrisCarpma(int A[][BOYUT], int B[][BOYUT], int C[][BOYUT]) {
    for (int i = 0; i < BOYUT; ++i) {
        for (int j = 0; j < BOYUT; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < BOYUT; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int matrisDeterminant(int A[][BOYUT]) {
    int det = 0;
    for (int i = 0; i < BOYUT; ++i) {
        det = det + (A[0][i] * (A[1][(i + 1) % 3] * A[2][(i + 2) % 3] - A[1][(i + 2) % 3] * A[2][(i + 1) % 3]));
    }
    return det;
}

void matrisYazdir(int matris[][BOYUT]) {
    for (int i = 0; i < BOYUT; ++i) {
        for (int j = 0; j < BOYUT; ++j) {
            cout << matris[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[BOYUT][BOYUT];
    int B[BOYUT][BOYUT];
    int C[BOYUT][BOYUT];

    cout << "A matrisini giriniz (3x3):" << endl;
    for (int i = 0; i < BOYUT; ++i) {
        for (int j = 0; j < BOYUT; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "B matrisini giriniz (3x3):" << endl;
    for (int i = 0; i < BOYUT; ++i) {
        for (int j = 0; j < BOYUT; ++j) {
            cin >> B[i][j];
        }
    }

    cout << "A matrisi:" << endl;
    matrisYazdir(A);

    cout << "B matrisi:" << endl;
    matrisYazdir(B);

    matrisToplama(A, B, C);
    cout << "C = A + B matrisi:" << endl;
    matrisYazdir(C);

    matrisCarpma(A, B, C);
    cout << "C = A * B matrisi:" << endl;
    matrisYazdir(C);

    int detA = matrisDeterminant(A);
    cout << "det(A) = " << detA << endl;

    return 0;
} 	
