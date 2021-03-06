#include<stdio.h>
#include<stdlib.h>
//linksed list node structure
typedef struct node{
	int value;
	struct node* next;
}node;
//adjancy list structure
typedef struct list{
	node* head;
}list;
//graph structure of vertex n and corresponding list
typedef struct graph{
	int vertex;
	list*  List;
}graph;


//function to make new linked list node of value a for adjancy list 
node* createNode(int a)
{
	node* new=(node*)malloc(sizeof(node));
	new->value=a;
	new->next=NULL;
	return new;	
}
//function for creating graph
graph* creategraph(int n)
{
	graph* Graph=(graph*)malloc(sizeof(graph));
	Graph->vertex=n;//graph of n vertex
	Graph->List=malloc(n*sizeof(list));// corresponding n adjancy lists
	for(int i=0;i<n;i++)
	{
		Graph->List[i].head=NULL;//intializing each list to be empty by pointing head to null	
	}
	return Graph;

}

//function to ADD edge (u,v)
void add(graph* Graph,int u, int v)
{	//creating new node of vertex v
	node* new=createNode(v);
	//adding this vertex to adjancy list of vetex u at the right pos so that whole list be in sorrted order
	node * temp=Graph->List[u].head;
	node* prev=NULL;
	//if adjancy list of u is empty just  make head =new
	if(Graph->List[u].head==NULL)
	{
		Graph->List[u].head=new;
		return;
	}
	//itherwise traverse through whole list till we find right pos ie pos of upper bound
	while(temp->value<new->value &&temp->next!=NULL)
	{	
		prev=temp;
		temp=temp->next;
		
	}
	//different conditions

	//if list have only one vertex
	if(prev==NULL)
	{
		if(temp->value<new->value)
		temp->next=new;	
		else
		{	new->next=temp;
			Graph->List[u].head=new;
		}
		return;	
	}
	//if we want to add in middle of of list somewhere
	if(temp->value>new->value)
	{
		
		new->next=temp;
		prev->next=new;	
		return;
	}
	//if upper bound is null , we have to add the ele at last in the list
	if(temp->next==NULL)
	{
		temp->next=new;
		return;
	}
}

//array implementaion of queue

//global variable to take care of queue starting and ending pos
int start=0;
int end=0;
//function enwq to insert ele at starting 
void enq(int * queue,int a)
{
	queue[start]=a;
	start++;
}
//function to deq most intially inserted IE from back
int deq(int * queue )
{	
	int ans=queue[end];
	end++;
	return ans;
		
}

//algo bfs to find out minm distance from a vertex a to z
void bfs(graph* Graph,int a,int z)
{	
	int n=Graph->vertex;
	int distance[n];
	//intl distances
	for(int i=0;i<n;i++)
	{
		
			if(i==a)
			distance[i]=0;//distance to itself 
			else
			distance[i]=-1;	//distance to every other vertex
	}
	//let a queue
	int queue[1000];
	enq(queue,a);
	//while this queue is not empty
	while(start!=end)
	{	//deq ele
		int u=deq(queue);
		node* temp=Graph->List[u].head;
		//for all the vertex whose distance from u is -1 
		while(temp!=NULL)
		{	
			if(distance[temp->value]==-1){
			
			enq(queue,temp->value);
			//for every vertex v such that (u,v) is an egde 
			//distance of (a to v)= (a to u)+1
			distance[temp->value]=distance[u]+1;}
			//next such vertex v
			temp=temp->next;
		}
	
	}
	//at the end, look at the sky,close the eyes and just print dist(u,v)
	printf("dist(%d,%d)=%d",a,z,distance[z]);
	
	//cheers!! you got that...
	
}

//as usual 
//function to convert int string into int 
int stoi(char a[10])
{
	int x;
	sscanf(a,"%d",&x);
	return x;
}
//i/o
int main()
{
	int n;
	
	char line[128];
	int lineNo=0;
	char v1[10];
	char v2[10];
	int a,z;
	graph* Graph;//intl the graph
	while(fgets(line,sizeof(line),stdin)!=NULL)
	{
		sscanf(line,"%s %s",v1,v2);
		if(lineNo==0)//first line have the number of vertex
		{n=stoi(v1);
		Graph=creategraph(n);}//make the graph of n vertex}
		else if(lineNo==1)//vertex i and j
		a=stoi(v1),z=stoi(v2);
		else 
		add(Graph,stoi(v1),stoi(v2));//add edge to graph

		lineNo++;
	}
	//run bfs on graph 
	bfs(Graph,a,z);
	//at the end of bfs print the desired output
	return 0;
}
