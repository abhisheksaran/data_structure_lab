#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//structure to make a tree node
typedef struct createNode
{
	int value;
	struct createNode* left;
	struct createNode* right;
}createNode;
//function to create a new node	
createNode* newNode(int v)
{
	createNode* temp=(createNode*)malloc(sizeof(createNode));
	temp->value=v;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

createNode* insert(createNode** head,int a)
{
	if(*head==NULL)
	{	*head=newNode(a);
		return *head;
	}
	
	createNode* temp=*head;
	createNode* prev=NULL;
	while(temp)
	{
		if(a<temp->value)
		{	prev=temp;
			temp=temp->left;
		}
		else
		{
			prev=temp;
			temp=temp->right;
	
		}
	}
	//printf("*%d\n",prev->value);
	if(a<prev->value)
	{
		prev->left=newNode(a);
	}
	else
		prev->right=newNode(a);
	

	return *head;
	
}
//printinf preorder
void preorder(createNode** head)
{	
	createNode* temp=*head;
	//if there is no ele
	if(temp==NULL)
	return;
	//parent first
	printf("%d ",temp->value);
	//left then
	if(temp->left!=NULL)
	preorder(&temp->left);
	//right at last
	if(temp->right!=NULL)
	preorder(&temp->right);
	
}
//printinf preorder

void postorder(createNode** head)
{
	createNode* temp=*head;
	//if there is no ele
	if(temp==NULL)
	return;
	//left first
	if(temp->left!=NULL)
	postorder(&temp->left);
	//then right
	if(temp->right!=NULL)
	postorder(&temp->right);
	//last parent
	printf("%d ",temp->value);
	
}

//printing inorder
void inorder(createNode** head)
{
	createNode* temp=*head;
	//if there is no ele
	if(temp==NULL)
	return;
	//left first
	if(temp->left!=NULL)
	inorder(&temp->left);
	//then parent 
	printf("%d ",temp->value);
	//right at last
	if(temp->right!=NULL)
	inorder(&temp->right);
	
}
//TO STORE INORDER 
int i=0;
void inorderArray(createNode** head,int **a)
{
	createNode* temp=*head;
	if(temp==NULL)
	return;

	if(temp->left!=NULL)
	inorderArray(&temp->left,a);
	
	*(*a+i)=temp->value;

	i++;
	if(temp->right!=NULL)
	inorderArray(&temp->right,a);
	
}
//to search a key and returning pointer to it,if doesn't exist return NULL
createNode* search(createNode** head,int k)
{
	createNode* temp=*head;
	createNode* temp3;
	//if there is no subtree of it 
	if(temp==NULL)
	return NULL;
	//if it'a value has been found at temp return temp 
	if(temp->value==k)
	{
		
		return temp;	
	}
	//key is less then temp then possibly be in it's left child
	if(k<temp->value)
	{	//if found, return pointer to it
		temp3=search(&temp->left,k);
		if(temp3!=NULL)
		return temp3;
	}
	//key is greater then temp then possibly be in it's right child
	else
	{
		//if found, return pointer to it
		temp3=search(&temp->right,k);
		if(temp3!=NULL)
		return temp3;
	}
	
	
	
}
//search parent of a given key and return pointer to it's node if exists
createNode* search_parent(createNode** head,int k)
{
	createNode* parent=*head;
	createNode* temp3;
	//if empty return null
	if(parent==NULL )
	return NULL;
	//if it's head then parent doesn't exist
	if(parent->value==k)
	return NULL;
	//rest is same as search
	if(parent->left!=NULL&& parent->left->value==k)
	{
		return parent;	
	}

	if(parent->right!=NULL&& parent->right->value==k)
	{
		
		return parent;	
	}
	
	if(k<parent->value)
	{
		
		temp3=search_parent(&parent->left,k);
		if(temp3!=NULL)
		return temp3;
	}
	else
	{	
		temp3=search_parent(&parent->right,k);
		if(temp3!=NULL)
		return temp3;
	}
	
	
	
}
//here comes the inmportant part
int dlt(createNode** head,int x,int *a)
{			
	//tree is empty
	if(*head==NULL)
	return -1;
	//storing inorder to find out succesor of x 
	inorderArray(&*head,&a);
	int j=0;
	int succr_value;
	while(a[j]!=x&&j<1000)
	{
		j++;	
	}
	//if key doesn't exist return -1
	if(j==1000)
	return -1;
	//o/w it will just come after x in inoder
	succr_value=a[j+1];
	//poniter to x
	createNode* temp=search(&*head,x);
	//pointer to succr
	createNode* succr=search(&*head,succr_value);
	//parent of x
	createNode* parent=search_parent(&*head,x);
	//parent of successor
	createNode* parent_succr=search_parent(&*head,succr_value);
	
	//if key have no ele in right part, then making connection between it's parent and it's left child
	if(temp->right==NULL)
	{
		if(temp==*head)
		{
			*head=temp->left;
			return 0;		
		}
		if(parent->left==temp)
		parent->left=temp->left;
		else if(parent->right==temp)
		parent->right=temp->left;
	}
	//if key have no ele in left part, then making connection between it's parent and it's right child
	else if(temp->left==NULL)
	{
		if(temp==*head)
		{
			*head=temp->right;
			return 0;		
		}
		if(parent->left==temp)
		parent->left=temp->right;
		else if(parent->right==temp)
		parent->right=temp->right;
	}
	//if key have  both the children,replace it with it's succsor
	else
	{
		temp->value=succr->value;
		//if parent of succssor is key , ie succr don't have any right child , and , key is left of it's parent , link parent's left and succr's right
		if(parent_succr!=temp)
		parent_succr->left=succr->right;
		//else means key is left of it's parent,link parent's right and succr's right
		else 
		parent_succr->right=succr->right;
	}
	//why we in both cases linked to succr's right child->> if key has both the children then succr can't have it's left child o/w that will become succr of key.
	return 0;
}
//function to convert int string in int
int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}
// i/o main
int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];
    char v4[15];

    int a[1000]={-1};
    int ret;
    int lineNo = 0;
    int n;	
    int nn;
    createNode* ans;
    createNode* head=NULL;
 //rest is history
    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s", v1, v2);
        lineNo++;

   
	
        if(strcmp(v1,"INS") == 0)
        {
		if(search(&head,stoi(v2))==NULL)
            head = insert(&head, stoi(v2));
     
	}
	else if(strcmp(v1,"PRE") == 0)
        {
           preorder(&head);
            printf("\n");
        }
        else if(strcmp(v1,"PST") == 0)
        {
            postorder(&head);
            printf("\n");
        }
        else if(strcmp(v1,"INO") == 0)
        {
             inorder(&head);
             printf("\n");
		i=0;
        }
	else if(strcmp(v1,"DEL") == 0)
        {
            ret=dlt(&head,stoi(v2),a);
           if(ret < 0)
                printf("%d\n", -1);
	 
        }
	else if(strcmp(v1,"SER") == 0)
        {
            ans=search(&head,stoi(v2));
           if(ans==NULL)
                printf("N\n");
	    else
		printf("Y\n");
	 
        }
        else
        {
            printf("INVALID\n");
        }
    }

   
    return 0;
}
