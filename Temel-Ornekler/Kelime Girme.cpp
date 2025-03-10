
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	int Sayi;
	string kelime;
	char Karakter='e';
	char GirilenKarakter;
	while(Karakter=='e')
	{
	cout<<"Bir Sayý Girin: ";
	cin>>Sayi;	
	cout<<"Bir Kelime Girin: ";
	cin>>kelime;
	while(Sayi>0)
	{
		cout<<kelime<<endl;
		Sayi--;
	}
	cout<<"Program baþýna tekrar dönmek istiyor musunuz?(e=evet)";
	cin>>GirilenKarakter;
	Karakter=GirilenKarakter;
	}
	cout<<"Programdan Çýktýnýz";
	
	system("pause");
	return 0;
	}
