#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int i;

struct Customer {
    char phone[14];
    char name[26];
    char email[22];
    int visits;
    struct Customer *next;
};

struct Customer *head = NULL;

int validatePhoneNumber(char *phone) {
    int len = strlen(phone);
    for (i = 0; i < len; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }
    return (len >= 10 && len <= 13);
}

int validateName(char *name) {
    int len = strlen(name);
    return ((len >= 5 && len <= 25) && (strncmp(name, "Mr. ", 4) == 0 || strncmp(name, "Mrs. ", 5) == 0));
}

int validateEmail(char *email) {
    int len = strlen(email);
    char *at = strchr(email, '@');
    char *dotcom = strstr(email, ".com");
    char *dotco_id = strstr(email, ".co.id");
    return (at != NULL && (dotcom != NULL || dotco_id != NULL) && len >= 10 && len <= 20);
}

void displayMedicineList() {
    printf("\n-------------------------------------------\n");
    printf("|  No  |     Nama Obat     |   Harga (IDR) |\n");
    printf("-------------------------------------------\n");
    printf("|  1   |   Paracetamol     |     5000      |\n");
    printf("|  2   |     Diapet        |     7000      |\n");
    printf("|  3   |     Oralit        |     3500      |\n");
    printf("|  4   |   Paratusin       |     5500      |\n");
    printf("|  5   |   OB Herbal       |     6000      |\n");
    printf("-------------------------------------------\n");
}

void displayCustomerTable(struct Customer *node) {
    printf("\n---------------------------------------------------------\n");
    printf("|   Phone Number   |        Name       |       Email       | Visits |\n");
    printf("---------------------------------------------------------\n");

    while (node != NULL) {
        printf("| %-16s| %-18s| %-18s|   %-6d|\n", node->phone, node->name, node->email, node->visits);
        node = node->next;
    }

    printf("---------------------------------------------------------\n");
}

void viewAllCustomers() {
    if (head == NULL) {
        printf("There is no data!\n");
        printf("Press any key to continue...");
        getch();
        return;
    }

    displayCustomerTable(head);
    printf("Press any key to continue...");
    getch();
}

void removeCustomer(char *phone) {
    if (head == NULL) {
        printf("There is no data!\n");
        printf("Press any key to continue...");
        getch();
        return;
    }

    struct Customer *current = head;
    struct Customer *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->phone, phone) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Customer with phone number %s removed successfully!\n", phone);
            printf("Press any key to continue...");
            getch();
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Data invalid! Customer with phone number %s not found.\n", phone);
    printf("Press any key to continue...");
    getch();
}

int main() {
    int input;

    do {
        system("cls");
        printf("SUNIB's Pharmacy\n");
        printf("================\n");
        printf("1. Process Order\n");
        printf("2. View All Customer\n");
        printf("3. Remove Customer\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                char phone[14];
                printf("Enter phone number[10-13][Numeric]: ");
                scanf("%s", phone);
                if (!validatePhoneNumber(phone)) {
                    printf("Invalid phone number!\n");
                    printf("Press any key to continue...");
                    getch();
                    break;
                }

                char registerChoice;
                printf("Do you want to register for membership? [y/n]: ");
                scanf(" %c", &registerChoice);

                if (registerChoice == 'y' || registerChoice == 'Y') {
                    char name[26];
                    printf("Input name[5-25][Mr. |Mrs. ]: ");
                    scanf(" %[^\n]s", name);
                    if (!validateName(name)) {
                        printf("Invalid name!\n");
                        printf("Press any key to continue...");
                        getch();
                        break;
                    }

                    char email[22];
                    printf("Enter email[10-20][email format]: ");
                    scanf("%s", email);
                    if (!validateEmail(email)) {
                        printf("Invalid email!\n");
                        printf("Press any key to continue...");
                        getch();
                        break;
                    }

                    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));
                    strcpy(newCustomer->phone, phone);
                    strcpy(newCustomer->name, name);
                    strcpy(newCustomer->email, email);
                    newCustomer->visits = 1;
                    newCustomer->next = NULL;

                    if (head == NULL) {
                        head = newCustomer;
                    } else {
                        struct Customer *temp = head;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = newCustomer;
                    }

                    displayMedicineList();

                    printf("Order processed successfully!\n");
                    printf("Press any key to continue...");
                    getch();
                } else {
                    displayMedicineList();

                    printf("Order processed successfully!\n");
                    printf("Press any key to continue...");
                    getch();
                }

                break;
            }
            case 2:
                viewAllCustomers();
                break;
            case 3: {
                char phone[14];
                printf("Enter phone number to remove: ");
                scanf("%s", phone);
                removeCustomer(phone);
                break;
            }
            case 4:
                printf("Thanks for using this program!\n");
                break;
            default:
                printf("Invalid input!!\n");
                printf("Press any key to continue");
                getch();
                break;
        }
    } while (input != 4);

    return 0;
}

