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
	cout<<"�imdiki n�fusu girin: ";
	cin>>nufus;
	cout<<"N�fus art�� oran�n� girin: ";
	cin>>artis;
	cout<<"N�fusu hesaplanmak istenen s�reyi girin: ";
	cin>>yil;
	
	while(sayac<=yil)
	{
		nufus=nufus+(nufus*artis);
		sayac=sayac+1;
	}
	
	cout<<"N�fus: " << nufus << endl;
	
	system("pause");
	return 0;
}
