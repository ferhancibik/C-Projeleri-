#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	long nufus;
	double artis;
	int yil;
	cout<<"Þimdiki nüfusu girin: ";
	cin>>nufus;

	cout<<"Nüfus artýþ oranýný girin: ";
	cin>>artis;

	cout<<"Nüfusu hesaplanmak istenen süreyi girin: ";
	cin>>yil;
	
	for(int i=1; i<=yil; i++)
	{
	
		nufus+=(nufus*artis);
	}
	
	cout<<"Nüfus: " << nufus << endl;
	
	system("pause");
	return 0;

}

