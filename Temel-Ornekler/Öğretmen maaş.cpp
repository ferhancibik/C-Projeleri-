#include <iostream>
#include <locale.h>
using namespace std;
int main(){
		setlocale(LC_ALL, "Turkish");
		
		int maas,dersSaati;
		
		cout<<"Maaþý Girin: ";
		cin>>maas;
		cout<<"Ders Saatini Girin: ";
		cin>>dersSaati;
		
		for(int i=1; i<=dersSaati; i++)
		{
			if(i<=10)
			{
				maas+=100;
			}
			else if(i>10 && i<=20)
			{
				maas+=125;
			}
			else{
				maas+=150;
			}
		}
		cout<<"Net Kazanç: "<<maas;
}
