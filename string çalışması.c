#include<stdio.h>
#include<string.h>

int isSub(char subString[],char String[]){
	int i,j=0;
	int control=0;
	int indexSub=0;
	int index=0;
	int counter=0;
	for(i=0;subString[i]!='\0';i++)
	 indexSub++;
	 for(j=0;String[j]!='\0';j++)
	 index++;
	 if(indexSub>index){
	 	printf("it isnt Substring");
	 return 0;
	 }
	 while(counter!=index){
	 	for(i=0;subString[i]!='\0';i++){
	 		if(subString[i]==String[j]){
	 			control=1;
	 			j++;
			 }
	 			
	    else 
		control=0;
	}
		counter++;
		j++; 
	 }
	 
	 if(control==1){
	 	printf("it is subString");
	 	return 1;
	 }
	 else{
	 	printf("is not");
	 	return 0;
	 }
}
int main(){
	char subString[100];
	char String[100];
	printf("Enter a subString:");
	gets(subString);
	printf("Enter main String:");
	gets(String);
	isSub(subString,String);

}
