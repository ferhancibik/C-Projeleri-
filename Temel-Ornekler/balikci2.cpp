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
	cout << "Balýk Ýsmi Giriniz: " << endl;
	cin >> balikBilgileri.balikIsmi;
	
	cout << "Lütfen" << balikBilgileri.balikIsmi << "Balýðýnýn Stoðunu Giriniz" << endl;
	cin >> balikBilgileri.stok;
	
	cout << "Lütfen" << balikBilgileri.balikIsmi << "Balýðýnýn Fiyatýný Giriniz" << endl;
	cin >> balikBilgileri.fiyat; 
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	 
	balikEkle();

	return 0; 
}
