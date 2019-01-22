#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//global variable to take care of stack's top element
int front=-1;
//structure for a tree node
typedef struct createNode
{
	char value;
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
//creating a function to add it's right and left entries
createNode* createTree(char data,createNode** left,createNode** right)
{
	createNode* head=intlizeTree(data);
	head->value=data;
	head->left=*left;
	head->right=*right;
	return head;
}
//function to print inorder ie first left then parent then right
void inorder(createNode** head)
{
	createNode* temp=*head;
	//if root is the only member in print it
	if(temp->left==NULL&&temp->right==NULL)
		printf("%c",temp->value);
	//if root is the only member in print it
	if(temp->left==NULL&&temp->right!=NULL)
	{
		printf("%c",temp->value);
		inorder(&temp->right);
	}	
	//if right is NULL but left not,  print inorder of left then print parent	
	if(temp->left!=NULL&&temp->right==NULL)
	{
		inorder(&temp->left);
		printf("%c",temp->value);	
	}
	//if both is not NULL, print inorder of left Then print parent then print inorder of right
	if(temp->left!=NULL&&temp->right!=NULL)
	{
		inorder(&temp->left);
		printf("%c",temp->value);
		inorder(&temp->right);	
	}
	
}
//fuction to push an ele on stack
void push(createNode** a,createNode** stack)
{	front++;
	stack[front]=*a;	
}
//function to pop an ele from top of the stack, returninf that element
createNode* pop(createNode** stack)
{
	createNode* a;
	a=stack[front];
	front--;
	return a;
}

int main()
{
	//array to store input , intl all ele are char zero
	char array[100]={"0"};
	//stack of the pointer of type createNode
	createNode* stack[100];
	scanf("%s",array);
	int i=0;
	int size=0;
	//when array[i]=0 means the final tree has been made there is no more ele to work on
	
	while(array[i]!=0)
	{	//id  current ele is a operator 
		if(array[i]=='+'||array[i]=='-'||array[i]=='*'||array[i]=='/'){
			createNode* a=pop(stack);
			createNode* b=pop(stack);
			//pop the upper two tree pointer and create a tree having parent current and right and left respectively top two
			createNode* temp=createTree(array[i],&b,&a);
			//push the pointer of that newly made tree on stack
			push(&temp,stack);
		
		}
		//otherwise just itlz a tree pointer and push it on the top of stack 
		else
		{
			createNode* temp=intlizeTree(array[i]);
			
			push(&temp,stack);
			
		}
		
	i++;	
	
	}
	//when it ends th only and top ele wil be having the pointer to root of the expression tree
	createNode* a=pop(stack);
	
	//print inorder of expression tree
	inorder(&a);
	
	

}
