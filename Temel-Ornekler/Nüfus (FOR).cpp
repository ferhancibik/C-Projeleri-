#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	long nufus;
	double artis;
	int yil;
	cout<<"�imdiki n�fusu girin: ";
	cin>>nufus;

	cout<<"N�fus art�� oran�n� girin: ";
	cin>>artis;

	cout<<"N�fusu hesaplanmak istenen s�reyi girin: ";
	cin>>yil;
	
	for(int i=1; i<=yil; i++)
	{
	
		nufus+=(nufus*artis);
	}
	
	cout<<"N�fus: " << nufus << endl;
	
	system("pause");
	return 0;

}

