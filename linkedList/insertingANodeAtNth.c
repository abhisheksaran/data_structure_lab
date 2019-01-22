#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* next;
};

struct node* head;

void Print()
 {
 struct node* temp=head;
 while(temp!=NULL)
 {
    printf("%p %d\n",temp,temp->data);
    temp=temp->next;
  }
 }

void insert(int x, int pos)
 {
 struct node* temp1=(struct node*)malloc(sizeof(struct node));
 temp1->data=x;
 temp1->next=NULL;

 if(pos==1)
  {
  temp1->next=head;
  head=temp1;
  return;
  }

  
 int index=2;
 struct node* temp2=head;
 while(index!=pos)
   {
   temp2=temp2->next;
   index ++;
   }
 temp1->next=temp2->next;
 temp2->next=temp1; 
 	  
 }

int main()
{
 head=NULL;
 insert(1,1);//1
 insert(2,2);//1 2
 insert(3,1);//3 1 2
 insert(4,2);//3 4 1 2

 Print();


 return 0;

}
