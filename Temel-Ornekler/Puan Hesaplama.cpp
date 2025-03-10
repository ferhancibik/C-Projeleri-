#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); 
	int turDog, fenDog, matDog, turYan, fenYan, matYan;
	double turNet, fenNet, matNet, toplamNet,turPuan,matPuan,fenPuan,toplamPuan;
	
	cout<<"Türkçe Doðru Sayýsýný Giriniz: ";
	cin>>turDog;
	cout<<"Türkçe Yanlýþ Sayýsýný Giriniz: ";
	cin>>turYan;
	cout<<"Matematik Doðru Sayýsýný Giriniz: ";
	cin>>matDog;
	cout<<"Matematik Yanlýþ Sayýsýný Giriniz: ";
	cin>>matYan;
	cout<<"Fen Bilgisi Doðru Sayýsýný Giriniz: ";
	cin>>fenDog;
	cout<<"Fen Bilgisi Yanlýþ Sayýsýný Giriniz: ";
	cin>>fenYan;
	
	int turSoru=turDog+turYan;
	int matSoru=matDog+matYan;
	int fenSoru=fenDog+fenYan;
	
	
	if(turSoru<=25 && matSoru<=25 && fenSoru<=25)
	{
		turNet=turDog-(turYan/4.0);
		matNet=matDog-(matYan/4.0);
		fenNet=fenDog-(fenYan/4.0);
		toplamNet=turNet+matNet+fenNet;
		turPuan=turNet*3;
		matPuan=matNet*5;
		fenPuan=fenNet*4;
		toplamPuan=turPuan+matPuan+fenPuan;
		cout<<"Türkçe Neti: " << turNet << endl;
		cout<<"Matematik Neti: " << matNet << endl;
		cout<<"Fen Bilgisi Neti: " << fenNet << endl;
		cout<<"Toplam Net: " << toplamNet << endl;
		cout<<"Türkçe Puaný: "<< turPuan << endl;
		cout<<"Matematik Puaný: "<< matPuan << endl;
		cout<<"Fen Bilgisi Puaný: "<< fenPuan << endl;
		cout<<"Toplam Puan: "<< toplamPuan << endl;
	}
	else
	{
		cout<<"Soru sayýsýný yanlýþ girdiniz. Her ders için en fazla 25 soru olacak þekilde giriniz!" << endl;
	}
	
	system("pause");
	return 0;
}
