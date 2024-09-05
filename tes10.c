#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_TABLE_SIZE 1007

typedef struct {
    char id[20];
    char name[51];
    char manufacturer[26];
    char regNumber[11];
    char batchNumber[20];
} Medicine;

typedef struct Node {
    Medicine data;
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

int hashFunction(const char* id) {
	int i;
    int sum = 0;
    for (i = 0; id[i] != '\0'; i++) {
        sum += id[i];
    }
    return sum % HASH_TABLE_SIZE;
}

Node* createNode(Medicine data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertMedicine(const Medicine* medicine) {
    int key = hashFunction(medicine->id);
    Node* newNode = createNode(*medicine);
    if (hashTable[key] == NULL) {
        hashTable[key] = newNode;
    } else {
        Node* temp = hashTable[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void viewMedicine() {
	int i;
    printf("View Medicine:\n");
    int found = 0;
    for ( i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            Node* temp = hashTable[i];
            while (temp != NULL) {
                printf("ID: %s\nName: %s\nManufacturer: %s\nRegistration Number: %s\nBatch Number: %s\n\n",
                       temp->data.id, temp->data.name, temp->data.manufacturer, temp->data.regNumber, temp->data.batchNumber);
                temp = temp->next;
                found = 1;
            }
        }
    }
    if (!found) {
        printf("There is no medicine(s)!\n");
    }
}

int main() {
    // Initialize hash table
    int i;
    for ( i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Main menu loop
    int choice;
    do {
        printf("Main Menu:\n");
        printf("1. View Medicine\n");
        printf("2. Insert Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewMedicine();
                break;
            // Add cases for other options (2, 3, 4) here
            default:
                if (choice != 4) {
                    printf("Invalid choice. Please enter a valid option.\n");
                }
                break;
        }
    } while (choice != 4);

    // Free memory allocated for hash table
    for ( i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}

