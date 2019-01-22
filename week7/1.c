//creating adj list of a directed graph
#include<stdio.h>
#include<stdlib.h>
//structure for linked list node
typedef struct createNode
{
	int value;
	struct createNode* next;
}createNode;
//structure for adj list containing address to it's head pointer
typedef struct adjList
{
	createNode* head;
}adjList;
//structure graph haing a vertex and it's corresponding adj list  
typedef struct graph
{
	int vertex;
	adjList* list;
}graph;
//function to create a new node 
createNode* newNode(int v)
{
	createNode* temp=malloc(sizeof(createNode));
	temp->value=v;
	temp->next=NULL;
	return temp;
}
//function to create graph
graph* createGraph(int vertex)
{
	graph* Graph=malloc(sizeof(graph));
	//graph having a total number of vertex=vertex 
	Graph->vertex=vertex;
	//graph having 'vertex' number of adj lists where i(th) adj list is adj list corresponding to i(th) vertex
	Graph->list=malloc(vertex*sizeof(adjList));
	//intializing head of adj list of each vertex to NULL;
	for(int i=0;i<vertex;i++)
	{
		createNode* temp=Graph->list[i].head;
		temp=NULL;	
	}
	
	return Graph;	
}

//function to add edge to graph
void addEdge(int u,int v,graph* Graph)
{	//creating new node
	createNode* temp=newNode(v);

	createNode* current=Graph->list[u].head;
	createNode* prev=NULL;	
	//treverse through the adj list of u till we get a greater vertex
	while(current!=NULL  )
	{	if(current->value > temp->value)
		break;
		prev=current;
		current=current->next;
			
	}
	//condition for empty adj list ie to add at start
	if(prev==NULL)
	{
		temp->next=Graph->list[u].head;
		Graph->list[u].head=temp;
		
	}
	//condition if we are adding the greatest number ie at the end
	else if(current==NULL)
	{
		prev->next=temp;
	}
	//o/w we have to add new node b/w pre and current
	else
	{
		prev->next=temp;
		temp->next=current;	
	}

	
}
//function to print the graph
void printIt(graph* Graph)
{	//for each vertex
	for(int i=0;i<Graph->vertex;i++)
	{	//for each vertex traverse through whole list
		createNode* temp=Graph->list[i].head;
		while(temp)
		{
			printf("%d$",temp->value);
			temp=temp->next;	
			
		}
		//if there is no edge starting from a particular vertex
		if(Graph->list[i].head==NULL)
		{
			printf("$");	
		}
		printf("\n");	
	}
}
//function to convert int string into integer
int stoi(char* str)
{
	int x;
	sscanf(str,"%d",&x);
	return x;
}




int main()
{	char line[128];
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
	//printing the adj list of each vertex in sorted order
	printIt(Graph);

}

