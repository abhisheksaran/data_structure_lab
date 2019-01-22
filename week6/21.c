//strategy:using a char stack structure to store and print the answer string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert string into integer
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}
//stack structure 
typedef struct stack{
    char value;
    struct stack* next;
}stack;
//headPointer intializes to null characters and size to zero
stack* head=NULL;
int size=0;
//function to insert char element at the beginning 
void push(char i)
{
	stack* newNode=(stack*)malloc(sizeof(stack));
        newNode->value=i;
	newNode->next=head;
        head=newNode;
        size++;
        
}
//function to dlt element from the beginning
char pop()
{   
	if(head==NULL)
	return '\0';
   
    stack* temp=head;
    head=temp->next;
    char deletedElement=temp->value;
    free(temp);
    size--;
	return deletedElement;	
}
//function to get the top element of the stack
char peekFront()
{   
	if(head==NULL)
	return '\0';
   
	return head->value;
}

int main()
{	int i=0;
	char a[128];
	scanf("%s",a);
	//check untill we got null character
	while(a[i]!='\0' )
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*')
		{	while(
			if(peekFront()=='\0'||peekFront()=='(')
			{
				push(a[i]);
			}
			if((a[i]=='*'||a[i]=='/')&&(peekFront()=='+'||a[i]=='-'))
			{
				push(a[i]);	
			}
			if((a[i]=='+'||a[i]=='-')&&(peekFront()=='*'||a[i]=='/'))
			{	
				printf("%c",pop());
	
			}

			if((a[i]=='+'&&peekFront()=='-')||(a[i]=='*'&&peekFront()=='/')||(a[i]=='/'&&peekFront()=='*')||(a[i]=='-'&&peekFront()=='+'))
			{
				printf("%c",pop());
				push(a[i]);				
			}
			


		}
	
	
		else if(a[i]=='(')
		{
			push(a[i]);	
		}

		else if(a[i]==')')
		{	char c=pop();
			while(c!='(')
			{
			printf("%c",c);
			c=pop();
			}			
				
		}
		
		else
		{
			printf("%c",a[i]);		
		}
	i++;

	}

	while(head!=NULL||pop()!='\0')
	{
		printf("%c",pop());	
	}
printf("\n");
	return 0;

}
