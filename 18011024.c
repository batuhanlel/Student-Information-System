#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct dersler{
	char kod[50];
	char ad[50];
	char kredi[50];
	char kontenjan[50];
	char ogretmen_id[50];
};
typedef struct dersler DERSLER;



struct ogrenciler{
	char id[50];
	char ad[50];
	char soyad[50];
	char ders_sayisi[50];
	char toplam_kredi_sayisi[50];
};
typedef struct ogrenciler OGRENCILER;



struct ogretmenler {
	char id[50];
	char ad[50];
	char soyad[50];
	char unvan[50];
};
typedef struct ogretmenler OGRETMENLER;

struct ders_kayit_txt {
	char benzersiz_id[5];
	char ogrenci_numara[50];
	char ders_kodu[50];
	char durum[5];
	char tarih[50];
};
typedef struct ders_kayit_txt DERS_KAYIT;

void Ders_Ekleme();
void Ders_Silme();
void Ders_Guncelleme();
void Dersler_Print();
int  Ders_Kodu_Kontrol(char*);
int  Ders_Hoca_id_kontrol(char*);

void Derse_Kayit(int, int);
void Ders_Kayit_Sil();
void Ogrenci_Ekleme();
void Ogrenci_Guncelleme();
void Ogrenci_Silme();
void Ogrenciler_Print();
int  Ogrenci_ID_Kontrol(char*);

void Ogretmen_Ekleme();
void Ogretmen_Silme();
void Ogretmen_Guncelleme();
void Ogretmenler_Print();
int  Ogretmen_ID_Kontrol(char*);

void Ogretmenin_Verdigi_Dersler_Print();
void Derse_Kayitli_Tum_Ogrenciler_Print();
void Ogrencinin_Aldigi_Tum_Dersler_Print();
void Ogretmen_Verdigi_Dersler_SinifListeleri_TXT();


void Ana_menu(int,int);
void Ders_menu();
void Ogrenci_menu(int,int);
void Ogretmen_menu();
void Listeleme_menu();



