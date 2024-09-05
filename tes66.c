#include <stdio.h>
#include <stdlib.h>

// Define colors for Red-Black Tree nodes
#define RED 0
#define BLACK 1

// Define node structure for Red-Black Tree
typedef struct rb_node {
    int data;
    int color;
    struct rb_node *left, *right, *parent;
} Node;

// Function to create a new Red-Black Tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always red initially
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// Function to fix the Red-Black Tree violations after insertion
void fixViolation(Node **root, Node *z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Function to insert a node in Red-Black Tree
void insert(Node **root, int data) {
    Node *z = createNode(data);
    Node *y = NULL;
    Node *x = *root;
    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
    z->color = RED;
    fixViolation(root, z);
}

// Function to search for a node in Red-Black Tree
Node* search(Node* root, int data) {
    while (root != NULL && root->data != data) {
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Function to print Red-Black Tree (inorder traversal)
void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to create Red-Black Tree and perform operations
int main() {
    Node *root = NULL;

    int choice, data;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Create Data\n");
        printf("2. Read Data\n");
        printf("3. Update Data\n");
        printf("4. Delete Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                printf("Data %d inserted into Red-Black Tree.\n", data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Data %d found in Red-Black Tree.\n", data);
                else
                    printf("Data %d not found in Red-Black Tree.\n", data);
                break;
            case 3:
                printf("Update Data is not implemented in this example.\n");
                break;
            case 4:
                printf("Delete Data is not implemented in this example.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    // Free memory for Red-Black Tree nodes
    // This can be done recursively using a post-order traversal
    // but for simplicity, we are not including it in this example

    return 0;
}

