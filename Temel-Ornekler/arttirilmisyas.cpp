
//kullan�c�dan al�nan iki ya� bilgisine g�re e�er birinci ya� b�y�k ise birinci ya�a 10 ekleyip ekranda g�sterin ikinci b�y�kse ikinciye on ekleyip ekranda g�sterin
#include<iostream>
#include<locale.h>

using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");


int yas_1,yas_2;
cout<<"Birinci ya�� giriniz:"<<endl;
cin>>yas_1;
cout<<"�kinci ya�� giriniz:"<<endl;
cin>>yas_2;
if(yas_1>yas_2)
{
yas_1 +=10;
cout<<"Artt�r�lm�� Ya�:"<<yas_1++<<endl;		
}
else
{	
yas_2 +=10;
cout<<"Artt�r�lm�� Ya�:"<<yas_2++<<endl;	
}




















 return 0;
}
