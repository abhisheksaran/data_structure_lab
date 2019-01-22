#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//linked list node
typedef struct node
{
	int value;
	struct node* next;
	
	
}node;
//list structure having pointer to it's head value
typedef struct list
{
	node* head;
}list;
//structure hash containing number of slots in hash table and linked list pointer
typedef struct hash
{
	int m;
	list* List;
}hash;
//function to create a function to return a linked list node
node* newNode(int a)
{
	node* temp=malloc(sizeof(node));
	temp->value=a;
	temp->next=NULL;
return temp;
}
//intilizing hash
hash* intlHash(int k)
{
	hash* Hash=malloc(sizeof(hash));
	Hash->m=k;//number of slots
	Hash->List=malloc(k*sizeof(list));//total m lists
	for(int i=0;i<k;i++)
	{
		Hash->List[i].head=NULL;//intially each list of hash slot is empty
	}
	return Hash;
}
//to insert a valur in hash fn
int insert(hash* Hash,int value)
{	//if number of slots is 0, not possible to insert
    if(Hash->m==0)
    {
        printf("-1\n");
        return 0;
    }//otherwise find out the slot of hash in which entry have to be entered
	int i=value%(Hash->m);
	node* new=newNode(value);//creating new node to add at the end of the ith slot's list
	node* temp=Hash->List[i].head;
	if(Hash->List[i].head==NULL)//if ith slot is empty, point head to it
	{
		Hash->List[i].head=new;
		return 0;	
	}
	while(temp->next!=NULL&&temp->value!=value)//adding at the end	if entry is not alredy inserted
	{
		temp=temp->next;
	}
	if(temp->value==value)//if there is already a same entry, printing -1, returning
	{	
		printf("-1\n");
		return 0;
	}
	

	temp->next=new;//finally adding at last 
	return 0;
	
}
//to print the ith slot of the hash
int print(hash* Hash,int i)
{	//if number of slot is equal to 0, there is nothing to print 
	if(Hash->m==0)
    	{
       	 	printf("-1\n");
        	return 0;
    	}
	
	node* temp=Hash->List[i].head;
	//if ith slot is empty or there is no ith slot then there is nothing to print so printing -1
	if(Hash->List[i].head==NULL||i>=(Hash->m))
	{
		printf("-1\n");
		return 0;	
	}
	//otherwise print the whole slot in the oreder of their insert time ie first to last
	while(temp)
	{
		printf("%d ",temp->value);
		temp=temp->next;	
	}
	printf("\n");
	return 0;
}
//to del a entry in  a hash
int del(hash* Hash,int x)
{//if number of slot is equal to 0, there is nothing to dlt 
    if(Hash->m==0)
    {
        printf("-1\n");
        return 0;
    }	
	//finding the slot where possibly key can be
	int i=x%(Hash->m);
	node* temp=Hash->List[i].head;
	//if ith slot is empty ie key is not in hash, return -1 or print -1 then return
	if(Hash->List[i].head==NULL)
	{
		printf("-1\n");
		return 0;	
	}
	node* prev=Hash->List[i].head;
	//traverse through list of ith slot till we found key
	while(temp->next!=NULL&&temp->value!=x)
	{	
		prev=temp;
		temp=temp->next;	
	}
	//if found make the link between prev and next
	if(Hash->List[i].head->value==x)//key found at Ist place
	{
		Hash->List[i].head=temp->next;
	}
	else if(temp->next==NULL&&temp->value==x)//key found at last place
	prev->next=NULL;
	//we reached at the end of the list but key hasn't found, ie , key is not there, printing -1
	else if(temp->next==NULL)
	{
		printf("-1\n");
		return 0;	
	}
	else//key found at any intermediate place
	{
		prev->next=temp->next;	
	}
	return 0;
}
//searchinf for a key
void search(hash* Hash,int x)
{	//if number of slot is equal to 0, there is nothing to search
    if(Hash->m==0)
    {
        printf("N\n");
        return ;
    }
	//finding the slot where possibly key can be
	int i=x%(Hash->m);	
	node* temp=Hash->List[i].head;
	//traverse through list of ith slot till we found key
	while(temp)
	{
		if(temp->value==x)
		{
			printf("Y\n");//if found print 'Y'
			return;	
		}
		temp=temp->next;	
	}
	printf("N\n");//not found print 'N'
	return;	
}
//function to convert integer string into inteager
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

int main()
{	//input/output
	char a[10];
	char b[10];
	char line[128];
	int lineNo=0;
	hash* Hash;
	while(fgets(line, sizeof line, stdin) != NULL )
	{
		sscanf(line,"%s %s",a,b);
		if(lineNo==0)
		{
			Hash=intlHash(stoi(a));	//intlizing hash with value of m		
		}
		else if(strcmp(a,"PRT")==0)//to print
		print(Hash,stoi(b));
		else if(strcmp(a,"INS")==0)//to insert
		insert(Hash,stoi(b));
		else if(strcmp(a,"DEL")==0)// to dlt a key
		del(Hash,stoi(b));
		else if(strcmp(a,"SRCH")==0)//to search a key
		search(Hash,stoi(b));
		else 
		printf("INVALID\n");
		
		lineNo++;
	}
}
