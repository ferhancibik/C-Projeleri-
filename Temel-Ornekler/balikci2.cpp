#include <iostream>
#include <locale.h>
#include <fstream> 
using namespace std;

struct balikBilgileri
{
	string balikIsmi;
	int stok;
	float fiyat;	
};

void balikEkle()
{
	cout << "Bal�k �smi Giriniz: " << endl;
	cin >> balikBilgileri.balikIsmi;
	
	cout << "L�tfen" << balikBilgileri.balikIsmi << "Bal���n�n Sto�unu Giriniz" << endl;
	cin >> balikBilgileri.stok;
	
	cout << "L�tfen" << balikBilgileri.balikIsmi << "Bal���n�n Fiyat�n� Giriniz" << endl;
	cin >> balikBilgileri.fiyat; 
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	 
	balikEkle();

	return 0; 
}
