#include<stdio.h>
#include<stdlib.h>
int insertionSort(int a[],int n)
{
int temp,i;
for(int j=1;j<n;j++)
{
	for(i=j-1;i>=0;i--)
	{
		if(a[j]<a[i])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			insertionSort(a,j);
			return a;
		}
			
	}
}
for(i=0;i<n;i++)
{
printf("%d ",*(sorted_array+i));
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



for(i=0;i<n;i++)
{
printf("%d ",*(sorted_array+i));
}

return 0;
}
