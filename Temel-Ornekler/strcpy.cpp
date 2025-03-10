#include<iostream>
#include<locale.h>
#include<cstring>
using namespace std;

int main()

{	
setlocale(LC_ALL,"Turkish");
char str1[]="Teknoloji Fakültesi\n"
            "Bilgisayar Mühendisliði";
const int MAX=80;
char str2[MAX];

strcpy(str2,str1);

cout<<str2<<endl;

return 0;
}
