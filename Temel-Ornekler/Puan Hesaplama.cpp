#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish"); 
	int turDog, fenDog, matDog, turYan, fenYan, matYan;
	double turNet, fenNet, matNet, toplamNet,turPuan,matPuan,fenPuan,toplamPuan;
	
	cout<<"T�rk�e Do�ru Say�s�n� Giriniz: ";
	cin>>turDog;
	cout<<"T�rk�e Yanl�� Say�s�n� Giriniz: ";
	cin>>turYan;
	cout<<"Matematik Do�ru Say�s�n� Giriniz: ";
	cin>>matDog;
	cout<<"Matematik Yanl�� Say�s�n� Giriniz: ";
	cin>>matYan;
	cout<<"Fen Bilgisi Do�ru Say�s�n� Giriniz: ";
	cin>>fenDog;
	cout<<"Fen Bilgisi Yanl�� Say�s�n� Giriniz: ";
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
		cout<<"T�rk�e Neti: " << turNet << endl;
		cout<<"Matematik Neti: " << matNet << endl;
		cout<<"Fen Bilgisi Neti: " << fenNet << endl;
		cout<<"Toplam Net: " << toplamNet << endl;
		cout<<"T�rk�e Puan�: "<< turPuan << endl;
		cout<<"Matematik Puan�: "<< matPuan << endl;
		cout<<"Fen Bilgisi Puan�: "<< fenPuan << endl;
		cout<<"Toplam Puan: "<< toplamPuan << endl;
	}
	else
	{
		cout<<"Soru say�s�n� yanl�� girdiniz. Her ders i�in en fazla 25 soru olacak �ekilde giriniz!" << endl;
	}
	
	system("pause");
	return 0;
}
