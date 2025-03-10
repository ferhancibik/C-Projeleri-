#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "Turkish");

	int a[7];
	int kck = 0;
	int byk = 0;

	cout << "7 adet deðer giriniz lütfen!!:" << endl;

	for (int i = 0; i < 7;  i++)
	{
		cout << i + 1 << ". deðeri giriniz. " << endl;
		cin >> a[i];
	}

	int boyut = sizeof(a) / sizeof(a[0]);

	int* enbyk = &a[0];

	int* enkck = &a[0];

	for (int i = 0; i < boyut; i++) {


		if (a[i] > *enbyk) 
		{
			enbyk = &a[i];
		}

		if (a[i] < *enkck) 
		{
			enkck = &a[i];
		}
	}
	
	int ort = 0;
	for (int i = 0; i < boyut; i++) {
	
		ort = ort + a[i];	
	}
		ort = ort/7;

	cout << "En yüksek sýcaklýk: " << *enbyk << endl;
	cout << "En düþük sýcaklýk: " << *enkck << endl;
	cout << "Sýcaklýk ortalamasý: " << ort << endl;

	return 0;
}
