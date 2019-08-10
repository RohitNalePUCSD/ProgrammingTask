#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

typedef struct NODE node;
typedef struct NODE *pnode;
typedef struct NODE **ppnode;

void enque(ppnode head, int n)
{
	pnode temp= *head,NNode;
	
	for(int i = 0; i < n; i++)
	{
		NNode = (pnode)malloc(sizeof(node));
		printf("Enter the data of new node\n");
		scanf("%d",&NNode->data);
		NNode->next = NULL;

		if(*head == NULL)
		{
			*head = NNode;
		}
		else
		{
			for(temp = *head; temp->next!=NULL; temp = temp->next);
			temp->next = NNode;
		}
	}

}

void display(pnode head)
{
	printf("\n\n->");
	for(pnode temp = head; temp != NULL; temp=temp->next)
		printf("%d->",temp->data);

	printf("NULL\n");
}


void dequeue(ppnode head)
{
	pnode temp = *head;
	*head = (*head)->next;
	free(temp);
}

void peek(pnode head)
{

	printf("\n\npeek of element = %d\n",head->data);
}


int main()
{
	pnode first = NULL;
	
	int n,ch;
	
	do
	{
		printf("case 1 : enqueq : insert into queue\ncase 2 : deque : delete from queue\ncase 3 : peek : display top element of queue\n");
		printf("case 4 : display\ncase 5 : exit\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
        		case 1:	printf("ENter the how many node create\n");
       	 			scanf("%d",&n);
				if(n == 0)
					return 0;
				enque(&first, n);
				break;

			case 2:	dequeue(&first);
				break;

			case 3: peek(first);
				break;

			case 4: display(first);
				break;
	
			case 5: exit(0);			
		}
	}while(1);
}
