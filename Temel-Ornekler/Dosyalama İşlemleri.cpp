#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>            // Dosyalama için gerekli kütüphane
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
											// ofstream veriyi yazdýrmayý saðlar
	ofstream yaz("balik.txt", ios::app);      // ios::app komutu mevcut dosyanýn üstüne ekleme yapýyor
	string ad_soyad="*Ferhan ÇIBIK*";        // normal durumda ios::out komutu bulunur bir defa gösterir
	
	if(yaz.is_open())
	{
		yaz << "Ferhan ÇIBIK\n";
		yaz << "Bilgisayar Mühendisliði" << endl;
		
		for(int i=0; i<ad_soyad.size(); i++)
		yaz.put(ad_soyad[i]);                   // put fonksiyonuyla karakter karakter yazýlýyor
		
		yaz.put('\n');
	}
	else 
	cout << "Dosya Bulunamadý.." << endl;                 
	
/*	ifstream yaz("yaz.txt", ios::in);            // ifstream veriyi okutmayý saðlar
	string okunan="";
	
	if(yaz.is_open())
	{
		while(!yaz.eof())             // eof sayfa/dosya sonu
		{
			getline(yaz,okunan);
			cout << okunan << endl;
		}
	}
	
	else 
	cout << "Dosya Bulunamadý.." << endl;	  */

	yaz.close();

	system("pause");
	return 0;
}
