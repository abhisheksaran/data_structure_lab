#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int heapSize=0;
//Code to parse integer from a string
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}



int parent(int i)
{
    /* Fill in */
	return (i-1)/2;
	
}

int left(int i)
{
    /* Fill in */
	return i*2+1;
}

int right(int i)
{
    /* Fill in */
	return i*2+2;
}

void swap(int *x, int *y)
{
    /* Fill in */
	int* temp;
	temp=x;
	x=y;
	y=temp;
}

void minHeapify(int a[],int i)
{
    /* Ensure that the subtree rooted at A[i] is a min heap. */		
	int min=i;
	if(left(i)<heapSize&&a[left(i)]<a[min])
	{
		min=left(i);	
	}
	if(right(i)<heapSize&&a[right(i)]<a[min])
	{
		min=right(i);	
	}
	
	swap(&a[i],&a[min]);
	
	if(min!=i && min>heapSize/2)
	{
	minHeapify(a,min);	
	}
	
	
}


int insertKey(int a[], int key,int n)
{
    /* Insert the element key into the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */	
	heapSize++;
	if(heapSize>n)
	{	printf("HEAPSIZE=%d n=%d\n",heapSize,n);
		heapSize--;
		return -1;
	}
	
	int i=heapSize;	
	a[i-1]=key;
	
	printf("HEAPSIZE=%d n=%d\n ",heapSize,n);
	while(parent(i)>=0&&a[parent(i)]>key)
	{
		swap(&a[i],&a[parent(i)]);
		i=parent(i);	
	}
	
	return 1;
}

int deleteKey(int a[], int i)
{
    /* Delete the element A[i] from the heap represented by A.
    Return 1 if the operation is successful and -1 otherwise. */
	if(i>=heapSize)
	return -1;
	swap(&a[i],&a[heapSize-1]);
	heapSize--;
	minHeapify(a,i);
	return 1;
	
}

int decreaseKey(int a[], int i, int newVal)
{
    /* Decrease the value of A[i] to newVal. Return 1 if the
    operation is successful and -1 otherwise. */
	if(newVal>=a[i]&&i>heapSize-1)
	return -1;
	a[i]=newVal;
	while(parent(i)>=0&&a[parent(i)]>a[i])
	{
	
		swap(&a[parent(i)],&a[i]);

		i=parent(i);				
	}
	return 1;
}


int extractMin(int a[])
{
    /* Delete the root of the min heap represented by A. Return
    the deleted element if the operation is successful and -1
    otherwise. */
	if(heapSize==0)
	return -1;

	int min=a[0];
	
	swap(&a[heapSize-1],&a[0]);
	
	heapSize--;
	minHeapify(a,0);
	
	return min;
}

int getMin(int a[])
{
    /* Get the root of the min heap represented by A. Return
    the element if the operation is successful and -1 otherwise. */
	if(heapSize<1)
	return -1;

	return a[0];
}

void print(int a[])
{
    /* Display the heap represented by A in the increasing order
    of their indices, one element per line.*/
	
	for(int i=0;i<heapSize;i++)
	{
		printf("I=%d %d\n",i,a[i]);
			
	}
	//printf("\n");
	
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
	//int n=stoi(v1);

        if(strcmp(v1,"INS") == 0)
        {
            ret = insertKey(A, stoi(v2),n);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"DEL") == 0)
        {
            ret = deleteKey(A, stoi(v2));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"EXT") == 0)
        {
            ret = extractMin(A);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            print(A);
        }
        else if(strcmp(v1,"DEC") == 0)
        {
            ret = decreaseKey(A, stoi(v2), stoi(v3));
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"MIN") == 0)
        {
            ret = getMin(A);
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
