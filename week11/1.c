#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tree
{
	int value;
	struct tree* parent;
	struct tree* left;
	struct tree* right;
}tree;




tree* newNode(int a)
{
	tree* temp=malloc(sizeof(tree));
	temp->value=a;
	temp->parent=NULL;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
tree* insert(tree* head, int value)
{
	
	tree* new=newNode(value);
	if(head==NULL)
	{		
		//printf("NUll\n");
		head=new;
		return head;
	}
	if(value>(head->value)&&head->right==NULL)
	{	//printf("RIGHTNUll\n");
		new->parent=head;
		head->right=new;	
	}
	else if(value>(head->value)&&head->right!=NULL)
	{//printf("RIGHT\n");
		insert(head->right,value);	
	}
	else if(value<(head->value)&&head->left==NULL)
	{//printf("LEFTNUll\n");
		new->parent=head;
		head->left=new;	
	}
	else if(value<(head->value)&&head->left!=NULL)
	{//printf("LEFT\n");
		insert(head->left,value);	
	}
	return head;
}
void post(tree* head)
{
	if(head==NULL)
	{
		printf("-1\n");
		return;	
	}
	
	 
	if(head->left!=NULL)
	{
		post(head->left);	
	}
	
	
	if(head->right!=NULL)
	{
		post(head->right);	
	}
	
	printf("%d ",head->value);

	return;
	
}

void maxm(tree* head)
{
	if(head==NULL)
	{
		printf("-1\n");
		return;	
	}
	
	if(head->right==NULL)
	{
		printf("%d\n",head->value);
		return;
	}
	
	else
	{
		maxm(head->right);	
	}
		
	
}

void minm(tree* head)
{
	if(head==NULL)
	{
		printf("-1\n");
		return;	
	}
	
	if(head->left==NULL)
	{
		printf("%d\n",head->value);
		return;
	}
	
	else
	{
		minm(head->left);	
	}
		
	
}

void del(tree* head, int x)
{	
	if(head->value==x)
	{
		if(head->left==NULL&&head->right!=NULL)
		{
			if(head->parent==NULL)
			head=head->right;
			else if(head->parent->left->value==x)
				head->parent->left=head->right;
			else if(head->parent->right->value==x)
				head->parent->right=head->right;
			
			return;
		}
		
		
		if(head->right==NULL&&head->left!=NULL)
		{
			
			if(head->parent==NULL)
			head=head->left;
			else if(head->parent->left->value==x)
				head->parent->left=head->left;
			else if(head->parent->right->value==x)
				head->parent->right=head->left;
			
			return;
		}
		if(head->right!=NULL&&head->left!=NULL)
		{	tree* temp=head->left;
			while(temp->right)
			{	
				temp=temp->right;			
			}
			head->value=temp->value;

			if(temp->parent->left=temp)
			temp->parent->left=temp->left;
			else if (temp->parent->right=temp)
			temp->parent->right=temp->left;
			return;
		}
		if(head->right==NULL&&head->left==NULL)	
		{	
			head=NULL;
			return;	
		}
	}
	else if(head->left!=NULL)
	{
		del(head->left,x);	
	}
	else if(head->right!=NULL)
	{
		del(head->right,x);
	}
	else
	{
		printf("-1\n");
		return;	
	}
}   
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}
int main()
{
	char a[10];
	char b[10];
	char line[128];
	int lineNo=0;
	tree* head;
	head=NULL;
	
	while(fgets(line, sizeof line, stdin) != NULL )
	{
		sscanf(line,"%s %s",a,b);
		
		if(strcmp(a,"PST")==0)
		{	post(head);
			printf("\n");
		}
		else if(strcmp(a,"INS")==0)
		head=insert(head,stoi(b));
		else if(strcmp(a,"DEL")==0)
		del(head,stoi(b));
		else if(strcmp(a,"MIN")==0)
		minm(head);
		else if(strcmp(a,"MAX")==0)
		maxm(head);
		else 
		printf("INVALID\n");
		
		lineNo++;
	}
}                                                                                                                                                                                                                                                                                                            

