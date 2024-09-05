#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap *createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap*) malloc(sizeof(MaxHeap));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    maxHeap->array = (int*) calloc(capacity, sizeof(int));

    return maxHeap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap *heap, int index) {
    int parentIndex = (index - 1) / 2;
    if (index && heap->array[parentIndex] < heap->array[index]) {
        swap(&heap->array[parentIndex], &heap->array[index]);
        heapifyUp(heap, parentIndex);
    }
}

void heapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(MaxHeap *heap, int data) {
    if (heap->size == heap->capacity) {
        printf("MaxHeap is full\n");
        return;
    }

    heap->size++;
    heap->array[heap->size - 1] = data;
    heapifyUp(heap, heap->size - 1);
}

void deleteMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("There is nod data\n");
        return;
    }

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    printf("Delete Success\n\n");
}

void printHeap(MaxHeap *heap) {
	int i,j;
    printf("Only 5 levels shown\n");
    int level = 0;
    int elementsInLevel = 1;
    int index = 0;

    while (level < 5 && index < 31) {
        int spaces = (1 << (5 - level)) - 1; 
        for (i = 0; i < spaces; i++) {
            printf("  ");
        }

        for (i = 0; i < elementsInLevel && index < 31; i++) {

            if(heap->array[index]) printf("%3d", heap->array[index++]);
            else printf("NL");

            if (i < elementsInLevel - 1) {
                for (j = 0; j < (spaces * 2) + 1; j++) {
                    printf("  ");
                }
            }
        }
        printf("\n");
        level++;
        elementsInLevel *= 2; 
    }

    printf("\n");
}

int main() {
    int choice;
    MaxHeap *maxHeap = createMaxHeap(100);

    do {
        choice = 0;
        puts("MAX HEAP TREE");
        puts("=============");
        puts("1. Insert");
        puts("2. View");
        puts("3. Delete");
        puts("4. Exit");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data, count;
                do {
                    printf("Input your data [1-100]: ");
                    count = scanf("%d", &data);
                    fflush(stdin);
                } while (data < 1 || data > 100 || !count);

                insert(maxHeap, data);
                printf("Insert Success\n\n"); 
                break;
            }

            case 2: {
                printHeap(maxHeap);
                break;
            }

            case 3: {
                deleteMax(maxHeap);
                break;
            }
            
            case 4: {
                free(maxHeap->array);
                free(maxHeap);
                break;
            }

            default: {
                puts("Invalid Choice !");
                break;
            }
        }

        if (choice != 4) {
            printf("Press Anything to Continue...");
            getch();
            fflush(stdin);
            system("cls");
        }

    } while (choice != 4);

    return 0;
}
