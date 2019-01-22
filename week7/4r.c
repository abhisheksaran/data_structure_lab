#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int clk=0;
int pos=0;
typedef struct node
{
	int value;
	struct node* next;
}node;

typedef struct List
{
	node* head;
	int start;
	int end;
}List;

typedef struct Graph
{
	int vertex;
	List* list;
}Graph;

node* createNode(int a)
{
	node* new=(node*)malloc(sizeof(node));
	new->value=a;
	new->next=NULL;
	return new;
}

Graph* createGraph(int n)
{
	Graph* graph=(Graph*)malloc(sizeof(Graph));
	graph->vertex=n;
	graph->list=(List*)malloc(n*sizeof(List));
	for(int i=0;i<n;i++) graph->list[i].head=NULL,graph->list[i].start=0,graph->list[i].end=0;

	return graph;
}

void addEdge(Graph* graph,int u,int v)
{
	node* new=createNode(v);
	node* temp=graph->list[u].head;
	if(temp==NULL) graph->list[u].head=new;
	else
	{	node* prev=NULL;
		while(temp!=NULL&&temp->value<new->value) prev=temp,temp=temp->next;
		if(prev==NULL) new->next=temp, graph->list[u].head=new;
		else if(temp==NULL) prev->next=new;
		else prev->next=new, new->next=temp;
	} 
}

int stoi(char* str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}

int explore(Graph* graph,int i,int* vis,int* order)
{	clk++;
	graph->list[i].start=clk;
	vis[i]=1;
	node* temp=graph->list[i].head;
	int ans;
	while(temp)
	{
		if(vis[temp->value]==-1) 
		{ans=explore(graph,temp->value,vis,order);
		if(ans==-1)
		return -1;}
		
		else if(graph->list[i].start>graph->list[temp->value].start&&graph->list[temp->value].end==0 )
		return -1;
	temp=temp->next;
	}
	clk++;
	graph->list[i].end=clk;
	order[pos]=i;
	pos++;
	return 0;
}

void dfs(Graph* graph)
{
	int n=graph->vertex;
	int vis[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=-1;
	

	}

	int order[n];
	int ans;
	for(int i=0;i<n;i++)
	{
		if(vis[i]==-1) 
		ans=explore(graph,i,vis,order);
		if(ans==-1)
		{printf("-1\n");
		return;}
	}
	
	
	
	
	for(int i=n-1;i>=0;i--)
	{
		printf("%d ",order[i]);
	}
	
}




int main()
{
	char line[128];
	char v1[2];
	char v2[2];
	int lineNo=0;
	Graph* graph;
	while(fgets(line,sizeof(line),stdin))
	{
		sscanf(line,"%s %s",v1,v2);
		if(lineNo==0) graph=createGraph(stoi(v1));
		else addEdge(graph,stoi(v1),stoi(v2));
		lineNo++;
	}
	dfs(graph);
}
