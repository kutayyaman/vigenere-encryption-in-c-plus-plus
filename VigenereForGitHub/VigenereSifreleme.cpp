/****************************************************************************
** SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
** BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
** PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
** ÖDEV NUMARASI…...: 4
** ÖÐRENCÝ ADI...............: Kutay
** ÖÐRENCÝ NUMARASI.: b171210074
** DERS GRUBU…………: D
****************************************************************************/
#include<iostream>
#include<conio.h>
using namespace std;
class Sifre
{
private:
	char* alfabe;
	char* sifreKelimesi;
	char* metin;
	char* sifrelenmisMetin;
	char* cozulmusMetin;
	int alfabeHarfSayisi;
	char dizi[27][27];
	int k;
	char ch;
	int sifreKarakterSayisi;
	int metinKarakterSayisi;

public:
	Sifre()
	{
		alfabeHarfSayisi = 26;
		k = 0;
		alfabe = new char[alfabeHarfSayisi];
		for (int i = 0; i < alfabeHarfSayisi; i++) //parametresiz kurucuda otomatik olarak türkce karakterler icermeyen alfabeyi alfabe dizisine atiyorum
		{
			alfabe[i] = 'A' + i;
		}
		for (int i = 0; i < alfabeHarfSayisi + 1; i++) //Vigenere tablosunu dizi isimli iki boyutlu dizide olusturuyorum.
		{
			for (int j = 0; j < alfabeHarfSayisi + 1; j++)
			{
				if (i == 0 && j == 0) // vigenere tablosunun ilk satir ilk sutunu boþtu onu atamak icin if kullandim
				{
					dizi[i][j] = ' ';
				}
				else
				{
					dizi[i][j] = alfabe[k];       //k degiskenini alfabedeki tum harfleri dolasmak icin kullaniyorum
					k++;
					if (k == alfabeHarfSayisi) //alfabedeki tum harfleri sira sira diziye atiyarak vigenere tablosunu olusturmus olucam
						k = 0;                 //ama alfabenin son harfine gelindigi zaman tekrar alfabenin ilk harfine donmesi icin k=0 yapiyorum
				}
			}
		}
		cout << "ALFABE\t:";
		for (int i = 0; i < alfabeHarfSayisi; i++) // kullanicinin kullanacagi alfabeyi ekrana bastiriyorum 
		{
			cout << alfabe[i];
		}
		cout << endl;

	}
	Sifre(char* alfabe, int alfabeKarakterSayisi)
	{
		alfabeHarfSayisi = alfabeKarakterSayisi;
		for (int i = 0; i < alfabeKarakterSayisi + 1; i++)  //vigenere tablosunu dizi isimli iki boyutlu dizide olusturuyorum
		{
			for (int j = 0; j < alfabeKarakterSayisi + 1; j++)
			{

				if (i == 0 && j == 0)  //vigenere tablosunun ilk satir ilk sutunundaki elemani bostu onu atiyorum
				{
					dizi[i][j] = ' ';
				}
				else
				{
					dizi[i][j] = alfabe[k];                 //k degiskenini alfabedeki tum harfleri dolasmak icin kullaniyorum
					k++;                                   //alfabedeki tum harfleri sira sira diziye atiyarak vigenere tablosunu olusturmus olucam
					if (k == alfabeKarakterSayisi)         //ama alfabenin son harfine gelindigi zaman tekrar alfabenin ilk harfine donmesi icin k=0 yapiyorum
						k = 0;
				}
			}
		}
		cout << "ALFABE\t:";
		for (int i = 0; i < alfabeKarakterSayisi; i++) //kullanicinin kullanacagi alfabeyi ekrana bastiriyorum
		{
			cout << alfabe[i];
		}
		cout << endl;

	}

