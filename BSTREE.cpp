#include<stdio.h>
#include <cstdlib>
struct node{
	int data;
	struct node *left;
	struct node *right;
	
};
typedef struct node BTREE;

BTREE *new_node(int x){
     BTREE *p=(BTREE *)malloc(sizeof(BTREE));
	 p->data=x;
     p->left=NULL;
     p->right=NULL;
     
}

BTREE *insert(BTREE *root,int x){
	if(root!=NULL){
		if(x<root->data)
		 root->left=insert(root->left,x);
		else
		 root->right=insert(root->right,x);
		  
	}
	else
	 root=new_node(x);
	  
	 return root; 
}
void preorder(BTREE *root){
	if(root!=NULL){
		printf("\n%d",root->data);
		
		preorder(root->left);
	
		preorder(root->right);
	}
}
void inorder(BTREE *root){
	if(root!=NULL){
		inorder(root->left);
		printf("\n%d",root->data);
		inorder(root->right);
	}
}
void postorder(BTREE *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("\n%d",root->data);
	}
}

int height(BTREE *root){
	if(root==NULL)
	return -1;
	else{
		int left_height,right_height;
		left_height=height(root->left);
		right_height=height(root->right);
		if(left_height<right_height)
		 return right_height+1;
		 else
		 return left_height+1;
		 
	}
	
	
}


	
int size(BTREE *root){
	if(root==NULL)
	 return 0;
	 else
	  return size(root->left)+1+size(root->right);
}
BTREE *delete_node(BTREE *root,int x){
	BTREE *p,*q;
	if(root==NULL)
	  return NULL;
	  if(root->data==x){
	  	if(root->left==root->right){
	  		free(root);
	  		return NULL;
		  }
		  else{
		  	if(root->left==NULL){
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
		  	p=q=root->right;
		  	while(p->left!=NULL)
		  	 p=p->left;
		  	 p->left=root->left;
		  	 free(root);
		  	 return q;
		       }
		   
		     }
		
		  	
	 	  }
	 	  else if(root->data<x)
	 	   root->right=delete_node(root->right,x);
	 	   else
	 	    root->left=delete_node(root->left,x);
	 	return root;
	  }
  




	 int main() { 
		  BTREE *myroot = NULL; int i = 0; 
		 do { printf("\n\nAgaca veri eklemek icin sayi giriniz...\nSayi = "); 
		  scanf("%d", &i); 
		  if(i != -1) myroot = insert(myroot, i); }
		while(i != -1); 
		
		delete_node(myroot,15);
		preorder(myroot); printf("\n"); 
		
		printf("number of node: %d",size(myroot));
		printf(" \n height::%d",height(myroot));
		
		
		
	
	return 0; 
		
	
}
