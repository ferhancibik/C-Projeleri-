//Kullan�c� taraf�ndan girilen boy ve cinsiyete g�re ideal kiloyu hesap eden program� yaz�n�z
#include<iostream>
#include<locale.h>

using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");

char cinsiyet;
double boy,ideal_kilo;

cout<<"Cinsiyeti Giriniz."<<endl;
cin>>cinsiyet;
cout<<"Boy Giriniz."<<endl;
cin>>boy;
if(cinsiyet=='K')
{
ideal_kilo=45.5+2.3*((boy/2.54)-60);
cout<<"�deal Kilonuz:"<<ideal_kilo;
}
else
{
ideal_kilo=50+2.3*((boy/2.54)-60);
cout<<"�deal Kilonuz:"<<ideal_kilo;
}

















return 0;
}
