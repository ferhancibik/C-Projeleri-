//klavyeden girilen plaka koduna g�re ilini ekrana yazd�ran prog switch case ile yap�n
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
cout<<"K�r�kkale"<<endl;
break;
case 6:
cout<<"Ankara"<<endl;
break;
default:
cout<<"Plaka Bulunamad�"<<endl;
}
return 0;
}
