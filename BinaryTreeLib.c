#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"BinaryTree.h"


/******************************************************************************************************
Helper function that allocates a new node with the given data and NULL left and right pointers.
*******************************************************************************************************/
struct node * newNode(int data)
{
struct node * node = malloc(sizeof(struct node));  

node ->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}


/*******************************************************************************************************************
Helper function that allocates one parent and its two children, first parameter is parent then left child then right 
********************************************************************************************************************/
struct node* build123(int p , int l, int r)
{

struct node* parent = newNode(p);
struct node* leftChild = newNode(l);
struct node* rightChild = newNode(r);

parent->left = leftChild;
parent->right = rightChild;

leftChild->left = NULL;
leftChild->right = NULL;

rightChild->left = NULL;
rightChild->right = NULL;

return parent;
}


/*******************************************************************************************************************
This function will print a pretty Binary Tree
********************************************************************************************************************/
void printBT(struct node * parent)
{
int n1=10;
int loop=3;
int pos;
int i,j,k;


for(i=0;i<n1;i++)
	printf(" ");

printf("%d\n",parent->data);

for(j =1 ;j<loop;j++)
{ 

pos =n1-j-1;

for(i=0;i<pos;i++)
	printf(" ");

printf("/");

for(k=i;k<n1+j;k++)
		printf(" ");
printf("\\");		
printf("\n");

//PrintT(parent->left,k,2);


}
}

/*
//improve the function. 
void PrintT(struct node * parent, int n1, int loop)
{
int i,j,k,pos;
for(i=0;i<n1;i++)
	printf(" ");

printf("%d\n",parent->data);

for(j =1 ;j<loop;j++)
{ 

pos =n1-j-1;

for(i=0;i<pos;i++)
	printf(" ");

printf("/");

for(k=i;k<n1+j;k++)
		printf(" ");
printf("\\");		
printf("\n");

}

}
*/

/*******************************************************************************************************************
This function will return the no of nodes in a Binary Tree
********************************************************************************************************************/
int sizeTree(struct node * head)
{
int count=1;

//base case when head is null
if(head == NULL)
	return 0;
//recursive count of node
count = count + sizeTree(head->left) + sizeTree(head->right);
//leaf node return from recursion
if((head->left ==NULL) && (head->right ==NULL))
	return 1;

return count;
}
/*******************************************************************************************************************
This function will return the no of nodes along the longest path from root to  farthest leaf
********************************************************************************************************************/

int maxDepth(struct node* node)
{
int depthMax; 

if(node == NULL)
	return 0;

depthMax = 1 + imax(maxDepth(node->left),maxDepth(node->right));

if((node->left ==NULL) && (node->right ==NULL))
	return 1;

return depthMax;

}
/*******************************************************************************************************************
helper function for finding the max
********************************************************************************************************************/
int imax(int a, int b)
{
if (a >=b)
return a;

else
return b;

}
/*******************************************************************************************************************
This function will return the minimum node value in a BST (Binary search Tree) ordered!!
********************************************************************************************************************/
int minValue(struct node * node)
{
int value;
if(node == NULL)
{
	printf("Error : Empty Tree");
	return -1;
}

while(node->left !=NULL) 
	node = node->left;
	
return node->data;

}
/*******************************************************************************************************************
Print Inorder a BST (Binary search Tree) ordered!!
********************************************************************************************************************/
printInorder(struct node * node)
{
if(node == NULL)
	return;

printInorder(node->left);
printf("%d ,",node->data);
printInorder(node->right);
}

/*******************************************************************************************************************
Print postorder a BST (Binary search Tree) ordered!!
********************************************************************************************************************/
printPostorder(struct node * node)
{
if(node == NULL)
	return;

printPostorder(node->left);

printPostorder(node->right);

printf("%d ,",node->data);
}


/*******************************************************************************************************************
Given a binary tree and a sum, return sum if the tree has a root-to-leaf path such that adding up all the values 
 along the path equals the given sum. Return -1 if no such path  found
********************************************************************************************************************/
int hasPathSum(struct node* node, int sum) 
{

int n1,n2;
int s;

if(node==NULL)
return -1;

//clever step the path sum will only be satisfied when the child tree has path sum (sum-node data)
s= sum - node->data;	


n1 = hasPathSum(node->left,s);	//check recursivly at left and right
n2 = hasPathSum(node->right,s);

//when leaf if the sum is same as leaf data that means there is a path to with that sum return 0 in this case
if((node->left==NULL) && (node->right == NULL))
{
	if(sum == node->data)
	return 0;
}
//if any side gets a zero that means that these is path
if(n1==0 || n2==0)
return 0;
else
return -1 ;

}

