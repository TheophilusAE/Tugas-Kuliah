#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int i;

typedef struct {
    char name[25];
    char id[10];
    int age;
    char description[1000];
    char code[10];
} Patient;

typedef struct Node {
    Patient data;
    int priority;
    struct Node* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    int size;
} PriorityQueue;

PriorityQueue createPriorityQueue() {
    PriorityQueue pq;
    pq.front = NULL;
    pq.size = 0;
    return pq;
}

QueueNode* createNode(Patient patient, int priority) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode != NULL) {
        newNode->data = patient;
        newNode->priority = priority;
        newNode->next = NULL;
    }
    return newNode;
}

void insertPatient(PriorityQueue* pq) {
    Patient patient;
    printf("Enter patient name: ");
    fgets(patient.name, sizeof(patient.name), stdin);
    patient.name[strcspn(patient.name, "\n")] = '\0';

    if (strlen(patient.name) < 4 || strlen(patient.name) > sizeof(patient.name) - 1) {
        printf("Name must be between 4 and %d characters!\n", sizeof(patient.name) - 1);
        return;
    }

    printf("Enter patient ID: ");
    scanf("%9s", patient.id);

    if (checkDuplicateID(pq, patient.id)) {
        printf("Duplicate ID! Please enter a unique ID.\n");
        return;
    }

    printf("Enter patient age: ");
    scanf("%d", &patient.age);

    if (patient.age < 0) {
        printf("Age must be at least 0!\n");
        return;
    }

    printf("Enter patient description/symptoms: ");
    getchar();
    fgets(patient.description, sizeof(patient.description), stdin);
    patient.description[strcspn(patient.description, "\n")] = '\0';

    if (strlen(patient.description) < 6) {
        printf("Description must be at least 6 characters!\n");
        return;
    }

    printf("Enter patient code (Red/Yellow/Green): ");
    scanf("%9s", patient.code);

    if (strcmp(patient.code, "Red") != 0 && strcmp(patient.code, "Yellow") != 0 && strcmp(patient.code, "Green") != 0) {
        printf("Invalid code! Please enter Red, Yellow, or Green.\n");
        return;
    }

    int priority;
    if (strcmp(patient.code, "Red") == 0) {
        priority = 3;
    } else if (strcmp(patient.code, "Yellow") == 0) {
        priority = 2;
    } else {
        priority = 1;
    }

    insertNode(pq, patient, priority);

    printf("Patient successfully added to the queue!\n");
}

int checkDuplicateID(PriorityQueue* pq, const char* id) {
    QueueNode* current = pq->front;
    for (i = 0; i < pq->size; ++i) {
        if (strcmp(current->data.id, id) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void insertNode(PriorityQueue* pq, Patient patient, int priority) {
    QueueNode* newNode = createNode(patient, priority);
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    if (pq->front == NULL) {
        pq->front = newNode;
        newNode->next = newNode;
    } else {
        QueueNode* current = pq->front;
        while (current->next != pq->front && current->next->priority >= priority) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    pq->size++;
}

void viewList(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("There is no queue yet!\n");
        return;
    }

    printf("Patient Queue:\n");
    QueueNode* current = pq->front;
    for (i = 0; i < pq->size; ++i) {
        printf("Name: %s\nID: %s\nAge: %d\nDescription: %s\nCode: %s\nPriority: %d\n\n",
               current->data.name, current->data.id, current->data.age, current->data.description, current->data.code, current->priority);
        current = current->next;
    }
}

void nextQueue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("There is no queue yet!\n");
        return;
    }

    printf("Removing the frontmost queue:\n");
    printf("Name: %s\nID: %s\nAge: %d\nDescription: %s\nCode: %s\nPriority: %d\n\n",
           pq->front->data.name, pq->front->data.id, pq->front->data.age, pq->front->data.description, pq->front->data.code, pq->front->priority);

    QueueNode* temp = pq->front;
    if (pq->size == 1) {
        pq->front = NULL;
    } else {
        pq->front = pq->front->next;
        QueueNode* last = pq->front;
        while (last->next != temp) {
            last = last->next;
        }
        last->next = pq->front;
    }

    free(temp);
    pq->size--;
}

void freeQueue(PriorityQueue* pq) {
    while (pq->size > 0) {
        nextQueue(pq);
    }
}

int main() {
    PriorityQueue patientQueue = createPriorityQueue();
    int choice;

    do {
    	system ("cls");
        printf("Sunib Patient Entry\n");
        printf("=====================");
        printf("[1]. Insert Patient\n");
        printf("[2]. View List\n");
        printf("[3]. Next Queue\n");
        printf("[4]. Exit\n");
        printf("Input >>>");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertPatient(&patientQueue);
                printf ("Press any key to continue...");
                getch ();
                break;
            case 2:
                viewList(&patientQueue);
                printf ("Press any key to continue...");
                getch ();
                break;
            case 3:
                nextQueue(&patientQueue);
                printf ("Press any key to continue...");
                getch ();
                break;
            case 4:
                freeQueue(&patientQueue);
                printf("Thankyouu for using this program!!\n");
                printf ("Press any key to continue...");
                getch ();
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                printf ("Press any key to continue...");
                getch ();
        }
    } while (choice != 4);

    return 0;
}

