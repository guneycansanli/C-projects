#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ogrenci{
	int numara;
	char isim[50];
	struct ogrenci *sonraki;
};
typedef struct ogrenci ogrenci;

  ogrenci *yeni,*ilk=NULL,*son=NULL,*gecici,*silgecici;

void yenikayit(int numara,char isim[])
{
	yeni=(ogrenci *)malloc(sizeof(ogrenci));
	yeni->numara=numara;
	strcpy(yeni->isim,isim);
	yeni->sonraki=NULL;
	
	if(ilk==NULL)
	{
		ilk=yeni;
		son=ilk;
	}	
	else
		{
			son->sonraki=yeni;
			son=son->sonraki;
		}
	
}
void listele()
{
	gecici=ilk;
	if(gecici==NULL)
	{
		printf("Liste bos...\n\n");
	}
	else
	{
	
	while(gecici!=NULL)
	{
		printf("\n\tNumara:%d\n",gecici->numara);
		printf("\n\tisim:%s\n",gecici->isim);
		gecici=gecici->sonraki;
	}
	}
	
	
}

void ogrsil()
{
	int kontrol=0;
	int sil;
	if(ilk==NULL)
	{
		printf("\n\tListe bostur..");
	}
	else
	{
		printf("\nsilmek istediniz ogrenci numarasi:");
		scanf("%d",&sil);
		
		if(sil==ilk->numara)
		{
			kontrol=1;
			gecici=ilk;
			ilk=ilk->sonraki;
			free(gecici);
			
		}
		else
		{
			kontrol=1;
			gecici=ilk;
		
			while(gecici!=NULL)
			{
			
				if(sil==gecici->sonraki->numara)
				{
					silgecici=gecici->sonraki;
					gecici->sonraki=silgecici->sonraki;
					free(silgecici);
					
				}
				gecici=gecici->sonraki;
			}
		}
		
	}
	if(kontrol==0)
		printf("\tsilmek istediginiz ogrenci listede yoktur.");
	else
	printf("\n\t%d sayisi listeden silinmistir...\n",sil);

	
}
void sill()
{
	
	if(ilk==NULL)
	{
		printf("liste zaten bos...");
		
	}
	else
	{
		while(ilk!=NULL)
		{
			gecici=ilk;
			ilk=ilk->sonraki;
			free(gecici);
			
		}
	}
	printf("\t\t\tListe tamamen temzilendi.\n");
}
void ters(ogrenci *gecici)
{
	
	if(gecici==NULL)
	return;
		
			ters(gecici->sonraki);
	printf("%d\t",gecici->numara);
	printf("%s\n",gecici->isim);
	


}
void basaekle(int numara,char isim[])
{
	yeni=(ogrenci *)malloc(sizeof(ogrenci));
	yeni->numara=numara;
	strcpy(yeni->isim,isim);
	if(ilk==NULL)
	{
		ilk=yeni;
		son=ilk;
		ilk->sonraki=NULL;
	}
	else
	{
		yeni->sonraki=ilk;
		ilk=yeni;
		
	}
	
	
}

int main()
{
	
    int secim;
    int no;
    int sayac=0;
    char name[50];
   
    while(1)
    {
    	printf("\t\tMENU\n1-Ogrenci ekle\n2-Ogrenci listele\n3-ogrenci sil\n4-Mevcut ogrenci sayisi\n5-Listeyi sil\n6-listeyi tersten yazdir\n\n7-listenin basina ekle\n8-Programdan cik");
    	 printf("\n\t\tSECiMiNiz:");
         scanf("%d",&secim);
		 switch(secim)
	{
		case 1:
			printf("\tEklemek istediginiz ogrenci numarasi:");
			scanf("%d",&no);
			printf("\tisimi:");
			scanf("%s",name);
			sayac++;
			yenikayit(no,name);
			break;
	    case 2:
	    	listele();
	    	break;
	    case 3:
	    	sayac--;
		    ogrsil();
		    break;
		case 4:
		    printf("\n\n\n\tMevcut ogrenci sayiyi %d dir\n",sayac);    
			break; 	
		case 5:
		    sill(); 
		    sayac=0;
			break;
		case 6:
		    ters(ilk);
		    break;
		case 7:
			printf("\tEklemek istediginiz ogrenci numarasi:");
			scanf("%d",&no);
			printf("\tisimi:");
			scanf("%s",name);
		     basaekle(no,name);
		     sayac++;
		     break;
		case 8:
		     exit(1);
			break;
			default: printf("Yanlis secim\n");			
	 } 

	}
   

}
