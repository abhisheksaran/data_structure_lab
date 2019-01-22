#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* next;
};

struct node* head;

void insert(int x)
{
 //
 struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->data=x;
 temp->next=head;
 head=temp; 
}

void Print()
 {
 struct node* temp=head;
 while(temp!=NULL)
 {
    printf("%p %d\n",temp,temp->data);
    temp=temp->next;
  }
 }


int main()
{
 head=NULL;
 int i,n,data;
 printf("how many numbers?\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  	scanf("%d",&data);
	insert(data);
	Print();	
 } 
 int num,pos;
 printf("please enter the number and pos at which you want to insert it\n ");
 scanf("%d %d",&num,&pos);
 Insert(num,pos);
 //Print();

 return 0;

}
