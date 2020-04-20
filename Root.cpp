#include<stdio.h>
#include <cstdlib>
struct node{
	int data;
	struct node *left;
	struct node *right;
	
};
typedef struct node BTREE;


BTREE *new_node(int i){
	BTREE *p=(BTREE *)malloc(sizeof(BTREE));
	p->data=i;
	p->left=NULL;
	p->right=NULL;
	return p;
}

BTREE *insert(BTREE *root,int i){
	if(root!=NULL){
		if(root->data<i)
			root->right=insert(root->right,i);
		else
		  root->left=insert(root->left,i);
		  	}
	else{
		root=new_node(i);
		return root;
	} 
		  	
}

int size(BTREE *root){
	if(root==NULL)
	  return NULL;
	else
	 return size(root->left)+1+size(root->right);
}

int height(BTREE *root){
	if(root==NULL)
	  return 0;
	  else{
	  	int Lheight,Rheight;
	  	Lheight=height(root->left);
	  	Rheight=height(root->right);
	  	if(Lheight>Rheight)
	  	  return Lheight+1;
	  	else
		  return Rheight+1; 
	  }
}

void preorder(BTREE *root){
	if(root==NULL)
	 printf("root is empty");
	 else{
	 	printf("%d",root->data);
	 	preorder(root->left);
	 	preorder(root->right);
	 	
	 }
	 
}
void inorder(BTREE *root){
	if(root==NULL)
	printf("root is empty");
	else{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}	
}

void postorder(BTREE *root){
	if(root==NULL)
	printf("root is empty");
	else{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}

int minValue(BTREE *root){
	if(root==NULL)
	return 0;
	else{
		while(root->left!=NULL)
		  root=root->left;
		 return (root->data); 
	}
}

int maxValue(BTREE *root){
	if(root==NULL)
	return 0;
	else{
	
	while(root->right!=NULL)
	     root=root->right;
	     return root->data;
		    }
}

int isSame(BTREE *root1,BTREE *root2){
	
	if(root1==NULL && root2==NULL)
	    return 1;
	else  if(root1!=NULL && root2!=NULL)  
	return (root1->data==root2->data && isSame(root1->left,root2->right) && (root1->right,root2->right));
	else 
	return 0;
}

int path(BTREE *root,int sum){
	int pathsum;
	if(root==NULL && sum==0)
	 return 1;
	 else{
	 	pathsum=sum-root->data;
	 	return (path(root->left,pathsum) || path(root->right,pathsum)); 
	 }
}

BTREE *copyOdd(BTREE *root1,BTREE *root2){
	if(root1!=NULL){
		if(root1->data%2==1)
		root2=insert(root2,root1->data);
		
		  root2 = copyOdd(root1 -> left, root2);
		   root2 = copyOdd(root1 -> right, root2);

	}
	return root2;
}
int toplam(BTREE *root,int sum){
	if(root!=NULL){
			sum+=root->data;
	    sum=toplam(root->left,sum);
		sum=toplam(root->right,sum);
	
	}
	
	return sum;

}
int kisayol(BTREE *root){
	if(root==NULL)
	return -1;
	else{
		int Lheight;
		int Rheight;
		Lheight=kisayol(root->left);
		Rheight=kisayol(root->right);
		if(Lheight>Rheight)
		 return Rheight+1;
		else 
		 return Lheight+1; 
		}
		
}


BTREE *delete_node(BTREE *root,int x){
	BTREE *p,*q;
	if(root==NULL)
	 return NULL;
	 else
	   if(root->data==x){
	   	if(root->left==root->right){
	   		free(root);
	   		return NULL;
		   }
		else if(root->left==NULL){
			p=root->right;
			free(root);
			return p;
		} 
		else if(root->right==NULL){
			p=root->left;
			free(root);
			return p;
		}  
		else{
			q=p=root->right;
			while(p->left!=NULL)
			 p=p->left;
			p->left=root->left;
			free(root);
			return q; 
		}
	   }
	   else if(root->data<x)
	   root->right=delete_node(root->right,x);
	   else
       root->left=delete_node(root->left,x);
}
int main(){
	BTREE *myroot=NULL;
	BTREE *myroot2=NULL;
	int secim;
	while(secim!=-1){
		printf("\n\t MENU\n1-Agaca ekle\n2-Agactan sil\n3-preorder\n4-inorder\n5-postorder\n6-Max value\n7-Min value\n8-Height\n9-Dugum(sayi tutan yuvarlaklarin:D) sayisi\n10-Tek olan datalari copyala(myroot2 ye)\n11-2 Agaci karsilastir\n");
		printf("12-Girilen bir x degeri, kokten itibaren yaprak dahil olmak uzere o yol üzerindeki verilerin toplamýna esit mi \n13-Tum datalarin toplami \n14-Yapraga giden en kisa yol ");
		printf("\n\n\tSeciminiz:");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				int veri;
				int agac;
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
					printf("eklemek istedigin sayi:");
					scanf("%d",&veri);
					myroot=insert(myroot,veri);
				}
				else{
					printf("eklemek istedigin sayi:");
					scanf("%d",&veri);
					myroot2=insert(myroot,veri);
				}	
				break;
			case 2:
			    int sil;
			    
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
					if(agac==1){
					printf("silmek istedigin sayi:");
					scanf("%d",&sil);
					myroot=delete_node(myroot,sil);
				}
				else{
					printf("silmek istedigin sayi:");
					scanf("%d",&sil);
					myroot2=delete_node(myroot2,sil);
				}	
				break;
				case 3:
					
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
					 preorder(myroot);
				}
				else{
					preorder(myroot2);
				}	
				break;
				case 4:
					
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
					 inorder(myroot);
				}
				else{
					inorder(myroot2);
				}	
				break;
				case 5:
					
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
					 postorder(myroot);
				}
				else{
					postorder(myroot2);
				}	
				break;
				case 6:
				
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
					printf("%d",maxValue(myroot));
				}
					
				else{
					printf("%d",maxValue(myroot2));
				}
				break;
				case 7:
					
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
						printf("%d",minValue(myroot));
					}
					
				else{
					printf("%d",minValue(myroot2));
				}
				break;
				case 8:
					
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
					printf("%d",height(myroot));
				}
					
				else{
				printf("%d",height(myroot2));
				}
				break;
				case 9:
					
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
						printf("%d",size(myroot));
					}
					
				else{
					printf("%d",size(myroot2));
				}
				break;
				case 10:
					copyOdd(myroot,myroot2);
					printf("1. agacin tek sayilari ikinci agaca eklendi");
					break;
			case 11:
				printf("%d",isSame(myroot,myroot2));
				break;
				case 12:
					
					int sayi;
					printf("sayiyi girin:");
					scanf("%d",&sayi);
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
						printf("%d",path(myroot,sayi));
					}
					
				else{
					printf("%d",path(myroot2,sayi));
				}
				break;
				case 13:
		
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
						printf("%d",toplam(myroot,0));
					}
					
				else{
					printf("%d",toplam(myroot2,0));
					}	
					break;	
				case 14:
				printf("1. agac icin 1 giriniz\n2. agac icin 2 giriniz\tsecim: ");
				scanf("%d",&agac);
				if(agac==1){
						printf("%d",kisayol(myroot));
					}
					
				else{
					printf("%d",kisayol(myroot2));
					}	
					break;		
	}
}
}











