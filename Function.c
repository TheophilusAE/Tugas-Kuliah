#include <stdio.h>
#include <stdlib.h>

float add(float a, float b) {
	float c = a+b;
    return c;
}

float subtract(float a, float b) {
    return a - b;
}

float divide(float a, float b) {
    return a / b;
}

float multiply(float a, float b) {
    return a * b;
}

int mod(int a, int b) {
    return a % b;
}

int main() {
    int input;
    float a1, a2, result;

    do {
        system("cls");
        printf("--------Welcome To Sunib Calculator---------\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Divide\n");
        printf("4. Multiply\n");
        printf("5. Mod\n");
        printf("6. Exit\n");
        printf("Input choice >> ");
        scanf("%d", &input);

        if (input >= 1 && input <= 5) {
            printf("Input number 1: ");
            scanf("%f", &a1);
            printf("Input number 2: ");
            scanf("%f", &a2);
        }

        switch (input) {
            case 1:
                result = add(a1, a2);
                printf("%.3f + %.3f = %.3f\n", a1, a2, result);
                break;
            case 2:
                result = subtract(a1, a2);
                printf("%.3f - %.3f = %.3f\n", a1, a2, result);
                break;
            case 3:
                result = divide(a1, a2);
                printf("%.3f / %.3f = %.3f\n", a1, a2, result);
                break;
            case 4:
                result = multiply(a1, a2);
                printf("%.3f * %.3f = %.3f\n", a1, a2, result);
                break;
            case 5:
                result = mod((int)a1, (int)a2);
                printf("%d %% %d = %d\n", (int)a1, (int)a2, (int)result);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice!\n");
        }

        if (input != 6) {
            printf("Press any key to continue...\n");
            getchar();
            getchar();
        }

    } while (input != 6);

    return 0;
}

