#include<stdio.h>
#include<stdlib.h>
#include"Linklist.h"


//this funct will build a linklist with 3 integers
struct node* build123(int a , int b, int c)
{
struct node* head = NULL;
head = malloc(sizeof(struct node));

struct node* second = NULL;
second = malloc(sizeof(struct node));

struct node* third = NULL;
third =  malloc(sizeof(struct node));

head->data = a;			//set up first data
head->next = second;		//connected to second

second->data = b;
second->next = third;

third->data = c;
third->next = NULL;		//last pointer to null

return head;
}

//this function will return size of a link list
int sizeList(struct node* head)
{
int count=1;
struct node * current = head;

if(head == NULL)
return 0;

while(current->next != NULL)
{
count++;
current = current->next;
}
return count;
}

//This function will print the list
int printList( struct node * head)
{
struct node * current = head;
int size = 0;

if(head == NULL){
printf("List is empty\n");
return 0;
}


while(current !=NULL)
{
printf("%d",current->data);
printf(" ->");
size++;
current = current->next;
}
printf("NULL\n");

return size;
}

//This function will add a data at the end of the list
struct node * addEnd(struct node * head, int data)
{
struct node * current = head;
struct node * new = NULL;

new = malloc(sizeof(struct node));
new->data = data;
new->next = NULL;

if(head == NULL)			//if head is NULL
{
return new;
}

while(current->next != NULL)
	current = current->next;	

current->next = new; 
return head;
}

//This function will add a data at the Front of the list, It is same as Push
struct node * addFront(struct node * head, int data)
{
struct node * current = head;
struct node * new = NULL;
new = malloc(sizeof(struct node));
new->data = data;

if(head == NULL)			//if head is NULL
{
new->next = NULL;
return new;
}

new->next = current;
head = new;

return head;
}



/***********************************************************************************************************/
/*this function will add at the p postion of the list, it will take head ref and position and data as input
/***********************************************************************************************************/
int insert(struct node ** headref, int pos, int data)
{
int size=0;
int i =0;
struct node * current = *headref;
struct node * new = NULL;
size = sizeList(*headref);

if(*headref == NULL)
{
printf("List is Empty data can not be inserted at given position\n");
return 0 ;
}

// if data to be inserted at the first position same like add Front 
if(pos==1)
{
*headref = addFront(current,data);			//either use the following code or use this lib function coded before.
/*
new = malloc(sizeof(struct node));
new->data = data;
new->next = current;
*headref = new;
*/

return 0;
}

//seek to one eliment before position and if list end before that show the error msg
for(i = 1; i<pos-1; i++)
{
current = current->next;
if(current == NULL)
{
printf("List is smaller can not be inserted at %d position\n",pos);
return 0 ;

}
} 

struct node * temp = current->next;
new = malloc(sizeof(struct node));
new->data = data;

current->next = new;
new->next = temp;
return 0;

}

/***********************************************************************************************************/
/*this function will search for an eliment in list and return the count
/***********************************************************************************************************/
 int search(struct node * head, int eliment)
 {
 int count=0;
 
 if(head==NULL)
 return 0;
 
 while(head !=NULL)
 {
 if(head->data == eliment)
 	count++;

head = head->next;	
 }
 
return count;
}



/***********************************************************************************************************/
/*this function will return nth eliment of a list
/***********************************************************************************************************/
int  getNth(struct node * head, int n)
{
int i =0;
struct node * current = head;

if(head==NULL)
 {
 printf("List is empty\n");
 return -1;
 }
 
 if(n==0)
 {
 printf("ERROR :position starts from 1 \n");
 return -1;
 }
 
 for(i = 1; i<n; i++)
{
current = current->next;
if(current == NULL)
{
printf("List is smaller there is no %d th node \n",n);
return -1 ;

}
} 
 return current->data;
}

/***********************************************************************************************************/
/*this function will delete the list and free the allocated memory
/***********************************************************************************************************/
int deleteList(struct node ** headref)
{
struct node * current = * headref;
struct node * temp = NULL;
*headref = NULL;

while(current != NULL)			//now free the memory
{

temp = current->next;
free(current);
current = temp;
}
return 0;
}

/***********************************************************************************************************/
/*this function will pop the first eliment and return the data of it
/***********************************************************************************************************/
int pop(struct node ** headref)
{
int data;
struct node * current = * headref;
if(current == NULL)
{
  printf("List is empty\n");
 return -1;
}

data = current->data;
*headref = current->next;
free(current);
return data;

}

/***********************************************************************************************************/
/*this function will pop the first node and return it
/***********************************************************************************************************/
struct node* popNode(struct node ** headref)
{

struct node * current = * headref;
if(current == NULL)
{
  printf("List is empty\n");
 return NULL;
}


*headref = current->next;

return current;

}




