#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char value;
	struct node* next;
		
}node;

node* createNode(char c)
{
	node* new=(node*)malloc(sizeof(node));
	new->value=c;
	new->next=NULL;
	return new;
}

void push(node** head,char c)
{
	
	node* new=createNode(c);
	if((*head)==NULL) (*head)=new;
	else
	{	node* temp=(*head);
		new->next=temp;
		*head=new;
	}
}

char pop(node** head)
{
	
	if((*head)==NULL) 
	{
		return '\0';
	}
	
	else
	{
		node* temp=(*head);
		char c=temp->value;
		(*head)=(*head)->next;
		free(temp);
		return c;
	}
}
int main()

{	
	node* head=NULL;
	char a[100];
	scanf("%s",a);
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]=='('||a[i]=='{'||a[i]=='[') push(&head,a[i]);
		else if(a[i]==')')
		{	char c=pop(&head);
			//printf("c=%c\n",c);
			if(c!='(') 
			{
				printf("0\n");
				return 0;			
			}
				
		} 

		else if(a[i]=='}')
		{	char c=pop(&head);
			if(c!='{') 
			{
				printf("0\n");
				return 0;			
			}
				
		} 
		else if(a[i]==']')
		{	char c=pop(&head);
			if(c!='[') 
			{
				printf("0\n");
				return 0;			
			}
				
		} 
	//printf("i=%d a[i]=%c\n",i,a[i]);
	i++;
		
	}
	if(pop(&head)=='\0')
	printf("1\n");
	else
	printf("0\n");
	
}
