#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	char value;
	struct tree* left;
	struct tree* right;
}tree;
int j=0;

tree* pop(tree** a)
{	j--;
	tree* ans=a[j];
	//printf("%c\n",a[j]->value);
	
	return ans;
}
void insert(tree** a,tree* key)
{
	a[j]=key;
	//printf("%c\n",a[j]->value);
	j++;
}
tree* createNode(char c,tree* t1, tree* t2 )
{
	tree* temp=(tree*)malloc(sizeof(tree));
	temp->value=c;
	temp->left=t1;
	temp->right=t2;
	return temp;	
}
void infix(tree* root)
{
	if(root->left!=NULL)
	infix(root->left);
	//printf("-1\n");}
	
	printf("%c",root->value);
	
	if(root->right!=NULL)
	infix(root->right);
	
	return;
	
}
int main()
{	
	char a[1000];
	scanf("%s",a);
	int i=0;
	tree** array=(tree**)malloc(100*sizeof(tree*));
		
	while(a[i]!='\0')
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*')
		{
			tree* t2=pop(array);
			tree* t1=pop(array);
			tree* newNode=createNode(a[i],t1,t2);
			//printf("%c\n",t1->value);
			insert(array,newNode);
		}
		else
		{
			tree* temp=(tree*)malloc(sizeof(tree));
			temp->value=a[i];
			temp->left=NULL;
			temp->right=NULL;
			//printf("%c\n",temp->value);
			insert(array,temp);
		}
	//printf("i=%d j=%d\n",i,j);
	i++;
	}
	
	
	tree* root=pop(array);
	//printf("%c",root->value);
	infix(root);
	//printf("\n");


	return 0;
}
