#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int clk=0;
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

void explore(Graph* graph,int i,int* vis)
{	clk++;
	graph->list[i].start=clk;
	vis[i]=1;
	node* temp=graph->list[i].head;
	while(temp)
	{
		if(vis[temp->value]==-1) explore(graph,temp->value,vis);
	temp=temp->next;
	}
	clk++;
	graph->list[i].end=clk;
}

void dfs(Graph* graph)
{
	int n=graph->vertex;
	int vis[n];
	for(int i=0;i<n;i++)
	{
		vis[i]=-1;
	

	}

	
	for(int i=0;i<n;i++)
	{
		if(vis[i]==-1) explore(graph,i,vis);
	}
	

	for(int i=0;i<n;i++)
	{
		printf("%d/%d\n",graph->list[i].start,graph->list[i].end);
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
