#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>            // Dosyalama i�in gerekli k�t�phane
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
											// ofstream veriyi yazd�rmay� sa�lar
	ofstream yaz("balik.txt", ios::app);      // ios::app komutu mevcut dosyan�n �st�ne ekleme yap�yor
	string ad_soyad="*Ferhan �IBIK*";        // normal durumda ios::out komutu bulunur bir defa g�sterir
	
	if(yaz.is_open())
	{
		yaz << "Ferhan �IBIK\n";
		yaz << "Bilgisayar M�hendisli�i" << endl;
		
		for(int i=0; i<ad_soyad.size(); i++)
		yaz.put(ad_soyad[i]);                   // put fonksiyonuyla karakter karakter yaz�l�yor
		
		yaz.put('\n');
	}
	else 
	cout << "Dosya Bulunamad�.." << endl;                 
	
/*	ifstream yaz("yaz.txt", ios::in);            // ifstream veriyi okutmay� sa�lar
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
	cout << "Dosya Bulunamad�.." << endl;	  */

	yaz.close();

	system("pause");
	return 0;
}
