#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	
	int vize,final;
	double ortalama;
	
	cout<<"Vize Girin: ";
	cin>>vize;
	
	cout<<"Finali Girin: ";
	cin>>final;
	
	ortalama=(vize*0.4)+(final*0.6);
	
	if(ortalama>=70)
	{
		cout<<"BAÞARILI";
	}
	else{
		cout<<"BAÞARISIZ";
	}
	system("pause");
	
	return 0;
}
