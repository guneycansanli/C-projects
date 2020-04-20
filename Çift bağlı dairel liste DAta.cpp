#include<stdio.h>
#include <cstdlib>
struct liste{
	int numara;
	struct liste *sonraki;
	struct liste *onceki;
};

typedef struct liste liste;
liste *ilk=NULL,*son=NULL,*yeni,*gecici;

void ekle(int numara1)
{
	yeni=(liste *)malloc(sizeof(liste));
	yeni->numara=numara1;
	
	if(ilk==NULL)
	{
		ilk=yeni;
		son=yeni;
		ilk->sonraki=ilk;
		ilk->onceki=ilk;
	}
		
	else
	{
		son=ilk;
	    ilk->onceki->sonraki=yeni;
		 yeni->sonraki=ilk;
		  yeni->onceki=ilk->onceki;
		   ilk->onceki=yeni;
		    ilk = yeni;

		
	}
	
}
void goruntule()
{
	gecici=ilk;
	if(ilk==NULL)
	{
		printf("liste bos");
	}
	else
	{
		printf("%d\n",gecici->numara);
		while(gecici->sonraki!=ilk)
		{
	
				printf("%d\n",gecici->numara);
				gecici=gecici->sonraki;
		}
	}
}

int main()
{
	int secim;

	
	while(1)
	{
		printf("\n\n\t\t-----------MENU----------\n1-Numara ekle\n2-Goruntule\n3-Ayni numaraya sahip varsa birini sil\n4-ilk numarayi sona koy\n5-Son numara ile ilk numarayi yer degistir\n6-programdan cik\n");
		printf("\n\tSEciminiz:");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				int no;
				printf("Eklemek istediginiz numara:");
				scanf("%d",&no);
				ekle(no);
				printf("%d sayisi listeye eklenmisir.",no);
				break;
				case 2:
					goruntule();
					break;
		}
	}
}
