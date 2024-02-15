#include <stdio.h>
#include <stdlib.h>

/*
	Author: Nicholas Bonilla
	Purpose: Creating functions to work between linked lists and strings
*/

typedef struct node 
{
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	//Creating count variable
	int num = 0;

	//Looping through linked list
	while(head != NULL)
	{
		//Increasing count
		num++;

		//Moving to next node
		head = head->next;	
	}

	//returning num

	return num;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	//Getting length
	int num = length(head);

	//Creating string
	char* str = (char*) malloc(sizeof(char) * (num+1));

	//Filling String
	for(int i = 0; i < num; i++)
	{
		//Getting current char
		str[i] = head->letter;

		//Moving to next char
		head = head->next;
	}

	//Returning string
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	//Making new node
	node* newNode = (node*) malloc(sizeof(node));
	newNode->letter=c;
	
	if(*pHead == NULL)
	{
		*pHead = newNode;
		return;
	}	

	    node* temp = *pHead;

   		//Looping through linked list
		//Creating temp node
		while(temp->next != NULL) 
    	{
        	//Changing temp
			temp = temp->next;
    	}

		//Linking nodes
    	// newNode->next = NULL;
	
		temp->next = newNode;

	//Assigning values to new node

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	//Creating temp node
	node* temp = *pHead;

	//Looping through linked list
    while (temp != NULL) 
    {
        //Setting head to next value
		*pHead = temp->next;

		//Freeing temp
        free(temp);

		//Updating temp
        temp = *pHead;
    }
	
	//Making head null
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}