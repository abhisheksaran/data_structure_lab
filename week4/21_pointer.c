#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

typedef struct stack{
    int value;
    struct stack* next;
}stack;

stack *head;

int size=0;
//intially stack is empty
//int top =-1;
int isEmpty()
{   //if there is no element in the stack then it is empty, return 1
    if(head==NULL)
    return 1;
	//otherwise return 0
	return 0;
}

int isFull(int n)
{   //if elements in the stack is equal to n-1,stack is full because maxm allowed size is n, so return 1
    if(size==n)
	return 1;
    //otherwise return 0
	return 0;
}


void Size(int n)
{  //a[top] is the most recently added element, so printing from a[top] todown a[0] 
	printf("%d\n",size);
}


int push(int i,int n)
{	//if stack is full, return -1
    if(isFull(n)==1)
    return -1;
    //otherwise insert it at top+1 and incr the top by one
		stack* newNode=(stack*)malloc(sizeof(stack));
        newNode->value=i;
		newNode->next=head;
        head=newNode;
        size++;
        return 0;
}

int pop(int i, int n)
{   //if stack is empty,there is no ele to dlt, so return -1
	if(isEmpty()==1)
	return -1;
    //otherwise returning the element a[top] and decr the top by one
    stack* temp=head;
    head=temp->next;
    int deletedElement=temp->value;
    free(temp);
    size--;
	return deletedElement;	
}

int peekFront()
{   //if stack is empty,there is no ele, so return -1
	if(isEmpty()==1)
	return -1;
    // otherwise return a[top], the the topmost ele
	return head->value;
}

void print()
{   //if stack is not empty,printing the elements in the the reverse order in which they are  inserted
    if(isEmpty()==0)
    {   stack* temp;
        temp=head;
        
        while(temp!=NULL)
        {
            printf("%d\n",temp->value);
            temp=temp->next;
        }    
    }    
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    //int *A = NULL;
    int ret;
    int lineNo = 0;
    int n;
    head=NULL;
    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {	n=stoi(v1);
           // struct A = (struct*) malloc(sizeof(struct)* n);
            continue;
        }

        if(strcmp(v1,"PSH") == 0)
        {
            ret = push(stoi(v2),n);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"POP") == 0)
        {
            ret = pop(stoi(v2),n);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"TOP") == 0)
        {
            ret = peekFront();
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print();
        }
        else if(strcmp(v1,"SZE") == 0)
        {
             Size(n);
           
        }
        else if(strcmp(v1,"EMP") == 0)
        {
            ret = isEmpty();
            printf("%d\n", ret);
	}
	else if(strcmp(v1,"FUL") == 0)
        {
            ret = isFull(n);
            printf("%d\n", ret);
        }
        else
        {
            printf("INVALID\n");
        }
    }

   
    return 0;
}
