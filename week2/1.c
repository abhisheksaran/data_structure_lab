#include<stdio.h>
#include<stdlib.h>

int* insertionSort(int a[],int n)
{
int temp,i;

for(i=0;i<n;i++)
{
	if(a[n-1]<a[i])
	{
		temp=a[i];
		a[i]=a[n-1];
		a[n-1]=temp;
		insertionSort(a,n);
		return a;
	}
		
}

}


int main()
{
int i;
int n;
printf("n=?");
scanf("%d",&n);
int array[n];
printf("enter the ele..");
for(i=0;i<n;i++)
{
scanf("%d",&array[i]);
}


int* sorted_array=insertionSort(array,n);
for(i=0;i<n;i++)
{
printf("%d ",*(sorted_array+i));
}

return 0;
}
