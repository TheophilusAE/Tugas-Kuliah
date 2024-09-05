#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct data {
    char name[25];
    int age;
    char ID[10];
    char desc[1000];
    char code[10];
};

void insert(struct data *ptr) {
    do {
        printf("Insert patient name [4-25]: ");
        fflush(stdin);
        gets(ptr->name);
    } while (strlen(ptr->name) < 4 || strlen(ptr->name) > 25);

    do {
        printf("Insert patient age [>= 0]: ");
        scanf("%d", &(ptr->age));
    } while (ptr->age < 0);

    do {
        printf("Insert patient ID [5]: ");
        fflush(stdin);
        gets(ptr->ID);
    } while (strlen(ptr->ID) != 5);

    do {
        printf("Insert description [>= 6 characters]: ");
        fflush(stdin);
        gets(ptr->desc);
    } while (strlen(ptr->desc) < 6);

    do {
        printf("Insert code [Red|Yellow|Green]: ");
        fflush(stdin);
        gets(ptr->code);
    } while (
        strcmp(ptr->code, "Red") != 0 &&
        strcmp(ptr->code, "red") != 0 &&
        strcmp(ptr->code, "Yellow") != 0 &&
        strcmp(ptr->code, "yellow") != 0 &&
        strcmp(ptr->code, "Green") != 0 &&
        strcmp(ptr->code, "green") != 0
    );
}

int main() {
    struct data patient;
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
                insert(&patient);
                printf("\n\nInsert Success\n");
                printf("Press Any Key to Continue...");
                getch();
                break;
            case 2:
                printf("Press Any Key to Continue...");
                getch();
                break;
            case 3:
                printf("Press Any Key to Continue...");
                getch();
                break;
            case 4:
                printf("Press Any Key to Continue...");
                getch();
                break;
            default:
                printf("Invalid Input!! Press Any Key to Continue...");
                getch();
                break;
        }
    } while (input != 4);

    return 0;
}

