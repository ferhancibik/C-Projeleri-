#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	int i,j,k,l,m,n,x,p,bosluk;
	
	for(i=1; i<=5; i++)
	{
		for(j=1; j<=i; j++)
		{
			cout<<"*";
	}
		cout<<""<<endl;
	}
	
	for(k=1; k<5; k++)
	{
		for(l=5; l>k; l--)
		{
			cout<<"*";
		}
		cout<<""<<endl;
	}
	
	/*---------------------BOÞLUKLU--------------------*/
	
	for(m=1; m<=5; m++)
	{
		for(bosluk=5; bosluk>=m; bosluk--)
		{
			cout<<" ";
		}
		for(n=1; n<=m; n++)
		{
			cout<<"*";
		}
		cout<<""<<endl;
	}
	
	for(x=1; x<=5; x++)
	{
		for(bosluk=0; bosluk<=x; bosluk++)
		{
			cout<<" ";
		}
		for(p=4; p>=x; p--)
		{
			cout<<"*";
		}
		cout<<""<<endl;
	}

	
	system("pause");
	return 0;
}
