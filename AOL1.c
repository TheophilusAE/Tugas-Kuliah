#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char inverseCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 32;
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}

void inverseCapitalize(char *str) {
	int i;
    int length = strlen(str);
    for (i = 0; i < length; i++) {
        str[i] = inverseCase(str[i]);
    }
}

int main() {
    char input[101];
    printf("Enter a string : ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    reverseString(input);
    inverseCapitalize(input);

    printf("Converted string: %s\n", input);

    return 0;
}

