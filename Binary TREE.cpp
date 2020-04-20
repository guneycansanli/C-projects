#include<stdio.h>
#include <cstdlib>
#include<conio.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node BTREE;

BTREE *new_node(int data){
	BTREE *p=(BTREE *)malloc(sizeof(BTREE));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
BTREE *insert(BTREE *root,int data){
	if(root!=NULL){
		if(data<root->data)
		 root->left=insert(root->left,data);
		else
		 root->right=insert(root->right,data); 
	}
	else
	 root=new_node(data);
	 
	return root; 
}
void preorder(BTREE *root){
	if(root!=NULL){
		printf(" %d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(BTREE *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}
void postorder(BTREE *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}
int size(BTREE *root){
	if(root==NULL)
	  return 0;
	else 
	 return size(root->left)+1+size(root->right);
	   
}

int main()
{
	BTREE *p=NULL;
	
	insert(p,25);
	insert(p,14);
	insert(p,23);
	insert(p,40);
	insert(p,24);
	insert(p,23);
	insert(p,48);
	insert(p,7);
	insert(p,5);
	insert(p,34);
	insert(p,10);
	insert(p,7);
	insert(p,17);
	insert(p,36);
	preorder(p);
	postorder(p);
	inorder(p);
	printf("%d",size(p));
	
	
	getch();
	return 0;
	
}
