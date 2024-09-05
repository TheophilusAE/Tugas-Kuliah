#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
+---------------------------------+
|Nama : Theophilus Alexander Elvan|
|NIM : 2702259986				  |
+---------------------------------+
**/

//Struct for node
struct node {
    char name[100];
    struct node* next;
};

// Function to push a new node onto the stack
struct node* push(struct node* head, char input[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    strcpy(newNode->name, input);
    newNode->next = head;
    return newNode;
}

// Function to pop a node from the stack
struct node* pop(struct node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to free allocated memory for the stack
void freeStack(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node* stack = NULL;

    char input1[100];
    char input2[100];
    int k = 1;
    
    do {
    	system ("cls");
	    printf ("Sunib Hospital\n");
	    printf ("===============\n\n\n");
	    do {
	    	printf("Please Input A Medicine Name [minimum 5 medicine] (\"done\" to finish): ");
	    	scanf ("%s", input1);
	    	
	    	if (strcmp(input1, "done") == 0) {
	    		break;
			}
			
	    	printf ("Medicine %s added to the prescription.\n",input1);
	    	stack = push(stack, input1);
		} while (strcmp(input1, "done") != 0);
		
	    
	    printf ("\nMedicine Prescription: \n");
	    while (stack != NULL) {
	        printf ("Take Medicine #%d: %s\n", k, stack->name);
	        stack = pop(stack);
	        k++;
	    }
	    
	    printf ("Do you want to continue? (yes/no): ");
	    scanf ("%s",input2);
	    
	    k = 1;
	    freeStack(stack);
	} while (strcmp(input2, "no") != 0);
    return 0;
}

/**
+---------------------------------+
|Nama : Theophilus Alexander Elvan|
|NIM : 2702259986				  |
+---------------------------------+
**/
