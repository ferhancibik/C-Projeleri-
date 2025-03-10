#include <iostream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int buyukbul(int matris[10][10], int& satir, int& sutun)
{
	int enBuyuk=0; 
	enBuyuk = matris[0][0];
    for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(matris[i][j]>=enBuyuk)
			{
				enBuyuk=matris[i][j];
				satir = i+1 ;
            	sutun = j+1; 
			}
		}
	}
	return enBuyuk;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	int enBuyukSatir;
    int enBuyukSutun;
	int matris[10][10];
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			matris[i][j]=rand() % (99-10+1)+10;
		}
	}
	int buyukSayi = buyukbul(matris,enBuyukSatir,enBuyukSutun);
	for(int i=0; i<10; i++)
	{
		cout<<"|";
		for(int j=0; j<10; j++)
		{
			if(matris[i][j]==buyukSayi)
			cout<<"*"<<matris[i][j]<<"*";
			else
			cout<<" "<<matris[i][j]<<" ";
			
			
		}
		cout<<"|"<<endl;
	}

	
	cout << "En buyuk sayi: " << buyukSayi << endl;
    cout << "Satir numarasi: " << enBuyukSatir << endl;
    cout << "Sutun numarasi: " << enBuyukSutun << endl;
	
	return 0;
}
