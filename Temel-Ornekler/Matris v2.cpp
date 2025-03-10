#include<iostream>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL,"Turkish");

 	int a[3][3];
 	int b[3][3];
 	int c[3][3];
 	
 	cout << "A matrisin degerlerini giriniz: " << endl;
	for (int i = 0; i < 3; i++) { 
 	for (int c = 0; c < 3; c++) {
 	cin >> a[i][c];
 	}
 	cout << endl;
	 }
 	cout << "B matrisin degerlerini giriniz: " << endl;
 
	for (int i = 0; i < 3; i++) { 
 	for (int c = 0; c < 3; c++) {
 	cin >> b[i][c];
 	}
 	cout << endl;
 	}
 
	for (int i = 0; i < 3; i++) { 
 	for (int k = 0; k < 3; k++) {
 	c[i][k] = a[i][k] + b[i][k];
 	}
 	}
 
 	cout << "*Matris Toplam*"<<endl;
	for (int i = 0; i < 3; i++) {
	cout << "[ ";
 	for (int k = 0; k < 3; k++) { 
 	cout <<c[i][k]<<" ";
 	}
 	cout << "]" << endl;
 	}
 	 int carpim[3][3];
 	for(int i=0;i<3;i++){
 	for(int j=0;j<3;j++){
 	carpim[i][j]=0;
 	for(int k=0;k<3;k++){
 	carpim[i][j] += a[i][k] * b[k][j];
	}
	}
	}
 	cout << endl << "*Matris Çarpým*"<< endl;
 	for (int i = 0; i < 3; i++) { 
 	cout << "[ ";
 	for (int c = 0; c < 3; c++) {
 	cout << carpim[i][c] << " ";
 	}
 	cout << "]" << endl;
 	}
 	int det;
 	det = a[0][0] * a[1][1] * a[2][2]
 	+ a[0][1] * a[1][2] * a[2][0]
 	+ a[0][2] * a[1][0] * a[2][1]
 	- a[0][2] * a[1][1] * a[2][0]
 	- a[0][1] * a[1][0] * a[2][2]
 	- a[0][0] * a[1][2] * a[2][1];
 
	 cout << "*Determinant*"<<endl; 
 	cout << det << endl;
 	return 0;
}
