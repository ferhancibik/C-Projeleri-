#include <iostream>
#include <iomanip>
using namespace std;

int cikarma(int sayi1, int sayi2)
{
	int sonuc1 = sayi1 - sayi2;
	cout << "��karma i�leminin cevab�: ";
	return sonuc1;
}

int toplama()
{
	int sayi3,sayi4;
	cout << "Toplama i�in 1. say�y� giriniz: " ;
	cin >> sayi3;
	cout << "Toplama i�in 2. say�y� giriniz: " ;
	cin >> sayi4;
	int sonuc2 = sayi3 + sayi4;
	cout << "Toplama i�leminin cevab�: ";
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
	cout << "Girilen say�n�n k�k de�eri: " ;
	return sonuc3;
}
int carpma()
{
	int sayi7,sayi8;
	cout << "�arpma i�in 1. say�y� giriniz: " ;
	cin >> sayi7;
	cout << "�arpma i�in 2. say�y� giriniz: " ;
	cin >> sayi8;
	int sonuc4 = sayi7 * sayi8;
	cout << "�arpma i�leminin cevab�: ";
	return sonuc4;	
}

int bolme(int sayi9, int sayi10)
{
	int sonuc5=sayi9 / sayi10;
	cout << "B�lme i�leminin cevab�: ";
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