	void sifreKelimesiAta()
	{
		cout << "sifre kelimesinin karakter sayisini giriniz:";
		cin >> sifreKarakterSayisi;
		sifreKelimesi = new char[sifreKarakterSayisi];
		cout << "sifre kelimesini giriniz:";
		cin >> sifreKelimesi;
		k = 0;
	}
	void metinAta()
	{
		cout << "sifrelemek istedigniz metinin karakter sayisini giriniz:";
		cin >> metinKarakterSayisi;
		metin = new char[metinKarakterSayisi];
		cout << "sifrelemek istedigniz metini giriniz:";
		cin >> metin;
		cout << endl;
		cout << endl;
		cout << "SIFRE\t\t\t:" << sifreKelimesi << endl;
		cout << "METIN\t\t\t:";
		cout << metin << endl;

	}
	char* sifrele()
	{
		cout << "SIFRELENMIS METIN\t:";
		sifrelenmisMetin = new char[metinKarakterSayisi];
		k = 0;
		int kontrolMetin = 0;
		int kontrolSifre = 0;
		int satirTut;
		int sutunTut;

		for (int d = 0; d < metinKarakterSayisi; d++) //verilen metindeki her karakter icin bir sifreli karakter olusturulcak
		{
			for (int j = 1; j < alfabeHarfSayisi + 1; j++)  // vigenere tablosunun yani dizinin ilk satir, sutununda sifredeki kontrol ettigmiz harfe denk gelen sutunu buluyoruz
			{                                               //vigenere sifrelemenin odevdeki verdigi kural yani.
				if (sifreKelimesi[kontrolSifre] == dizi[0][j])  //eger bulduysa kacýncý sutun oldugnu sutunTut degiskeninde tutacak.
				{
					sutunTut = j;
					break;
				}

			}
			for (int i = 1; i < alfabeHarfSayisi + 1; i++) // vigenere tablosunun yani ilk sutununun bulundugu satirlarda metindeki kontrol ettigmiz harfe denkl gelen satiri bulup satirTut degiskeninde tutuyoruz.
			{
				if (metin[kontrolMetin] == dizi[i][0]) // eger bulduysa satiri satirTut degiskeninde tutuyoruz.
				{
					satirTut = i;
					break;
				}

			}

			sifrelenmisMetin[k] = dizi[satirTut][sutunTut]; //bulunan bu satirTut sutunTut degiskenlerinin tuttugu degerleri dizide yani vigenere tablosunda yerine koyup sifreli harfi buluyorum ve sifrelenmisMetin'e atiyorum.
			k++;
			kontrolSifre++;
			kontrolMetin++;
			if (kontrolSifre == sifreKarakterSayisi) //sifredeki harflerin hepsini kullandiysak tekrardan basa donmesi icin kontrolSifre  degiskenini 0'a esitliyorum.
				kontrolSifre = 0;
		}
		return sifrelenmisMetin;

	}
	char* sifrecoz()
	{

		cozulmusMetin = new char[metinKarakterSayisi];
		int kontrolSifre = 0;
		int kontrolSifreliMetin = 0;
		k = 0;
		int dolasSutun;
		int dolasSatir;
		cout << "DESIFRE METIN\t\t:";
		for (int u = 0; u < metinKarakterSayisi; u++) //verilen metindeki her karakter icin bir sifreli karakter olusturulmustu simdi bunlarin hepsini teker teker cozmek icin dongu
		{
			for (int j = 0; j < alfabeHarfSayisi + 1; j++) // vigenere tablosunun ilk satirinda sifre kelimesinin harflerini bulup kodluyorduk simdi yine cozmek icin tekrar buluyoruz.
			{
				if (dizi[0][j] == sifreKelimesi[kontrolSifre]) //eger bulduysak o sutun degerini dolasSutun degiskenine atiyoruz.
				{
					dolasSutun = j;
					break;
				}
			}
			for (int i = 1; i < alfabeHarfSayisi + 1; i++) //bu bulunan sutunun bir altindaki harften baslayarak tablonun en alt satirina kadar o sutunu kontrol ediyoruz
			{
				if (dizi[i][dolasSutun] == sifrelenmisMetin[kontrolSifreliMetin]) //eger sifrelenmismetindeki kontrol ettigmiz harfe esit olan harfi bulduysak oranin satir degerini dolasSatir degiskenine atiyoruz.
				{
					dolasSatir = i;
					break;
				}
			}
			cozulmusMetin[k] = dizi[dolasSatir][0]; //girilen metinin harfleri ilk sutununun altindaki satirlarda tutuluyordu ve biz bu satirin degerini yukarda bulduk 
			k++;                                    //yani bu buldugmuz satirdaki ilk sutun elemanini cozulmusMetin isimli diziye atip sifreli metnin cozulmus halini olusturucam
			kontrolSifre++;
			kontrolSifreliMetin++;
			if (kontrolSifre == sifreKarakterSayisi) //eger sifredeki en son harfide kontrol ettiysek en bastaki harfe donmesi icin kontrolSifre degiskenin 0'a esitliyorum
				kontrolSifre = 0;
		}

		return cozulmusMetin;
	}

	~Sifre()
	{
	}

};
int main()
{
	Sifre s1;
	s1.sifreKelimesiAta();
	s1.metinAta();
	cout << s1.sifrele() << endl;
	cout << s1.sifrecoz() << endl;
	cout << "----------------------------------------------" << endl;
	cout << "PARAMETRELI SINIF KURUCUSU CAGRILICAK" << endl;
	int alfabeKarakterSayisi;
	char* alfabe;
	cout << "alfabenizdeki karakter sayisini giriniz:";
	cin >> alfabeKarakterSayisi;
	alfabe = new char[alfabeKarakterSayisi];
	cout << "alfabenizi giriniz:";
	cin >> alfabe;
	cout << endl;
	Sifre s2(alfabe, alfabeKarakterSayisi);
	s2.sifreKelimesiAta();
	s2.metinAta();
	cout << s2.sifrele() << endl;
	cout << s2.sifrecoz() << endl;
	system("PAUSE");
}