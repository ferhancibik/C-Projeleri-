#include <iostream>
using namespace std;

string yaziyaz(string kelime, int sayac)
{
	if(sayac>=1)
	{
		cout << kelime << endl;
		return yaziyaz(kelime, sayac-1);
	}
    else
    return "";
                   
}	 

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	yaziyaz("Ferhan",5);
	
	return 0;
}
