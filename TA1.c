#include <stdio.h>
#include <string.h>

int main() {
	int i;
    char input[500];
    fgets(input, sizeof(input), stdin);

    int smiley_count = 0;
    int frowny_count = 0;
    int length = strlen(input);

    for (i = 0; i < length - 1; i++) {
        if (input[i] == ':' && input[i + 1] == ')') {
            smiley_count++;
        }
		else if (input[i] == ':' && input[i + 1] == '(') {
            frowny_count++;
        }
    }

    if (smiley_count > 0 && frowny_count == 0) {
        printf("alive\n");
    }
	else if (frowny_count > 0 && smiley_count == 0) {
        printf("undead\n");
    }
	else if (smiley_count > 0 && frowny_count > 0) {
        printf("double agent\n");
    }
	else {
        printf("machine\n");
    }

    return 0;
}

