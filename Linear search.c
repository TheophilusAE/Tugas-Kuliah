#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target,i;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d.\n", i);
            return 0;
        }
    }

    printf("Element not found in the array.\n");
    return 0;
}

