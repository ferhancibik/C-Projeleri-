#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;


int kontrol(string cumle, string arananKelime, string degisecekKelime)
{
	int sayac=0;
	int birinciIndex=cumle.find(arananKelime);
	if(birinciIndex!=-1)
	{
		for(int i=birinciIndex; i<cumle.size(); i++)
		{
			if(cumle[i]==' ')
			{
				break;
			}
			sayac++;
		}
			
		cumle.erase(birinciIndex,sayac);
		
		cumle.insert(birinciIndex,degisecekKelime);
		cout<<cumle<<endl;
		return 1;
	}
	else
	{
		cout<<"Aranan Kelime Bulunamadý"<<endl;
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	string cumle;
	string yeniKelime;
	string aranacakKelime;
	cout<<"Bir Cümle Girin: "; 
	getline(cin>>ws,cumle);	
	cout<<"Aranacak Kelimeyi Girin: ";
	cin>>aranacakKelime;
	cout<<"Yeni kelimeyi Girin: ";
	cin>>yeniKelime;
	cout<<kontrol(cumle,aranacakKelime,yeniKelime);
	
	
}