/***********************************************************************************************************/
/*this function will insert the eliment in sorted order
/***********************************************************************************************************/
int sortedInsert(struct node ** headref, struct node * newNode)
{
struct node * current = * headref;
struct node * temp = NULL;

//special case for head is NULL or data to be inserted at the first place
if( (*headref == NULL) || (current->data >= newNode->data) )  
{
newNode->next = *headref;
*headref = newNode;
return 0;
}

// Locate the node before the point of insertion

while(newNode->data >= current->data)
{
temp = current;

if(current->next !=NULL)
	current = current->next;
else
{
current = NULL;
break;
}
}

temp->next = newNode;
newNode->next = current;
return 0 ;
}
/***********************************************************************************************************/
/*this function will insert the eliment in sorted order
/***********************************************************************************************************/
void insertSort(struct node** headref) 
{

struct node * current = * headref;
struct node * Next = NULL;
struct node * result = NULL;

while(current !=NULL)  //take every eliment and send to sortedInsert
{
Next = current->next;

sortedInsert(&result,current);
current = Next;
}
*headref = result;
}

/***********************************************************************************************************/
/*this function will Append list 'b' into 'a' and set the b to NULL
/***********************************************************************************************************/
void append(struct node** aref, struct node** bref)
{
struct node* a = *aref;
struct node* b = *bref;

if(b ==NULL)
	return;
if(a==NULL)
{
a= b;
b=NULL ;
return;
}
//walk till the end of a
while(a->next !=NULL)
{
a= a->next;
}
a->next = b;
b=NULL;
return;

}
/***********************************************************************************************************/
/*Given a list, split it into two sublists — one for the front half, and one for the back half. If
the number of elements is odd, the extra element should go in the front list. SoFrontBackSplit() on the 
list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,11}
/***********************************************************************************************************/
void frontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) 
{
struct node* slow= source;
struct node* fast= source;
int fcount=0;
int scount = 0;

//if source is null or it has single value, it will go to front and back will be NULL
if( (source ==NULL) || (source->next == NULL) )
{
*frontRef = source;
backRef = NULL;
return;
}

while( (fast->next !=NULL) && (fast->next->next != NULL) )
{

slow = slow->next;
fast= fast->next->next;
fcount = fcount+2;
scount++; 
}
*backRef = slow->next;
slow->next = NULL;

*frontRef = source;

}

/***********************************************************************************************************/
/*Remove duplicates from a sorted list.
/***********************************************************************************************************/
void removeDuplicates(struct node * head)
{
struct node* current= head;
struct node* temp = NULL;
struct node* f =NULL;
while(current->next !=NULL)
{
	temp = current->next;

	while( (current->data == temp->data) && (temp->next !=NULL) )
	{
		f= temp;
		temp=temp->next;
		free(f);
		
	}
	
	current->next = temp;
	current = temp;
}

}


/***********************************************************************************************************/
/* Take the node from the front of the source, and move it to the front of the dest.
/* It is an error to call this with the source list empty.
/***********************************************************************************************************/
void moveNode(struct node** destRef, struct node** sourceRef) 
{
struct node* s = NULL;
//struct node* d = *destRef;

if(*sourceRef == NULL)
{
printf("Error : Source list is empty\n");
return;
}

s= popNode(sourceRef);

s->next = *destRef;
*destRef = s;


}

/***********************************************************************************************************/
/*Given the source list, split its nodes into two shorter lists. If we number the elements 0, 1, 2, ... 
then all the even elements should go in the first list, and all the odd elements in the second. 
The elements in the new lists may be in any order.
/***********************************************************************************************************/
void alternatingSpilt(struct node* source, struct node** aRef, struct node** bRef)
{
*aRef = NULL;
*bRef = NULL;

while(source !=NULL)
{
moveNode(aRef,&source);
moveNode(bRef,&source);
}

}

/***********************************************************************************************************/
/*Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
/***********************************************************************************************************/
struct node* shuffleMerge(struct node* a, struct node* b) 
{
struct node * result = NULL;

while( a!=NULL || b!=NULL)
{

if(a!=NULL)
moveNode(&result,&a);

if(b!=NULL)
moveNode(&result,&b);

}
return result; 
}

