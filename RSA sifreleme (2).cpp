#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>

int asal(int x){
	int a;
	for(a=2;a<x;a++){
		if(x%a==0)
		return 0;
		else{
	   return 1;
	   }
	}
}

int gcd(int e,int t){
    int i, gcd;

    for(i=1; i<=e && i<=t;++i)
    {
        if(e%i==0 && t%i==0)
            gcd = i;
    }
    return gcd;
}
 

int publicc(int t){
	int i=0;
	int x=2;
	int c;
	   while(i!=1){
	   	c=gcd(x,t);
	   	if(c==1)
	   	i=1;
	   	x++;
	   }
	   return x-1;
	}	
int privated(int e,int t){
	int i=1;
	while(i*e%t!=1){
		i++;
	}
	return i;
}
int enocription(int m,int e,int n){
    int x=1;
    int i;
    for(i=0;i<e;i++){
    	x*=m;
	}
	x=x%n;
	
	return x;

}  
int deocription(int m,int d,int n){
    int x=1;
    int i;
    for(i=0;i<d;i++){
    	x*=m;
	}
	x=x%n;
	return x;

}  

int main(){
	int p,q,n,t,e,d,len=0,i;
	int a[100];
	int m[100];
	int y[100];
	printf("Sifreleme icin 1.ASAl sayiyi giriniz:");
	scanf("%d",&p);
	if(asal(p)==0){
		printf("Girdiginiz sayi asal degildir");
		return 0;
	}
	
	printf("Sifreleme icin 2.ASAl sayiyi giriniz:");
	scanf("%d",&q);
	if(asal(q)==0){
		printf("Girdiginiz sayi asal degildir");
		return 0;
	}
	
	
    printf("Mesajinizi yaziniz:");
    scanf("%s",&a);
    
   while(a[len]!=NULL){
   	 i++;
   	 len++;
   }
                            
  	
	n=p*q;
	t=(p-1)*(q-1);
	e=publicc(t);
    d=privated(e,t);
	printf("Public key:(%d,%d)",e,n);
	printf("\nPrivate key:(%d,%d)\n",d,n);
	
	for(i=0;i<len;i++){
		m[i]=enocription(a[i],e,n);
		m[i]=m[i]%25;
		m[i]+=96;
	}
	printf("Sifreli mesaj:");
	for(i=0;i<len;i++){
		printf("%c",m[i]);
	}
		for(i=0;i<len;i++){
		y[i]=m[i];
	}
	for(i=0;i<len;i++){
		y[i]=deocription(a[i],d,n);
		y[i]=m[i]%25;
		y[i]+=96;
	}
	printf("\nDesifleri mesaj:");
	for(i=0;i<len;i++){
		printf("%c",y[i]);	
   }
   getchar();
}

