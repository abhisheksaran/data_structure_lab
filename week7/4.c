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
	//to find if their a backEdge exists
	int backEdge;	
}visited;


typedef struct finishTime
{	
	int vertex;
	int start;
	int finish;	
}finishTime;

visited* intlVisit(graph* Graph)
{
	visited* Visited=malloc(Graph->vertex*sizeof(visited));
	for(int i=0;i<Graph->vertex;i++)
	{
		Visited[i].v=i;
		Visited[i].visit=0;
		Visited[i].backEdge=0;	
	}
	return Visited;
		
}

finishTime* intlTime(graph* Graph)
{
	finishTime* timing=malloc(Graph->vertex*sizeof(finishTime));
	for(int i=0;i<Graph->vertex;i++)
	{
		timing[i].vertex=i;
		timing[i].start=0;
		timing[i].finish=0;	
	}
	return timing;
		
}
//to print the vertices in topological order
void printTime(graph* Graph,finishTime* timing)
{	//sorting the vertices in incr order acc to their finish time by insertion sort 
	for(int i=1;i<Graph->vertex;i++)
	{	int temp=timing[i].finish;
		int temp2=timing[i].vertex;
		int j=i-1;
		while(j>=0&& timing[j].finish>temp)
		{
			timing[j+1].finish=timing[j].finish;
			timing[j+1].vertex=timing[j].vertex;
			j--;
			
		}
		timing[j+1].finish=temp;
		timing[j+1].vertex=temp2;
	}
	//now printing the vertices in decr order of their finish time
	for(int i=Graph->vertex-1;i>=0;i--)
	{
		printf("%d ",timing[i].vertex);	
	}
	printf("\n");
}
  
int clk=1;
int explore(int i, graph* Graph,visited* Visited,finishTime* timing)
{	int ans=0;
	Visited[i].visit=1;
	//we have set the backEdge variable to zero
	Visited[i].backEdge=1;
	timing[i].start=clk;
	clk++;
	createNode* temp=Graph->list[i].head;
	while(temp)
	{	//if we found backedge 1, means it's it's their exist a backedge between prev temp and temp 
		if(Visited[temp->value].backEdge==1)
		{

			return -1;
		}
		
		if(Visited[temp->value].visit==0)
		{
			
			ans=explore(temp->value,Graph,Visited,timing);
			if(ans==-1)
			return -1;
		}	
		//whenever we go backtrack we have to make backEdge again 0 so that we can eliminate cross edges		

		//if there is no element further backtrack
		if(temp->next==NULL)
		Visited[i].backEdge=0;
		// and if next value is visited backtrack
		else if(Visited[temp->next->value].visit==1)
		Visited[temp->next->value].backEdge=0;

		temp=temp->next;
	}
	
	
	timing[i].finish=clk;
	clk++;
	return 0;
	
}
finishTime* dfs(graph* Graph)
{	
	visited* Visited=intlVisit(Graph);
	finishTime* timing=intlTime(Graph);
	int ans=0;;
	for(int i=0;i<Graph->vertex;i++)
	{	//intializing that there is no back edge
		for(int j=0;j<Graph->vertex;j++)
		{
			Visited[j].backEdge=0;
		}

		if(Visited[i].visit==0)
		ans=explore(i,Graph,Visited,timing);
		//if there is a backEdge print -1
		if(ans==-1)
		{
			printf("-1\n");
			break;	
		}
		visited* Visited=intlVisit(Graph);
		
	}
	//if there in no back egde found, print vertices in topological order
	if(ans==0)
	printTime(Graph,timing);

	return timing;
	
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
	
}


