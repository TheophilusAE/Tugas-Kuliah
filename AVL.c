#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Game {
    char title[26];
    char genre[11];
    int stock;
    struct Game *left;
    struct Game *right;
    int height;
} Game;


int max(int a, int b);
int height(Game *N);
Game* newNode(char title[], char genre[], int stock);
Game *rightRotate(Game *y);
Game *leftRotate(Game *x);
int getBalance(Game *N);
Game* insertGame(Game* node, char title[], char genre[], int stock);
void inOrder(Game *root);
Game* search(Game *root, char title[]);
Game* minValueNode(Game* node);
Game* deleteNode(Game* root, char title[]);
Game* updateStock(Game* root, char title[], int quantity, char type[]);


Game *root = NULL;

int main() {
    int choice;

    do {
        system("cls");
        printf("Bluejack GShop\n");
        printf("==============\n");
        printf("1. Insert Game\n");
        printf("2. View Game\n");
        printf("3. Update Stock\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[26], genre[11];
                int stock;
                
                printf("Enter game title (5-25 characters): ");
                scanf("%s", title);
                if (strlen(title) < 5 || strlen(title) > 25) {
                    printf("Title must be between 5 and 25 characters.\n");
                    getch();
                    break;
                }
                
                if (search(root, title) != NULL) {
                    printf("Title must be unique.\n");
                    getch();
                    break;
                }
                
                printf("Enter game genre (Action, RPG, Adventure, Card Game): ");
                scanf("%s", genre);
                if (strcmp(genre, "Action") != 0 && strcmp(genre, "RPG") != 0 && strcmp(genre, "Adventure") != 0 && strcmp(genre, "Card Game") != 0) {
                    printf("Invalid genre.\n");
                    getch();
                    break;
                }
                
                printf("Enter game stock (at least 1): ");
                scanf("%d", &stock);
                if (stock < 1) {
                    printf("Stock must be at least 1.\n");
                    getch();
                    break;
                }

                root = insertGame(root, title, genre, stock);
                printf("Game inserted successfully.\n");
                getch();
                break;
            }
            case 2: {
                if (root == NULL) {
                    printf("Warehouse is empty!\n");
                } else {
                    inOrder(root);
                }
                getch();
                break;
            }
            case 3: {
                char title[26], type[10];
                int quantity;
                
                printf("Enter game title to update: ");
                scanf("%s", title);
                Game *game = search(root, title);
                if (game == NULL) {
                    printf("Data not found\n");
                    getch();
                    break;
                }
                
                printf("Enter update type (add/remove): ");
                scanf("%s", type);
                if (strcmp(type, "add") != 0 && strcmp(type, "remove") != 0) {
                    printf("Invalid update type.\n");
                    getch();
                    break;
                }
                
                printf("Enter quantity to %s: ", type);
                scanf("%d", &quantity);
                if (strcmp(type, "remove") == 0 && (quantity < 1 || quantity > game->stock)) {
                    printf("Invalid quantity.\n");
                    getch();
                    break;
                }
                if (strcmp(type, "add") == 0 && quantity < 1) {
                    printf("Quantity must be at least 1.\n");
                    getch();
                    break;
                }

                root = updateStock(root, title, quantity, type);
                printf("Stock updated successfully.\n");
                getch();
                break;
            }
            case 4:
                printf("Thank you for using this program!!");
                getch();
                break;
        }
    } while (choice != 4);

    return 0;
}


int height(Game *N) {
    if (N == NULL)
        return 0;
    return N->height;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}


Game* newNode(char title[], char genre[], int stock) {
    Game* game = (Game*) malloc(sizeof(Game));
    strcpy(game->title, title);
    strcpy(game->genre, genre);
    game->stock = stock;
    game->left = NULL;
    game->right = NULL;
    game->height = 1; 
    return(game);
}


Game *rightRotate(Game *y) {
    Game *x = y->left;
    Game *T2 = x->right;

    
    x->right = y;
    y->left = T2;

    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    
    return x;
}


Game *leftRotate(Game *x) {
    Game *y = x->right;
    Game *T2 = y->left;

    
    y->left = x;
    x->right = T2;

    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    
    return y;
}


int getBalance(Game *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


Game* insertGame(Game* node, char title[], char genre[], int stock) {
    if (node == NULL)
        return(newNode(title, genre, stock));

    if (strcmp(title, node->title) < 0)
        node->left = insertGame(node->left, title, genre, stock);
    else if (strcmp(title, node->title) > 0)
        node->right = insertGame(node->right, title, genre, stock);
    else 
        return node;


    node->height = 1 + max(height(node->left), height(node->right));


    int balance = getBalance(node);


    if (balance > 1 && strcmp(title, node->left->title) < 0)
        return rightRotate(node);

    
    if (balance < -1 && strcmp(title, node->right->title) > 0)
        return leftRotate(node);

    
    if (balance > 1 && strcmp(title, node->left->title) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    
    if (balance < -1 && strcmp(title, node->right->title) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void inOrder(Game *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Title: %s, Genre: %s, Stock: %d\n", root->title, root->genre, root->stock);
        inOrder(root->right);
    }
}


Game* search(Game *root, char title[]) {
    if (root == NULL || strcmp(root->title, title) == 0)
        return root;

    if (strcmp(title, root->title) < 0)
        return search(root->left, title);

    return search(root->right, title);
}


Game* updateStock(Game* root, char title[], int quantity, char type[]) {
    Game *game = search(root, title);
    if (game == NULL)
        return root;

    if (strcmp(type, "remove") == 0) {
        game->stock -= quantity;
        if (game->stock == 0) {
            root = deleteNode(root, title);
        }
    } else if (strcmp(type, "add") == 0) {
        game->stock += quantity;
    }

    return root;
}


Game* deleteNode(Game* root, char title[]) {
    if (root == NULL)
        return root;

    if (strcmp(title, root->title) < 0)
        root->left = deleteNode(root->left, title);
    else if (strcmp(title, root->title) > 0)
        root->right = deleteNode(root->right, title);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Game *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            Game* temp = minValueNode(root->right);
            strcpy(root->title, temp->title);
            strcpy(root->genre, temp->genre);
            root->stock = temp->stock;
            root->right = deleteNode(root->right, temp->title);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


Game* minValueNode(Game* node) {
    Game* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

