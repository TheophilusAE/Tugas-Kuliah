#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
	int i;
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = false;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a word into the Trie
void insert(TrieNode* root, char* word) {
    TrieNode* temp = root;
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index]) {
            temp->children[index] = createNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

// Function to search for a word in the Trie
bool search(TrieNode* root, char* word) {
    TrieNode* temp = root;
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp != NULL && temp->isEndOfWord);
}

// Function to delete a word from the Trie
bool deleteWord(TrieNode* root, char* word) {
    TrieNode* temp = root;
    int len = strlen(word);
    int i;
    for (i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }
    if (temp != NULL && temp->isEndOfWord) {
        temp->isEndOfWord = false;
        return true;
    }
    return false;
}

// Function to print all words in the Trie
void printTrieWords(TrieNode* root, char* buffer, int depth) {
    if (root == NULL)
        return;
    if (root->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            buffer[depth] = 'a' + i;
            printTrieWords(root->children[i], buffer, depth + 1);
        }
    }
}

int main() {
    TrieNode* root = createNode();

    int choice;
    char word[100];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert word\n");
        printf("2. Delete word\n");
        printf("3. Search word\n");
        printf("4. View all words in Trie\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word to insert: ");
                scanf("%s", word);
                insert(root, word);
                printf("Word '%s' inserted into Trie.\n", word);
                break;
            case 2:
                printf("Enter word to delete: ");
                scanf("%s", word);
                if (deleteWord(root, word)) {
                    printf("Word '%s' deleted from Trie.\n", word);
                } else {
                    printf("Word '%s' not found in Trie.\n", word);
                }
                break;
            case 3:
                printf("Enter word to search: ");
                scanf("%s", word);
                printf("Searching for '%s': %s\n", word, search(root, word) ? "Found" : "Not found");
                break;
            case 4:
                printf("Words in Trie:\n");
                printTrieWords(root, word, 0);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    // No need to free memory as we are not using dynamic memory allocation in this example

    return 0;
}

