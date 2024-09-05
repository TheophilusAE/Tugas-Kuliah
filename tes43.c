#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_MED_NAME_LENGTH 51
#define MAX_MAN_NAME_LENGTH 26
#define HASH_TABLE_SIZE 1007

typedef struct Medicine {
    char id[20];
    char name[MAX_MED_NAME_LENGTH];
    char manufacturer[MAX_MAN_NAME_LENGTH];
    int regNumber;
    int batchNumber;
    struct Medicine* next;
} Medicine;

Medicine* hashTable[HASH_TABLE_SIZE];

unsigned long hashFunction(const char *id) {
    unsigned long hash = 5381;
    int c;

    while ((c = *id++))
        hash = ((hash << 5) + hash) + c;

    return hash % HASH_TABLE_SIZE;
}

Medicine* createMedicineNode(const char *id, const char *name, const char *manufacturer, int regNumber, int batchNumber) {
    Medicine* newMedicine = (Medicine*)malloc(sizeof(Medicine));
    if (newMedicine != NULL) {
        strcpy(newMedicine->id, id);
        strcpy(newMedicine->name, name);
        strcpy(newMedicine->manufacturer, manufacturer);
        newMedicine->regNumber = regNumber;
        newMedicine->batchNumber = batchNumber;
        newMedicine->next = NULL;
    }
    return newMedicine;
}

int isUniqueName(const char *name) {
	int i;
    for ( i = 0; i < HASH_TABLE_SIZE; i++) {
        Medicine* current = hashTable[i];
        while (current != NULL) {
            if (strcmp(current->name, name) == 0)
                return 0; // Not unique
            current = current->next;
        }
    }
    return 1; // Unique
}

void insertMedicine() {
    char name[MAX_MED_NAME_LENGTH];
    char manufacturer[MAX_MAN_NAME_LENGTH];
    int regNumber;
    int batchNumber;

    do {
        printf("Enter Medicine Name [5-50][unique]: ");
        scanf("%50s", name);
    } while (strlen(name) < 5 || strlen(name) > 50 || !isUniqueName(name));

    do {
        printf("Enter Manufacturer Name[3-25][end with Ltd.]: ");
        scanf("%25s", manufacturer);
    } while (strlen(manufacturer) < 3 || strlen(manufacturer) > 25 || strcmp(manufacturer + strlen(manufacturer) - 4, "Ltd.") != 0);

    do {
        printf("Enter Registration Number[10 digits][Numeric]: ");
        scanf("%d", &regNumber);
    } while (regNumber < 0 || regNumber > 9999999999);

    do {
        printf("Enter Batch/Lot Number[>= 16]: ");
        scanf("%d", &batchNumber);
    } while (batchNumber < 16);

    int serialNumber = 1;
    unsigned long key;
    char id[20];
    do {
        sprintf(id, "M%05d-%d-%c%c", serialNumber, regNumber, manufacturer[0], name[0]);
        key = hashFunction(id);
        if (hashTable[key] != NULL) {
            serialNumber++;
        }
    } while (hashTable[key] != NULL);

    Medicine* newMedicine = createMedicineNode(id, name, manufacturer, regNumber, batchNumber);
    if (newMedicine == NULL) {
        printf("Memory allocation failed. Cannot insert medicine.\n");
        return;
    }

    if (hashTable[key] == NULL) {
        hashTable[key] = newMedicine;
    } else {
        Medicine* current = hashTable[key];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMedicine;
    }
    printf("Medicine inserted successfully!\n");
}

void removeMedicine(const char *medicineId) {
    unsigned long key = hashFunction(medicineId);

    Medicine* current = hashTable[key];
    Medicine* prev = NULL;

    while (current != NULL && strcmp(current->id, medicineId) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Medicine not found.\n");
        return;
    }

    printf("Medicine found:\n");
    printf("ID: %s\nName: %s\nManufacturer: %s\nRegistration Number: %d\nBatch Number: %d\n",
        current->id, current->name, current->manufacturer, current->regNumber, current->batchNumber);

    printf("Do you want to delete this medicine? (y/n): ");
    char confirmation;
    scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y') {
        if (prev == NULL) {
            hashTable[key] = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Medicine deleted successfully!\n");
    } else {
        printf("Medicine not deleted.\n");
    }
}

void viewMedicine() {
    int i;
    int found = 0;
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("|%-20s|%-25s|%-30s|%-15s|%-15s|\n", "Medicine ID", "Name", "Manufacturer", "Reg. Number", "Batch Number");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        Medicine* current = hashTable[i];
        while (current != NULL) {
            found = 1;
            printf("|%-20s|%-25s|%-30s|%-15d|%-15d|\n",current->id, current->name, current->manufacturer, current->regNumber, current->batchNumber);
            printf("---------------------------------------------------------------------------------------------------------------\n");
            current = current->next;
        }
    }
    if (!found) {
        printf("There are no medicines!\n");
    }
}

int main() {
    int choice;
    char medicineId[20];

    do {
        system("cls");
        printf("Sunib Hospital\n");
        printf("==============\n");
        printf("1. View Medicine\n");
        printf("2. Insert Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                system("cls");
                viewMedicine();
                printf("\n");
                printf("Press any key to continue...");
                getch();
                break;
            case 2:
                system("cls");
                insertMedicine();
                printf("\n");
                printf("Press any key to continue...");
                getch();
                break;
            case 3:
                system("cls");
                printf("Enter Medicine ID to remove: ");
                scanf("%s", medicineId);
                removeMedicine(medicineId);
                printf("\n");
                printf("Press any key to continue...");
                getch();
                break;
            case 4:
                printf("Exiting program.\n");
                printf("\n");
                printf("Press any key to continue...");
                getch();
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                printf("\n");
                printf("Press any key to continue...");
                getch();
                
        }
    } while (choice != 4);

    return 0;
}

