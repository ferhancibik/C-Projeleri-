#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "Turkish");

	int a[7];
	int kck = 0;
	int byk = 0;

	cout << "7 adet de�er giriniz l�tfen!!:" << endl;

	for (int i = 0; i < 7;  i++)
	{
		cout << i + 1 << ". de�eri giriniz. " << endl;
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

	cout << "En y�ksek s�cakl�k: " << *enbyk << endl;
	cout << "En d���k s�cakl�k: " << *enkck << endl;
	cout << "S�cakl�k ortalamas�: " << ort << endl;

	return 0;
}