/*******************************************************************************************************************
Print all Paths from root to leafs 
********************************************************************************************************************/
//Helper Function for recursion

void pritnPathrecur(struct node * node, int path[] ,int pathLen)
{

int i;
if(node == NULL)
return;

path[pathLen] = node->data;
pathLen++;

if(node->left !=NULL)				//go left with  your saved array and its length
pritnPathrecur(node->left,path,pathLen);

if(node->right !=NULL)				//go right with  your saved array		
pritnPathrecur(node->right,path,pathLen);

if((node->left ==NULL)&&(node->right ==NULL))	//okay leaf, time to print your bag lets see, you got the weight of your bag boy??
{
//ohh yes I am
printf("path :");
for(i=0;i<pathLen;i++)
	printf("->%d ",path[i]);

printf("\n");
}
}

//actual function to call
void printPaths(struct node * node)
{
int path[100];
int pathLen = 0;
pritnPathrecur(node,path,pathLen);

}

/*******************************************************************************************************************
Mirror a existing  Binary Tree 
********************************************************************************************************************/
void mirror(struct node * node)
{
struct node * temp= NULL;

if(node == NULL)
return;

//recursion with childs
mirror(node->left);
mirror(node->right);

//swap
temp = node->right;
node->right = node->left;
node->left = temp;

}
/*******************************************************************************************************************
For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the
original node. The resulting tree should still be a binary search tree. 
********************************************************************************************************************/
void doubleTree(struct node* node)
{
struct node * temp= NULL;
struct node * temp2;

if(node == NULL)
return;

//recursion with childs
doubleTree(node->left);
doubleTree(node->right);

//operation
temp = newNode(node->data);
temp2 = node->left;
node->left = temp;
temp->left = temp2;

}

/*******************************************************************************************************************
Return 1 if two trees are same, 0 if not
********************************************************************************************************************/
int sameTree(struct node* a, struct node* b)
{

if(a==NULL && b==NULL)
return 1;

if( (a==NULL && b!=NULL) || (a!=NULL && b==NULL) )
return 0;

return ( (a->data == b->data) && sameTree(a->left,b->left) && sameTree(a->right,b->right)  ); 



}

/*******************************************************************************************************************
It will check if a tree is BST or not if Its a BST it will return 1 else 0
********************************************************************************************************************/

/*
Returns true if the given tree is a BST and its
values are >= min and <= max.
*/
int isBSTUtil(struct node* node, int min, int max) {

if (node==NULL) return(1);

// false if this node violates the min/max constraint
if (node->data<min || node->data>max) return(0);

// otherwise check the subtrees recursively,
// tightening the min or max constraint
return (isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data+1, max) );


}

int isBST(struct node* node)
{
return  isBSTUtil(node,0, 1000000);
}


void main()
{
struct node * n1 = newNode(7);
struct node * n2 = newNode(10);
struct node * n3 = newNode(50);
struct node * n4 = newNode(80);
int count =0;

struct node * q=NULL;
//printf("data : %d\n",n1->data);

struct node * p = build123(5,4,6);
printf("pdata : %d\n",p->data);
printf("pleftdata : %d\n",p->left->data);
printf("prightdata : %d\n",p->right->data);
p->right->right = n1;
p->right->left = n2;

//p->left->right = n3;
//p->left->left = n4;

//count = minValue(p);
//printf("min value :%d\n",count);

//count = hasPathSum(p,19	);
/*
if(count == 0)
printf("yes it has a path\n");

else
printf("oops no path\n");
*/
/*
printPaths(p);
mirror(p);
printf("%d\n",p->right->left->data);
*/
/*
doubleTree(p);
printf("%d\n",p->left->left->left->left->left->data);
*/

q=build123(9,6,10);
/*
count = sameTree(p,q);

if(count == 1)
printf("yes same\n");

else
printf("  not same\n");
*/

count = isBST(p);

if(count == 1)
printf("It is  a BST\n");

else
printf("Not BST\n");





}
