#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");
	int sayi;
	double sayiAdedi;
	int toplam=0;
	double ortalama=0;
	int sayac=1;
	cout<<"Sayý Adedi Girin: ";
	cin>>sayiAdedi;
	
	while(sayac<=sayiAdedi)
	{
		cout<<sayac<<". Sayýyý giriniz: ";
		cin>>sayi;
		toplam+=sayi;
		sayac=sayac+1;
	}
	
	ortalama=toplam/sayiAdedi;
	
	cout<<"Ortalama: "<< ortalama<<endl;
	
	system("pause");
	return 0;
}
