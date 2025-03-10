#include <iostream>

using namespace std;

int main()
{

	int sayac,sayac2,sayac3,sayac4;
	sayac=1;
	sayac2=1;
	sayac3=5;
	sayac4=1;
	while(sayac<=5)
	{
		sayac2=1;
			while(sayac2<=sayac)
			{
				cout<<"*";
				sayac2++;
			}		
		cout<<""<<endl;
		sayac++;
	}
	
	while(sayac3>=1)
	{
		sayac4=1;
		while(sayac4<sayac3)
		{
			cout<<"*";
			sayac4++;
		}
		cout<<""<<endl;
		sayac3--;
	}
	
	int bosluk, yildiz,bosluk1, yildiz1;
	int satir=1;
	int satir1=1;
	
	while(satir<=5)
	{
		
		bosluk=5;
		while(bosluk>=satir)
		{
			cout<<" ";
			bosluk--;
		}
		yildiz=1;
		while(yildiz<=satir)
		{
			cout<<"*";
			yildiz++;
		}
		
		cout<<""<<endl;
		
		satir++;
	}
	
	
	while(satir1<=5)
	{
		bosluk1=0;
		while(bosluk1<=satir1)
		{
			cout<<" ";
			bosluk1++;
		}
		yildiz1=4;
		while(yildiz1>=satir1)
		{
			cout<<"*";
			yildiz1--;
		}	
		cout<<""<<endl;
		satir1++;
	}
	system("pause");
	return 0;
}

