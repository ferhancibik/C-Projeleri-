#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "turkish");
	int nufus;
	double artis;
	int yil;
	int sayac=1;
	cout<<"Þimdiki nüfusu girin: ";
	cin>>nufus;
	cout<<"Nüfus artýþ oranýný girin: ";
	cin>>artis;
	cout<<"Nüfusu hesaplanmak istenen süreyi girin: ";
	cin>>yil;
	
	while(sayac<=yil)
	{
		nufus=nufus+(nufus*artis);
		sayac=sayac+1;
	}
	
	cout<<"Nüfus: " << nufus << endl;
	
	system("pause");
	return 0;
}
