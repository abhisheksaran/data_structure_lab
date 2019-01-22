#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int idx=1;
//structure to make a tree node
typedef struct createNode
{
	int value;
	int index;
	struct createNode* left;
	struct createNode* right;
}createNode;

//function to create a new node	
createNode* newNode(int v)
{
	createNode* temp=(createNode*)malloc(sizeof(createNode));
	temp->value=v;
	temp->index=idx;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//function to search a given index number ,returning a pointer to it
createNode* search(createNode** head,int pos)
{	
	createNode* temp2=*head;
	createNode* temp3;
	//if tree is empty
	if(temp2==NULL)
	return NULL;
	//if temp2's index is not same as pos
	if(temp2->index!=pos)
	{	//seeing in it's left part
		if(temp2->left!=NULL)	
		{	//recursive call	
			temp3=search(&temp2->left,pos);
			//if index is found return that pointer
			if(temp3!=NULL)
			return temp3;
		}
		//if not move to it's right part
		else if(temp2->right!=NULL )
		{	//recursive call	
			temp3=search(&temp2->right,pos);
			//if index is found return that pointer
			if(temp3!=NULL)
			return temp3;
		}
		//if it's neither at parent nor it's child then it doesn't exist so returning NULL
		else 
			return NULL;
		
	}
	//if we reach here than temp 's index is same as pos
	return temp2;
		
	
}
//finction to insert the ele at given index 's left child
int insertLeft(createNode** head, int v, int pos)
{	
	//if given index doesn't exist return -1
	if(pos>idx)
	return -1;
	//creating new node
	createNode* node=newNode(v);

	createNode* temp=*head;
	createNode* ans;
	//if index has been found
	if(temp->index==pos)
	{	
		if(temp->left==NULL)
		{
			temp->left=node;
			return 0;
		}
		//if it's left is not free
		else	
			return -1;		
	}


		//we have to search it in it's left part
		ans=search(&temp->left,pos);
		//if found and it's left is free assign and return 
		if(ans!=NULL)
		{	if(ans->left==NULL)
			{
				ans->left=node;
				return 0;
			}
			//if it's left is not free
			else	
				return -1;
		}
		// if not found in left , don't give up, try to search in it's right part
		ans=search(&temp->right,pos);
		if(ans!=NULL)
		{	
			if(ans->left==NULL)
			{
				ans->left=node;
				return 0;
			}
			//if it's left is not free
			else	
				return -1;
		}
		
	//if you reach here that means places are already occupied		
	return -1;
}
//same as left insert
int insertRight(createNode** head, int v, int pos)
{	if(pos>idx)
	return -1;
	
	createNode* node=newNode(v);
	
	createNode* temp=*head;
	createNode* ans;
	

	if(temp->index==pos)
	{
		if(temp->right==NULL)
		{
			temp->right=node;
			return 0;
		}
		else	
			return -1;		
	}


		ans=search(&temp->left,pos);
		if(ans!=NULL&&ans->right==NULL)
		{	
			ans->right=node;
			return 0;
		}

		ans=search(&temp->right,pos);
		if(ans!=NULL&&ans->right==NULL)
		{
			ans->right=node;
			return 0;
		}
		
			
	return -1;
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
//global var to find occr
int occrn=0;
//function to find out occr of a particular key in tree
void occr(createNode** head,int k)
{
	createNode* temp=*head;
	if(temp->value==k)
	occrn++;
	if(temp->left!=NULL)
	occr(&temp->left,k);
	if(temp->right!=NULL)
	occr(&temp->right,k);
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

    
    int ret;
    int lineNo = 0;
    int n;	
    int nn;

    createNode* head=NULL;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s %s", v1, v2, v3, v4);
        lineNo++;
	//first line having a root entry
        if(lineNo == 1)
        {	n=stoi(v1);
		//making root
            	head=newNode(n);
		//each succesful insertion increment idx by 1
		idx++;
		
            continue;
        }
	//rest is history
        if(strcmp(v1,"INS") == 0&&strcmp(v4,"l") == 0)
        {
            ret = insertLeft(&head, stoi(v2),stoi(v3));
            if(ret < 0)
                printf("%d\n", -1);
	    else
		idx++;
        }
        else if(strcmp(v1,"INS") == 0&&strcmp(v4,"r") == 0)
        {
            ret = insertRight(&head, stoi(v2),stoi(v3));
            if(ret < 0)
                printf("%d\n", -1);
	    else
		idx++;
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
        }
	else if(strcmp(v1,"OCC") == 0)
        {
            occr(&head,stoi(v2));
            printf("%d\n",occrn);
	    //after each call , again intl to zero
	    occrn=0;
        }
        else
        {
            //printf("INVALID\n");
		printf("\n");
		continue;
        }
    }

   
    return 0;
}
