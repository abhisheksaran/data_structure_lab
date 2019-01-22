#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    char value;
    struct stack* next;
}stack;
int size=0;
stack *head;
int push(char i)
{	
	stack* newNode=(stack*)malloc(sizeof(stack));
        newNode->value=i;
	newNode->next=head;
        head=newNode;
        size++;
        return 0;
}


char pop()
{   //if stack is empty,there is no ele to dlt, so return -1
	if(head==NULL)
	return '\0';
    //otherwise returning the element a[top] and decr the top by one
    stack* temp=head;
    head=temp->next;
    char deletedElement=temp->value;
    free(temp);
    size--;
	return deletedElement;	
}

char peekFront()
{   //if stack is empty,there is no ele, so return -1
	if(head==NULL)
	return '\0';
    // otherwise return a[top], the the topmost ele
	return head->value;
}


int main (int argc, char **argv)
{
head=NULL;
 char a[10000];
 scanf("%s",a);
//int n=strlen(v1);
int i=0;
while(a[i]!='\0')
{
if(a[i]=='}')
{
	if(peekFront()=='{')
	pop();
	else
	push(a[i]);
	
}
else if(a[i]==']')
{
	if(peekFront()=='[')
	pop();
	else
	push(a[i]);
	
}
else if(a[i]==')')
{
	if(peekFront()=='(')
	pop();
	else
	push(a[i]);
	
}
else push(a[i]);

i++;
//printf("size=%d, i=%d, head=%c\n",size,i,head->value);
}

if(head==NULL)
printf("1\n");
else
printf("0\n");

 

return 0;

}

