//kullanýcý tarafýndan girilen iki sayý aralýgýndaki asal sayýlarý ekranda yazýan prog
#include<iostream>
#include<locale.h>
#include<iomanip>
using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");

int sayi_1,sayi_2;
bool asal_mi=true;
cout<<"ÝLK SAYIYI GÝRÝNÝZ:"<<endl;
cin>>sayi_1;
cout<<"ÝKÝNCÝ SAYIYI GÝRÝNÝZ:"<<endl;
cin>>sayi_2;
for (int i=sayi_1;i<=sayi_2;i++)
{
 for (int j=2;j<i;j++)
 {
 	asal_mi=true;
  if (i%j==0)
    {
  	cout<<"ASAL DEÐÝL!"<<i<<endl;
    asal_mi=false;
  	break;// koþul saðlanýrsa bir sayý için diðerlerini denemiyo kýrýyo baþka sayýya geçiyo.
  	}
 }
 
 if(asal_mi==true)
 {
 	cout<<"ASAL:"<<i<<endl;
 }
}




return 0;
}
