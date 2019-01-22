#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int  topp;
int topn;

void set(int n1 ,int n2)
{
	topp=0;
	topn=n1;
}

int stoi(char* a)
{
	int x;
	sscanf(a,"%d",&x);
	return x;

}

void push(int n1,int n2,int a,int *b)
{
	//printf("a=%d\n",a);
	if(a<0&&topn>n1+n2-1)
	{
		printf("-1\n");
		return;	
	}	
	else if(a<0) b[topn]=a,topn++;
	else if(a>=0&&topp>n1-1)
	{
		printf("-1\n");
		return;	
	}
	else b[topp]=a,topp++;

	return;
	
}

void popp(int *a)
{
	if(topp==0)
	{
		printf("-1\n");
		return;	
	}
	else
	{
		topp--;
		printf("%d\n",a[topp]);
		
		return ;	
	}
}


void popn(int n1,int *a)
{
	if(topn==n1)
	{
		printf("0\n");
		return;	
	}
	else
	{
		topn--;
		printf("%d\n",a[topn]);
		
		return ;	
	}
}

void prtp(int *a)
{
	for(int i=topp-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
}

void prtn(int *a,int n1)
{
	for(int i=topn-1;i>=n1;i--)
	{
		printf("%d\n",a[i]);
	}
}


int main()
{
	int  n1,n2;
	//scanf("%d %d",&n1,&n2);
	char v1[5];
	char v2[5];
	char line[128];
	int lineNo=0;
	int *a;

	while(fgets(line,sizeof(line),stdin)!=NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		if(lineNo==0) n1=stoi(v1);
		else if(lineNo==1) n2=stoi(v1),a=(int *)malloc((n1+n2)*sizeof(int )),set(n1,n2);
		else if(strcmp(v1,"PSH")==0) push(n1,n2,stoi(v2),a);
		else if(strcmp("POPP",v1)==0) popp(a);
		else if(strcmp("POPN",v1)==0) popn(n1,a);
		else if(strcmp("PRTP",v1)==0) prtp(a);
		else if(strcmp("PRTN",v1)==0) prtn(a,n1);

			//printf("n1=%d n2=%d",n1,n2);

	lineNo++;	
	}
}
