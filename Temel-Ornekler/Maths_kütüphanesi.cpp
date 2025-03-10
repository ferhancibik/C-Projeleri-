#include <iostream>
#include <iomanip>
using namespace std;

int cikarma(int sayi1, int sayi2)
{
	int sonuc1 = sayi1 - sayi2;
	cout << "Çýkarma iþleminin cevabý: ";
	return sonuc1;
}

int toplama()
{
	int sayi3,sayi4;
	cout << "Toplama için 1. sayýyý giriniz: " ;
	cin >> sayi3;
	cout << "Toplama için 2. sayýyý giriniz: " ;
	cin >> sayi4;
	int sonuc2 = sayi3 + sayi4;
	cout << "Toplama iþleminin cevabý: ";
	return sonuc2;
}

long double kok_alma(int sayi5)
{
	long double sonuc3;
	for(long double i=0; i<sayi5; i++)
{
	if(i*i==sayi5)
	{
	sonuc3 = i;     
	}
}	
	cout << "Girilen sayýnýn kök deðeri: " ;
	return sonuc3;
}
int carpma()
{
	int sayi7,sayi8;
	cout << "Çarpma için 1. sayýyý giriniz: " ;
	cin >> sayi7;
	cout << "Çarpma için 2. sayýyý giriniz: " ;
	cin >> sayi8;
	int sonuc4 = sayi7 * sayi8;
	cout << "Çarpma iþleminin cevabý: ";
	return sonuc4;	
}

int bolme(int sayi9, int sayi10)
{
	int sonuc5=sayi9 / sayi10;
	cout << "Bölme iþleminin cevabý: ";
	return sonuc5;
}
int main()
{
	setlocale(LC_ALL,"Turkish");
	
	cout << cikarma(5,6) << endl; 
	cout << "-------------------------------" << endl;
	cout << bolme(20,4) << endl;
	cout << "-------------------------------" << endl;
	cout << toplama() << endl;
	cout << "-------------------------------" << endl;	
	cout << carpma() << endl;
	cout << "-------------------------------" << endl;	
	cout << kok_alma(81) << endl;
	
	return 0;
}
