#include <stdio.h>
#include <stdlib.h>
#include<locale.h> // Türkçe karakterde sorun olmamasý için locale.h kütüphanesini çaðýrdým.

/*
	Ogrenci No: 20817022
	Ad Soyad: 	Okan Fidan
    ------------------------------------------------------------------
	Program ilk çalýþtýðýnda ekrana hoþ geldiniz bilgisi yazdýrýyorum.
	Main fonksiyonunda gereksiz kalabalýk ve karýþýklýk olmasýn diye.
*/
void hosgeldinizBolumu(){
	printf("Müþteri Ekleme Programý\n");
	printf("Öðrenci No: 20817022\nAd Soyad: Okan Fidan\n");
	printf("--------------------------------------------\n");
	printf("Müþteri Eklemek Ýçin \"<ekle>\" komutunu kullanmalýsýnýz.\n");
	printf("Programý Sonlandýrmak Ýçin \"<durdur>\" komutunu kullanmalýsýnýz.\n");
	printf("--------------------------------------------\n");
}

void musteriEkle() {
	char ad[50], soyad[50], memleket[50], meslek[50]; // Karakter içeren deðiþkenleri tanýmladým.
	int dogum_yili; // Integer içeren deðiþkenleri tanýmladým.
	long long int tcKimlikNo; // TC kimlik no 11 haneden oluþacaðý için long long int veri türünü kullandým.
	double dolarKuru = 7.8155; // Dolar kurunu manuel girdim sonuç ekranýnda aylýk abonelik ücretini dolara çevireceðim.
	float aylikAbonelikUcreti; // Aylýk abonelik ücretini scanf ile buraya yazdýracaðým.
	
	printf("Müþteri Ad:"); // Müþteri adýný yazmasýný iste.
	scanf("%s", ad); // Müþteri adýný deðiþkene tanýmla.
	
	printf("Müþteri Soyad:"); // Müþteri soyadýný yazmasýný iste.
	scanf("%s", soyad); // Müþteri soyadýný deðiþkene tanýmla.
	
	printf("Müþteri T.C No:"); // Müþteri TCK mosunu yazmasýný iste.
	scanf("%lld", &tcKimlikNo); // Müþteri TCK mosunu deðiþkene tanýmla.
	
	printf("Müþteri Memleket:"); // Müþteri memleketini yazmasýný iste.
	scanf("%s", memleket); // Müþteri memleketini deðiþkene tanýmla.
	
	printf("Müþteri Mesleði:"); // Müþteri mesleðini yazmasýný iste.
	scanf("%s", meslek); // Müþteri mesleðini deðiþkene tanýmla.
	
	printf("Müþteri Doðum Yýlý:"); // Müþteri doðum yýlýný yazmasýný iste.
	scanf("%d", &dogum_yili); //Müþteri doðum yýlýný deðiþkene tanýmla.
	
	printf("Aylýk Ödemesi Gereken Abonelik Ücreti (TRY):"); // Müþterinin aylýk ödemesi gereken üyelik ücretini türk lirasý cinsinden yazmasýný iste.
	scanf("%f", &aylikAbonelikUcreti); // Müþterinin aylýk ödemesi gereken üyelik ücretini float deðiþkene tanýmla.
	
	int yas = (2020-dogum_yili); // Günümüz yýlýndan inputa girilen ve deðiþkene tanýmlanan yaþý çýkarýp yaþý buluyorum.
	float dolaraCevir = aylikAbonelikUcreti / dolarKuru; // Abonelik ücretini dolara çeviriyorum.
	
	/*
		Deðiþkene tanýmlanan verileri ekrana yazdýrýyorum.
	*/
	
	printf("--------------------------------------------\n");
	printf("Müþteri baþarýlý þekilde oluþturuldu.\n");
	printf("--------------------------------------------\n");
	printf("Müþteri Adý: %s %s\n", ad, soyad);
	printf("Müþteri T.C Kimlik No: %lld\n", tcKimlikNo);
	printf("Müþteri Memleketi: %s\n", memleket);
	printf("Müþteri Mesleði: %s\n", meslek);
	printf("Müþteri Doðum Yýlý: %d\n", dogum_yili);
	printf("Müþteri Yaþý: %d\n", yas);
	printf("--------------------------------------------\n");
	printf("Aylýk Ödemesi Gereken Abonelik Ücreti (TRY Cinsinden) : %f\n", aylikAbonelikUcreti);
	printf("Aylýk Ödemesi Gereken Abonelik Ücreti (USD Cinsinden) : %f\n", dolaraCevir);
	printf("--------------------------------------------\n");
	
	/*
		Tekrar ekleme yapýlmasý yada programýn durdurulabilmesi için komut fonksiyonumu tekrar çaðýrýyorum.
	*/
	komutBekle();
}

void komutBekle(){
	char komut[30]; // Girilen komutu bu deðiþkene tanýmlayacaðým.
	printf("Lütfen bir komut girin:");
	scanf("%s", komut); // Girilen komutu deðiþkene tanýmlýyorum.
	if (strcmp(komut, "ekle") == 0) { // Girilen komut "ekle" deðerine eþit mi diye kontrol ediyorum.
		musteriEkle(); // Eðer komut "ekle" deðerine eþit ise müþteri ekleme fonksiyonumu çaðýrýyorum.
	} else if (strcmp(komut, "durdur") == 0) { // Girilen komut "durdur" deðerine eþit mi diye kontrol ediyorum.
		printf("\nProgramdan baþarýlý bir þekilde çýkýþ yaptýnýz.");
		exit(0); // Programý sonlandýrýyorum.
	}else {
		printf("Hatalý komut girdiniz.\n");
		
		/*
			Eðer girilen komutlar tanýmlý komut listesinde bulunmuyorsa tekrar komut girilmesini istiyorum.
			Bu iþlemler switch - case yapýsý ile de yapýlabilir. Onlarý C dilinde daha öðrenmediðim için if else þeklinde yaptým.
		*/
		komutBekle();
	}
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Turkish"); // Türkçe karakter sorunu olmasýn diye locale.h kütüphanesini kullanarak setlocale fonksiyonunu kullandým.
	hosgeldinizBolumu(); // Program ilk çalýþtýðýnda ekrana yazdýrdýðým Öðrenci ve Diðer Bilgiler Kýsmý
	komutBekle(); // Kullanýcýdan iþlem yapmak için komut bekleniyor...
}




