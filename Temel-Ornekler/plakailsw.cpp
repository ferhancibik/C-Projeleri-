//klavyeden girilen plaka koduna göre ilini ekrana yazdýran prog switch case ile yapýn
#include<iostream>
#include<locale.h>
#include<iomanip>
using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");

int plaka;
cin>>plaka;
switch(plaka)
{
case 27:
cout<<"Antep"<<endl;
break;
case 7:
cout<<"Antalya"<<endl;
break;
case 71:
cout<<"Kýrýkkale"<<endl;
break;
case 6:
cout<<"Ankara"<<endl;
break;
default:
cout<<"Plaka Bulunamadý"<<endl;
}
return 0;
}
