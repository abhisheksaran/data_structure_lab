#include<stdio.h>
#include<stdlib.h>
//global variable to keep track of queue's front and back position
int front=0;
int back=1;

//structure for linked list node
typedef struct createNode
{
	int value;
	struct createNode* next;
}createNode;
//function to create a new node which returns pointer to it.
createNode* newNode(int v)
{
	createNode* temp=(createNode*)malloc(sizeof(createNode));
	temp->value=v;
	temp->next=NULL;
	return temp;	
}
//structure to pointer to adj list
typedef struct adjList
{
	createNode* head;	
}adjList;
//structure graph having n vertices and adj lists;
typedef struct graph
{
	int n;
	adjList* list;
}graph;
//functio to crate graph of n vertices and n adj lists
graph* intializeGraph(int vertex)
{
	graph* Graph=malloc(sizeof(graph));
	Graph->n=vertex;
	Graph->list=malloc(vertex*sizeof(adjList));
	//intializing all adj lists empty
	for(int i=0;i<vertex;i++)
	{
		Graph->list[i].head=NULL;	
	}
	return Graph;
}
//function to add edge
void addEdge(graph* Graph,int u,int v)
{
	createNode* temp=newNode(v);
	createNode* current=Graph->list[u].head;
	createNode* prev=NULL;
	while(current!=NULL && current->value<temp->value)
	{
		prev=current;
		current=current->next;
	}   	
	if(prev==NULL)
	{	
		temp->next=Graph->list[u].head;
		Graph->list[u].head=temp;	
	}
	else if(current ==NULL)
	{
		prev->next=temp;
	}
	else
	{
		temp->next=current;
		prev->next=temp;		
	}
	
}





//structure to store distances
typedef struct distance
{

	int *dist;
	
}distance;
//intialize all distances to -1 except with itself=0
distance* intlDistance(graph* Graph)
{	//a array of n vertices in which ith ele shows the distances from vertex i
	distance* Distance=(distance*)malloc(Graph->n*sizeof(distance));
	
	for(int i=0;i<Graph->n;i++)
	{	//i th ele have n memberes array associated with it in which entry i,j shows distance of i to j'
		Distance[i].dist=(int *)malloc(Graph->n*sizeof(int));
 		for(int j=0;j<Graph->n;j++)
		{
			Distance[i].dist[j]=-1;	
			if(i==j)
			{
				Distance[i].dist[j]=0;
			}
		}	
	}
	return Distance;
}
//function to insert ele at back in queue
void enqueue(int *queue,int value)
{
		queue[back]=value;
		back++;
}
//function to deq ele from front in queue
int dequeue(int *queue)
{
		int a=queue[front];
		front++;
		return a;
	
}
//function to implement algorithm bfs	
distance* algoBfs(graph* Graph,int s)
{
	distance* Distance=intlDistance(Graph);	
	int queue[1000];
	//want to find distances from s
	queue[0]=s;
	//while queue is empty
	while(front!=back)
	{	//deq ele
		int u=dequeue(queue);
		createNode* temp=Graph->list[u].head;
		//for all it's neighbours which are unvisited, update distances
		while(temp!=NULL)
		{	
			if(Distance[s].dist[temp->value]==-1)
			{	//yet unvisited , enq it's value
				enqueue(queue,temp->value);
				//update distances of child from s =distances of parent from s+1
				Distance[s].dist[temp->value]=Distance[s].dist[u]+1;
				//as graph is indirc so dist(i,j)=dist(j,i)
				Distance[temp->value].dist[s]=Distance[s].dist[temp->value];
			}
			//next neighbour		
			temp=temp->next;
		}
		
	}
	return Distance;
}
//print function the output
void printIt(graph* Graph,distance* Distance,int s,int k)
{	
	for(int i=0;i<Graph->n;i++)
	{	//print all the vertex number which is at most =k from s and obviously reachable 
		if(Distance[s].dist[i]<=k&&Distance[s].dist[i]!=-1)
		printf("%d ",i);
	}
	
}

//to convert int string in integer
int stoi(char* string)
{
	int a;
	sscanf(string,"%d",&a);
	return a;
}

int main()
{	//input number of vertex,s and k
	int vertex;
	scanf("%d",&vertex);
	graph* Graph=intializeGraph(vertex);
	int s;
	int k;
	scanf("%d %d\n",&s,&k);
	char a[2];
	char b[2];
	int lineNo=0;
	char line[5];
	int u,v;
	//input edge a and b as string
	while(fgets(line,sizeof(line),stdin))
	{
		sscanf(line,"%s %s",a,b);
                u=stoi(a);
		v=stoi(b);
		//as it's undirc graph an edge u,v also means edge v to u.
		addEdge(Graph,u,v);
		addEdge(Graph,v,u);
		lineNo++;	
	}
	//RUNNING BFS AND GETTING DISTANCES
	distance* Distance=algoBfs(Graph,s);
	//PRIUNTING THE REQUIRED OUTPUT FROM DISTANCES
	printIt(Graph,Distance,s,k);
	printf("\n");
	
}
