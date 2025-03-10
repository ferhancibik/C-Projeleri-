#include <iostream>
#include <locale.h>
using namespace std;

int usthesaplama(int sayi1,int sayi2)       //fonksiyon ile üst hesaplama
{
	int sonuc=1;
	for(int i=0;i<sayi2;i++)
	{
		sonuc*=sayi1;
	}
	return sonuc;
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	cout << usthesaplama(4,3);
	
	
	return 0;
}
