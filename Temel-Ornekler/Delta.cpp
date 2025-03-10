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
	cout<<"a Katsayýsýný Girin: ";
	cin>>a;
	cout<<"b Katsayýsýný Girin: ";
	cin>>b;
	cout<<"c Katsayýsýný Girin: ";
	cin>>c;
	delta=pow(b,2)-4*a*c;

	if(delta>0)
	{
	kok1=((-b+pow(delta,0.5))/(2*a));
    kok2=((-b-pow(delta,0.5) )/(2*a));	
    cout<<"1.Kök: "<<kok1<<endl;
	cout<<"2.Kök: "<<kok2;
	}
	else if(delta==0)
	{
		kok1=-b/(2*a);
		cout<<"1.Kök: "<<kok1;
	}
	else
	{
		cout<<"Reel Kök Yoktur.";
	}
	system("pause");
	return 0;

}
