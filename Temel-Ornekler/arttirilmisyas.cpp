
//kullanýcýdan alýnan iki yaþ bilgisine göre eðer birinci yaþ büyük ise birinci yaþa 10 ekleyip ekranda gösterin ikinci büyükse ikinciye on ekleyip ekranda gösterin
#include<iostream>
#include<locale.h>

using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");


int yas_1,yas_2;
cout<<"Birinci yaþý giriniz:"<<endl;
cin>>yas_1;
cout<<"Ýkinci yaþý giriniz:"<<endl;
cin>>yas_2;
if(yas_1>yas_2)
{
yas_1 +=10;
cout<<"Arttýrýlmýþ Yaþ:"<<yas_1++<<endl;		
}
else
{	
yas_2 +=10;
cout<<"Arttýrýlmýþ Yaþ:"<<yas_2++<<endl;	
}




















 return 0;
}
