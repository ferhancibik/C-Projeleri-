#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); 
	int a,b,c;
	double delta;
	double kok1,kok2;
	cout<<"a Katsay�s�n� Girin: ";
	cin>>a;
	cout<<"b Katsay�s�n� Girin: ";
	cin>>b;
	cout<<"c Katsay�s�n� Girin: ";
	cin>>c;
	delta=pow(b,2)-4*a*c;

	if(delta>0)
	{
	kok1=((-b+pow(delta,0.5))/(2*a));
    kok2=((-b-pow(delta,0.5) )/(2*a));	
    cout<<"1.K�k: "<<kok1<<endl;
	cout<<"2.K�k: "<<kok2;
	}
	else if(delta==0)
	{
		kok1=-b/(2*a);
		cout<<"1.K�k: "<<kok1;
	}
	else
	{
		cout<<"Reel K�k Yoktur.";
	}
	system("pause");
	return 0;

}
