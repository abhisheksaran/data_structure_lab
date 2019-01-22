#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

typedef struct queue{
    int value;
    struct queue* next;
    
}queue;

queue* head;

int size=0;
//intially queue is empty, front and rear pointing at -1



int isEmpty()
{   //queue will be empty if front and rear will have no ele to point on, so return 1
    if(head=NULL)
    return 1;
	// otherwise return 0
	return 0;

	
}
void Size(int n)
{   //if queue is empty size =0
    if(isEmpty()==1)
    printf("0\n");
    else
	printf("%d\n",size);
    //otherwise size will be rear-front +1, but as queue is circular taking modulo n
}


int isFull(int n)
{   //queue will be full if rear will be at n-1 and front at 0
    if(size==n)
	return 1;
    //otherwise queue is not full, returning 0
	return 0;
}

int enqueue(int i,int n)
{	// if queue is full, no space to insert next ele, return -1
    if(isFull(n)==1)
    return -1;
    // else if queue is empty, initializing fornt and rear to 0
    if(head==NULL)
    {
        queue* temp=(queue*)malloc(sizeof(queue));
        temp->value=i;
        temp->next=NULL;
        head=temp;
        size++;
        return 0;
    }
    queue* temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    queue* temp2=(queue*)malloc(sizeof(queue));
    temp2->value=i;
    temp2->next=NULL;
    temp=temp2;
    size++;
    printf("size=%d\n",size);
    return 0;
}

int dequeue(int i, int n)
{   // if queue is empty, no space to insert next ele, return -1
	if(isEmpty()==1)
	return -1;
    
    queue* temp=head;
    int deletedElement =head->value;
    head=temp->next;
    free(temp);
    size--;
	return deletedElement;
	
}

int peekFront()
{   // if empty , no front ele
	if(isEmpty()==1)
	return -1;
    queue* temp=head;

	return temp->value;
}




void print(int n)
{   //print starts from front 
	
    //if queue is not empty we gonna print its elements
    if(isEmpty()==0)
    {
        queue* temp=head;
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

    head=NULL;
    int ret;
    int lineNo = 0;
    int n;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {	n=stoi(v1);
           // A = (int*) malloc(sizeof(int)* stoi(v1));
            continue;
        }

        if(strcmp(v1,"ENQ") == 0)
        {
            ret = enqueue(stoi(v2),n);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"DEQ") == 0)
        {
            ret = dequeue(stoi(v2),n);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"FRN") == 0)
        {
            ret = peekFront();
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(n);
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
