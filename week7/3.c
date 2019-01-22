//start finish time
#include<stdio.h>
#include<stdlib.h>
//structure for linked list node
typedef struct createNode
{
	int value;
	struct createNode* next;
}createNode;
//structure for adj list
typedef struct adjList
{
	createNode* head;
}adjList;
//structure for graph
typedef struct graph
{
	int vertex;
	adjList* list;
}graph;
//function to create graph of given vertices and adj list corresponding to each vertex
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
//function to create a new node
createNode* newNode(int v)
{
	createNode* temp=malloc(sizeof(createNode));
	temp->value=v;
	temp->next=NULL;

	return temp;
}
//function to add a edge in graph
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

//struvture to keep track of visited vertex
typedef struct visited
{
	int v;
	int visit;	
}visited;

//structure to store start and finish time of a vertex in dfs
typedef struct finishTime
{
	int start;
	int finish;	
}finishTime;
//function to intialize all vertex visit=false
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
//function to intialize all finish and start time equal to zero
finishTime* intlTime(graph* Graph)
{
	finishTime* timing=malloc(Graph->vertex*sizeof(finishTime));
	for(int i=0;i<Graph->vertex;i++)
	{
		timing[i].start=0;
		timing[i].finish=0;	
	}
	return timing;
		
}
//global variable to keep track of clock
int clk=1;
//function explore to explore all the so far unvisited neighboutrs in each iter
void explore(int i, graph* Graph,visited* Visited,finishTime* timing)
{
	Visited[i].visit=1;
	//intial time when vertex i started exporing
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
	//this is the time when all the neighbours has been visited , so updating finish time of vertex i
	timing[i].finish=clk;
	clk++;
	
	
}
//function to implement dfs algo
finishTime* dfs(graph* Graph)
{	//call to intialize visit and finshTime functions
	visited* Visited=intlVisit(Graph);
	finishTime* timing=intlTime(Graph);
	//for each fub
	for(int i=0;i<Graph->vertex;i++)
	{
		if(Visited[i].visit==0)
		explore(i,Graph,Visited,timing);
	
		
	}
	return timing;
	
}
//function to print the start and finish time	
void printTime(graph* Graph,finishTime* timing)
{	//for each vertex i 
	for(int i=0;i<Graph->vertex;i++)
	{
		printf("%d/%d\n",timing[i].start,timing[i].finish);	
	}
}
//function to create char int into integer data type
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
	//input
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
	//calling dfs
	finishTime* timing=dfs(Graph);
	//calling print fn
	printTime(Graph,timing);
}