int main(){

	system("title US�S V.12.09010.1.2");
	setlocale(LC_ALL, "Turkish");

	int i;	
	int kredi_limit, ders_sayi_limit;
		
	printf("\t\t\tB�LG� ��LEM S�STEM�NE HO�GELD�N�Z!!\n\n");
	printf("Sistemi �al��t�rmadan �nce Sistem Taraf�ndan Kullan�lacak Olan \n'Dersler' '��renciler' '��retim_�yeleri' ve '��renciDersKay�t'\n�simli 'txt' Uzant�l� Dosyalar�n EXE Program�yla Ayn� Klas�rde\nOldu�undan Emin Olunuz");
	printf("\n\nDosya Konumlar�ndan Eminseniz Devam Etmek i�in 1'i Tu�lay�n�z\nProgram� Sonland�rmak ��in 0'� Tu�lay�n�z\n"); scanf("%d",&i);
	if(!i){
		system("cls");		
		return 0;		
	}
	system("cls");
	printf("\t\t\tB�LG� ��LEM S�STEM�NE HO�GELD�N�Z!!\n\n");	
	printf("\nSistem �lk Kez �al��t��� ��in Kurulumun Tamamlanmas� Gerekmekte !!\n\nKurulum ��in Gerekenler :\n");
	printf("-->Bir ��rencinin Alabilece�i MAKS�MUM KRED� Say�s�\n-->Bir ��rencinin Alabilece�i MAKS�MUM DERS  Say�s�\n");
	
	
	printf("\nMAKS�MUM KRED� SAYISINI G�R�N�Z : ");
	scanf("%d", &kredi_limit);
	getchar();
	
	printf("MAKS�MUM DERS  SAYISINI G�R�N�Z : ");
	scanf("%d", &ders_sayi_limit);
	getchar();
	system("cls");
	
	printf("\t\t\tB�LG� ��LEM S�STEM�NE HO�GELD�N�Z!!\n\n");
	printf("Girmi� Oldu�unuz Verilere G�re Sistemin Kurulumu Tamamlanm��t�r!!\nMen�ye Gitmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
	system("cls");
	
	Ana_menu(kredi_limit,ders_sayi_limit);
	
	
	
	return(0);
}



void Ana_menu(int kredi_limit, int ders_limit){
	
	int i, j;
	
	j=1;
	while(j){
		printf("\n\t\t\t\tANA MEN�");
		printf("\n1)DERS ��LEMLER�\n -->Ders Ekleme\n -->Ders Silme\n -->Ders G�ncelleme\n -->Dersleri G�r�nt�leme");
		printf("\n2)��RENC� ��LEMLER�\n -->Ders Kay�t\n -->Ders B�rakma\n -->��renci Ekleme\n -->��renci Silme\n -->��renci G�ncelleme\n -->T�m ��rencileri G�r�nt�leme");
		printf("\n3)��RET�M �YES� ��LEMLER�\n -->��retim �yesi Ekleme\n -->��retim �yesi Silme\n -->��retim �yesi G�ncelleme\n -->T�m ��retim �yelerini G�r�nt�leme");
		printf("\n4)L�STELEME ��LEMLER�\n -->��retim �yesi Verdi�i Dersleri Listeleme\n -->Derse Kay�tl� ��rencileri Listeleme\n -->��rencinin Ald��� Dersleri Listeleme\n -->��retim �yesinin Verdi�i Derslerin S�n�f Listelerini Olu�turma");
		printf("\nDEVAM ETMEK �STED���N�Z �ST BA�LI�IN NUMARASINI G�R�N�Z\nPROGRAMI SONLANDIRMAK ���N 0 G�R�N�Z\nTercihiniz : "); scanf("%d",&i); getchar();
		if(i==1){
			system("cls");
			Ders_menu();
		}		
		else if(i==2){
			system("cls");
			Ogrenci_menu(kredi_limit,ders_limit);
		}
		else if(i==3){
			system("cls");
			Ogretmen_menu();
		}
		else if(i==4){
			system("cls");
			Listeleme_menu();
		}else if(i==0){
			j = 0;
		}
	}
	return;	
}

void Ders_menu(){
	int i, j=1;
	while(j){
		system("cls");
		printf("\n\t\tDERS ��LEMLER�");
		printf("\n1)Ders Ekleme\n2)Ders G�ncelleme\n3)Dersleri G�r�nt�leme\n4)Ders Silme");
		printf("\n\nDEVAM ETMEK ���N �STED���N�Z ��LEM�N NUMARASINI G�R�N�Z\n�ST MEN�YE D�NMEK ���N 0 G�R�N�Z\nTercihiniz : "); scanf("%d",&i); getchar();
		if(i==1){
			system("cls");
			Ders_Ekleme();	
		}		
		else if(i==2){
			system("cls");
			Ders_Guncelleme();
		}
		else if(i==3){
			system("cls");
			Dersler_Print();
		}
		else if(i==4){
			system("cls");
			Ders_Silme();
		}
		else if(i==0){
			system("cls");
			j = 0;
		}		
	}	
}

void Ogrenci_menu(int kredi, int ders){
	int i, j=1;
	while(j){
		system("cls");
		printf("\n\t\t��RENC� ��LEMLER�");
		printf("\n1)Ders Kay�t\n2)Ders B�rakma\n3)��renci Ekleme\n4)��renci Silme\n5)��renci G�ncelleme\n6)T�m ��rencileri G�r�nt�leme");
		printf("\n\nDEVAM ETMEK ���N �STED���N�Z ��LEM�N NUMARASINI G�R�N�Z\n�ST MEN�YE D�NMEK ���N 0 G�R�N�Z\nTercihiniz : "); scanf("%d",&i); getchar();
		if(i==1){
			system("cls");
			Derse_Kayit(kredi,ders);	
		}		
		else if(i==2){
			system("cls");
			Ders_Kayit_Sil();
		}
		else if(i==3){
			system("cls");
			Ogrenci_Ekleme();
		}
		else if(i==4){
			system("cls");
			Ogrenci_Silme();
		}
		else if(i==5){
			system("cls");
			Ogrenci_Guncelleme();
		}
		else if(i==6){
			system("cls");
			Ogrenciler_Print();
		}
		else if(i==0){
			system("cls");
			j = 0;
		}		
	}
}

void Ogretmen_menu(){
	int i, j=1;
	while(j){
		system("cls");
		printf("\n\t\t��RET�M �YES� ��LEMLER�");
		printf("\n1)��retim �yesi Ekleme\n2)��retim �yesi Silme\n3)��retim �yesi G�ncelleme\n4)T�m ��retim �yelerini G�r�nt�leme");
		printf("\n\nDEVAM ETMEK ���N �STED���N�Z ��LEM�N NUMARASINI G�R�N�Z\n�ST MEN�YE D�NMEK ���N 0 G�R�N�Z\nTercihiniz : "); scanf("%d",&i); getchar();
		if(i==1){
			system("cls");
			Ogretmen_Ekleme();	
		}		
		else if(i==2){
			system("cls");
			Ogretmen_Silme();
		}
		else if(i==3){
			system("cls");
			Ogretmen_Guncelleme();
		}
		else if(i==4){
			system("cls");
			Ogretmenler_Print();
		}
		else if(i==0){
			system("cls");
			j = 0;
		}		
	}
}

void Listeleme_menu(){
	printf("\n4)\n -->	\n -->");
	int i, j=1;
	while(j){
		system("cls");
		printf("\n\t\tL�STELEME ��LEMLER�");
		printf("\n1)��retim �yesi Verdi�i Dersleri Listeleme\n2)Derse Kay�tl� ��rencileri Listeleme\n3)��rencinin Ald��� T�M Dersleri Listeleme\n4)��retim �yesinin Verdi�i Derslerin S�n�f Listelerini Olu�turma");
		printf("\n\nDEVAM ETMEK ���N �STED���N�Z ��LEM�N NUMARASINI G�R�N�Z\n�ST MEN�YE D�NMEK ���N 0 G�R�N�Z\nTercihiniz : "); scanf("%d",&i); getchar();
		if(i==1){
			system("cls");
			Ogretmenin_Verdigi_Dersler_Print();	
		}		
		else if(i==2){
			system("cls");
			Derse_Kayitli_Tum_Ogrenciler_Print();
		}
		else if(i==3){
			system("cls");
			Ogrencinin_Aldigi_Tum_Dersler_Print();
		}
		else if(i==4){
			system("cls");
			Ogretmen_Verdigi_Dersler_SinifListeleri_TXT();
		}
		else if(i==0){
			system("cls");
			j = 0;
		}		
	}
}



void Ders_Kayit_Sil(){
	
	char ogrenci_id[15];
	printf("Kayd�n� Silmek �stedi�iniz ��renci Numaras�n� Giriniz : ");
	scanf("%s", ogrenci_id);
	getchar();

	char ders_kod[15];
	printf("\nKayd�n� Silmek �stedi�iniz Ders Kodunu Giriniz : ");
	scanf("%s", ders_kod);
	getchar();
	
	FILE *fp_kayit, *fp_kayit_kopya, * fp_ogrenci_kopya, * fp_ogrenciler, *fp_dersler;

	int j = 0;
	char line[100]; char divider[2] = ",";
	char* jeton; char* parsed_derskayit[10];

	int k = 0;
	char line2[100];
	char* jeton2; char* parsed_ogrenciler[10];

	int p = 0;
	char line3[100];
	char* jeton3; char* parsed_dersler[10];
	
	fp_kayit = fopen("��renciDersKay�t.txt", "r");
	
	if(fp_kayit == NULL){
		
		perror("��renciDersKay�t dosyas� a��lamad�: ");
		return;
	}
	
	fp_kayit_kopya = fopen("replica.txt", "w");
						
	if(fp_kayit_kopya == NULL){
							
		perror("replica.txt a��lamad�: ");
		fclose(fp_kayit);
		return;
	}	
	
	int counter = 0;
	while(fgets(line, sizeof(line), fp_kayit)){
		
		j = 0;
		jeton = strtok(line,divider);
		while(jeton != NULL){
			
			parsed_derskayit[j] = jeton;
			jeton = strtok(NULL, divider);
			j++;
		}
		
		if(strcmp(parsed_derskayit[1], ogrenci_id) == 0 && strcmp(parsed_derskayit[2], ders_kod) == 0 && strcmp(parsed_derskayit[3], "1") == 0){		
		
			counter = 1;
		}
	}
	
	if(counter == 0){

		printf("\nGirdi�iniz ��renci Numaras� ve Ders Kodu �le E�le�en Bir Veri Bulunamad�!!!\n�st Men�ye Y�nlendiriliyorsunuz!!\nHerhangi Bir Tu�a Bas�n : ");
		fclose(fp_kayit);
		fclose(fp_kayit_kopya);	
		getch();
		return;
	}	
	
	int cikarilan_dersin_kredisi;
	
	rewind(fp_kayit);
		
	while(fgets(line, sizeof(line), fp_kayit)){
		
		j = 0;
		jeton = strtok(line,divider);
		while(jeton != NULL){
			
			parsed_derskayit[j] = jeton;
			jeton = strtok(NULL, divider);
			j++;
		}
		
		if(strcmp(parsed_derskayit[1], ogrenci_id) == 0 && strcmp(parsed_derskayit[2], ders_kod) == 0 && strcmp(parsed_derskayit[3], "1") == 0){		
		
			fprintf(fp_kayit_kopya,"%s,%s,%s,0,%s,\n", parsed_derskayit[0], parsed_derskayit[1], parsed_derskayit[2],  parsed_derskayit[4]);				
		
			fp_dersler = fopen("Dersler.txt","r");
			
			if(fp_dersler == NULL){
			
				perror("Dersler.txt dosyasi a��lamad� : ");
				fclose(fp_kayit_kopya);
				fclose(fp_kayit);
				return;
			}			
			
			while(fgets(line2, sizeof(line2), fp_dersler)){
				
				k = 0;
				jeton2 = strtok(line2, divider);
				while(jeton2 != NULL){
					
					parsed_dersler[k] = jeton2;
					jeton2 = strtok(NULL,divider);
					k++;
				}		
			
				if(strcmp(parsed_dersler[0], ders_kod) == 0){
										
					cikarilan_dersin_kredisi = atoi(parsed_dersler[2]);
				}
			}
		
			fp_ogrenciler = fopen("��renciler.txt","r");
			
			if(fp_ogrenciler == NULL){
			
				perror("��renciler.txt dosyasi a��lamad� : ");
				fclose(fp_kayit_kopya);
				fclose(fp_kayit);
				fclose(fp_dersler);
				return;
			}
			
			fp_ogrenci_kopya = fopen("replica2.txt", "w");
			
			if(fp_ogrenci_kopya == NULL){
				
				perror("replica2.txt dosyasi a��lamad�: ");
				fclose(fp_kayit_kopya);
				fclose(fp_kayit);
				fclose(fp_dersler);
				fclose(fp_ogrenciler);
				return;	
			}
			
			while(fgets(line3, sizeof(line3), fp_ogrenciler)){
				
				p = 0;
				jeton3 = strtok(line3, divider);
				while(jeton3 != NULL){
					
					parsed_ogrenciler[p] = jeton3;
					jeton3 = strtok(NULL,divider);
					p++;
				}
				
				if(strcmp(parsed_ogrenciler[0], ogrenci_id) == 0){
					
					int mevcut_kredi;
					int mevcut_ders_sayisi;
					
					mevcut_kredi = atoi(parsed_ogrenciler[4]);
					mevcut_ders_sayisi = atoi(parsed_ogrenciler[3]);
					
					mevcut_kredi -= cikarilan_dersin_kredisi;
					mevcut_ders_sayisi--; 
					
					sprintf(parsed_ogrenciler[4],"%d",mevcut_kredi);
					sprintf(parsed_ogrenciler[3],"%d",mevcut_ders_sayisi);
					
					fprintf(fp_ogrenci_kopya,"%s,%s,%s,%s,%s,\n", parsed_ogrenciler[0], parsed_ogrenciler[1], parsed_ogrenciler[2], parsed_ogrenciler[3], parsed_ogrenciler[4]);
					
					
				}
				else{
					
					fprintf(fp_ogrenci_kopya,"%s,%s,%s,%s,%s,\n", parsed_ogrenciler[0], parsed_ogrenciler[1], parsed_ogrenciler[2], parsed_ogrenciler[3], parsed_ogrenciler[4]);					
				}		
			}
				
				
			
		}
		else{
			
			fprintf(fp_kayit_kopya,"%s,%s,%s,%s,%s,\n", parsed_derskayit[0], parsed_derskayit[1], parsed_derskayit[2], parsed_derskayit[3], parsed_derskayit[4]);
		}
	}
	fclose(fp_kayit_kopya);
	fclose(fp_ogrenci_kopya);
	fclose(fp_kayit);
	fclose(fp_dersler);
	fclose(fp_ogrenciler);	
	
	int ret;
	ret =  remove("��renciDersKay�t.txt");
	
	if(ret != 0) {
    	perror("\nError: unable to delete the file");
	} 
	
	int ret2;
	ret2 = rename("replica.txt", "��renciDersKay�t.txt");
	
	if(ret2 != 0) {
    	perror("\nError: unable to rename the file");
	} 		
	
	ret =  remove("��renciler.txt");
	
	if(ret != 0) {
    	perror("\nError: unable to delete the file");
	} 
	
	ret2 = rename("replica2.txt", "��renciler.txt");
	
	if(ret2 != 0) {
    	perror("\nError: unable to rename the file");
	} 	
	printf("��rencinin Derse Kay�d� Ba�ar�yla Silindi\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
}

void Derse_Kayit(int kredi_limit, int ders_sayi_limit){
	
	time_t t = time(NULL);
    struct tm kayit_tarih;  
    kayit_tarih = *localtime(&t);  

	int j = 0;
	char line[256]; char divider[2] = ",";
	char* jeton; char* parsed_ogrenciler[10];

	int k = 0;
	char line2[256];
	char* jeton2; char* parsed_dersler[10];

	int p = 0;
	char line3[256];
	char* jeton3; char* parsed_derskayit[10];
	
	char ogrenci_numara[15]; char ders_kodu[15];
	printf("\nKay�t Olacak ��rencinin Numaras�n� Giriniz : ");
	scanf("%s", ogrenci_numara);
	getchar();
	
	FILE *fp_ogrenciler, *fp_dersler, *fp_ogrenciler_kopya, *fp_kayit;
	
	fp_ogrenciler = fopen("��renciler.txt","r");
	
	if(fp_ogrenciler == NULL){
		
		perror("��renciler dosyas� a��lamad�: ");
		return;
	}
	
	
	fp_ogrenciler_kopya = fopen("replica.txt", "w");
						
	if(fp_ogrenciler_kopya == NULL){
							
		perror("replica.txt a��lamad�: ");
		fclose(fp_ogrenciler);
		return;
	}	


	
	int counter = 0;
	while(fgets(line, sizeof(line), fp_ogrenciler)){
		
		j = 0;
		jeton = strtok(line,divider);
		while(jeton != NULL){
			
			parsed_ogrenciler[j] = jeton;
			jeton = strtok(NULL, divider);
			j++;
		}
		
		if(strcmp(parsed_ogrenciler[0], ogrenci_numara) == 0){		
		
			counter = 1;
		}
	}
	
	if(counter == 0){
		
		printf("\nGirdi�iniz ��renci Numaras� Bulunamam��t�r\n�st Men�ye Y�nlendiriliyorsunuz\nHerhangi Bir Tu�a Bas�n");
		fclose(fp_ogrenciler);
		fclose(fp_ogrenciler_kopya);
		getch();
		return;
	}
	
	printf("\nKay�t Olmak �stedi�iniz Dersin Kodunu Giriniz : ");
	scanf("%s", ders_kodu);
	getchar();
			
	fp_dersler = fopen("Dersler.txt", "r");
			
	if(fp_dersler == NULL){
				
		perror("Dersler.txt a��lamad�: ");
		fclose(fp_ogrenciler);
		fclose(fp_ogrenciler_kopya);		
		return;
	}
				
	int counter2 = 0;
	while(fgets(line2, sizeof(line2), fp_dersler)){
		
		j = 0;
		jeton2 = strtok(line2,divider);
		while(jeton2 != NULL){
			
			parsed_dersler[j] = jeton2;
			jeton2 = strtok(NULL, divider);
			j++;
		}
		
		if(strcmp(parsed_dersler[0], ders_kodu) == 0){		
		
			counter2 = 1;
		}
	}
	
	if(counter2 == 0){
		
		printf("\nGirdi�iniz Ders Kodu Bulunamam��t�r\n�st Men�ye Y�nlendiriliyorsunuz\nHerhangi Bir Tu�a Bas�n");
		fclose(fp_ogrenciler);
		fclose(fp_dersler);
		fclose(fp_ogrenciler_kopya);
		getch();
		return;
	}
	
	fp_kayit = fopen("��renciDersKay�t.txt", "r");
	
	if(fp_kayit == NULL){
		
		perror("\n��renciDersKay�t.txt a��lamad�: ");
		return;
	}
	
	int counter3 = 0;
	while(fgets(line3, sizeof(line3), fp_kayit)){
		
		j = 0;
		jeton3 = strtok(line3, divider);
		while(jeton3 != NULL){
			
			parsed_derskayit[j] = jeton3;
			jeton3 = strtok(NULL, divider);
			j++;
		}
		
		if(strcmp(parsed_derskayit[2], ders_kodu) == 0 && strcmp(parsed_derskayit[1], ogrenci_numara) == 0){		
			
			if(strcmp(parsed_derskayit[3], "1") == 0){
				counter3 = 1;
			}
				
		}
	}
	
	if(counter3 == 1){
		
		printf("\nNumaras� Girilen ��renci Bu Derse Kay�tl� Durumda!!!\n�st Men�ye Y�nlendiriliyorsunuz\nHerhangi Bir Tu�a Bas�n");
		fclose(fp_ogrenciler);
		fclose(fp_dersler);
		fclose(fp_ogrenciler_kopya);
		getch();
		return;
	}	
	
	rewind(fp_ogrenciler);
	rewind(fp_dersler);
	fclose(fp_kayit);
		
	int ogrenci_ders_sayisi, ogrenci_mevcut_kredi, ders_kredi;
	
	while(fgets(line, sizeof(line), fp_ogrenciler)){
		
		j = 0;
		jeton = strtok(line,divider);
		while(jeton != NULL){
			
			parsed_ogrenciler[j] = jeton;
			jeton = strtok(NULL, divider);
			j++;
		}
		
		if(strcmp(parsed_ogrenciler[0], ogrenci_numara) == 0){
			
			while(fgets(line2, sizeof(line2), fp_dersler)){
				
				k = 0;
				jeton2 = strtok(line2,divider);
				while(jeton2 != NULL){
					
					parsed_dersler[k] = jeton2;
					jeton2 = strtok(NULL, divider);
					k++;
				}
				
				if(strcmp(parsed_dersler[0], ders_kodu) == 0){
					
					ogrenci_ders_sayisi = atoi(parsed_ogrenciler[3]);
					ogrenci_mevcut_kredi = atoi(parsed_ogrenciler[4]);
					
					ders_kredi = atoi(parsed_dersler[2]);
					
					if(((ders_kredi + ogrenci_mevcut_kredi) <= kredi_limit) && (ogrenci_ders_sayisi + 1) <= ders_sayi_limit){
						
						ogrenci_ders_sayisi += 1;
						ogrenci_mevcut_kredi += ders_kredi;
									
						sprintf(parsed_ogrenciler[3], "%d", ogrenci_ders_sayisi);
						sprintf(parsed_ogrenciler[4], "%d", ogrenci_mevcut_kredi);
											
						fprintf(fp_ogrenciler_kopya, "%s,%s,%s,%s,%s,\n", parsed_ogrenciler[0], parsed_ogrenciler[1], parsed_ogrenciler[2], parsed_ogrenciler[3], parsed_ogrenciler[4]);
						
						fp_kayit = fopen("��renciDersKay�t.txt","a");
						
						if(fp_kayit == NULL){
							
							perror("��renciDersKay�t.txt dosyas� a��lamad� :");
							return;
						}
												
						int unique_id;
						unique_id = atoi(parsed_derskayit[0]);
						unique_id++;
											
						sprintf(parsed_derskayit[0],"%d", unique_id);
						sprintf(parsed_derskayit[4],"%02d:%02d:%02d %02d/%02d/%d", kayit_tarih.tm_hour, kayit_tarih.tm_min, kayit_tarih.tm_sec, kayit_tarih.tm_mday, kayit_tarih.tm_mon + 1, kayit_tarih.tm_year + 1900);
						//sprintf(parsed_derskayit[4],"%s",  asctime(kayit_tarih));
						
						
						parsed_derskayit[3] = "1";
						
						fprintf(fp_kayit, "%s,%s,%s,%s,%s,\n", parsed_derskayit[0], parsed_ogrenciler[0], parsed_dersler[0], parsed_derskayit[3], parsed_derskayit[4]);
						//fclose(fp_kayit);
					}
					else if(((ders_kredi + ogrenci_mevcut_kredi) > kredi_limit)){
						
						printf("Kredi limitini a�t�n�z.");
						fprintf(fp_ogrenciler_kopya, "%s,%s,%s,%s,%s,\n", parsed_ogrenciler[0], parsed_ogrenciler[1], parsed_ogrenciler[2], parsed_ogrenciler[3], parsed_ogrenciler[4]);
						return;
					}
					else{
						
						printf("Ders sayisi limitini a�t�n�z.");
						fprintf(fp_ogrenciler_kopya, "%s,%s,%s,%s,%s,\n", parsed_ogrenciler[0], parsed_ogrenciler[1], parsed_ogrenciler[2], parsed_ogrenciler[3], parsed_ogrenciler[4]);
						return;
					}
				}
				
			}		
		}
		else{
			
			fprintf(fp_ogrenciler_kopya, "%s,%s,%s,%s,%s,\n", parsed_ogrenciler[0], parsed_ogrenciler[1], parsed_ogrenciler[2], parsed_ogrenciler[3], parsed_ogrenciler[4]);	
		}		
	}
	fclose(fp_ogrenciler);
	fclose(fp_dersler);
	fclose(fp_ogrenciler_kopya);
	fclose(fp_kayit);
	
	int kontrol;
	kontrol =  remove("��renciler.txt");
	
	if(kontrol) {
    	perror("\nError: unable to delete the file");
	} 
	
	
	kontrol = rename("replica.txt", "��renciler.txt");
	
	if(kontrol) {
    	perror("\nError: unable to rename the file");
	} 		
	printf("\n��renci Derse Ba�ar�l� Bir �ekilde Kay�t Oldu!!!\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
}




void Ogretmen_Verdigi_Dersler_SinifListeleri_TXT(){
	
	

	
	DERS_KAYIT *ders_kayit;
	ders_kayit = (DERS_KAYIT*) malloc(sizeof(DERS_KAYIT));
	if(ders_kayit == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	DERSLER *ders;	
	ders = (DERSLER*) malloc (sizeof(DERSLER));
	if(ders == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	OGRENCILER *ogrenci;
	ogrenci = (OGRENCILER*) malloc (sizeof(OGRENCILER));
	
	if(ogrenci == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	OGRETMENLER *ogretmen;
	ogretmen = (OGRETMENLER*) malloc (sizeof(OGRETMENLER));                                                                           
	if(ogretmen == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	char *ogretmen_id, *ders_adi;
	ogretmen_id = (char*) malloc(sizeof(char)*20);
	ders_adi    = (char*) malloc(sizeof(char)*20);
		
	printf("��retim G�revlisi ID'sini Giriniz : ");
	scanf("%s", ogretmen_id);
	
	FILE *fp_dersler, *fp_sinif_listesi, * fp_derskayit, * fp_ogrenciler;
	
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	
	char *line2;
	line2 = (char*) malloc(sizeof(char)*100);
	
	char *line3;
	line3 = (char*) malloc(sizeof(char)*100);


	fp_dersler = fopen("Dersler.txt", "r");
	
	if(fp_dersler == NULL){
		
		perror("dersler dosyas� a��lamad�: ");
		return;
	}
	


	while(fgets(line, 100, fp_dersler)){
		
		sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", ders->kod, ders->ad, ders->kredi, ders->kontenjan, ders->ogretmen_id);
				
		if(strcmp(ders->ogretmen_id, ogretmen_id) == 0){
			

			sprintf(ders_adi,"%s_SINIFLISTESI.txt", ders->kod);
			
			fp_sinif_listesi = fopen(ders_adi, "w");
			
			
			fp_derskayit = fopen("��renciDersKay�t.txt", "r");
			
			if(fp_derskayit == NULL){
				
				perror("��renciDersKay�t a��lamad� : ");
				return;
			}
			
			while(fgets(line2, 100, fp_derskayit)){
		
				sscanf(line2,"%[^,],%[^,],%[^,],%[^,],%[^,]", ders_kayit->benzersiz_id, ders_kayit->ogrenci_numara, ders_kayit->ders_kodu, ders_kayit->durum, ders_kayit->tarih);
				
				if(strcmp(ders_kayit->ders_kodu, ders->kod) == 0 && strcmp(ders_kayit->durum, "1") == 0){
					
					fp_ogrenciler = fopen("��renciler.txt", "r");
					
					if(fp_ogrenciler == NULL){
						
						perror("Unable to open file: ");
						return;
					}
					
					while(fgets(line3, 100, fp_ogrenciler)){
									
						sscanf(line3,"%[^,],%[^,],%[^,],%[^,],%[^,]", ogrenci->id, ogrenci->ad, ogrenci->soyad, ogrenci->ders_sayisi, ogrenci->toplam_kredi_sayisi);
						
						if(strcmp(ders_kayit->ogrenci_numara, ogrenci->id) == 0){
			
							fprintf(fp_sinif_listesi,"%s %s %s \n", ogrenci->id, ogrenci->ad, ogrenci->soyad);
						}
					}
					fclose(fp_ogrenciler);
				}				
			}
			fclose(fp_derskayit);
			fclose(fp_sinif_listesi);					
		}		
	}
	free(ders_kayit);
	free(ders);
	free(ogrenci);
	free(ogretmen);
	free(line);
	free(line2);
	free(line3);
	free(ders_adi);
	free(ogretmen_id);
	
	printf("DERSKODU_SINIFL�STES� Dosyalar� EXE Program�n�n Bulundu�u Dosya Konumunda Olu�tu.\n");
	printf("Herhangi Bir ��kt� Almad�ysan�z ��retim �yesinin ID'sini Kontrol Edip Tekrar Deneyiniz veya Bu ��retim �yesi Herhangi Bir Ders Vermemekte!!\n");
	printf("�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n�z : ");
	getch();
}

void Ogrencinin_Aldigi_Tum_Dersler_Print(){
	
	char *ogrenci_numara;
	ogrenci_numara = (char*) malloc(sizeof(char)*10);
	
	DERS_KAYIT *ders_kayit;
	ders_kayit = (DERS_KAYIT*) malloc(sizeof(DERS_KAYIT));
	if(ders_kayit == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	DERSLER *ders;	
	ders = (DERSLER*) malloc (sizeof(DERSLER));
	if(ders == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	
	char *line2;
	line2 = (char*) malloc(sizeof(char)*100);
	

	printf("��rencinin Numaras�n� Giriniz : ");
	scanf("%s", ogrenci_numara);
	getchar();
	
	FILE *fp_ders_kayit, *fp_dersler;
	
	fp_ders_kayit = fopen("��renciDersKay�t.txt", "r");
	
	if(fp_ders_kayit == NULL){
		
		perror("��renciDersKay�t dosyas� a��lamad� : ");
		return;
	}
	
	
	
	while(fgets(line, 100, fp_ders_kayit)){
		
	
		sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,]", ders_kayit->benzersiz_id, ders_kayit->ogrenci_numara, ders_kayit->ders_kodu, ders_kayit->durum, ders_kayit->tarih);
				
		if(strcmp(ders_kayit->ogrenci_numara, ogrenci_numara) == 0 && strcmp(ders_kayit->durum, "1") == 0){
			
			fp_dersler = fopen("Dersler.txt", "r");
			
			if(fp_dersler == NULL){
				
				perror("Unable to open file: ");
				return;
			}
			
			while(fgets(line2, 100, fp_dersler)){
								
				sscanf(line2, "%[^,],%[^,],%[^,],%[^,],%[^,]", ders->kod, ders->ad, ders->kredi, ders->kontenjan, ders->ogretmen_id);
				
				if(strcmp(ders_kayit->ders_kodu, ders->kod) == 0){
					
					printf("%s %s \n", ders->kod, ders->ad);
				}
			}
			fclose(fp_dersler);
		}				
	}
	fclose(fp_ders_kayit);
	free(ders);
	free(ders_kayit);
	free(line);
	free(line2);
	free(ogrenci_numara);
	printf("Herhangi Bir ��kt� Almad�ysan�z ��renci Numaras�n� Kontrol Edip Tekrar Giriniz veya Bu ��renci Herhangi Bir Ders Almamakta\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");  getch();		
	
}

void Derse_Kayitli_Tum_Ogrenciler_Print(){
	
	char *ders_kodu;
	ders_kodu = (char*) malloc(sizeof(char)*10);
	
	DERS_KAYIT *ders_kayit;
	ders_kayit = (DERS_KAYIT*) malloc(sizeof(DERS_KAYIT));
	
	if(ders_kayit == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	OGRENCILER *ogrenci;
	ogrenci = (OGRENCILER*) malloc (sizeof(OGRENCILER));
	
	if(ogrenci == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	printf("Ders Kodunu Giriniz : ");
	scanf("%s", ders_kodu);
	getchar();
	
	FILE *fp_ders_kayit, *fp_ogrenciler;
	
	fp_ders_kayit = fopen("��renciDersKay�t.txt", "r");
	
	if(fp_ders_kayit == NULL){
		
		perror("��renciDersKay�t dosyas� a��lamad� : ");
		return;
	}
	

	char *line;
	line = (char*) malloc(sizeof(char)*100);
	
	char *line2;
	line2 = (char*) malloc(sizeof(char)*100);
		
	while(fgets(line, 100, fp_ders_kayit)){


		sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,]", ders_kayit->benzersiz_id, ders_kayit->ogrenci_numara, ders_kayit->ders_kodu, ders_kayit->durum, ders_kayit->tarih);
	
		if(strcmp(ders_kayit->ders_kodu, ders_kodu) == 0 && strcmp(ders_kayit->durum, "1") == 0 ){
			
			fp_ogrenciler = fopen("��renciler.txt", "r");
			
			if(fp_ogrenciler == NULL){
				
				perror("Unable to open file: ");
				return;
			}
			
			while(fgets(line2, 100, fp_ogrenciler)){
						
				
				sscanf(line2, "%[^,],%[^,],%[^,],%[^,],%[^,]", ogrenci->id, ogrenci->ad, ogrenci->soyad, ogrenci->ders_sayisi, ogrenci->toplam_kredi_sayisi);
				
				if(strcmp(ders_kayit->ogrenci_numara, ogrenci->id) == 0){
					
					printf("%s %s %s \n", ogrenci->id, ogrenci->ad, ogrenci->soyad);
				}
			}
			fclose(fp_ogrenciler);
		}				
	}
	fclose(fp_ders_kayit);
	free(ders_kayit);
	free(ogrenci);
	free(line);
	free(line2);
	free(ders_kodu);
	printf("Herhangi Bir ��kt� Almad�ysan�z Ders Kodunu Kontrol Edip Tekrar Giriniz veya Bu Dersi Herhangi Bir ��renci Almamakta\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");  getch();

}

void Ogretmenin_Verdigi_Dersler_Print(){
	
	DERSLER *ders;	
	ders = (DERSLER*) malloc (sizeof(DERSLER));
	if(ders == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	char *ogretmen_id;
	ogretmen_id = (char*) malloc(sizeof(char)*10);
	
	printf("��retim �yesinin ID'sini Giriniz : ");
	scanf("%s", ogretmen_id);
	getchar();
	
	FILE *fp_dersler;
	
	fp_dersler = fopen("Dersler.txt", "r");
	
	if(fp_dersler == NULL){
		
		perror("Dersler.txt a��lamad� : ");
		return;
	}
				
	int counter = 1;
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	while(fgets(line, 100, fp_dersler)){
		

		sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,]", ders->kod, ders->ad, ders->kredi, ders->kontenjan, ders->ogretmen_id);
		
		if(strcmp(ders->ogretmen_id, ogretmen_id) == 0){
			
			printf("%s %s\n", ders->kod, ders->ad);
			
		}	
	}
	fclose(fp_dersler);
	free(ders);
	free(line);	
	printf("Herhangi Bir ��kt� Almad�ysan�z ��retim �yesinin ID'sini Kontrol Edip Tekrar Giriniz veya Bu ��retim �yesi Ders Vermemekte\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");  getch();
}





void Ogrenci_Ekleme(){
	
	OGRENCILER *ogrenci;
	ogrenci = (OGRENCILER*) malloc (sizeof(OGRENCILER));
	
	if(ogrenci == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	FILE *fp_ogrenciler;
		
	fp_ogrenciler = fopen("��renciler.txt", "a");
	if(fp_ogrenciler == NULL){
		
		perror("Error opening file");
		return;
	}		
	
	
				
	int j, counter = 1, secim;
	printf("\nG�RECE��N�Z ��RENC� B�LG�LER�N�N FORMATI A�A�IDAK� G�B� OLMALIDIR!!\nYEN� B�R ��RENC� EKLED���N�Z ���N KRED� VE DERS SAYISINI  0  OLARAK G�R�N�Z!!!");
	printf("\nFormat : ��renci_numaras�,��renci_ad�,��renci_soyad�,��rencinin_ald���_ders_say�s�,��rencinin_ald���_toplam_kredi,\n");
	
	
	while(counter){
		printf("\n�rnek  : 11111111,isim1 isim2,soyad,1,4,\n");
		scanf("%[^,],%[^,],%[^,],%[^,],%[^,]", ogrenci->id, ogrenci->ad, ogrenci->soyad, ogrenci->ders_sayisi, ogrenci->toplam_kredi_sayisi);
		getchar();

		if(Ogrenci_ID_Kontrol(ogrenci->id) == 0){
			
			printf("Girmi� Oldu�unuz ��renci Numaras� Bulunmaktad�r.Tekrar Denemek ��in 1 �st Men�ye D�nmek ��in 0 Giriniz : "); 
			scanf("%d",&secim);
			getchar();
			if(secim==0){
				fclose(fp_ogrenciler);
				return;
			}
		}
		else{
			counter = 0;
		}		
	}


		
	fprintf(fp_ogrenciler,"%s,%s,%s,%s,%s,\n",ogrenci->id, ogrenci->ad, ogrenci->soyad, ogrenci->ders_sayisi, ogrenci->toplam_kredi_sayisi);
	fclose(fp_ogrenciler);
	free(ogrenci);
	printf("\nGirmi� Oldu�unuz ��renci Ba�ar�yla Eklenmi�tir!!");
	printf("\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();	
	
}

void Ogrenci_Guncelleme(){
	
	int i,j;
	
	OGRENCILER *ogrenci;
	ogrenci = (OGRENCILER*) malloc(sizeof(OGRENCILER));
	if(ogrenci == NULL){
		perror("Bellek alan� a��lamad� : ");
	}
	
	FILE *fp_ogrenciler;
	fp_ogrenciler = fopen("��renciler.txt", "r");
	if(fp_ogrenciler == NULL){
		
		perror("��renciler.txt a��lamad� : ");
		return;
	}	
	
	int index;
	char *line, *yeni_ad, *yeni_soyad;
	line = (char*) malloc(sizeof(char)*100);
	yeni_ad = (char*) malloc(sizeof(char)*100);
	yeni_soyad = (char*) malloc(sizeof(char)*100);
	
	printf("\n �NDEX   | NUMARA | �S�M | SOY�S�M | DERS SAYISI | TOPLAM KRED�\n");
	i = 1;
	while(fgets(line, 100, fp_ogrenciler)){
		
		printf("%d.",i);
		printf("%s", line);
		i++;
	}
	printf("\n\nG�ncellemek �stedi�iniz ��rencinin �NDEX�N� Giriniz: ");
	scanf("%d", &index);
	getchar();
	
	rewind(fp_ogrenciler);
	
	i=0;
	while(fgets(line, 100, fp_ogrenciler)){
		
		ogrenci = (OGRENCILER*) realloc(ogrenci, (i+1)*sizeof(OGRENCILER));
		
		sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", ogrenci[i].id, ogrenci[i].ad, ogrenci[i].soyad, ogrenci[i].ders_sayisi, ogrenci[i].toplam_kredi_sayisi);
		
		if((i+1)==index){
			printf("\n��rencinin YEN� Ad�n� ve Soyad�n� Giriniz\n�rnek Format :  isim1 isim2,soyisim,\n\t\t");
			scanf("%[^,],%[^,],", yeni_ad, yeni_soyad);
			getchar();
			strcpy(ogrenci[i].ad, yeni_ad);
			strcpy(ogrenci[i].soyad, yeni_soyad);
		}
		i++;
	}
	
	fclose(fp_ogrenciler);
	
	
	fp_ogrenciler = fopen("��renciler.txt", "w");
	if(fp_ogrenciler == NULL){
		
		perror("��renciler.txt a��lamad� : ");
		return;
	}
	
	for(j=0;j<i;j++){
		fprintf(fp_ogrenciler,"%s,%s,%s,%s,%s,\n", ogrenci[j].id, ogrenci[j].ad, ogrenci[j].soyad, ogrenci[j].ders_sayisi, ogrenci[j].toplam_kredi_sayisi);
	}
	
	fclose(fp_ogrenciler);
	free(ogrenci);
	free(line);
	free(yeni_ad);
	free(yeni_soyad);

	printf("\n------------------G�NCELLEND�----------------\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
}

void Ogrenci_Silme(){
	
	/*
	FILE *fp_ogrenciler, *fp_ogrenciler_kopya;

	fp_ogrenciler = fopen("��renciler.txt", "r");
	if(fp_ogrenciler == NULL){
		
		perror("Error opening file");
		return;
	}	
	
	
	int silinen_satir;
	Ogrenciler_Print();
	
	printf("Silmek istedi�iniz dersin indexini giriniz: ");
	scanf("%d", &silinen_satir);
	getchar();
	
	fp_ogrenciler_kopya = fopen("replica.txt", "w");

	char line[256]; int temp = 1;
	while(fgets(line, sizeof(line), fp_ogrenciler)){
		
		if(temp != silinen_satir){
			
			fputs(line, fp_ogrenciler_kopya);
		}
		temp++;
	}
	fclose(fp_ogrenciler);
	fclose(fp_ogrenciler_kopya);
	
	int kontrol;
	kontrol =  remove("��renciler.txt");
	
	if(kontrol != 0) {
    	perror("\nError: unable to delete the file");
	} 
	
	kontrol = rename("replica.txt", "��renciler.txt");
	
	if(kontrol != 0) {
    	perror("\nError: unable to delete the file");
	} 	*/
	printf("\n------------------�ALI�MA DEVAM ETMEKTE----------------\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
}

void Ogrenciler_Print(){
	
	FILE *fp_ogrenciler;
	fp_ogrenciler = fopen("��renciler.txt", "r");
	
	if(fp_ogrenciler == NULL){
		
		perror("��renciler.txt a��lamad� : ");
		return;
	}
		
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	int i = 1;
	printf("\n �NDEX |  | NUMARA | �S�M | SOY�S�M | DERS SAYISI | TOPLAM KRED�\n");
	while(fgets(line, 100, fp_ogrenciler)){
		
		printf("%d.",i);
		printf("%s", line);
		i++;
	}
	
	if(fclose(fp_ogrenciler) != 0){
        
		perror("��renciler.txt kapat�lamad� : ");
    }
	free(line);
	printf("\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : "); getch();
}

int Ogrenci_ID_Kontrol(char* id_test){
	
	
	FILE *fp_ogrenciler;
	
	fp_ogrenciler = fopen("��renciler.txt", "r");
	
	if(fp_ogrenciler == NULL){
		
		perror("��renciler.txt a��lamad� : ");
		return;
	}
			
	char divider[2] = ",";
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	while(fgets(line, 100, fp_ogrenciler)){
		
		strtok(line, divider);
		if(strcmp(line, id_test) == 0){
			free(line);
			fclose(fp_ogrenciler);
			return 0;
		}
	}
	free(line);
	fclose(fp_ogrenciler);
	return 1;	
}





void Ogretmen_Guncelleme(){
	
	
	int guncellenen_satir, i, j;
	
	OGRETMENLER *ogretmen;
	ogretmen = (OGRETMENLER*) malloc (sizeof(OGRETMENLER));                                                                           
	if(ogretmen == NULL){
		
		printf("out of memory."); exit(1);
	}

	FILE *fp_ogretmenler;
	fp_ogretmenler = fopen("��retim_�yeleri.txt", "r");
	if(fp_ogretmenler == NULL){
		
		perror("Error opening file");
		return;
	}	
	
	char *line, *yeni_ad, *yeni_soyad, *yeni_unvan;
	line = (char*) malloc(sizeof(char)*100);
	yeni_ad = (char*) malloc(sizeof(char)*100);
	yeni_soyad = (char*) malloc(sizeof(char)*100);
	yeni_unvan = (char*) malloc(sizeof(char)*100);
	i = 1;
	
	printf("\n �NDEX  |ID|   �S�M   |   SOY�S�M   |   UNVAN \n");
	while(fgets(line, 100, fp_ogretmenler)){
		
		printf("  %d.	 ",i);
		printf(" %s", line);
		i++;
	}
	
	rewind(fp_ogretmenler);
	
	printf("\n\nG�ncellemek �stedi�iniz ��retim �yesinin �NDEX�N� Giriniz : ");
	scanf("%d", &guncellenen_satir);
	getchar();
	
	i=0;
	while(fgets(line, 100, fp_ogretmenler)){
		
		ogretmen = (OGRETMENLER*) realloc(ogretmen, (i+1)*sizeof(OGRETMENLER));
		
		sscanf(line, "%[^,],%[^,],%[^,],%[^,]", ogretmen[i].id, ogretmen[i].ad, ogretmen[i].soyad, ogretmen[i].unvan);
		
		if((i+1) == guncellenen_satir){
			printf("\n��retim �yesinin YEN� Ad�n�, Soyad�n� ve Unvan�n� Giriniz\n�rnek Format :  isim1 isim2,soyisim,unvan,\n\t\t");
			scanf("%[^,],%[^,],%[^,],", yeni_ad, yeni_soyad, yeni_unvan);
			getchar();
			strcpy(ogretmen[i].ad, yeni_ad);
			strcpy(ogretmen[i].soyad, yeni_soyad);
			strcpy(ogretmen[i].unvan, yeni_unvan);
		}
		i++;
	}
	
	fclose(fp_ogretmenler);
	
	fp_ogretmenler = fopen("��retim_�yeleri.txt", "w");
	if(fp_ogretmenler == NULL){
		
		perror("Error opening file");
		return;
	}
	
	for(j=0;j<i;j++){
		fprintf(fp_ogretmenler, "%s,%s,%s,%s,\n", ogretmen[j].id, ogretmen[j].ad, ogretmen[j].soyad, ogretmen[j].unvan);
	}
	
	fclose(fp_ogretmenler);
	free(ogretmen);
	free(yeni_ad);
	free(yeni_soyad);
	free(yeni_unvan);
	free(line);
	printf("\n------------------G�NCELLEND�----------------\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();	
}

void Ogretmen_Silme(){
	
/*	FILE *fp_ogretmenler, *fp_ogretmenler_kopya;

	fp_ogretmenler = fopen("��retim_�yeleri.txt", "r");
	if(fp_ogretmenler == NULL){
		
		perror("Error opening file");
		return;
	}	
	
	
	int silinen_satir;
	Ogretmenler_Print();
	
	printf("Silmek istedi�iniz dersin indexini giriniz: ");
	scanf("%d", &silinen_satir);
	getchar();
	
	fp_ogretmenler_kopya = fopen("replica.txt", "w");

	char line[256]; int temp = 1;
	while(fgets(line, sizeof(line), fp_ogretmenler)){
		
		if(temp != silinen_satir){
			
			fputs(line, fp_ogretmenler_kopya);
		}
		temp++;
	}
	fclose(fp_ogretmenler);
	fclose(fp_ogretmenler_kopya);
	
	int kontrol;
	kontrol =  remove("��retim_�yeleri.txt");
	
	if(kontrol != 0) {
    	perror("\nError: unable to delete the file");
	} 
	
	kontrol = rename("replica.txt", "��retim_�yeleri.txt");
	
	if(kontrol != 0) {
    	perror("\nError: unable to delete the file");
	} 	
	*/
	printf("\n------------------�ALI�MA DEVAM ETMEKTE----------------\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
}

void Ogretmenler_Print(){
	
	FILE* fp_ogretmenler;
	fp_ogretmenler = fopen("��retim_�yeleri.txt", "r");
	
	if(fp_ogretmenler == NULL){
		
		perror("Error opening file");
		return;
	}
		
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	int i = 1;
	printf("\n �NDEX   | ID | �S�M | SOY�S�M | UNVAN \n");
	while(fgets(line, 100, fp_ogretmenler)){
		
		printf("%d. ",i);
		printf("%s", line);
		i++;
	}
	
	if(fclose(fp_ogretmenler) != 0){
        
		perror("Unable to close the dersler");
    }
    free(line);
    printf("\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : "); getch();
}

int Ogretmen_ID_Kontrol(char* id_test){
	
	FILE* fp_ogretmenler; 
	fp_ogretmenler = fopen("��retim_�yeleri.txt", "r");
	if(fp_ogretmenler == NULL){
		
		perror("Error opening file");
		return;
	}
			
	char divider[2] = ",";
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	while(fgets(line, 100, fp_ogretmenler)){
		
		strtok(line, divider);
		if(strcmp(line, id_test) == 0){
			free(line);
			fclose(fp_ogretmenler);
			return 0;
		}
	}
	fclose(fp_ogretmenler);
	free(line);
	return 1;

}

void Ogretmen_Ekleme(){
	
	OGRETMENLER *ogretmen;
	ogretmen = (OGRETMENLER*) malloc (sizeof(OGRETMENLER));                                                                           
	if(ogretmen == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	FILE *fp_ogretmenler;
	
	fp_ogretmenler = fopen("��retim_�yeleri.txt", "a");
	
	if(fp_ogretmenler == NULL){
		
		perror("Error opening file");
		return;
	}


	int counter = 1, secim;

	printf("\nG�RECE��N�Z ��RET�M �YES� B�LG�LER�N�N FORMATI A�A�IDAK� G�B� OLMALIDIR!!");
	printf("\nFormat : ��retim_�yesi_id,��retim_�yesi_isim,��retim_�yesi_soyisim,��retim_�yesi_unvan,\n");
	
	
	while(counter){
		
		printf("\n�rnek  : 11111,isim,soyisim,dr,\n");
		scanf("%[^,],%[^,],%[^,],%[^,]", ogretmen->id, ogretmen->ad, ogretmen->soyad, ogretmen->unvan);
		getchar();
		if(Ogretmen_ID_Kontrol(ogretmen->id) == 0){
			
			printf("\n\nGirmi� Oldu�unuz ��retim �yesi ID'si Bulunmaktad�r.Tekrar Denemek ��in 1 �st Men�ye D�nmek ��in 0 Giriniz : "); 
			scanf("%d",&secim);
			getchar();
			if(secim==0){
				fclose(fp_ogretmenler);
				return;
			}
		}
		else{
			counter = 0;
		}		
	}
	
	fprintf(fp_ogretmenler,"%s,%s,%s,%s,\n",ogretmen->id, ogretmen->ad, ogretmen->soyad, ogretmen->unvan);	
	fclose(fp_ogretmenler);
	free(ogretmen);
	
	printf("\nGirmi� Oldu�unuz ��retim �yesi Ba�ar�yla Eklenmi�tir!!");
	printf("\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();	
}


 
void Dersler_Print(){
	
	FILE* fp_dersler;
	fp_dersler = fopen("Dersler.txt", "r");
	
	if(fp_dersler == NULL){
		
		perror("Error opening file");
		return;
	}
	
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	
	int i = 1;
	printf("\n�NDEX | DERS KODU | DERS ADI | DERS KRED�S� | DERS KONTENJANI | HOCA ID\n\n");
	
	while(fgets(line, 100, fp_dersler)){
		
		printf("%d.",i);
		printf("%s", line);
		i++;
	}
	
	
	
	if(fclose(fp_dersler) != 0){
        
		perror("Unable to close the dersler");
    }
    free(line);
   	printf("\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
    getch();
}

void Ders_Guncelleme(){
	
	int guncellenen_satir, i, j;
	
	DERSLER *ders;	
	ders = (DERSLER*) malloc (sizeof(DERSLER));
	if(ders == NULL){
		
		perror("out of memory."); exit(1);
	}
	
	
	FILE *fp_dersler;
	fp_dersler = fopen("Dersler.txt", "r");
	if(fp_dersler == NULL){
		
		perror("Error opening file");
		return;
	}	
	
	char *line, *yeni_ders_adi, *yeni_kontenjan, *yeni_ogretmen_id;
	line = (char*) malloc(sizeof(char)*100);
	yeni_ders_adi = (char*) malloc(sizeof(char)*100);
	yeni_kontenjan = (char*) malloc(sizeof(char)*100);
	yeni_ogretmen_id = (char*) malloc(sizeof(char)*100);
	
	i = 1;
	printf("\n�NDEX | DERS KODU | DERS ADI | DERS KRED�S� | DERS KONTENJANI | HOCA ID\n\n");
	
	while(fgets(line, 100, fp_dersler)){
		
		printf("%d.",i);
		printf("%s", line);
		i++;
	}
	
	rewind(fp_dersler);
	
	printf("\n\nG�ncellemek �stedi�iniz Dersin �NDEX�N� Giriniz : ");
	scanf("%d", &guncellenen_satir);
	getchar();
	
	i=0;
	while(fgets(line, 100, fp_dersler)){
		
		ders = (DERSLER*) realloc(ders, (i+1)*sizeof(DERSLER));
		
		sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", ders[i].kod, ders[i].ad, ders[i].kredi, ders[i].kontenjan, ders[i].ogretmen_id);
		
		if((i+1) == guncellenen_satir){
			printf("\nDersin YEN� Ad�n�, Kontenjan�n� ve Dersi Veren ��retim G�revlisinin IDsini Giriniz\n�rnek Format :  ders ad�,kontenjan,ogretmen �d,\n\t\t");
			scanf("%[^,],%[^,],%[^,],", yeni_ders_adi, yeni_kontenjan, yeni_ogretmen_id);
			getchar();
			if(Ogretmen_ID_Kontrol(yeni_ogretmen_id) == 0){
				strcpy(ders[i].ad, yeni_ders_adi);
				strcpy(ders[i].kontenjan, yeni_kontenjan);
				strcpy(ders[i].ogretmen_id, yeni_ogretmen_id);
			}
			else{
				printf("Girmi� Oldu�unun ��retim �yesi ID'si Bulunamam��t�r!!\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n�z : ");
				fclose(fp_dersler);
				free(ders);
				free(line);
				free(yeni_ders_adi);
				free(yeni_kontenjan);
				free(yeni_ogretmen_id);
				getch();
				return;
			}
		}
		i++;
	}
	fclose(fp_dersler);
	
	fp_dersler = fopen("Dersler.txt", "w");
	if(fp_dersler == NULL){
		
		perror("Error opening file");
		return;
	}
	
	for(j=0;j<i;j++){
		fprintf(fp_dersler,"%s,%s,%s,%s,%s,\n", ders[j].kod, ders[j].ad, ders[j].kredi, ders[j].kontenjan, ders[j].ogretmen_id);
	}
	
	fclose(fp_dersler);
	free(ders);
	free(line);
	free(yeni_ders_adi);
	free(yeni_kontenjan);
	free(yeni_ogretmen_id);
	
	printf("\nGirmi� Oldu�unuz Ders G�ncellenmi�tir!!");
	printf("\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
	
}

void Ders_Silme(){
	
/*	FILE *fp_dersler, *fp_dersler_kopya;

	fp_dersler = fopen("Dersler.txt", "r");
	if(fp_dersler == NULL){
		
		perror("Error opening file");
		return;
	}	
	
	
	int silinen_satir;
	Dersler_Print();
	printf("Silmek istedi�iniz dersin indexini giriniz: ");
	scanf("%d", &silinen_satir);
	getchar();
	
	fp_dersler_kopya = fopen("replica.txt", "w");

	char line[256]; int temp = 1;
	while(fgets(line, sizeof(line), fp_dersler)){
		
		if(temp != silinen_satir){
			
			fputs(line, fp_dersler_kopya);
		}
		temp++;
	}
	fclose(fp_dersler);
	fclose(fp_dersler_kopya);
	
	int kontrol;
	kontrol =  remove("Dersler.txt");
	
	if(kontrol != 0) {
    	perror("\nError: unable to delete the file");
	} 
	
	kontrol = rename("replica.txt", "Dersler.txt");
	
	if(kontrol != 0) {
    	perror("\nError: unable to delete the file");
	} */
	printf("\n------------------�ALI�MA DEVAM ETMEKTE----------------\n\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();	
}

int Ders_Hoca_id_kontrol(char* id_test){
	
	FILE* fp_ogretmenler; 
	fp_ogretmenler = fopen("��retim_�yeleri.txt", "r");
	if(fp_ogretmenler == NULL){
		
		printf("Error opening file");
		return;
	}
			
	char divider[2] = ",";
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	while(fgets(line, 100, fp_ogretmenler)){
		
		strtok(line, divider);
		if(strcmp(line, id_test) == 0){
			fclose(fp_ogretmenler);
			free(line);
			return 0;
		}
	}
	fclose(fp_ogretmenler);
	free(line);
	return 1;
}

int Ders_Kodu_Kontrol(char* kod_test){
	
	FILE* fp_dersler;
	fp_dersler = fopen("Dersler.txt", "r");
	if(fp_dersler == NULL){
		
		printf("Error opening file");
		return;
	}	
	
	char divider[2] = ",";
	char *line;
	line = (char*) malloc(sizeof(char)*100);
	while(fgets(line, 100, fp_dersler)){
		
		strtok(line, divider);
		if(strcmp(line, kod_test) == 0){
			fclose(fp_dersler);
			free(line);
			return 1;
		}
	}
	fclose(fp_dersler);
	free(line);
	return 0;
}

void Ders_Ekleme(){
	
	DERSLER *ders;	
	ders = (DERSLER*) malloc (sizeof(DERSLER));
	if(ders == NULL){
		
		printf("out of memory."); exit(1);
	}
	
	FILE* fp_dersler; 
	fp_dersler = fopen("Dersler.txt", "a");
	
	if(fp_dersler == NULL){
		
		perror("Error opening file");
		return;
	}
	int counter = 1, secim;
	
	printf("\nG�RECE��N�Z DERS B�LG�LER�N�N FORMATI A�A�IDAK� G�B� OLMALIDIR!!");
	printf("\nFormat : ders_kodu,ders_ad�,ders_kredisi,ders_kontenjan�,dersi_veren_��retim_�yesi_IDsi,\n");
	while (counter){
		printf("\n�rnek  : blm1234,�rnek ders,1,10,100,\n");	
		scanf("%[^,],%[^,],%[^,],%[^,],%[^,]", ders->kod, ders->ad, ders->kredi, ders->kontenjan, ders->ogretmen_id);		 
		getchar();     	
		if(Ders_Kodu_Kontrol(ders->kod) == 1){
			
			printf("Girmi� oldu�unuz ders kodu bulunmaktad�r.Tekrar Denemek ��in 1 �st Men�ye D�nmek ��in 0 Giriniz : "); 
			scanf("%d",&secim);
			getchar();
			if(secim==0){
				fclose(fp_dersler);
				return;
			}
		}
		else if(Ders_Hoca_id_kontrol(ders->ogretmen_id) == 1){
				
			printf("\nGirmi� oldu�unuz ��retim �ysei ID'si Bulunamad�.Tekrar Denemek ��in 1 �st Men�ye D�nmek ��in 0 Giriniz : "); scanf("%d",&secim);
			if(secim==0){
				fclose(fp_dersler);
				return;
			}			
		}
		else{
			counter = 0;
		}
	}
	
	fprintf(fp_dersler,"%s,%s,%s,%s,%s,\n",ders->kod, ders->ad, ders->kredi, ders->kontenjan, ders->ogretmen_id);
	fclose(fp_dersler);
	free(ders);
	printf("\nGirmi� Oldu�unuz Ders Ba�ar�yla Eklenmi�tir!!");
	printf("\n�st Men�ye D�nmek ��in Herhangi Bir Tu�a Bas�n : ");
	getch();
	
}


