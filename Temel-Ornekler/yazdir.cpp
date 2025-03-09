#include <iostream>
#include <locale.h>
using namespace std;

string yazdir(string kelime)
{
	int boyut=kelime.size();
	if(boyut>=1)
	{
		boyut--;
		cout << kelime << endl;
		kelime.erase(0,1);
		return yazdir(kelime);
	}
	else 
	return "";
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	yazdir("Ferhan");
	
	
	return 0;
}
