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
cout<<"E�itkenard�r"<<endl;	
}
else if (a==b||a==c||b==c)
{
cout<<"�kizkenard�r"<<endl;
}
else
{
cout<<"�e�itkenard�r"<<endl;
}


return 0;
}
