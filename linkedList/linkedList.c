#include<stdio.h>
#include<stdlib.h>
struct node* head;
struct node
{
	int data;
	struct node* next;
};


void insertBegin(int a)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->next=head;
	head=temp;
}

void print()
{
	struct node* temp2=head;
	while(temp2!=NULL)
	{	
		printf("%d",temp2->data);
		temp2=temp2->next;		
	}
}

int main()
{	head=NULL;
	//head->next=NULL;// don't do head=NULL otherwise u can't do head->next=temp in line 24
	int a,n,i;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter the values\n");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&a);
		insertBegin(a);
		print();	
	}
	return 0;
}
