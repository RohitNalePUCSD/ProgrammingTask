/*
	Question : Implement Circular Queue using singly linked list
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

PNODE Front = NULL; 
PNODE Rear = NULL;

void enQeue(PPNODE Head, int value)
{
	PNODE temp, NewN;

	
	NewN = (PNODE)malloc(sizeof(NODE));
	NewN->data = value;
	NewN->next = NULL;

	if(*Head == NULL) 
	{
		*Head = Front = Rear = NewN;
		 Rear->next = Front;
	}
	else
	{
		Rear->next = NewN;
		Rear = Rear->next;
		Rear->next = Front;
	}
}

void deQueue(PPNODE Head)
{
	if(*Head == NULL)
	{
		 printf("\nQueue is empty...!\n");
                 return ;

	}

	if(*Head == Rear)
	{
		free(*Head);
		*Head = NULL;
		printf("Delete the Front element\n");
		return ;
	}

	*Head = (*Head)->next; 
	free(Front);
	Front = *Head;
	Rear->next = *Head;
	printf("\nDelete the Front element\n");

}

void display(PNODE Head)
{
	if(Head == NULL)
	{
		printf("\nQueue is empty...!\n");
		return ;
	}
	
	PNODE temp = Head;
	printf("\n\n");

	do
	{
		printf("%d-->",temp->data);
		temp = temp->next;
	}while(temp != Head);

	printf("NULL\n\n");
}


int main()
{
	PNODE First = NULL;
	int choice, value;
	
	do
	{
		printf("\n\ncase 1: enQueue : Insert an element\ncase 2: deQueue : Delete an element\n");
		printf("case 3: Dispaly\ncase 4: Exit\n");
		printf("Enter the choices\n");
		scanf("%d",&choice);

		switch(choice)
		{	
			case 1: printf("Enter the element\n");
				scanf("%d",&value);
				enQeue(&First, value);
				break;

			case 2:	deQueue(&First);
				break;
	
			case 3:	display(First);
				break;
			
			case 4: exit(0);
		}

	}while(1);
} 


