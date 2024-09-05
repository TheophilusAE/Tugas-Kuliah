#include <stdio.h>

typedef struct{
	char location[50];
	char city[50];
	int price;
	int rooms;
	int bathroom;
	int carpark;
	char type[50];
	char furnish[50];
}Hotel;

int Atoi(const char *str) {
    int result = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13)) {
        str++;
    }

    if (*str == '-' || *str == '+') {
        sign = (*str++ == '-') ? -1 : 1;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str++ - '0');
    }

    return sign * result;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int compStr(const char *haystack, const char *needle) {
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (!*n) {
            return 1;
        }

        haystack++;
    }

    return 0;
}

void display(Hotel data[], int r){
	int i;
	printf("\n%-25s%-25s%-15s%-12s%-15s%-15s%-25s%s\n", 
			"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
	
	for(i = 0; i < r; i++){
		printf("%-25s%-25s%-15d%-12d%-15d%-15d%-25s%s\n", data[i].location, data[i].city,
				data[i].price, data[i].rooms, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
	}
}

void select(Hotel data[], int r, const char *c, const char *f){
	
	int found = 0;
	int match;
	int i;
	for(i = 0; i < r; i++){
		if(compStr(c,"Location") == 1){
			match = compStr(data[i].location, f);	
		}else if(compStr(c,"City") == 1){
			match = compStr(data[i].city, f);
		}else if(compStr(c,"Price") == 1){
			match = (data[i].price == Atoi(f));
		}else if(compStr(c,"Rooms") == 1){
			match = (data[i].rooms == Atoi(f));
		}else if(compStr(c,"Bathroom") == 1){
			match = (data[i].bathroom == Atoi(f));
		}else if(compStr(c,"Carpark") == 1){
			match = (data[i].carpark == Atoi(f));
		}else if(compStr(c,"Type") == 1){
			match = compStr(data[i].type, f);
		}else if(compStr(c,"Furnish") == 1){
			match = compStr(data[i].furnish, f);
		}
		
		if(match){
			if(!found){
				printf("Data found. Detail of data:\n");
				printf("%-25s%-25s%-15s%-12s%-15s%-15s%-25s%s\n", 
						"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
				found = 1;
			}
			printf("%-25s%-25s%-15d%-12d%-15d%-15d%-25s%s\n", data[i].location,
					data[i].city, data[i].price, data[i].rooms, data[i].bathroom,
					data[i].carpark, data[i].type, data[i].furnish);
		}
	}
	
	if(!found){
		printf("Data not found!\n");
	}

}

void sort(Hotel data[], int r, const char *c, const char *o){
	Hotel temp;
	int match;
	int i,j;
	
	for(i = 0; i < r-1; i++){
		for(j = i+1; j < r; j++){
			if(compStr(c,"Location") == 1){
				match = strcmp(data[i].location, data[j].location);	
			}else if(compStr(c,"City") == 1){
				match = strcmp(data[i].city, data[j].city);
			}else if(compStr(c,"Price") == 1){
				match = data[i].price - data[j].price;
			}else if(compStr(c,"Rooms") == 1){
				match = data[i].rooms - data[j].rooms;
			}else if(compStr(c,"Bathroom") == 1){
				match = data[i].bathroom - data[j].bathroom;
			}else if(compStr(c,"Carpark") == 1){
				match = data[i].carpark - data[j].carpark;
			}else if(compStr(c,"Type") == 1){
				match = strcmp(data[i].type, data[j].type);
			}else if(compStr(c,"Furnish") == 1){
				match = strcmp(data[i].furnish, data[j].furnish);
			}else{
				printf("Invalid Column\n");
				return;
			}
			
			if((compStr(o, "asc") == 1 && match > 0) || (compStr(o, "desc") == 1 && match < 0)){
				temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
	
	printf("Data found. Detail of data:\n");
	display(data, 10);
}

void Export(Hotel data[], int r, const char* filename){
	FILE *file;
	char outputname[1000];
	const char *ptr;
	int j;
	
	for (ptr = filename; *ptr; ++ptr) {
        if (*ptr == ' ') {
            printf("Invalid filename. Please avoid spaces.\n");
            return;
        }
    }
    
    snprintf(outputname, sizeof(outputname), "%s.csv", filename);
    
    file = fopen(outputname, "r");
    if (file != NULL) {
        fclose(file);
        printf("File '%s' already exists. Please choose a different filename.\n", outputname);
        return;
    }

    file = fopen(outputname, "w");
    if (file == NULL) {
        printf("Error creating or opening the file.\n");
        return;
    }

    fprintf(file, "Location,City,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");

    for (j = 0; j < r; j++) {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n",
               data[j].location, data[j].city, data[j].price,
               data[j].rooms, data[j].bathroom, data[j].carpark,
               data[j].type, data[j].furnish);
    }

    fclose(file);
    printf("Data successfully written to file %s!\n", outputname);
}

int main(){
	Hotel data[4000];
	FILE *file;
	file = fopen("file.csv", "r");
	
	if(file == NULL){
		printf("Error Reading the CSV file.\n"); 
		fclose(file);
		return 1;
	}
	
	int rows = 0;
	char line[500];
	
	if(fgets(line, sizeof(line), file) == NULL){
		printf("There's no Data'\n");
		fclose(file);
		return 1;
	}
	
	do{
		fgets(line, sizeof(line), file);
		
		int read = sscanf(line, "%49[^,],%49[^,],%d,%d,%d,%d,%49[^,],%49[^\n]", 
							data[rows].location, data[rows].city, &data[rows].price, &data[rows].rooms,
							&data[rows].bathroom, &data[rows].carpark, data[rows].type, data[rows].furnish);
		
		if(read != 8){
			printf("Invalid Data Format\n");
			fclose(file);
			return 1;
		}

		rows++;
		
	} while (!feof(file));
	
	int choice;
	do{
		printf("What do you want to do?\n");
		printf("1. Display Data\n");
		printf("2. Search Data\n");
		printf("3. Sort Data\n");
		printf("4. Export Data\n");
		printf("5. Exit\n");
		printf("Your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				int row;
				printf("Number of rows: ");
				scanf("%d", &row);
				display(data, row);
				break;
			}
			case 2:
			{
				char column[50];
				char find[50];
				printf("Choose column: ");
				scanf("%s", column);
				printf("What data do you want to find? ");
				scanf("%s", find);
				select(data, rows, column, find);
				break;
			}
			case 3:
			{
				char column[50];
				char order[5];
				printf("Choose column: ");
				scanf(" %s", column);
				printf("Sort ascending or descending (asc/desc)? ");
				scanf(" %s", order);
				sort(data, rows, column, order);	
				break;
			}
			case 4:
			{
				char name[50];
				printf("File name: ");
				scanf("%s", name);
				Export(data, rows, name);
				break;
			}
			case 5:
			{
				printf("You have exited the program\n");
				break;
			}
		}
		
		if (choice != 5) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n')
                ; 
            while (getchar() != '\n')
                ; 
             printf("\033[2J\033[H");
        }
		
	} while(choice != 5);
	
	return 0;
}
