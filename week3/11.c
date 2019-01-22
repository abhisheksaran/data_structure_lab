#include<stdio.h>
#include<stdlib.h>
int j=1;
int* insertionSort(int *a ,int a_count,int n)
{ 
    if(n<a_count)
    {
        int i=n-1;
        int key=a[n];
        while(key>a[i]&&i>=0)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
        //printf("%d\n",a[n]);
        n++;
        insertionSort(a,a_count,n);
    }
    return a;

}

int main()
{
    int n,i;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    a=insertionSort(a,n,0);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}