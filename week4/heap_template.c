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
int front =0;
int rear=-1;
void Size(int a[],int n)
{
	printf("%d\n",(n+rear-front)%n);
}

int enqueue(int a[], int i,int n)
{	if(rear>front&& rear-front==n-1)
	return -1;
	if(front>rear&& front-rear<=1)
	return -1;

	if(rear>front&& rear<n-1)
	{	if(rear=0)
		rear++;
		a[rear]=i;
	}
	if(rear>front&& rear==n-1&& rear-front<n-1)
	{
		rear=0;
		a[rear]=i;	
	}
	
	if(front>rear&& front-rear>1)
	{
		rear++;
		a[rear]=i;	
	}
 
}

int dequeue(int a[], int i, int n)
{
	if(rear==front)
	return -1;
	if(front>rear&& front==n-1)
	{
		front=0;
		return a[n-1];	
	}
	front++;
	return a[front--];
	
}

int peekFront(int a[])
{
	if(rear==front)
	return -1;
	return a[front];
}

int isFull(int n)
{
    	if(rear>front &&rear-front==n-1)
	return 1;
	if(rear<front && front-rear==1)
	return 1;

	return 0;
}

int isEmpty()
{
	if(rear==front)
	return 1;

	return 0;
	
}

void print(int a[],int n)
{
	int i=front;
	while(i!=rear&&i<=n-1)
	{
		printf("%d\n",a[i]);
		i++;	
	} 
	if(i==n&&front>rear)
	{	i==0;
		while(i!=rear&&i<=n-1)
		{
		printf("%d\n",a[i]);
		i++;	
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
            if(ret < 0)
                printf("%d\n", -1);
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
            if(ret < 0)
                printf("%d\n", -1);
	}
	else if(strcmp(v1,"FUL") == 0)
        {
            ret = isFull(n);
            if(ret < 0)
                printf("%d\n", -1);
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
