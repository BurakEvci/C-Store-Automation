/****************************************************************************
**																SAKARYA ÜNÝVERSÝTESÝ
**													 BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**															BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**															  PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**	ÖDEV NUMARASI   : PROJE 
**	ÖÐRENCÝ ADI   : Burak Can Evci
**	ÖÐRENCÝ NUMARASI : g211210091
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
	string ürünKodu;
	string SipariþÜrünKodu;
	string aranan_Ürün;
	string aranan_müþteri;
	string aranan_sipariþ;
	string ürünAdi;
	string üreticisi;
	string TeminSüresi;
	double fiyat;
	double ÖzelFiyat;
	string kdv_Orani;
	int StokAdedi;
	string firmaNo;
	string firmaAdi;
	string firmaTel;
	string firmaYetkili;
	char müsteriKategorisi;
	string adres;
	string siparisTarihi;
	int siparisTutari;
	double siparisTutariGenel;
	double siparisTutariÖzel;
	string SiparisListesi;
	string SiparisAlan;
	string FirmaNo;
	int siparisMiktarý;

	HANDLE renkSec;  // renkli yazmak icin gerekli kod
	renkSec = GetStdHandle(STD_OUTPUT_HANDLE); // renkli yazmak icin gerekli kod

	int yanýt;
	int cevap1;
	int cevap2;
	char cevap ;
	int cevap5;
	


	setlocale(LC_ALL, "Turkish");
	do
	{
		cout << "   Ne yapmak istiyorsunuz ? " << endl;
		cout << "   1) ürünler için iþlemler " << endl;
		cout << "   2) müþteriler için iþlemler  " << endl;
		cout << "   3) sipariþler için iþlemler " << endl;
		cin >> secim;
	

	if (secim == 1) // Eger secim 1'se ürünler icin islemleri yap
	{
		
		

			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1) Ürün Ekleme " << endl;
				cout << "   2) Ürün Arama   " << endl;
				cout << "   3) Ürün Listeleme " << endl;
				cout << "   4) Ürün Düzeltme " << endl;
				cout << "   5) Ürün Silme " << endl;
				cin >> cevap1;
			} while (cevap1 != 1 && cevap1 != 2 && cevap1 != 3 && cevap1 != 4 && cevap1 != 5);
			
			
			if (cevap1 == 1) //Eger cevap1 1'se ürün ekleme ýslemleri
			{
				ofstream DosyaYaz;
				DosyaYaz.open("urun.txt", ios::app);
				do
				{
					SetConsoleTextAttribute(renkSec, 12);
					cout << "UYARI: Her ürün için farklý bir ürün kodu girmelisiniz!";
					SetConsoleTextAttribute(renkSec, 7);

					cout << "\n urun kodu      :"; cin >> ürünKodu;
					cout << "\n urun adi      :"; cin >> ürünAdi;
					cout << "\n urun Üreticisi   :"; cin >> üreticisi;
					cout << "\n Temin süresi     :"; cin >> TeminSüresi;
					cout << "\n Fiyatý       :"; cin >> fiyat;
					cout << "\n Özel fiyat       :"; cin >> ÖzelFiyat;
					cout << "\n Kdv Oraný     :"; cin >> kdv_Orani;
					cout << "\n Stok adedi    :"; cin >> StokAdedi;

					DosyaYaz << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' '
						<< TeminSüresi << ' ' << fiyat << ' '
						<< ÖzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi << ' ' << "\n ";
					cout << "\n urun bilgilerini kayýt ettiniz.Baska bir urunu kayýt etmek icin (e/h): "; cin >> cevap;
					

				} while (cevap == 'e');
				DosyaYaz.close();
				cout << "dosyaya yazim tamamlandi. " << endl;


			}


			if (cevap1 == 2) // cevap1 2 ise ürün arama islemleri
			{
				cout << "aranan ürünün ürün kodunu giriniz" << endl;
				cin >> aranan_Ürün;

				int deðer = 0;

				ifstream DosyaOku("urun.txt");
				while (DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSüresi >> fiyat >> ÖzelFiyat >> kdv_Orani >> StokAdedi)
				{

					if (aranan_Ürün == ürünKodu)
					{
						 deðer = 1;
						cout << "aranan ürün: " << endl;
						cout << "Ürün kodu : " << ürünKodu << endl;
						cout << "Ürün adý : " << ürünAdi << endl;
						cout << "Ürün üreticisi: " << üreticisi << endl;
						cout << "Temin süresi : " << TeminSüresi << endl;
						cout << "Fiyat : " << fiyat << endl;
						cout << "Özel Fiyat : " << ÖzelFiyat << endl;
						cout << "Kdv Oraný : " << kdv_Orani << endl;
						cout << "Stok Adedi : " << StokAdedi << endl;



					}



				}
				DosyaOku.close();
				if (deðer == 0)
				{
					cout << " Aranan Ürün Bulunamadý." << endl;

				}

			}
					



			if (cevap1 == 3) // Eger cevap1 3 ise urunleri listeler
			{
				
				ifstream DosyaOku("urun.txt");
				while (DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSüresi >> fiyat >> ÖzelFiyat >> kdv_Orani >> StokAdedi)
				{
					
					cout << "Ürün kodu : " << ürünKodu << endl;
					cout << "Ürün adý : " << ürünAdi << endl;
					cout << "Ürün üreticisi: " << üreticisi << endl;
					cout << "Temin süresi : " << TeminSüresi << endl;
					cout << "Fiyat : " << fiyat << endl;
					cout << "Özel Fiyat : " << ÖzelFiyat << endl;
					cout << "Kdv Oraný : " << kdv_Orani << endl;
					cout << "Stok Adedi : " << StokAdedi << endl;
					cout << "**************************************"<< endl;

				}

				DosyaOku.close();

				
			}


			if (cevap1 == 4) // Eger cevap1 4 ise urun düzeltir
			{
				string arananString;
				cout << " Düzeltilecek ürün kodu  : "; cin >> arananString;
				ifstream DosyaOku("urun.txt");
				ofstream DosyaYaz("urun.tmp");
				while (DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSüresi >> fiyat >> ÖzelFiyat >> kdv_Orani >> StokAdedi)
				{
	
					if (arananString == ürünKodu)
					{
						cout << " Dosyadaki kayýt \n";
						cout << " Ürün Adi : " << ürünAdi << endl;
						cout << " Üreticisi : "<< üreticisi << endl;
						cout << " Temin Süresi : " << TeminSüresi << endl;
						cout << " Fiyatý : " << fiyat << endl;
						cout << " Özel Fiyatý : " << ÖzelFiyat << endl;
						cout << " Kdv Oraný : " << kdv_Orani << endl;
						cout << " Stok Adedi : " << StokAdedi << endl;
						cout << "\n Kayýt için yeni deðerler giriþi \n";
						cout << "\n Ürün Kodu : "; cin >> ürünKodu;
						cout << "\n Ürün Adý : "; cin >> ürünAdi;
						cout << "\n Üreticisi : "; cin >> üreticisi;
						cout << "\n Temin Süresi : "; cin >> TeminSüresi;
						cout << "\n Fiyat : "; cin >> fiyat;
						cout << "\n Özel Fiyat : "; cin >> ÖzelFiyat;
						cout << "\n Kdv Oraný : "; cin >> kdv_Orani;
						cout << "\n Stok Adedi : "; cin >> StokAdedi;

						DosyaYaz << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' ' << TeminSüresi << ' ' << fiyat << ' ' << ÖzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi << "\n";

					}
					else
					{
						DosyaYaz << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' ' << TeminSüresi << ' ' << fiyat << ' ' << ÖzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi << "\n";
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
				cout << "silinecek ürün kodu  : "; cin >> arananString;
				ifstream DosyaOku("urun.txt",ios::in);
				ofstream DosyaYaz("urun.tmp");
				
				while (DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSüresi >> fiyat >> ÖzelFiyat >> kdv_Orani >> StokAdedi)
				{
					
					if (arananString == ürünKodu)
					{
						cout << "Silindi"<< endl;
					}
					else
					{
						//Silinmeyecek kayýtlarý yedek dosyaya kaydet
						DosyaYaz << ürünKodu << ' ' << ürünAdi << ' ' << üreticisi << ' ' << TeminSüresi << ' ' << fiyat << ' ' << ÖzelFiyat << ' ' << kdv_Orani << ' ' << StokAdedi <<endl;
					}
				}
				//dosyalarý kapat
				DosyaYaz.close();
				DosyaOku.close();
					
				//Asýl veri dosyasýný diskten sil
				remove("urun.txt");
				//yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.
				rename("urun.tmp", "urun.txt");
			
			}

					
	}

	if (secim == 2) // secim 2 ise Müþterilerle ilgili iþlemler.
	{
		
		
			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1) Müþteri Ekleme " << endl;
				cout << "   2) Müþteri Arama   " << endl;
				cout << "   3) Müþteri Düzeltme " << endl;
				cout << "   4) Müþteri Silme " << endl;
				cin >> cevap2;
			} while (cevap2 != 1 && cevap2 != 2 && cevap2 != 3 && cevap2 != 4);


			if (cevap2 == 1) // cevap2 1 ise  müsteri ekleme islemi
			{
				ofstream DosyaYaz1;
				DosyaYaz1.open("cari.txt",ios::app);


				do
				{
					SetConsoleTextAttribute(renkSec, 12);
					cout << "UYARI: Her ürün için farklý bir ürün kodu girmelisiniz!" << endl;
					SetConsoleTextAttribute(renkSec, 7);

					cout << "\n firma numarasý      :"; cin >> firmaNo;
					cout << "\n firma adi     :"; cin >> firmaAdi;
					cout << "\n firma telefon : "; cin >> firmaTel;
					cout << "\n firma yetkilisi     :"; cin >> firmaYetkili;
					cout << "\n Müþteri Kategorisi(genel(g),ozel(o))  :"; cin >> müsteriKategorisi;
					cout << "\n adres       :"; cin >> adres;

					DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << müsteriKategorisi << ' ' << adres << "\n";
					cout << "\n müþteri bilgilerini eklediniz.Baska bir müþteriyi eklemek istiyor musunuz (e/h): "; cin >> cevap;



				} while (cevap == 'e');
				DosyaYaz1.close();
				cout << "Dosyaya yazim tamamlandi." << endl;

				
			}


			if (cevap2 == 2) // cevap2 2 ise müþteri arama iþlemi
			{

				cout << "aranacak müþterinin firma numarasýný giriniz." << endl;
				cin >> aranan_müþteri;
				int deger = 0;
				
				
						ifstream DosyaOku1("cari.txt");
						while(DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> müsteriKategorisi >> adres)
						{
							
							if (aranan_müþteri == firmaNo)
							{
								deger = 1;
								cout << "aranan müþteri: " << endl;
								cout << "Firma Numarasý : " << firmaNo << endl;
								cout << "Firma Adý : " << firmaAdi << endl;
								cout << "Firma Telefonu: " << firmaTel << endl;
								cout << "Firma Yetkilisi : " << firmaYetkili << endl;
								cout << "Müþteri Kategorisi(genel(g),ozel(o)) : " << müsteriKategorisi << endl;
								cout << "Adres : " << adres << endl;

								
							}

						}
						if(deger==0)
						{
						cout << "aranan müþteri bulunamadý" << endl;
						}

						DosyaOku1.close();
						
			}


			if (cevap2 == 3) // cevap2 3 ise müþteri düzeltme iþlemi.
			{
				string arananString;
				cout << " Düzeltilecek müþterinin firma numarasýný giriniz : "; cin >> arananString;
				ifstream DosyaOku1("cari.txt");
				ofstream DosyaYaz1("cari.tmp");
				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> müsteriKategorisi >> adres)
				{

					if (arananString == firmaNo)
					{
						cout << " Dosyadaki kayýt \n";
						cout << "\n firma numarasý      :" << firmaNo;
						cout << "\n firma adi     :" <<  firmaAdi;
						cout << "\n firma telefon : " << firmaTel;
						cout << "\n firma yetkilisi     :" << firmaYetkili;
						cout << "\n (genel/özel)müsteri kategorisi  :" << müsteriKategorisi;
						cout << "\n adres       :" <<  adres;
						cout << "\n Kayýt için yeni deðerler giriþi \n";
						cout << "\n firma numarasý      :"; cin >> firmaNo;
						cout << "\n firma adi     :"; cin >> firmaAdi;
						cout << "\n firma telefon : "; cin >> firmaTel;
						cout << "\n firma yetkilisi     :"; cin >> firmaYetkili;
						cout << "\n (genel/özel)müsteri kategorisi  :"; cin >> müsteriKategorisi;
						cout << "\n adres       :"; cin >> adres;

						DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << müsteriKategorisi << ' ' << adres << "\n";

					}
					else
					{
						DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << müsteriKategorisi << ' ' << adres << "\n";
					}
				}
				DosyaYaz1.close();
				DosyaOku1.close();
				remove("cari.txt");
				rename("cari.tmp", "cari.txt");
			
				
			}


			if (cevap2 == 4)  // cevap2 4 ise müþteri silme iþlemi
			{
				string arananString;
				cout << "silinecek Müþteri firma numarasý  : "; cin >> arananString;
				ifstream DosyaOku1("cari.txt", ios::in);
				ofstream DosyaYaz1("cari.tmp");

				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> müsteriKategorisi >> adres)
				{

					if (arananString == firmaNo)
					{
						cout << "Silindi";
					}
					else
					{
						//Silinmeyecek kayýtlarý yedek dosyaya kaydet
						DosyaYaz1 << firmaNo << ' ' << firmaAdi << ' ' << firmaTel << ' ' << firmaYetkili << ' ' << müsteriKategorisi << ' ' << adres << "\n";

					}
				}
				//dosyalarý kapat
				DosyaYaz1.close();
				DosyaOku1.close();

				//Asýl veri dosyasýný diskten sil
				remove("cari.txt");
				//yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.
				rename("cari.tmp", "cari.txt");
			
					
			}

	}


	if (secim == 3) // secim 3 ise sipariþ iþlemleri
	{
		
		
			do
			{
				cout << "   Ne yapmak istiyorsunuz ? " << endl;
				cout << "   1) Sipariþ Oluþtur " << endl;
				cout << "   2) Sipariþ Arama   " << endl;
				cout << "   3) Sipariþ Düzeltme " << endl;
				cout << "   4) Sipariþ Silme " << endl;
				cout << "   5) Sipariþ Raporlama " << endl;
				cin >> cevap5;
			} while (cevap5 != 1 && cevap5 != 2 && cevap5 != 3 && cevap5 != 4 && cevap5 != 5);


			if (cevap5 == 1) // cevap5 1 ise siparis ekleme islemi
			{
				ifstream DosyaOku("urun.txt", ios::in);
				while (DosyaOku >> ürünKodu >> ürünAdi >> üreticisi >> TeminSüresi >> fiyat >> ÖzelFiyat >> kdv_Orani >> StokAdedi)
				{
					SetConsoleTextAttribute(renkSec, 11);
					cout << "************************ ÜRÜN BÝLGÝLERÝ ************************ \n";
					cout << "Ürün kodu : " << ürünKodu << endl;
					cout << "Ürün adý : " << ürünAdi << endl;
					cout << "Ürün üreticisi: " << üreticisi << endl;
					cout << "Temin süresi : " << TeminSüresi << endl;
					cout << "Fiyat : " << fiyat << endl;
					cout << "Özel Fiyat : " << ÖzelFiyat << endl;
					cout << "Kdv Oraný : " << kdv_Orani << endl;
					cout << "Stok Adedi : " << StokAdedi << endl;
					SetConsoleTextAttribute(renkSec, 7);
				}
				string  SipariþEdilenÜrünKodu;
				cout << "\n Sipariþ edilecek ürünün kodu : "; cin >> SipariþEdilenÜrünKodu;
				if (ürünKodu == SipariþEdilenÜrünKodu)
				{
					DosyaOku.close();
				}

				ifstream DosyaOku1;
				DosyaOku1.open("cari.txt");
				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> müsteriKategorisi >> adres)
				{
					SetConsoleTextAttribute(renkSec, 6);
					cout << "************************ FÝRMA BÝLGÝLERÝ ************************ \n";
					cout << "  firma numarasý      :" <<  firmaNo;
					cout << "\n firma adi     :" <<		 firmaAdi;
					cout << "\n firma telefon : " <<  firmaTel;
					cout << "\n firma yetkilisi     :" << firmaYetkili;
					cout << "\n müsteri kategorisi(genel/özel)  :" << müsteriKategorisi;
					cout << "\n adres       :" << adres << endl;
					SetConsoleTextAttribute(renkSec, 7);
				}
				DosyaOku1.close();

				cout << "\n Sipariþ verecek firmanýn numarasýný giriniz :"; cin >> FirmaNo;
				
				DosyaOku1.open("cari.txt");

				while (DosyaOku1 >> firmaNo >> firmaAdi >> firmaTel >> firmaYetkili >> müsteriKategorisi >> adres)
				{
					if (firmaNo == FirmaNo)
					{
						

						cout << "Sipariþ Vermek Ýstiyor Musunuz ?(evet için 1 ,hayýr için 2 sayýsýný giriniz.) : "; cin >> yanýt;
						

						if (yanýt == 1)
						{
							cout << "Sipariþ Tarihini giriniz : "; cin >> siparisTarihi;
							cout << "Sipariþ Miktarýný giriniz : "; cin >> siparisMiktarý;


							siparisTutariGenel = fiyat * siparisMiktarý;
							siparisTutariÖzel = ÖzelFiyat * siparisMiktarý;
							SiparisAlan = firmaAdi;


							ofstream DosyaYaz2;
							DosyaYaz2.open("siparis.txt", ios::app);
							
							if(müsteriKategorisi == 'o')
							{ 
								DosyaYaz2 << FirmaNo << ' ' << SipariþEdilenÜrünKodu << ' ' << siparisTarihi << ' ' << siparisTutariÖzel << ' '  << SiparisAlan << ' ' << "\n ";
							
								ifstream DosyaOku2("siparis.txt", ios::in);

								
								cout << "\n Sipariþ Verildi." << endl;
								            

								SetConsoleTextAttribute(renkSec, 11);
								cout << "Sipariþ edilen Ürünün Bilgileri" << endl;
								cout << "Ürün kodu : " << SipariþEdilenÜrünKodu << endl;
								cout << "Ürün adý : " << ürünAdi << endl;
								cout << "Ürün üreticisi: " << üreticisi << endl;
								cout << "Temin süresi : " << TeminSüresi << endl;
								cout << "Fiyat : " << fiyat << endl;
								cout << "Özel Fiyat : " << ÖzelFiyat << endl;
								cout << "Kdv Oraný : " << kdv_Orani << endl;
								cout << "Stok Adedi : " << StokAdedi << endl;
								
								SetConsoleTextAttribute(renkSec, 6);
								cout << "Sipariþ eden Müþterinin Bilgileri" << endl;
								cout << "Firma Numarasý : " << firmaNo << endl;
								cout << "Firma Adý : " << firmaAdi << endl;
								cout << "Firma Telefonu: " << firmaTel << endl;
								cout << "Firma Yetkilisi : " << firmaYetkili << endl;
								cout << "Müþteri Kategorisi(genel(g),ozel(o)) : " << müsteriKategorisi << endl;
								cout << "Adres : " << adres << endl;


								SetConsoleTextAttribute(renkSec, 12);
								cout << "Sipariþ Bilgileri : " ;
								cout << "\n Sipariþi Alan : " << SiparisAlan;
								cout << "\n Sipariþ Tarihi : " << siparisTarihi;
								cout << "\n Sipariþ Tutarý : " << siparisTutariÖzel;
								
								
								SetConsoleTextAttribute(renkSec, 7);
								DosyaOku2.close();
							
							
							}

							if (müsteriKategorisi == 'g')
							{
								DosyaYaz2 << FirmaNo << ' ' << SipariþEdilenÜrünKodu << ' ' << siparisTarihi << ' ' << siparisTutariGenel << ' ' << SiparisAlan << ' ' << "\n ";
							

								ifstream DosyaOku2("siparis.txt", ios::in);

								
								cout << "\n Sipariþ Verildi." << endl;
								SetConsoleTextAttribute(renkSec, 11);
								cout << "Sipariþ edilen Ürünün Bilgileri" << endl;
								cout << "Ürün kodu : " << SipariþEdilenÜrünKodu << endl;
								cout << "Ürün adý : " << ürünAdi << endl;
								cout << "Ürün üreticisi: " << üreticisi << endl;
								cout << "Temin süresi : " << TeminSüresi << endl;
								cout << "Fiyat : " << fiyat << endl;
								cout << "Özel Fiyat : " << ÖzelFiyat << endl;
								cout << "Kdv Oraný : " << kdv_Orani << endl;
								cout << "Stok Adedi : " << StokAdedi << endl;
								
								SetConsoleTextAttribute(renkSec, 6);
								cout << "Sipariþ eden Müþterinin Bilgileri" << endl;
								cout << "Firma Numarasý : " << firmaNo << endl;
								cout << "Firma Adý : " << firmaAdi << endl;
								cout << "Firma Telefonu: " << firmaTel << endl;
								cout << "Firma Yetkilisi : " << firmaYetkili << endl;
								cout << "Müþteri Kategorisi(genel(g),ozel(o)) : " << müsteriKategorisi << endl;
								cout << "Adres : " << adres << endl;


								SetConsoleTextAttribute(renkSec, 12);
								cout << "Sipariþ Bilgileri : ";
								cout << "\n Sipariþi Alan : " << SiparisAlan;
								cout << "\n Sipariþ Tarihi : " << siparisTarihi;
								cout << "\n Sipariþ Tutarý : " << siparisTutariGenel;

								SetConsoleTextAttribute(renkSec, 7);
								
								DosyaOku2.close();

							
							}
							DosyaYaz2.close();
							
						}

						
						if (yanýt == 2)
						{
							cout << "Sipariþ Verilmemiþtir.";

						}


					}

				}


				cout << "\n Dosyaya yazým tamamlandý" << endl;
									
			}




			if (cevap5 == 2) // cevap5 2 ise sipariþ arama 
			{
				string arananÜrün;
				

				cout << "Sipariþi aranacak firma numarasýný giriniz." << endl;
				cin >> aranan_sipariþ;

				cout << "Sipariþi aranacak ürünün kodunu giriniz" << endl;
				cin >> arananÜrün;

				int degerr = 0;
				ifstream DosyaOku2("siparis.txt");
				while (DosyaOku2 >> FirmaNo >> ürünKodu >> siparisTarihi >> siparisTutari  >> SiparisAlan)
				{

					if (aranan_sipariþ == FirmaNo&&ürünKodu==arananÜrün)
					{
						degerr = 1;
						cout << "aranan sipariþ: " << endl;
						cout << "Firma Numarasý : " << FirmaNo << endl;
						cout << "Ürün Kodu : " << ürünKodu << endl;
						cout << "Sipariþ Tarihi : " << siparisTarihi << endl;
						cout << "Sipariþ Tutarý : " << siparisTutari << endl;
					
						cout << "Sipariþ Alan : " << SiparisAlan << endl;


					}

				}

				DosyaOku2.close();

				if(degerr==0)
				{
				cout << "aranan sipariþ bulunamadý" << endl;
				}

			
			}



			if (cevap5 == 3) // cevap5 3 ise sipariþ düzeltme iþlemi
			{
				string düzeltilecekString2;
				string düzeltilecekString1;

				cout << " Düzeltilecek sipariþin Firma Numarasý  : "; cin >> düzeltilecekString2;
				cout << " Düzeltilecek sipariþin Ürün Kodu  : "; cin >> düzeltilecekString1;
				
				ifstream DosyaOku2("siparis.txt");
				ofstream DosyaYaz2("siparis.tmp");
				while (DosyaOku2 >> FirmaNo >> ürünKodu >> siparisTarihi >> siparisTutari >> SiparisAlan)
				{

					if (düzeltilecekString2 == FirmaNo&&düzeltilecekString1==ürünKodu)
					{
						cout << " Dosyadaki kayýt \n";
						cout << "\n firma numarasi : " << FirmaNo;
						cout << "\n ürün kodu : " << ürünKodu;
						cout << "\n siparis tarihi : " <<  siparisTarihi;
						cout << "\n siparis tutarý : " << siparisTutari;
						cout << "\n siparisi alan : " <<  SiparisAlan;
	
						cout << "\n Kayýt için yeni deðerler giriþi \n";
						cout << "\n siparis tarihi : "; cin >> siparisTarihi;
						cout << "Sipariþ Tutarý : \n" << siparisTutari;
						cout << "siparisi alan : \n"; cin >> SiparisAlan;
						
						DosyaYaz2 << FirmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << siparisTutari  << ' '  << SiparisAlan << ' ' << "\n ";
					}
					else
					{
						DosyaYaz2 << FirmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << siparisTutari << ' '  << SiparisAlan << ' ' << "\n ";
					}
				}
				DosyaYaz2.close();
				DosyaOku2.close();
				remove("siparis.txt");
				rename("siparis.tmp", "siparis.txt");
			
				
			}



			if (cevap5 == 4) // cevap5 4 ise sipariþ silme iþlemi
			{
				string siparisSilmeÜrün;
				string siparisSilmeNo;
				cout << "\nSipariþi silinecek firmanýn firma numarasýný giriniz : "; cin >> siparisSilmeNo;
				cout << "\nSipariþi silinecek ürünün ürün kodunu giriniz"; cin >> siparisSilmeÜrün;
				
									
				ifstream DosyaOku2("siparis.txt", ios::in);
				ofstream DosyaYaz2("siparis.tmp");

				while (DosyaOku2 >> FirmaNo >> ürünKodu >> siparisTarihi >> siparisTutari  >> SiparisAlan)
				{

					if (siparisSilmeNo == FirmaNo&&siparisSilmeÜrün==ürünKodu)
					{
						cout << "Silindi";
					}
					else
					{
						//Silinmeyecek kayýtlarý yedek dosyaya kaydet

						DosyaYaz2 << FirmaNo << ' ' << ürünKodu<< ' ' << siparisTarihi << ' ' << siparisTutari << ' '  << SiparisAlan << ' ' << endl;
					}
				}
				//dosyalarý kapat
				DosyaYaz2.close();
				DosyaOku2.close();

				//Asýl veri dosyasýný diskten sil
				remove("siparis.txt");
				//yedek dosyanýn ismini asýl dosya ismi olarak deðiþtir.
				rename("siparis.tmp", "siparis.txt");

			}


			if (cevap5 == 5) // cevap5 5 ise sipariþ raporu iþlemi
			{
				ifstream DosyaOku2("siparis.txt");
				ofstream DosyaYaz3("siparislistesi.txt");
				while (DosyaOku2 >> FirmaNo >> ürünKodu >> siparisTarihi >> siparisTutari >> SiparisAlan)
				{

					cout << "Firma Numarasý : " << FirmaNo << endl;
					cout << "Ürün kodu : " << ürünKodu << endl;
					cout << "Sipariþ tarihi : " << siparisTarihi << endl;
					cout << "Sipariþ tutarý : " << siparisTutari << endl;
					cout << "Sipariþi alan : " << SiparisAlan << endl;
					cout << "**************************************" << endl;

					DosyaYaz3 << FirmaNo << ' ' << ürünKodu << ' ' << siparisTarihi << ' ' << siparisTutari << ' '  << SiparisAlan << ' ' << endl;

				}
				DosyaOku2.close();
				DosyaYaz3.close();	

			}

		
	}
} while (1);


}

