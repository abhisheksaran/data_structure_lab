#include<stdio.h>
#include<stdlib.h>
int findPivotPosition(int a[],int n)
{
int i;
int count=0;
	for(i=1;i<n;i++)
	{
	if(a[i]<=a[0])
	count++;	
	}
return count;
}

int main()
{
int i;
int array[]={1};
int n=sizeof(array)/sizeof(array[0]);

int pivPos=findPivotPosition(array,n);
printf("%d\n	",pivPos);

return 0;
}
