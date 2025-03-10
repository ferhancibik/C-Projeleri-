
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

char birlestir(char *x, char *y, char *z)
{
	char *p;
	char *q=z;
	
	for(p=x; *p != '\0'; p++, z++)
		*z=*p;
	
	for(p=y; *p != '\0'; p++, z++)
		*z=*p;
		
	*z='\0';
	return q;
}

int main ()
{
	char str1[] = "abc", str2[] = "xyz";
	char birlesme[10];
	char *q;
	q=birlestir(str1, str2, birlesme);
	cout << "birlestirilen string: " << q << '\n';
	
	getch();
	return 0;
}




