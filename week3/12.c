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
int i=0;
int j=0;
void merge(int a[],int b[],int m,int n)
{
/* Fill in */
    
    if(a[i]<b[j]&&i<n&&j<m)
    {
        printf("%d\n",a[i]);
        i++;
        merge(a,b,m,n);
    
    }

    if(a[i]>=b[j]&&i<n&&j<m)
    {
        printf("%d\n",b[j]);
        j++;
        merge(a,b,m,n);
    }
    if(i==n)
    {
        while(j<m)
        {
            printf("%d\n",b[j]); 
            j++;  
        }
    }
    if(j==m)
    {
        while(i<n)
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
    int *B = NULL;
    int n,m;

    fgets(line, sizeof line, stdin);
    sscanf(line, "%s", v1);
    n=stoi(v1);
    A = (int*) malloc(sizeof(int)* n);
    for(int i=0;i<n;i++)
    {
	fgets(line, sizeof line, stdin);
 	sscanf(line, "%s", v1);
	A[i]= stoi(v1);
    }
    fgets(line, sizeof line, stdin);
    sscanf(line, "%s", v1);
    m=stoi(v1);
    B = (int*) malloc(sizeof(int)* m);
    for(int i=0;i<m;i++)
    {
	fgets(line, sizeof line, stdin);
 	sscanf(line, "%s", v1);
	B[i]= stoi(v1);
    }
    merge(A,B,m,n);
    if(A)
        free(A);
    return 0;
}
