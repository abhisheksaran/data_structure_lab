//output is  the edges of the resulting unique DFS forest 𝐹
#include<stdio.h>
#include<stdlib.h>
//structure linked list node
typedef struct createNode
{
	int value;
	struct createNode* next;
}createNode;
//structure adjlist of a vertex
typedef struct adjList
{
	createNode* head;
}adjList;
//structure graph containg adj list and total number of vertex
typedef struct graph
{
	int vertex;
	adjList* list;
}graph;
//function to create graphs of total no of vertex='vertexes' 
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
//function to add edge same as prev q
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


//structure to see if a vertex is already visited or not
typedef struct visited
{
	int v;
	int visit;	
}visited;
//function to intilize all visited=false
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


//for sorting purpose, my aim is to store each edge of dfs unique tree graph in a new structure dfs in sorted manner same as addinf edges in main graph

//structure to store edges of uniq forest dfs tree
typedef struct dfs
{	//same as graph structure
	int vertex;
	adjList* list;
}dfs;
//function to create uniq forest dfs tree
dfs* createDfs(int vertexs)
{	//same as intializing graph
	dfs* Dfs=malloc(sizeof(dfs));
	Dfs->vertex=vertexs;
	Dfs->list=malloc(vertexs*sizeof(adjList));
	for(int i=0;i<vertexs;i++)
	{
		Dfs->list[i].head=NULL;	
	}
	return Dfs;
}
//function to add edge of uniq forest dfs tree to above dfs structure
void addDfs(int u,int v,dfs* Dfs)
{	//same as adding edges to graph
	createNode* current=Dfs->list[u].head;
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
		temp->next=Dfs->list[u].head;
		Dfs->list[u].head=temp;
			
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
//dfs explore function
dfs* explore(visited* Visited, graph* Graph,int i,dfs* Dfs)
{	//make visit=true
	Visited[i].visit=1;
	createNode* temp=Graph->list[i].head;
	//see it's all neighbours
	while(temp!=NULL)
	{	//if not visited explore it
		if(Visited[temp->value].visit==0)
		{
			//and add this edge between i and it's neighbour(temp->value) to uniq dfs forest structure
			addDfs(i,temp->value,Dfs);
			explore(Visited,Graph,temp->value,Dfs);	
		}
		//move to next neighbour	
		temp=temp->next;
	}
	return Dfs;
	
}
//function to implement dfs algorithm
void DFS(graph* Graph)
{	//create a uniq dfs forest graph to store it's edges
	dfs* Dfs=createDfs(Graph->vertex);
	visited* Visited=malloc(Graph->vertex *sizeof(visited));
	//calling intiVisit to set all false
	Visited=intlVisit(Graph)
	//for all vertexs
	for(int i=0;i<Graph->vertex;i++)
	{	//id not alredy visited ,explore
		if(Visited[i].visit==0)
		{
			explore(Visited,Graph,i,Dfs);	
		}
	}
	
	//all vertexs have been visited, so now print it's dfs uniq tree
	printDfs(Dfs);
}
//function for printing
void printDfs(dfs* Dfs)
{	//for all vertexs
	for(int i=0;i<Dfs->vertex;i++)
	{
		createNode* temp=Dfs->list[i].head;
		//printinf all it's neighbours
		while(temp)
		{
			printf("(%d,%d)\n",i,temp->value);
			temp=temp->next;
			
		}	
			
	}
}
//function to convert int string in integer	
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
				
		}
		else	
		{
			addEdge(u,v,Graph);
		}
		
		lineNo++;
			
	}
	//a call to dfs algorithm
	DFS(Graph);
}


