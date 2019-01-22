#include<stdio.h>
#include<stdlib.h>
 
typedef struct createNode
{
	int value;
	struct createNode* next;
}createNode;

typedef struct adjList
{
	createNode* head;
}adjList;

typedef struct graph
{
	int vertex;
	adjList* list;
}graph;

graph* createGraph(int vertexs)
{
	graph* Graph=malloc(sizeof(graph));
	Graph->vertex=vertexs;
	Graph->list=malloc(vertexs*sizeof(adjList));
	for(int i=0;i<vertexs;i++)
	{
		Graph->list[i].head=NULL;	
	}
	return Graph;
}

createNode* newNode(int v)
{
	createNode* temp=malloc(sizeof(createNode));
	temp->value=v;
	temp->next=NULL;

	return temp;
}

void addEdge(int u,int v,graph* Graph)
{
	createNode* current=Graph->list[u].head;
	createNode* prev=NULL;
	createNode* temp=newNode(v);
	while(current)
	{
		if(temp->value<current->value)
		break;
		prev=current;
		current=current->next;	
	}
	if(prev==NULL)
	{
		temp->next=Graph->list[u].head;
		Graph->list[u].head=temp;
			
	}
	else if(current==NULL)
	{
		prev->next=temp;	
	}
	else
	{
		prev->next=temp;
		temp->next=current;	
	}
}


typedef struct visited
{
	int v;
	int visit;	
}visited;


typedef struct finishTime
{
	int start;
	int finish;
	int vertex;	
}finishTime;

visited* intlVisit(graph* Graph)
{
	visited* Visited=malloc(Graph->vertex*sizeof(visited));
	for(int i=0;i<Graph->vertex;i++)
	{
		Visited[i].v=i;
		Visited[i].visit=0;	
	}
	return Visited;
		
}

finishTime* intlTime(graph* Graph)
{
	finishTime* timing=malloc(Graph->vertex*sizeof(finishTime));
	for(int i=0;i<Graph->vertex;i++)
	{
		timing[i].start=0;
		timing[i].finish=0;
		timing[i].vertex=i;	
	}
	return timing;
		
}
int clk=1;
void explore(int i, graph* Graph,visited* Visited,finishTime* timing)
{
	Visited[i].visit=1;
	timing[i].start=clk;
	clk++;
	createNode* temp=Graph->list[i].head;
	while(temp)
	{	
		if(Visited[temp->value].visit==0)
		{
			
			explore(temp->value,Graph,Visited,timing);
			
		}	
		temp=temp->next;
	}
	timing[i].finish=clk;
	clk++;
	
	
}
finishTime* dfs(graph* Graph)
{	
	visited* Visited=intlVisit(Graph);
	finishTime* timing=intlTime(Graph);
	for(int i=0;i<Graph->vertex;i++)
	{
		if(Visited[i].visit==0)
		explore(i,Graph,Visited,timing);
	
		visited* Visited=intlVisit(Graph);
		
	}
	return timing;
	
}
	
finishTime* decrOrdr(graph* Graph,finishTime* timing)
{	
	for(int i=1;i<Graph->vertex;i++)
	{	int temp=timing[i].finish;
		int temp2=timing[i].vertex;
		int j=i-1;
		while(j>=0&& timing[j].finish<temp)
		{
			timing[j+1].finish=timing[j].finish;
			timing[j+1].vertex=timing[j].vertex;
			j--;
			
		}
		timing[j+1].finish=temp;
		timing[j+1].vertex=temp2;

	}
	return timing;

	for(int i=0;i<Graph->vertex;i++)
	{
		printf("%d/%d\n",timing[i].vertex,timing[i].finish);	
	}
}

void strngConnected(graph* rGraph)
{
	finishTime* timing=dfs(rGraph);
	finishTime* timing=decrOrdr(rGraph,timing);
	
}

int stoi(char *str)
{	int x;
	sscanf(str,"%d",&x);
	return x;
}

int main()
{
	char line[4];
	char a[2];
	char b[2];
	int u,v;
	int vertex;
	int lineNo=0;
	graph* Graph;
	graph* rGraph;

	while(fgets(line, sizeof(line),stdin))
	{
		sscanf(line,"%s %s",a,b);
		u=stoi(a);
		v=stoi(b);

		if(lineNo==0)
		{
			Graph=createGraph(u);
			rGraph=createGraph(u);
				
		}
		else	
		{
			addEdge(u,v,Graph);
			addEdge(v,u,rGraph);
		}
		
		lineNo++;
			
	}
	strngConnected(rgraph);
}


