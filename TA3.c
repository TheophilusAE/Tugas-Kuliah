#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100
#define MAX_NAME_LEN 31
#define MAX_CLASS_LEN 81

typedef struct {
    char name[MAX_NAME_LEN];
    char class[MAX_CLASS_LEN];
} Person;

int class_value(const char* class_str) {
    if (strcmp(class_str, "upper") == 0) {
    	return 2;
	}
    if (strcmp(class_str, "middle") == 0) {
    	return 1;
	}
    if (strcmp(class_str, "lower") == 0) {
    	return 0;
	}
    return 1;
}

int compare_classes(const char* class1, const char* class2) {
	int i;
    char class1_parts[10][7], class2_parts[10][7];
    int len1 = 0, len2 = 0;

    char temp_class1[MAX_CLASS_LEN], temp_class2[MAX_CLASS_LEN];
    strcpy(temp_class1, class1);
    strcpy(temp_class2, class2);

    char* token = strtok(temp_class1, "-");
    while (token != NULL) {
        strcpy(class1_parts[len1++], token);
        token = strtok(NULL, "-");
    }

    token = strtok(temp_class2, "-");
    while (token != NULL) {
        strcpy(class2_parts[len2++], token);
        token = strtok(NULL, "-");
    }

    int max_len = len1 > len2 ? len1 : len2;
    for (i = 0; i < max_len; i++) {
        int val1 = i < len1 ? class_value(class1_parts[len1 - 1 - i]) : 1;
        int val2 = i < len2 ? class_value(class2_parts[len2 - 1 - i]) : 1;
        if (val1 != val2) {
            return val2 - val1;
        }
    }

    return 0;
}

int compare_people(const void* a, const void* b) {
    Person* person1 = (Person*)a;
    Person* person2 = (Person*)b;

    int class_cmp = compare_classes(person1->class, person2->class);
    if (class_cmp == 0) {
        return strcmp(person1->name, person2->name);
    }
    return class_cmp;
}

int main() {
    int T,i,t;
    scanf("%d", &T);

    for (t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);
        Person people[MAX_PEOPLE];

        for (i = 0; i < n; i++) {
            scanf("%s", people[i].name);
            people[i].name[strlen(people[i].name) - 1] = '\0';
            scanf(" %s class", people[i].class);
        }

        qsort(people, n, sizeof(Person), compare_people);

        for (i = 0; i < n; i++) {
            printf("%s\n", people[i].name);
        }
        printf("==============================\n");
    }

    return 0;
}

