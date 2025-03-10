#include <iostream>
#include <locale.h>
#include <math.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main(){
	
	setlocale(LC_ALL,"Turkish");

	srand(time(0));
	
	float sayi[50000];
	
	for(int i=0;i<50000;i++)
	{
	float	sayilar=(rand()%(100-100+1)+100)+((float)rand()/(float)RAND_MAX);
	sayi[i]=sayilar;
	cout<<sayilar<<endl;
	}
	cout<<endl;
	float toplam=0;
	for(int c=0;c<50000;c++)
	{
		toplam=sayi[c]+toplam;
		
	}
	cout<<toplam<<endl;

int ortalama;
ortalama=toplam/50000;
cout<<ortalama;

	system ("pause");
	return 0;
} 	
