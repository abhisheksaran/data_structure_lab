#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int value;
	int visited;
	struct node* next;
}node;

typedef struct List
{
	node* head;
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
	new->visited=-1;
	new->next=NULL;
	return new;
}

Graph* createGraph(int n)
{
	Graph* graph=(Graph*)malloc(sizeof(Graph));
	graph->vertex=n;
	graph->list=(List*)malloc(n*sizeof(List));
	for(int i=0;i<n;i++) graph->list[i].head=NULL;

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
{
	vis[i]=1;
	node* temp=graph->list[i].head;
	while(temp)
	{
		if(vis[temp->value]==-1) temp->visited=1,explore(graph,temp->value,vis);
	temp=temp->next;
	}
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
		node* temp=graph->list[i].head;
		while(temp){
			if(temp->visited==1)
			printf("(%d,%d)\n",i,temp->value);
			temp=temp->next;	
		}
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
