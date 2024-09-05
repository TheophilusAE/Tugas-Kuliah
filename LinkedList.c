#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//Linked List
struct node 
{
	int data;
	struct node *next;
};

struct node *InsAtBegining (struct node *head,int data) {
	struct node *newnode = (struct node*) malloc (sizeof(struct node));
	newnode->data = data;
	newnode->next = head;
	return newnode;
}

int main () 
{
	struct node *head = NULL;
	int input,data;
	
	while (1) 
	{
		printf ("Menu\n");
		printf ("1. Insert Begin\n");
		printf ("2. Insert End\n");
		printf ("3. Delete Begin\n");
		printf ("4. Display Data\n");
		printf ("5. Exit\n");
		printf ("Input : ");
		scanf ("%d", &input);
		
		switch (input) 
		{
			case 1:
				system ("cls");
				printf ("Input Data : ");
				scanf ("%d",&data);
				printf ("Press Anything To continue...");
				getch ();
				break;
			case 2:
				system ("cls");
				printf ("Input Data : ");
				scanf ("%d",&data);
				printf ("Press Anything To continue...");
				getch ();
				break;
			case 3:
				
				printf ("Press Anything To continue...");
				getch ();
				break;
			case 4:
				system ("cls");
				printf ("Input Data : ");
				scanf ("%d",&data);
				printf ("Press Anything To continue...");
				getch ();
				break;
			case 5:
				system ("cls");
				printf ("Thankyou For Using This program!!");
				printf ("Press Anything To continue...");
				getch ();
				break;
		}
		
	}
	
}
