//output is  the edges of the resulting unique bFS forest 𝐹
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
//structure to store distance
typedef struct distance
{
	int u;
	
	int* dist;
}distance;
//function to intilize all distances
distance* intlDist(graph* Graph,int x)
{
	

	distance* Distance=malloc(Graph->vertex*sizeof(distance));
	Distance->dist=malloc(Graph->vertex*sizeof(int));

	for(int i=0;i<Graph->vertex;i++)
	{	Distance[x].dist[i]=-1;
		if(i==x)
			Distance[x].dist[i]=0;
		
	}
	return Distance;
		
}


//for sorting purpose, my aim is to store each edge of bfs unique tree graph in a new structure bfs in sorted manner same as add edges in main graph

//structure to store edges of uniq forest bfs tree
typedef struct bfs
{	//same as graph structure
	int vertex;
	adjList* list;
}dfs;
//function to create uniq forest bfs tree
bfs* createBfs(int vertexs)
{	//same as intializing graph
	bfs* Bfs=malloc(sizeof(bfs));
	Bfs->vertex=vertexs;
	Bfs->list=malloc(vertexs*sizeof(adjList));
	for(int i=0;i<vertexs;i++)
	{
		Bfs->list[i].head=NULL;	
	}
	return Bfs;
}
//function to add edge of uniq forest dfs tree to above dfs structure
void addBfs(int u,int v,bfs* Bfs)
{	//same as adding edges to graph
	//printf("%d %d",u,v);
	createNode* current=Bfs->list[u].head;
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
		temp->next=Bfs->list[u].head;
		Bfs->list[u].head=temp;
			
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

//to deq a ele from queue
int dequeue(createNode** head)
{	int ans;
	createNode* temp=*head;
	if(temp->next==NULL)
	{
	*head=NULL;
	return temp->value;
	}
	createNode* prev=*head;
	while(temp->next)
	{	
		prev=temp;
		temp=temp->next;	
	}
	
	
	prev->next=NULL;
	ans=temp->value;
	//free(temp);
	return ans;
}

//function for printing
void printBfs(bfs* Bfs)
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

//function to implement dfs algorithm
void BFS(graph* Graph)
{	//create a uniq dfs forest graph to store it's edges

	dfs* Dfs=createDfs(Graph->vertex);
	visited* Visited=malloc(Graph->vertex *sizeof(visited));
	distance* Distance=intlDist(Graph,0);
	int u;
	adjList* queue=malloc(sizeof(adjList));
	queue->head=NULL;
	createNode* temp=newNode(0);
	//printf("2\n");	
	queue->head=temp;
	
	while(queue->head)
	{	//printf("3\n");
		
		u=dequeue(&queue->head);
		//printf("dq=%d\n",u);
		
		createNode* temp2=Graph->list[u].head;
		
		while(temp2)
		{	//printf("4\n");
			//return;
			if(Distance[0].dist[temp2->value]==-1){
			createNode* temp=newNode(temp2->value);
			temp->next=queue->head;
			queue->head=temp;
			//printf("enq=%d\n",queue->head->value);
			Distance[0].dist[temp2->value]=Distance[0].dist[u]+1;
			//printf("%d %d\n",u,temp2->value);
			addBfs(u,temp->value,Bfs);
			}
			temp2=temp2->next;

		
		}
	}
	
	//all vertexs have been visited, so now print it's dfs uniq tree
	printBfs(Bfs);
}

//function to convert int string in integer
	
int stoi(char *str)
{	int x;
	sscanf(str,"%d",&x);
	return x;
}

int main()
{
	char line[128];
	int vertex;
	int u,v;
	char a[5];
	char b[5];
	int lineNo=0;
	graph* Graph ;
	//taking inputs
	while(fgets(line,sizeof line, stdin)!=NULL)
	{	
		sscanf(line, "%s %s",a,b);
		u=stoi(a);
		v=stoi(b);
		//first line having number of vertex, creating graph
		if(lineNo==0)
		{
		vertex=u;
		Graph =createGraph(vertex);
		}
		//adding edges till EOF
		else
		addEdge(u,v,Graph);
		lineNo++;
	}
	
	//a call to dfs algorithm
	//printf("1\n");
	BFS(Graph);
	//printIt(Graph);
}


