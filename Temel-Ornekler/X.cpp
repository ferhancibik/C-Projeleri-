
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main ()
{
	int a[] = {3,2,1,4,6,2,1};
	int *p;
	int boyut, i;
	boyut = sizeof(a)/sizeof(a[0]);
	
	cout << a << ", " << &a[0] << '\n';
	
	p = &a[0];
	cout << *p << '\n';
	
	p = a;
	cout << *p << '\n';
	
	cout << p << ", " << *p << ", " << p+1 << ", " << *(p+1) << '\n';
	
	for(i=0; i<boyut; i++)
	{
		cout << a[i] << " ";
		cout << '\n';
	}
	
	for(p=a; p<&a[boyut]; p++)
	{
		cout << *p << " ";
		cout << '\n';
	}
	
	for(p=a; p<a+boyut; p++)
	{
		cout << *p << " ";
		cout << '\n';
	}
	
	for(i=0; i<boyut; i++)
	{
		cout << *(a+i) << " ";
		cout << '\n';
	}
	
	getch();
	return 0;
}

