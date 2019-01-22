#include<stdio.h>
#include<stdlib.h>
int count=0;
int* merge(int a[],int ni,int nj,int i,int j)
{
//int c[ni+nj];
while(i<ni&&j<nj)
{
	if(a[i]<a[j])
	{
	a[i+count]=a[i];
	count++;
	merge(a,ni-1,nj,i++,j);
	return a;		
	}
	else
	{
	a[i+count]=a[j];
	count++;
	merge(a,ni,nj-1,i,j++);
	return a;
	}
}

}

int main()
{
int i;
int array[]={1,7,9,11,2,5,13,15,17,21};
int n=sizeof(array)/sizeof(array[0]);

int* sorted_array=merge(array,4,6,0,4);
for(i=0;i<n;i++)
{
printf("%d\n",*(sorted_array+i));
}

return 0;
}
