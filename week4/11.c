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
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void maxHeapify(int a[],int i)
{
    //finding maxm among two children 		
	int max=i;
	if(left(i)<heapSize&&a[left(i)]>a[max])
	{
		max=left(i);	
	}
	if(right(i)<heapSize&&a[right(i)]>a[max])
	{
		max=right(i);	
	}
	//swap maxm with parent
	swap(&a[i],&a[max]);
	// swaping may violate max heap property of subtree having parent as min
	// so applying maxxHeapify to min subtree 
	if(max!=i && left(max)<=heapSize-1&& right(max)<=heapSize-1)
	{
	maxHeapify(a,max);	
	}
    //recursion will stop when we reach upto leaves
	
	
}


int insertKey(int a[], int key,int n)
{
    //if heap is ful return -1
	heapSize++;
	if(heapSize>n)
	{	
		heapSize--;
		return -1;
	}
	//otherwise insert at last position
	int i=heapSize-1;	
	a[i]=key;
	//move upwards by swaping element with it's parent till it's greater then it's parent
	while(parent(i)>=0&&a[parent(i)]<a[i])
	{
		swap(&a[i],&a[parent(i)]);
		i=parent(i);	
	}
	
	return 1;
}


	

int increaseKey(int a[], int i, int newVal)
{
    //if newVal is greater then a[i] , return -1
	if(newVal<=a[i]&&i>heapSize-1)
	return -1;
    //otherwise assign a[i] to newVal
	a[i]=newVal;
    //move upwards by swaping element with it's parent till it's greater then it's parent
	while(parent(i)>=0&&a[parent(i)]<a[i])
	{
		swap(&a[parent(i)],&a[i]);
		i=parent(i);				
	}
	return 1;
}


int extractMax(int a[])
{
   //if heap is empty return -1
	if(heapSize==0)
	return -1;
    //otherwise swap it with last element and decr heapSize
	int max=a[0];
	//swaping violates maxxHeap property , so applying mean heap again
	swap(&a[heapSize-1],&a[0]);
	heapSize--;
	maxHeapify(a,0);
	//returning extracted min value	
	return max;
}



void print(int a[])
{
    //printing the values in indexing order
	for(int i=0;i<heapSize;i++)
	{
		printf("%d\n",a[i]);
			
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


        if(strcmp(v1,"INS") == 0)
        {
            ret = insertKey(A, stoi(v2),n);
            if(ret < 0)
                printf("%d\n", -1);
        }
        
   
        else if(strcmp(v1,"EXT") == 0)
        {
            ret = extractMax(A);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {	
            print(A);
        }
        else if(strcmp(v1,"INC") == 0)
        {
            ret = increaseKey(A, stoi(v2), stoi(v3));
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
