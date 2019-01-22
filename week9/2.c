#include<stdio.h>
#include<stdlib.h>
//structure for a tree node
typedef struct createNode
{
	int value;
	struct createNode* left;
	struct createNode* right;
}createNode;
//structure for a pointer name parent to a tree node
typedef struct parent
{
	createNode* parent;
}parent;

//intializing  tree with value as root and left, right =NULL
createNode* intlizeTree(int data)
{
	createNode* head=(createNode*)malloc(sizeof(createNode));
	head->value=data;
	head->left=NULL;
	head->right=NULL;
	return head;	
}
//creating a function to create the rest of the tree
void createTree(int data, createNode** head)
{	//pointer to root
	createNode* temp=*head;
	//till we got a empty entry
	while(temp->left!=NULL&&temp->right!=NULL)	
	{	//our first priority is to fill left 
		//so if a parent's left 's either left or right is empty go toward it 
		if(temp->left->left==NULL||temp->left->right==NULL)
		temp=temp->left;
		//if we reached here means left is fulfilled so we will see right
		else
		temp=temp->right;
		
	}
	//if we come out of while loop beacause of both left and right is NULL or only left is NULL, fill the entry in left 
	if(temp->left==NULL)
	{	createNode* temp2;
		temp2=(createNode*)malloc(sizeof(createNode));
		temp2->value=data;
		temp2->left=NULL;
		temp2->right=NULL;
		temp->left=temp2;
		
	}
	//if we reach here means left is full and right is empty so fill in the values 
	else if(temp->right==NULL)
	{
		createNode* temp2;
		temp2=(createNode*)malloc(sizeof(createNode));
		temp2->value=data;
		temp2->left=NULL;
		temp2->right=NULL;
		temp->right=temp2;
					
	}
}
//function to print inorder ie first left then parent then right
void inorder(createNode** head)
{
	createNode* temp=*head;
	//if root is the only member in print it
	if(temp->left==NULL&&temp->right==NULL)
		printf("%d ",temp->value);
	//if root is the only member in print it
	if(temp->left==NULL&&temp->right!=NULL)
	{
		printf("%d ",temp->value);
		inorder(&temp->right);
	}	
	//if right is NULL but left not,  print inorder of left then print parent
	if(temp->left!=NULL&&temp->right==NULL)
	{
		inorder(&temp->left);
		printf("%d ",temp->value);	
	}
	//if both is not NULL, print inorder of left Then print parent then print inorder of right
	if(temp->left!=NULL&&temp->right!=NULL)
	{
		inorder(&temp->left);
		printf("%d ",temp->value);
		inorder(&temp->right);	
	}
	
}
//function to print inorder ie first parent then left then right
void preorder(createNode** head)
{
	createNode* temp=*head;
	//if head is not NULL print it as it is parent
	if(temp!=NULL)
		printf("%d ",temp->value);
	//if left is NULL but right not,print preorder of right
	if(temp->left==NULL&&temp->right!=NULL)
	{
		
		preorder(&temp->right);
	}	
	//if right is NULL but left not, print preorder of left
	if(temp->left!=NULL&&temp->right==NULL)
	{
		preorder(&temp->left);
		
	}
	//if both is not NULL, first print preorder of left then preorder of right 
	if(temp->left!=NULL&&temp->right!=NULL)
	{
		preorder(&temp->left);
		preorder(&temp->right);	
	}
	
}
//function to print inorder ie first left then right then parent
void postorder(createNode** head)
{
	createNode* temp=*head;
	
	//if left is NULL but right not,print postorder of right
	if(temp->left==NULL&&temp->right!=NULL)
	{
		
		postorder(&temp->right);
	}	
	//if right is NULL but left not, print postorder of left
	if(temp->left!=NULL&&temp->right==NULL)
	{
		postorder(&temp->left);
		
	}
	//if both is not NULL, first print postorder of left then postorder of right 
	if(temp->left!=NULL&&temp->right!=NULL)
	{
		postorder(&temp->left);
		postorder(&temp->right);	
	}
	//if temp is not equal to NULL print it as its left and right till fuction reaches here, has been printed
	if(temp!=NULL)
		printf("%d ",temp->value);
}


//inputs
int main()
{
	int vertices;
	int root;
	int data;
	scanf("%d",&vertices);
	scanf("%d",&root);
	//intialize tree with root
	createNode* head =intlizeTree(root);
	
	for(int i=0;i<vertices-1;i++)
	{
		scanf("%d",&data);
		createTree(data,&head);
		
	}
	//we are gonna print if there is at least one ele o/w there is nothing to print
	if(vertices>0)
	{
		inorder(&head);
		printf("\n");
		preorder(&head);
		printf("\n");
		postorder(&head);
    		printf("\n");
	}
	

}
