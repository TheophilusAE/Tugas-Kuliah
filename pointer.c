#include <stdio.h>

int main() {
    int var = 10;
    int *ptr = &var;

    printf("Value of var: %d\n", var);
    printf("Value of var using pointer: %d\n", *ptr);

    printf("Address of var: %p\n", (void*)&var);
    printf("Address stored in pointer ptr: %p\n", (void*)ptr);

    *ptr = 20;

    printf("Modified value of var: %d\n", var);

    return 0;
}

