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

int size=0;
//intially queue is empty, front and rear pointing at -1
int front =-1;
int rear=-1;


int isEmpty()
{   //queue will be empty if front and rear will have no ele to point on, so return 1
    if(rear==-1&&front==-1)
    return 1;
	// otherwise return 0
	return 0;

	
}
void Size(int a[],int n)
{   //if queue is empty size =0
    if(isEmpty()==1)
    printf("0\n");
    else
	printf("%d\n",(n+rear-front+1)%n);
    //otherwise size will be rear-front +1, but as queue is circular taking modulo n
}


int isFull(int n)
{   //queue will be full if rear will be at n-1 and front at 0
    if(rear>front &&rear-front==n-1)
	return 1;
    //in circular scenerio, queue will be also full if front have no place to insert the next ele, 
    //in this situation size=n+1-1=n which is maxm
	if(rear<front && front-rear==1)
	return 1;
    //otherwise queue is not full, returning 0
	return 0;
}

int enqueue(int a[], int i,int n)
{	// if queue is full, no space to insert next ele, return -1
    if(isFull(n)==1)
    return -1;
    // else if queue is empty, initializing fornt and rear to 0
    if(isEmpty()==1)
    {
        rear=0;
        front=0;
        a[rear]=i;
    }
    // else if rear reached upto maxm index, n-1, and as queue is not full, can insert next ele at 0, ie in circular way
    else if(rear>front&& rear==n-1&& rear-front<n-1)
	{
		rear=0;
		a[rear]=i;
	}
    // else incr rear by one and inserting the ele. at that pos
    else 
    {
        rear++;
		a[rear]=i;   
    }
    
 
}

int dequeue(int a[], int i, int n)
{   // if queue is empty, no space to insert next ele, return -1
	if(isEmpty()==1)
	return -1;
    //if front reached upto maxm index, n-1, can dlt ele and pointing front to 0, ie in circular w//
	if(rear<front&& front==n-1)
	{
		front=0;
		return a[n-1];	
	}
    //if this is last ele , after dlting this queue will be empty so front and reat points to -1, the condn of empty queue
    if(rear==front)
    {   int temp=front;
        rear=-1;
        front=-1;
        return a[temp];
    }
    // else decr front by one and dltting the ele. at that pos
	front++;
	return a[front-1];
	
}

int peekFront(int a[])
{   // if empty , no front ele
	if(isEmpty()==1)
	return -1;
    //else return front
	return a[front];
}




void print(int a[],int n)
{   //print starts from front 
	int i=front;
    //if queue is not empty we gonna print its elements
    if(isEmpty()==0)
    {
    //print till we reacj to maxm-1 index
	while(i!=rear&&i<n-1)
	{
		printf("%d\n",a[i]);
		i++;	
	}
    //printing maxm index ele
    printf("%d\n",a[i]); 
    i++;
    //if still there are ele left , implies elements are in circular form
    // ie starts from 0 untill we reach to rear
	if(i==n&&front>rear)
	{	i=0;
		while(i!=rear&&i<n-1)
		{
		printf("%d\n",a[i]);
		i++;	
		} 
        printf("%d\n",a[i]);
	}
    

    }
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    int *A = NULL;
    int ret;
    int lineNo = 0;
    int n;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {	n=stoi(v1);
            A = (int*) malloc(sizeof(int)* stoi(v1));
            continue;
        }

        if(strcmp(v1,"ENQ") == 0)
        {
            ret = enqueue(A, stoi(v2),n);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"DEQ") == 0)
        {
            ret = dequeue(A, stoi(v2),n);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"FRN") == 0)
        {
            ret = peekFront(A);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(A,n);
        }
        else if(strcmp(v1,"SZE") == 0)
        {
             Size(A,n);
           
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

    if(A)
        free(A);

    return 0;
}
