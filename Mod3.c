#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* 
	Nama : Theophilus Alexander Elvan 
	Nim : 2702259986
*/
struct data {
    char name[25];
    int age;
    char ID[10];
    char desc[1000];
    char code[10];
};

struct Node {
    struct data patient;
    int priority;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, struct data* patient, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    newNode->patient = *patient;
    newNode->priority = priority;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

void displayQueue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("There is no queue yet!\n");
    } else {
    	printf("Patient List: \n");
    	printf("------------------------------------------------------------------------------\n");
        printf("| %-25s | %-3s | %-8s | %-20s | %-6s |\n", "Name", "Age", "ID", "Description", "Code");
        printf("------------------------------------------------------------------------------\n");

        struct Node* current = q->front;
        while (current != NULL) {
            printf("| %-25s | %-3d | %-8s | %-20s | %-6s |\n",
                   current->patient.name, current->patient.age, current->patient.ID,
                   current->patient.desc, current->patient.code);
            current = current->next;
        }
        printf("------------------------------------------------------------------------------\n");
    }
}

void insert(struct Queue* q) {
    struct data patient;

    do {
        printf("Insert patient name [4-25]: ");
        fflush(stdin);
        gets(patient.name);
    } while (strlen(patient.name) < 4 || strlen(patient.name) > 25);

    do {
        printf("Insert patient age [>= 0]: ");
        scanf("%d", &(patient.age));
    } while (patient.age < 0);

    do {
        printf("Insert patient ID [5]: ");
        fflush(stdin);
        gets(patient.ID);
    } while (strlen(patient.ID) != 5);

    struct Node* current = q->front;
    while (current != NULL) {
        if (strcmp(patient.ID, current->patient.ID) == 0) {
            printf("Duplicate ID! Please enter a different ID.\n");
            return;
        }
        current = current->next;
    }

    do {
        printf("Insert description [>= 6 characters]: ");
        fflush(stdin);
        gets(patient.desc);
    } while (strlen(patient.desc) < 6);

    do {
        printf("Insert code [Red|Yellow|Green]: ");
        fflush(stdin);
        gets(patient.code);
    } while (
        strcmp(patient.code, "Red") != 0 &&
        strcmp(patient.code, "Yellow") != 0 &&
        strcmp(patient.code, "Green") != 0
    );

    int priority;
    if (strcmp(patient.code, "Red") == 0) {
        priority = 3;
    } else if (strcmp(patient.code, "Yellow") == 0) {
        priority = 2;
    } else {
        priority = 1;
    }

    enqueue(q, &patient, priority);
    printf("\nInsert Success\n");
}

void nextQueue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("There is no queue yet!\n");
    } else {
        printf("The next patient is:\n");
        printf("Name           : %s\n",q->front->patient.name);
        printf("Age            : %d\n",q->front->patient.age);
        printf("ID             : %s\n",q->front->patient.ID);
        printf("Description    : %s\n",q->front->patient.desc);
        printf("Code           : %s\n",q->front->patient.code);
        dequeue(q);
    }
}

int main() {
    struct Queue patientQueue;
    initializeQueue(&patientQueue);
    int input;

    do {
        system("cls");
        printf("Sunib Patient Entry\n");
        printf("====================\n");
        printf("[1] Insert Patient\n");
        printf("[2] View List\n");
        printf("[3] Next Queue\n");
        printf("[4] Exit\n");
        printf(">>> ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                insert(&patientQueue);
                printf("Press Any Key to Continue...");
                getch();
                break;
            case 2:
                displayQueue(&patientQueue);
                printf("\nPress Any Key to Continue...");
                getch();
                break;
            case 3:
                nextQueue(&patientQueue);
                printf("]\nPress Any Key to Continue...");
                getch();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid Input!! Press Any Key to Continue...");
                getch();
                break;
        }
    } while (input != 4);

    return 0;
}

/* 
	Nama : Theophilus Alexander Elvan 
	Nim : 2702259986
*/
