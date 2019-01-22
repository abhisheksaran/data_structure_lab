#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int size=0;
int stoi(char* a)
{
	int x;
	sscanf(a,"%d",&x);
	return x;

}

typedef struct node{
	char value;
	struct node* next;	
}node;

node* createNode(char a)
{
	node* new=(node*)malloc(sizeof(node));
	new->value=a;
	new->next=NULL;
	return new;
}
void push(char* b, node** head)
{		
	char a=b[0];

	node* new=createNode(a);
	if(*head==NULL) 
	{*head=new,size++;
	return ;}
	new->next=*head;
	*head=new;
	size++;
}

void pop(node** head)
{	
	if(*head==NULL)
	{ printf("-1\n");
	return ;}
	else if((*head)->next==NULL) 
	{printf("%c\n",(*head)->value),*head=NULL,size--;
	return ;}
	else
	{
		node* temp=*head;
		printf("%c\n",temp->value);
		*head=temp->next;
		free(temp);
		size--;

		return;

	}
	
}

void top(node** head)
{	
	if(*head==NULL)
	{ printf("-1\n");
	return ;}
	else 
	{printf("%c\n",(*head)->value);
	 return ;}

	
}

void prt(node** head)
{	
	node* temp=(*head);
	while(temp)
	{
		printf("%c\n",temp->value);	
		temp=temp->next;
	}
}

int main()
{
	
	char v1[5];
	char v2[5];
	char line[128];
	//int lineNo=0;

	node* head=NULL;

	while(fgets(line,sizeof(line),stdin)!=NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		if(strcmp(v1,"PSH")==0) push(v2,&head);
		else if(strcmp("POP",v1)==0) pop(&head);
		else if(strcmp("TOP",v1)==0) top(&head);
		else if(strcmp("PRT",v1)==0) prt(&head);
		else if(strcmp("SZE",v1)==0) printf("%d\n",size);
		else if(strcmp("EMP",v1)==0) 
		{if(head==NULL) printf("1\n");
		else printf("0\n");}

		//if(head==NULL) 
		//printf("null\n");
		//else printf("N\n");
			//printf("n1=%d n2=%d",n1,n2);
	
	}
}
