//kullan�c� taraf�ndan girilen iki say� aral�g�ndaki asal say�lar� ekranda yaz�an prog
#include<iostream>
#include<locale.h>
#include<iomanip>
using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");

int sayi_1,sayi_2;
bool asal_mi=true;
cout<<"�LK SAYIYI G�R�N�Z:"<<endl;
cin>>sayi_1;
cout<<"�K�NC� SAYIYI G�R�N�Z:"<<endl;
cin>>sayi_2;
for (int i=sayi_1;i<=sayi_2;i++)
{
 for (int j=2;j<i;j++)
 {
 	asal_mi=true;
  if (i%j==0)
    {
  	cout<<"ASAL DE��L!"<<i<<endl;
    asal_mi=false;
  	break;// ko�ul sa�lan�rsa bir say� i�in di�erlerini denemiyo k�r�yo ba�ka say�ya ge�iyo.
  	}
 }
 
 if(asal_mi==true)
 {
 	cout<<"ASAL:"<<i<<endl;
 }
}




return 0;
}
