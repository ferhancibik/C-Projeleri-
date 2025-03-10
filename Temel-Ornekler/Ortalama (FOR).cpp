#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish");
	int sayi;
	int toplam=0;
	double ortalama=0;
	double sayiAdedi;
	
	cout<<"Sayý Adedi Girin: ";
	cin>> sayiAdedi;
	
	for(int i=1; i<=sayiAdedi; i=i+1)
	{
		cout<<i<<". Sayýyý giriniz: ";
		cin>>sayi;
		toplam=toplam+sayi;
	}
	
	ortalama=toplam/sayiAdedi;
	
	cout<<"Ortalama: "<< ortalama<<endl;
	
	system("pause");
	return 0;
}
