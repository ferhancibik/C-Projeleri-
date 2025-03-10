#include <iostream>
#include <locale.h>
using namespace std;

int usthesaplama()
{
	int sonuc2;
	int sayi_1;
	
	cout << "Lütfen 1.sayýyý giriniz: " << endl;
	cin >> sayi_1;
	const int sayi_2=1/2;
	

	
		sonuc2*=sayi_1;
	
	return sonuc2;
}


int main()
{
	setlocale(LC_ALL,"Turkish");
	
	int sonuc= usthesaplama();
	cout << sonuc << endl;
	system("pause");	
	return 0;
}

