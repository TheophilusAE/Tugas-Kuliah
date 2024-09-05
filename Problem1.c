#include <stdio.h>
#include <string.h>

int main () {
	int smiley = 0;
	int frowny = 0;
	char text[160];
	
	fgets (text,sizeof(text),stdin);
	
	int length = strlen(text);
	int i;
	for (i = 0;i < length - 1;i++){
		if (text[i] == ':' && text[i + 1] == ')'){
			smiley++;
		}
		else if (text[i] == ':' && text[i + 1] == '('){
			frowny++;
		}
	}
	
	if (smiley > 0 && frowny == 0) {
        printf("alive\n");
    }
	else if (frowny > 0 && smiley == 0) {
        printf("undead\n");
    }
	else if (smiley > 0 && frowny > 0) {
        printf("double agent\n");
    }
	else {
        printf("machine\n");
    }

    return 0;
}