/***********************************************************************************************************/
/* Takes two lists sorted in increasing order, and
splices their nodes together to make one big sorted list which is returned
/***********************************************************************************************************/
struct node* sortedMerge(struct node* a, struct node* b)
{
struct node * result = NULL;

struct node * final = NULL;

if(a==NULL)
{
result = b; 
insertSort(&result);
return result;
}

if(b==NULL)
{
result = a; 
insertSort(&result);
return result;
}
//if a and b both are not null than check and send the minimum to result.
while(a!=NULL && b!=NULL)
{
if(a->data <= b->data)
	moveNode(&result,&a);
else
	moveNode(&result,&b);

}
//whatever is remaining will come in front as it is

while(a!=NULL)
	moveNode(&result,&a);
	
while(b!=NULL)
	moveNode(&result,&b);	

//now result will be in descending order because moveNode will move in front.

while(result!=NULL)
	moveNode(&final,&result);		//move again to final it will be in ascending order.
	
return final;	

}

/***********************************************************************************************************/
/*Merge Sort function. Uses previous lib functions use recursion
/***********************************************************************************************************/
void mergeSort(struct node** headRef) 
{
struct node * part1  = NULL;

struct node * part2= NULL;

struct node * head = *headRef;

if ( (head ==NULL) || (head->next ==NULL) )	//boundry condition
return;

frontBackSplit(*headRef,&part1,&part2);		//split head into two sublist part1 part2

mergeSort(&part1);				//apply merge  sort on individual part

mergeSort(&part2);

*headRef = sortedMerge(part1,part2);		//combine them

}

/***********************************************************************************************************/
/*Compute a new sorted list that represents the intersection of the two given sorted lists.
/***********************************************************************************************************/
struct node* sortedIntersect(struct node* a, struct node* b)
{

struct node * intersect=NULL;

while (a!=NULL && b!=NULL)
{
if (a->data < b->data)
a=a->next;

if(a->data > b->data) 
b=b->next;

if(a->data == b->data)
{
intersect = addFront(intersect,b->data);
a=a->next;
b=b->next;

}
}
mergeSort(&intersect);
return intersect;
}


/***********************************************************************************************************/
/*This function will reverse the List 
/***********************************************************************************************************/
void reverse(struct node** headRef)
{
struct node* reverse = NULL;
while(*headRef !=NULL)
	moveNode(&reverse,headRef);

*headRef = reverse;
}

/***********************************************************************************************************/
/*This function will reverse the List with recursion 
/***********************************************************************************************************/
void recursiveReverse(struct node** headRef) {
struct node* first;
struct node* rest;
if (*headRef == NULL) return;
// empty list base case
first = *headRef;
// suppose first = {1, 2, 3}
rest = first->next;
// rest = {2, 3}
if (rest == NULL) return;
// empty rest base case
recursiveReverse(&rest);
// Recursively reverse the smaller {2, 3} case
// after: rest = {3, 2}
first->next->next = first;
// put the first elem on the end of the list
first->next = NULL;
// (tricky step -- make a drawing)
*headRef = rest;
// fix the head pointer
}










int main()
{
struct node * head;
struct node * head2=NULL;
int size;
int c;
struct node * front;
struct node * back;


head = build123(12,5,2);
size = sizeList(head);
head = addEnd(head,7);
head = addFront(head,10);

printf("head : ");
printList(head);

//insert(&head,4,5);
//insert(&head,6,5);
//printList(head);
//c= search(head,5);
//printf("search: %d\n",c);

//c= getNth(head,0);
//printf("4th eliment is %d\n",c);

//deleteList(&head);

/*
c= pop(&head);
printf("pooped eliment is %d\n",c);
printList(head);

struct node * new  = (struct node *) malloc(sizeof(struct node));
new->data = 8;
new->next = NULL	;

sortedInsert(&head,new);
printList(head);

*/

//head2 = build123(5,6,7);
//append(&head,&head2);



//frontBackSplit(head,&front,&back);


//printList(front);
//printList(back);	
//insertSort(&head);
//printList(head2);

//removeDuplicates(head);
//printList(head);

//moveNode(&head2,&head);
//printList(head);
/*
alternatingSpilt(head,&front,&back);
insertSort(&front);
insertSort(&back);
printList(front);
//back = NULL;
printList(back);
//printList(head);
head = NULL;
//head = shuffleMerge(front,back);
//printList(head);



head = sortedMerge(front,back);
printList(head);
*/


/*
printf("\nfront :");
printList(front);

printf("\nback :");
printList(back);

struct node *a;
struct node * b;
frontBackSplit(back,&a,&b);

printf("\na :");
printList(a);
printf("\nb :");
printList(b);
*/
mergeSort(&head);
printList(head);

/*
head2 = NULL;
head2 = build123(10,12,25);
head2 = addFront(head2,2);
printf("\nhead2 :");
printList(head2);
struct node *a;
a = sortedIntersect(head,head2);

printf("\na :");
printList(a);

reverse(&head2);
printf("\nrevesrse head2 :");
printList(head2);


moveNode(&head,&head2);
printList(head);
*/

recursiveReverse(&head);
printList(head);


}





