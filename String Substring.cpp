#include<stdio.h>
#include<string.h>

int isSub(char subString[],char String[]){
	int i=0;
	int j=0;
	int x=0;
	int a;
	int control=0;
	int subindex=0;
	int index=0;
	
	for(i=0;subString[i]!='\0';i++)
	    subindex++;
	for(j=0;String[j]!='\0';j++)
	      index++;
	      if(index<subindex)
	      control=0;
	      else if(subString[0]==String[0]&&subString[1]=='\0'&&String[1]=='\0')
		  control=1;
		  else{
		        for(j=0;j<index;j++){
		        	x++;
		        	if(String[j]==subString[0])
		        	  a=x;
				}
			
					for(i=0;i<subindex;i++){
						if(subString[i]==String[a-1]){
							 control=1;
							 a++;
						}
						
						 
					}
				
					  
				  }
				  if(control==1)
				  printf("okey");
				  else
				  printf("no");
				  
				   return control; 
			  }
		  
		      


int main(){
	char subString[100];
	char String[100];
	printf("enter subString:");
	gets(subString);
	printf("enter main String:");
	gets(String);
	isSub(subString,String);
	
}
