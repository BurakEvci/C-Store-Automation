/****************************************************************************
**																SAKARYA �N�VERS�TES�
**													 B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**															B�LG�SAYAR M�HEND�SL��� B�L�M�
**															  PROGRAMLAMAYA G�R��� DERS�
**
**	�DEV NUMARASI   : PROJE 
**	��RENC� ADI   : Burak Can Evci
**	��RENC� NUMARASI : g211210091
**	DERS GRUBU : A
****************************************************************************/


#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Turkish");
	int secim;
	string �r�nKodu;
	string Sipari��r�nKodu;
	string aranan_�r�n;
	string aranan_m��teri;
	string aranan_sipari�;
	string �r�nAdi;
	string �reticisi;
	string TeminS�resi;
	double fiyat;
	double �zelFiyat;
	string kdv_Orani;
	int StokAdedi;
	string firmaNo;
	string firmaAdi;
	string firmaTel;
	string firmaYetkili;
	char m�steriKategorisi;
	string adres;
	string siparisTarihi;
	int siparisTutari;
	double siparisTutariGenel;
	double siparisTutari�zel;
	string SiparisListesi;
	string SiparisAlan;
	string FirmaNo;
	int siparisMiktar�;

	HANDLE renkSec;  // renkli yazmak icin gerekli kod
	renkSec = GetStdHandle(STD_OUTPUT_HANDLE); // renkli yazmak icin gerekli kod

	int yan�t;
	int cevap1;
	int cevap2;
	char cevap ;
	int cevap5;
	


	setlocale(LC_ALL, "Turkish");
	do
	{
		cout << "   Ne yapmak istiyorsunuz ? " << endl;
		cout << "   1) �r�nler i�in i�lemler " << endl;
		cout << "   2) m��teriler i�in i�lemler  " << endl;
		cout << "   3) sipari�ler i�in i�lemler " << endl;
		cin >> secim;
	

	if (secim == 1) // Eger secim 1'se �r�nler icin islemleri yap
	{
		
		

			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1) �r�n Ekleme " << endl;
				cout << "   2) �r�n Arama   " << endl;
				cout << "   3) �r�n Listeleme " << endl;
				cout << "   4) �r�n D�zeltme " << endl;
				cout << "   5) �r�n Silme " << endl;
				cin >> cevap1;
			} while (cevap1 != 1 && cevap1 != 2 && cevap1 != 3 && cevap1 != 4 && cevap1 != 5);
			
			
			if (cevap1 == 1) //Eger cevap1 1'se �r�n ekleme �slemleri
			{
				ofstream DosyaYaz;
				DosyaYaz.open("urun.txt", ios::app);
				do
				{
					SetConsoleTextAttribute(renkSec, 12);
					cout << "UYARI: Her �r�n i�in farkl� bir �r�n kodu girmelisiniz!";
					SetConsoleTextAttribute(renkSec, 7);

					cout << "\n urun kodu      :"; cin >> �r�nKodu;
					cout << "\n urun adi      :"; cin >> �r�nAdi;
					cout << "\n urun �reticisi   :"; cin >> �reticisi;
					cout << "\n Temin s�resi     :"; cin >> TeminS�resi;
					cout << "\n Fiyat�       :"; cin >> fiyat;
					cout << "\n �zel fiyat       :"; cin >> �zelFiyat;
					cout << "\n Kdv Oran�     :"; cin >> kdv_Orani;
					cout << "\n Stok adedi    :"; cin >> StokAdedi;

					DosyaYaz << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' '
						<< TeminS�resi << ' ' << fiyat << ' '
						<< �zelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi << ' ' << "\n ";
					cout << "\n urun bilgilerini kay�t ettiniz.Baska bir urunu kay�t etmek icin (e/h): "; cin >> cevap;
					

				} while (cevap == 'e');
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi. " << endl;


			}


			if (cevap1 == 2) // cevap1 2 ise �r�n arama islemleri
			{
				cout << "aranan �r�n�n �r�n kodunu giriniz" << endl;
				cin >> aranan_�r�n;

				int de�er = 0;

				ifstream DosyaOku("urun.txt");
				while (DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminS�resi >> fiyat >> �zelFiyat >> kdv_Orani >> StokAdedi)
				{

					if (aranan_�r�n == �r�nKodu)
					{
						 de�er = 1;
						cout << "aranan �r�n: " << endl;
						cout << "�r�n kodu : " << �r�nKodu << endl;
						cout << "�r�n ad� : " << �r�nAdi << endl;
						cout << "�r�n �reticisi: " << �reticisi << endl;
						cout << "Temin s�resi : " << TeminS�resi << endl;
						cout << "Fiyat : " << fiyat << endl;
						cout << "�zel Fiyat : " << �zelFiyat << endl;
						cout << "Kdv Oran� : " << kdv_Orani << endl;
						cout << "Stok Adedi : " << StokAdedi << endl;



					}



				}
				DosyaOku.close();
				if (de�er == 0)
				{
					cout << " Aranan �r�n Bulunamad�." << endl;

				}

			}
					



			if (cevap1 == 3) // Eger cevap1 3 ise urunleri listeler
			{
				
				ifstream DosyaOku("urun.txt");
				while (DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminS�resi >> fiyat >> �zelFiyat >> kdv_Orani >> StokAdedi)
				{
					
					cout << "�r�n kodu : " << �r�nKodu << endl;
					cout << "�r�n ad� : " << �r�nAdi << endl;
					cout << "�r�n �reticisi: " << �reticisi << endl;
					cout << "Temin s�resi : " << TeminS�resi << endl;
					cout << "Fiyat : " << fiyat << endl;
					cout << "�zel Fiyat : " << �zelFiyat << endl;
					cout << "Kdv Oran� : " << kdv_Orani << endl;
					cout << "Stok Adedi : " << StokAdedi << endl;
					cout << "**************************************"<< endl;

				}

				DosyaOku.close();

				
			}


			if (cevap1 == 4) // Eger cevap1 4 ise urun d�zeltir
			{
				string arananString;
				cout << " D�zeltilecek �r�n kodu  : "; cin >> arananString;
				ifstream DosyaOku("urun.txt");
				ofstream DosyaYaz("urun.tmp");
				while (DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminS�resi >> fiyat >> �zelFiyat >> kdv_Orani >> StokAdedi)
				{
	
					if (arananString == �r�nKodu)
					{
						cout << " Dosyadaki kay�t \n";
						cout << " �r�n Adi : " << �r�nAdi << endl;
						cout << " �reticisi : "<< �reticisi << endl;
						cout << " Temin S�resi : " << TeminS�resi << endl;
						cout << " Fiyat� : " << fiyat << endl;
						cout << " �zel Fiyat� : " << �zelFiyat << endl;
						cout << " Kdv Oran� : " << kdv_Orani << endl;
						cout << " Stok Adedi : " << StokAdedi << endl;
						cout << "\n Kay�t i�in yeni de�erler giri�i \n";
						cout << "\n �r�n Kodu : "; cin >> �r�nKodu;
						cout << "\n �r�n Ad� : "; cin >> �r�nAdi;
						cout << "\n �reticisi : "; cin >> �reticisi;
						cout << "\n Temin S�resi : "; cin >> TeminS�resi;
						cout << "\n Fiyat : "; cin >> fiyat;
						cout << "\n �zel Fiyat : "; cin >> �zelFiyat;
						cout << "\n Kdv Oran� : "; cin >> kdv_Orani;
						cout << "\n Stok Adedi : "; cin >> StokAdedi;

						DosyaYaz << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' ' << TeminS�resi << ' ' << fiyat << ' ' << �zelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi << "\n";

					}
					else
					{
						DosyaYaz << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' ' << TeminS�resi << ' ' << fiyat << ' ' << �zelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi << "\n";
					}
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("urun.txt");
				rename("urun.tmp", "urun.txt");
			
			
			
			}
					

			if (cevap1 == 5)  // Eger cevap1 5 ise urun siler.
			{
				string arananString;
				cout << "silinecek �r�n kodu  : "; cin >> arananString;
				ifstream DosyaOku("urun.txt",ios::in);
				ofstream DosyaYaz("urun.tmp");
				
				while (DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminS�resi >> fiyat >> �zelFiyat >> kdv_Orani >> StokAdedi)
				{
					
					if (arananString == �r�nKodu)
					{
						cout << "Silindi"<< endl;
					}
					else
					{
						//Silinmeyecek kay�tlar� yedek dosyaya kaydet
						DosyaYaz << �r�nKodu << ' ' << �r�nAdi << ' ' << �reticisi << ' ' << TeminS�resi << ' ' << fiyat << ' ' << �zelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi <<endl;
					}
				}
				//dosyalar� kapat
				DosyaYaz.close();
				DosyaOku.close();
					
				//As�l veri dosyas�n� diskten sil
				remove("urun.txt");
				//yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.
				rename("urun.tmp", "urun.txt");
			
			}

					
	}

	if (secim == 2) // secim 2 ise M��terilerle ilgili i�lemler.
	{
		
		
			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1) M��teri Ekleme " << endl;
				cout << "   2) M��teri Arama   " << endl;
				cout << "   3) M��teri D�zeltme " << endl;
				cout << "   4) M��teri Silme " << endl;
				cin >> cevap2;
			} while (cevap2 != 1 && cevap2 != 2 && cevap2 != 3 && cevap2 != 4);


			if (cevap2 == 1) // cevap2 1 ise  m�steri ekleme islemi
			{
				ofstream DosyaYaz1;
				DosyaYaz1.open("cari.txt",ios::app);


				do
				{
					SetConsoleTextAttribute(renkSec, 12);
					cout << "UYARI: Her �r�n i�in farkl� bir �r�n kodu girmelisiniz!" << endl;
					SetConsoleTextAttribute(renkSec, 7);

					cout << "\n firma numaras�      :"; cin >> firmaNo;
					cout << "\n firma adi     :"; cin >> firmaAdi;
					cout << "\n firma telefon : "; cin >> firmaTel;
					cout << "\n firma yetkilisi     :"; cin >> firmaYetkili;
					cout << "\n M��teri Kategorisi(genel(g),ozel(o))  :"; cin >> m�steriKategorisi;
					cout << "\n adres       :"; cin >> adres;

					DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << m�steriKategorisi << ' ' << adres << "\n";
					cout << "\n m��teri bilgilerini eklediniz.Baska bir m��teriyi eklemek istiyor musunuz (e/h): "; cin >> cevap;



				} while (cevap == 'e');
				DosyaYaz1.close();
				cout << "Dosyaya yazim tamamlandi." << endl;

				
			}


			if (cevap2 == 2) // cevap2 2 ise m��teri arama i�lemi
			{

				cout << "aranacak m��terinin firma numaras�n� giriniz." << endl;
				cin >> aranan_m��teri;
				int deger = 0;
				
				
						ifstream DosyaOku1("cari.txt");
						while(DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> m�steriKategorisi >> adres)
						{
							
							if (aranan_m��teri == firmaNo)
							{
								deger = 1;
								cout << "aranan m��teri: " << endl;
								cout << "Firma Numaras� : " << firmaNo << endl;
								cout << "Firma Ad� : " << firmaAdi << endl;
								cout << "Firma Telefonu: " << firmaTel << endl;
								cout << "Firma Yetkilisi : " << firmaYetkili << endl;
								cout << "M��teri Kategorisi(genel(g),ozel(o)) : " << m�steriKategorisi << endl;
								cout << "Adres : " << adres << endl;

								
							}

						}
						if(deger==0)
						{
						cout << "aranan m��teri bulunamad�" << endl;
						}

						DosyaOku1.close();
						
			}


			if (cevap2 == 3) // cevap2 3 ise m��teri d�zeltme i�lemi.
			{
				string arananString;
				cout << " D�zeltilecek m��terinin firma numaras�n� giriniz : "; cin >> arananString;
				ifstream DosyaOku1("cari.txt");
				ofstream DosyaYaz1("cari.tmp");
				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> m�steriKategorisi >> adres)
				{

					if (arananString == firmaNo)
					{
						cout << " Dosyadaki kay�t \n";
						cout << "\n firma numaras�      :" << firmaNo;
						cout << "\n firma adi     :" <<  firmaAdi;
						cout << "\n firma telefon : " << firmaTel;
						cout << "\n firma yetkilisi     :" << firmaYetkili;
						cout << "\n (genel/�zel)m�steri kategorisi  :" << m�steriKategorisi;
						cout << "\n adres       :" <<  adres;
						cout << "\n Kay�t i�in yeni de�erler giri�i \n";
						cout << "\n firma numaras�      :"; cin >> firmaNo;
						cout << "\n firma adi     :"; cin >> firmaAdi;
						cout << "\n firma telefon : "; cin >> firmaTel;
						cout << "\n firma yetkilisi     :"; cin >> firmaYetkili;
						cout << "\n (genel/�zel)m�steri kategorisi  :"; cin >> m�steriKategorisi;
						cout << "\n adres       :"; cin >> adres;

						DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << m�steriKategorisi << ' ' << adres << "\n";

					}
					else
					{
						DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << m�steriKategorisi << ' ' << adres << "\n";
					}
				}
				DosyaYaz1.close();
				DosyaOku1.close();
				remove("cari.txt");
				rename("cari.tmp", "cari.txt");
			
				
			}


			if (cevap2 == 4)  // cevap2 4 ise m��teri silme i�lemi
			{
				string arananString;
				cout << "silinecek M��teri firma numaras�  : "; cin >> arananString;
				ifstream DosyaOku1("cari.txt", ios::in);
				ofstream DosyaYaz1("cari.tmp");

				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> m�steriKategorisi >> adres)
				{

					if (arananString == firmaNo)
					{
						cout << "Silindi";
					}
					else
					{
						//Silinmeyecek kay�tlar� yedek dosyaya kaydet
						DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << m�steriKategorisi << ' ' << adres << "\n";

					}
				}
				//dosyalar� kapat
				DosyaYaz1.close();
				DosyaOku1.close();

				//As�l veri dosyas�n� diskten sil
				remove("cari.txt");
				//yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.
				rename("cari.tmp", "cari.txt");
			
					
			}

	}


	if (secim == 3) // secim 3 ise sipari� i�lemleri
	{
		
		
			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1) Sipari� Olu�tur " << endl;
				cout << "   2) Sipari� Arama   " << endl;
				cout << "   3) Sipari� D�zeltme " << endl;
				cout << "   4) Sipari� Silme " << endl;
				cout << "   5) Sipari� Raporlama " << endl;
				cin >> cevap5;
			} while (cevap5 != 1 && cevap5 != 2 && cevap5 != 3 && cevap5 != 4 && cevap5 != 5);


			if (cevap5 == 1) // cevap5 1 ise siparis ekleme islemi
			{
				ifstream DosyaOku("urun.txt", ios::in);
				while (DosyaOku >> �r�nKodu >> �r�nAdi >> �reticisi >> TeminS�resi >> fiyat >> �zelFiyat >> kdv_Orani >> StokAdedi)
				{
					SetConsoleTextAttribute(renkSec, 11);
					cout << "************************ �R�N B�LG�LER� ************************ \n";
					cout << "�r�n kodu : " << �r�nKodu << endl;
					cout << "�r�n ad� : " << �r�nAdi << endl;
					cout << "�r�n �reticisi: " << �reticisi << endl;
					cout << "Temin s�resi : " << TeminS�resi << endl;
					cout << "Fiyat : " << fiyat << endl;
					cout << "�zel Fiyat : " << �zelFiyat << endl;
					cout << "Kdv Oran� : " << kdv_Orani << endl;
					cout << "Stok Adedi : " << StokAdedi << endl;
					SetConsoleTextAttribute(renkSec, 7);
				}
				string  Sipari�Edilen�r�nKodu;
				cout << "\n Sipari� edilecek �r�n�n kodu : "; cin >> Sipari�Edilen�r�nKodu;
				if (�r�nKodu == Sipari�Edilen�r�nKodu)
				{
					DosyaOku.close();
				}

				ifstream DosyaOku1;
				DosyaOku1.open("cari.txt");
				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> m�steriKategorisi >> adres)
				{
					SetConsoleTextAttribute(renkSec, 6);
					cout << "************************ F�RMA B�LG�LER� ************************ \n";
					cout << "  firma numaras�      :" <<  firmaNo;
					cout << "\n firma adi     :" <<		 firmaAdi;
					cout << "\n firma telefon : " <<  firmaTel;
					cout << "\n firma yetkilisi     :" << firmaYetkili;
					cout << "\n m�steri kategorisi(genel/�zel)  :" << m�steriKategorisi;
					cout << "\n adres       :" << adres << endl;
					SetConsoleTextAttribute(renkSec, 7);
				}
				DosyaOku1.close();

				cout << "\n Sipari� verecek firman�n numaras�n� giriniz :"; cin >> FirmaNo;
				
				DosyaOku1.open("cari.txt");

				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> m�steriKategorisi >> adres)
				{
					if (firmaNo == FirmaNo)
					{
						

						cout << "Sipari� Vermek �stiyor Musunuz ?(evet i�in 1 ,hay�r i�in 2 say�s�n� giriniz.) : "; cin >> yan�t;
						

						if (yan�t == 1)
						{
							cout << "Sipari� Tarihini giriniz : "; cin >> siparisTarihi;
							cout << "Sipari� Miktar�n� giriniz : "; cin >> siparisMiktar�;


							siparisTutariGenel = fiyat * siparisMiktar�;
							siparisTutari�zel = �zelFiyat * siparisMiktar�;
							SiparisAlan = firmaAdi;


							ofstream DosyaYaz2;
							DosyaYaz2.open("siparis.txt", ios::app);
							
							if(m�steriKategorisi == 'o')
							{ 
								DosyaYaz2 << FirmaNo << ' ' << Sipari�Edilen�r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutari�zel << ' '  << SiparisAlan << ' ' << "\n ";
							
								ifstream DosyaOku2("siparis.txt", ios::in);

								
								cout << "\n Sipari� Verildi." << endl;
								            

								SetConsoleTextAttribute(renkSec, 11);
								cout << "Sipari� edilen �r�n�n Bilgileri" << endl;
								cout << "�r�n kodu : " << Sipari�Edilen�r�nKodu << endl;
								cout << "�r�n ad� : " << �r�nAdi << endl;
								cout << "�r�n �reticisi: " << �reticisi << endl;
								cout << "Temin s�resi : " << TeminS�resi << endl;
								cout << "Fiyat : " << fiyat << endl;
								cout << "�zel Fiyat : " << �zelFiyat << endl;
								cout << "Kdv Oran� : " << kdv_Orani << endl;
								cout << "Stok Adedi : " << StokAdedi << endl;
								
								SetConsoleTextAttribute(renkSec, 6);
								cout << "Sipari� eden M��terinin Bilgileri" << endl;
								cout << "Firma Numaras� : " << firmaNo << endl;
								cout << "Firma Ad� : " << firmaAdi << endl;
								cout << "Firma Telefonu: " << firmaTel << endl;
								cout << "Firma Yetkilisi : " << firmaYetkili << endl;
								cout << "M��teri Kategorisi(genel(g),ozel(o)) : " << m�steriKategorisi << endl;
								cout << "Adres : " << adres << endl;


								SetConsoleTextAttribute(renkSec, 12);
								cout << "Sipari� Bilgileri : " ;
								cout << "\n Sipari�i Alan : " << SiparisAlan;
								cout << "\n Sipari� Tarihi : " << siparisTarihi;
								cout << "\n Sipari� Tutar� : " << siparisTutari�zel;
								
								
								SetConsoleTextAttribute(renkSec, 7);
								DosyaOku2.close();
							
							
							}

							if (m�steriKategorisi == 'g')
							{
								DosyaYaz2 << FirmaNo << ' ' << Sipari�Edilen�r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutariGenel << ' ' << SiparisAlan << ' ' << "\n ";
							

								ifstream DosyaOku2("siparis.txt", ios::in);

								
								cout << "\n Sipari� Verildi." << endl;
								SetConsoleTextAttribute(renkSec, 11);
								cout << "Sipari� edilen �r�n�n Bilgileri" << endl;
								cout << "�r�n kodu : " << Sipari�Edilen�r�nKodu << endl;
								cout << "�r�n ad� : " << �r�nAdi << endl;
								cout << "�r�n �reticisi: " << �reticisi << endl;
								cout << "Temin s�resi : " << TeminS�resi << endl;
								cout << "Fiyat : " << fiyat << endl;
								cout << "�zel Fiyat : " << �zelFiyat << endl;
								cout << "Kdv Oran� : " << kdv_Orani << endl;
								cout << "Stok Adedi : " << StokAdedi << endl;
								
								SetConsoleTextAttribute(renkSec, 6);
								cout << "Sipari� eden M��terinin Bilgileri" << endl;
								cout << "Firma Numaras� : " << firmaNo << endl;
								cout << "Firma Ad� : " << firmaAdi << endl;
								cout << "Firma Telefonu: " << firmaTel << endl;
								cout << "Firma Yetkilisi : " << firmaYetkili << endl;
								cout << "M��teri Kategorisi(genel(g),ozel(o)) : " << m�steriKategorisi << endl;
								cout << "Adres : " << adres << endl;


								SetConsoleTextAttribute(renkSec, 12);
								cout << "Sipari� Bilgileri : ";
								cout << "\n Sipari�i Alan : " << SiparisAlan;
								cout << "\n Sipari� Tarihi : " << siparisTarihi;
								cout << "\n Sipari� Tutar� : " << siparisTutariGenel;

								SetConsoleTextAttribute(renkSec, 7);
								
								DosyaOku2.close();

							
							}
							DosyaYaz2.close();
							
						}

						
						if (yan�t == 2)
						{
							cout << "Sipari� Verilmemi�tir.";

						}


					}

				}


				cout << "\n Dosyaya yaz�m tamamland�" << endl;
									
			}




			if (cevap5 == 2) // cevap5 2 ise sipari� arama 
			{
				string aranan�r�n;
				

				cout << "Sipari�i aranacak firma numaras�n� giriniz." << endl;
				cin >> aranan_sipari�;

				cout << "Sipari�i aranacak �r�n�n kodunu giriniz" << endl;
				cin >> aranan�r�n;

				int degerr = 0;
				ifstream DosyaOku2("siparis.txt");
				while (DosyaOku2 >> FirmaNo >> �r�nKodu >> siparisTarihi >> siparisTutari  >> SiparisAlan)
				{

					if (aranan_sipari� == FirmaNo&&�r�nKodu==aranan�r�n)
					{
						degerr = 1;
						cout << "aranan sipari�: " << endl;
						cout << "Firma Numaras� : " << FirmaNo << endl;
						cout << "�r�n Kodu : " << �r�nKodu << endl;
						cout << "Sipari� Tarihi : " << siparisTarihi << endl;
						cout << "Sipari� Tutar� : " << siparisTutari << endl;
					
						cout << "Sipari� Alan : " << SiparisAlan << endl;


					}

				}

				DosyaOku2.close();

				if(degerr==0)
				{
				cout << "aranan sipari� bulunamad�" << endl;
				}

			
			}



			if (cevap5 == 3) // cevap5 3 ise sipari� d�zeltme i�lemi
			{
				string d�zeltilecekString2;
				string d�zeltilecekString1;

				cout << " D�zeltilecek sipari�in Firma Numaras�  : "; cin >> d�zeltilecekString2;
				cout << " D�zeltilecek sipari�in �r�n Kodu  : "; cin >> d�zeltilecekString1;
				
				ifstream DosyaOku2("siparis.txt");
				ofstream DosyaYaz2("siparis.tmp");
				while (DosyaOku2 >> FirmaNo >> �r�nKodu >> siparisTarihi >> siparisTutari >> SiparisAlan)
				{

					if (d�zeltilecekString2 == FirmaNo&&d�zeltilecekString1==�r�nKodu)
					{
						cout << " Dosyadaki kay�t \n";
						cout << "\n firma numarasi : " << FirmaNo;
						cout << "\n �r�n kodu : " << �r�nKodu;
						cout << "\n siparis tarihi : " <<  siparisTarihi;
						cout << "\n siparis tutar� : " << siparisTutari;
						cout << "\n siparisi alan : " <<  SiparisAlan;
	
						cout << "\n Kay�t i�in yeni de�erler giri�i \n";
						cout << "\n siparis tarihi : "; cin >> siparisTarihi;
						cout << "Sipari� Tutar� : \n" << siparisTutari;
						cout << "siparisi alan : \n"; cin >> SiparisAlan;
						
						DosyaYaz2 << FirmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutari  << ' '  << SiparisAlan << ' ' << "\n ";
					}
					else
					{
						DosyaYaz2 << FirmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutari << ' '  << SiparisAlan << ' ' << "\n ";
					}
				}
				DosyaYaz2.close();
				DosyaOku2.close();
				remove("siparis.txt");
				rename("siparis.tmp", "siparis.txt");
			
				
			}



			if (cevap5 == 4) // cevap5 4 ise sipari� silme i�lemi
			{
				string siparisSilme�r�n;
				string siparisSilmeNo;
				cout << "\nSipari�i silinecek firman�n firma numaras�n� giriniz : "; cin >> siparisSilmeNo;
				cout << "\nSipari�i silinecek �r�n�n �r�n kodunu giriniz"; cin >> siparisSilme�r�n;
				
									
				ifstream DosyaOku2("siparis.txt", ios::in);
				ofstream DosyaYaz2("siparis.tmp");

				while (DosyaOku2 >> FirmaNo >> �r�nKodu >> siparisTarihi >> siparisTutari  >> SiparisAlan)
				{

					if (siparisSilmeNo == FirmaNo&&siparisSilme�r�n==�r�nKodu)
					{
						cout << "Silindi";
					}
					else
					{
						//Silinmeyecek kay�tlar� yedek dosyaya kaydet

						DosyaYaz2 << FirmaNo << ' ' << �r�nKodu<< ' ' << siparisTarihi << ' ' << siparisTutari << ' '  << SiparisAlan << ' ' << endl;
					}
				}
				//dosyalar� kapat
				DosyaYaz2.close();
				DosyaOku2.close();

				//As�l veri dosyas�n� diskten sil
				remove("siparis.txt");
				//yedek dosyan�n ismini as�l dosya ismi olarak de�i�tir.
				rename("siparis.tmp", "siparis.txt");

			}


			if (cevap5 == 5) // cevap5 5 ise sipari� raporu i�lemi
			{
				ifstream DosyaOku2("siparis.txt");
				ofstream DosyaYaz3("siparislistesi.txt");
				while (DosyaOku2 >> FirmaNo >> �r�nKodu >> siparisTarihi >> siparisTutari >> SiparisAlan)
				{

					cout << "Firma Numaras� : " << FirmaNo << endl;
					cout << "�r�n kodu : " << �r�nKodu << endl;
					cout << "Sipari� tarihi : " << siparisTarihi << endl;
					cout << "Sipari� tutar� : " << siparisTutari << endl;
					cout << "Sipari�i alan : " << SiparisAlan << endl;
					cout << "**************************************" << endl;

					DosyaYaz3 << FirmaNo << ' ' << �r�nKodu << ' ' << siparisTarihi << ' ' << siparisTutari << ' '  << SiparisAlan << ' ' << endl;

				}
				DosyaOku2.close();
				DosyaYaz3.close();	

			}

		
	}
} while (1);


}

