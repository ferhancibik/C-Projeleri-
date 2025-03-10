//kuullanýcý tarafýndan girilen ders ortalamasýna göre harf karþýlýðýný aþaðýdaki koþula göre yapan ve ekrana harf notunu giren programý yazýn
#include<iostream>
#include<locale.h>

using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");

int ort,sayi_1,sayi_2;
cout<<"Birinci sayýyý giriniz:"<<endl;
cin>>sayi_1;
cout<<"Ýkinci sayýyý giriniz:"<<endl;
cin>>sayi_2;


ort=(sayi_1+sayi_2)/2;

if(ort>0&&ort<30)
{
cout<<"FF"<<endl;	
}
else if (ort>=30&&ort<45)
{
cout<<"FD"<<endl;	
}
else if (ort>=45&&ort<50)
{
cout<<"DD"<<endl;	
}
else if (ort>=50&&ort<55)
{
cout<<"DC"<<endl;	
}
else if (ort>=55&&ort<65)
{
cout<<"CC"<<endl;	
}
else if(ort>=65&&ort<70) 
{
cout<<"CB"<<endl;	
}
else if (ort>=70&&ort<80)
{
cout<<"BB"<<endl;	
}
else if (ort>=80&&ort<90)
{
cout<<"BA"<<endl;	
}
else if(ort>=90&&ort<=100)
{
cout<<"AA"<<endl;	
}









return 0;
}
