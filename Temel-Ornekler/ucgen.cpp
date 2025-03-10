#include<iostream>
#include<locale.h>

using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");
int a,b,c;
cin>>a;
cin>>b;
cin>>c;

if(a==b&&b==c)
{
cout<<"Eþitkenardýr"<<endl;	
}
else if (a==b||a==c||b==c)
{
cout<<"Ýkizkenardýr"<<endl;
}
else
{
cout<<"Çeþitkenardýr"<<endl;
}


return 0;
}
