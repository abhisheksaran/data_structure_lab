#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

//int size=0;
//intially stack is empty
int positive =0;
int negative =0;



int push(int a[], int i,int n, int nn)
{	//if stack is full, return -1
    if((i>=0&&positive==n)||(i<0&&negative==nn))
    return -1;
	
    //otherwise insert it at top+1 and incr the top by one
    if(i<0&&negative<nn)
    {
	a[positive+negative]=i;
	negative++;

    }	
    if(i>=0&&positive<n)
    {
 	a[positive+negative]=i;
	positive++;
    }
    return 0;
	
		
}

int popp(int a[])
{   
	if(positive==0)
	return -1;
	int i=positive+negative-1;
	while(a[i]<0&&i>=0)
	{
		i--;	
	}
	int ans=a[i];
	while(i<positive+negative-1)
	{
		a[i]=a[i+1];
	i++;	
	} 
	positive--;
    
	return ans;	
}


int popn(int a[])
{   
	if(negative<=0)
	return 0;
	int i=positive+negative-1;
	while(a[i]>=0&&i>=0)
	{
		i--;	
	}
	int ans=a[i];
	while(i<positive+negative-1)
	{
		a[i]=a[i+1];	
		i++;
	} 
	negative--;
    
	return ans ;	
}



void printp(int a[])
{   
    if(positive>0)
    {	int i=positive +negative-1;
        while(i>=0)
        {    if(a[i]>=0)
            printf("%d\n",a[i]);
		i--;
        }    
    }    
}

void printn(int a[])
{  
    if(negative>0)
    {	int i=positive +negative-1;
        while(i>=0)
        {    if(a[i]<0)
            printf("%d\n",a[i]);
		i--;
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
    int nn;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);
        lineNo++;

        if(lineNo == 1)
        {	n=stoi(v1);
            //A = (int*) malloc(sizeof(int)* stoi(v1));
            continue;
        }
	if(lineNo == 2)
        {	nn=stoi(v1);
            A = (int*) malloc(sizeof(int)* (nn+n));
            continue;
        }

        if(strcmp(v1,"PSH") == 0)
        {
            ret = push(A, stoi(v2),n,nn);
            if(ret < 0)
                printf("%d\n", -1);
        }
        else if(strcmp(v1,"POPN") == 0)
        {
            ret = popn(A);
            printf("%d\n", ret);
	}
	else if(strcmp(v1,"POPP") == 0)
        {
            ret = popp(A);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRTN") == 0)
        {
            printn(A);
        }
        else if(strcmp(v1,"PRTP") == 0)
        {
            printp(A);
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
