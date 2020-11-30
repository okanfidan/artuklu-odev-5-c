#include <stdio.h>
#include <stdlib.h>
#include<locale.h> // T�rk�e karakterde sorun olmamas� i�in locale.h k�t�phanesini �a��rd�m.

/*
	Ogrenci No: 20817022
	Ad Soyad: 	Okan Fidan
    ------------------------------------------------------------------
	Program ilk �al��t���nda ekrana ho� geldiniz bilgisi yazd�r�yorum.
	Main fonksiyonunda gereksiz kalabal�k ve kar���kl�k olmas�n diye.
*/
void hosgeldinizBolumu(){
	printf("M��teri Ekleme Program�\n");
	printf("��renci No: 20817022\nAd Soyad: Okan Fidan\n");
	printf("--------------------------------------------\n");
	printf("M��teri Eklemek ��in \"<ekle>\" komutunu kullanmal�s�n�z.\n");
	printf("Program� Sonland�rmak ��in \"<durdur>\" komutunu kullanmal�s�n�z.\n");
	printf("--------------------------------------------\n");
}

void musteriEkle() {
	char ad[50], soyad[50], memleket[50], meslek[50]; // Karakter i�eren de�i�kenleri tan�mlad�m.
	int dogum_yili; // Integer i�eren de�i�kenleri tan�mlad�m.
	long long int tcKimlikNo; // TC kimlik no 11 haneden olu�aca�� i�in long long int veri t�r�n� kulland�m.
	double dolarKuru = 7.8155; // Dolar kurunu manuel girdim sonu� ekran�nda ayl�k abonelik �cretini dolara �evirece�im.
	float aylikAbonelikUcreti; // Ayl�k abonelik �cretini scanf ile buraya yazd�raca��m.
	
	printf("M��teri Ad:"); // M��teri ad�n� yazmas�n� iste.
	scanf("%s", ad); // M��teri ad�n� de�i�kene tan�mla.
	
	printf("M��teri Soyad:"); // M��teri soyad�n� yazmas�n� iste.
	scanf("%s", soyad); // M��teri soyad�n� de�i�kene tan�mla.
	
	printf("M��teri T.C No:"); // M��teri TCK mosunu yazmas�n� iste.
	scanf("%lld", &tcKimlikNo); // M��teri TCK mosunu de�i�kene tan�mla.
	
	printf("M��teri Memleket:"); // M��teri memleketini yazmas�n� iste.
	scanf("%s", memleket); // M��teri memleketini de�i�kene tan�mla.
	
	printf("M��teri Mesle�i:"); // M��teri mesle�ini yazmas�n� iste.
	scanf("%s", meslek); // M��teri mesle�ini de�i�kene tan�mla.
	
	printf("M��teri Do�um Y�l�:"); // M��teri do�um y�l�n� yazmas�n� iste.
	scanf("%d", &dogum_yili); //M��teri do�um y�l�n� de�i�kene tan�mla.
	
	printf("Ayl�k �demesi Gereken Abonelik �creti (TRY):"); // M��terinin ayl�k �demesi gereken �yelik �cretini t�rk liras� cinsinden yazmas�n� iste.
	scanf("%f", &aylikAbonelikUcreti); // M��terinin ayl�k �demesi gereken �yelik �cretini float de�i�kene tan�mla.
	
	int yas = (2020-dogum_yili); // G�n�m�z y�l�ndan inputa girilen ve de�i�kene tan�mlanan ya�� ��kar�p ya�� buluyorum.
	float dolaraCevir = aylikAbonelikUcreti / dolarKuru; // Abonelik �cretini dolara �eviriyorum.
	
	/*
		De�i�kene tan�mlanan verileri ekrana yazd�r�yorum.
	*/
	
	printf("--------------------------------------------\n");
	printf("M��teri ba�ar�l� �ekilde olu�turuldu.\n");
	printf("--------------------------------------------\n");
	printf("M��teri Ad�: %s %s\n", ad, soyad);
	printf("M��teri T.C Kimlik No: %lld\n", tcKimlikNo);
	printf("M��teri Memleketi: %s\n", memleket);
	printf("M��teri Mesle�i: %s\n", meslek);
	printf("M��teri Do�um Y�l�: %d\n", dogum_yili);
	printf("M��teri Ya��: %d\n", yas);
	printf("--------------------------------------------\n");
	printf("Ayl�k �demesi Gereken Abonelik �creti (TRY Cinsinden) : %f\n", aylikAbonelikUcreti);
	printf("Ayl�k �demesi Gereken Abonelik �creti (USD Cinsinden) : %f\n", dolaraCevir);
	printf("--------------------------------------------\n");
	
	/*
		Tekrar ekleme yap�lmas� yada program�n durdurulabilmesi i�in komut fonksiyonumu tekrar �a��r�yorum.
	*/
	komutBekle();
}

void komutBekle(){
	char komut[30]; // Girilen komutu bu de�i�kene tan�mlayaca��m.
	printf("L�tfen bir komut girin:");
	scanf("%s", komut); // Girilen komutu de�i�kene tan�ml�yorum.
	if (strcmp(komut, "ekle") == 0) { // Girilen komut "ekle" de�erine e�it mi diye kontrol ediyorum.
		musteriEkle(); // E�er komut "ekle" de�erine e�it ise m��teri ekleme fonksiyonumu �a��r�yorum.
	} else if (strcmp(komut, "durdur") == 0) { // Girilen komut "durdur" de�erine e�it mi diye kontrol ediyorum.
		printf("\nProgramdan ba�ar�l� bir �ekilde ��k�� yapt�n�z.");
		exit(0); // Program� sonland�r�yorum.
	}else {
		printf("Hatal� komut girdiniz.\n");
		
		/*
			E�er girilen komutlar tan�ml� komut listesinde bulunmuyorsa tekrar komut girilmesini istiyorum.
			Bu i�lemler switch - case yap�s� ile de yap�labilir. Onlar� C dilinde daha ��renmedi�im i�in if else �eklinde yapt�m.
		*/
		komutBekle();
	}
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Turkish"); // T�rk�e karakter sorunu olmas�n diye locale.h k�t�phanesini kullanarak setlocale fonksiyonunu kulland�m.
	hosgeldinizBolumu(); // Program ilk �al��t���nda ekrana yazd�rd���m ��renci ve Di�er Bilgiler K�sm�
	komutBekle(); // Kullan�c�dan i�lem yapmak i�in komut bekleniyor...
}




