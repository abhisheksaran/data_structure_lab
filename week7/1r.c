#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int value;
	struct node* next;
}node;

typedef struct List
{
	node* head;
}List;

typedef struct graph
{
	int vertex;
	List* list;
	
}graph;

node* createNode(int i)
{
	node* new=(node*)malloc(sizeof(node));
	new->value=i;
	new->next=NULL;

	return new;
}

graph* createGraph(int n)
{
	graph* Graph=(graph*)malloc(sizeof(graph));
	Graph->vertex=n;
	Graph->list=(List*)malloc(n*sizeof(List));
	for(int i=0;i<n;i++)
	{
		Graph->list[i].head=NULL;
	}

	return Graph;
}

void addedge(graph* Graph,int u,int v)
{
	node* temp=Graph->list[u].head;
	node* new=createNode(v);
	if(temp==NULL)
	Graph->list[u].head=new;
	else
	{	node* prev=NULL;
		while(temp!=NULL&&temp->value<new->value) prev=temp,temp=temp->next;
		if(prev==NULL) new->next=temp, Graph->list[u].head=new;
		else if(temp!=NULL&&temp->value>new->value) new->next=temp,prev->next=new;
		else prev->next=new;
	}

}
void print(graph* Graph)
{
	for(int i=0;i<Graph->vertex;i++)
	{
		node* temp=Graph->list[i].head;
		while(temp) printf("%d$",temp->value), temp=temp->next;
		if(!Graph->list[i].head) printf("$");
		printf("\n");
	}
}

int stoi(char* str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}
int main()
{
	graph* Graph;
	//int n;
	//int u,v;
	char line[128];
	char v1[2];
	char v2[2];
	int lineNo=0;
	while(fgets(line,sizeof(line),stdin)!=NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		if(lineNo==0) Graph=createGraph(stoi(v1));
		else 
		{
			addedge(Graph,stoi(v1),stoi(v2));
			
		}
	//printf("%d %d\n",stoi(v1),stoi(v2));
	lineNo++;
	}
	print(Graph);
}
