#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main () {
	int input;
	do {
		system ("cls");
		printf ("Sunib Hospital\n");
		printf ("==============\n");
		printf ("1. View Medicine\n");
		printf ("2. Insert Medicine\n");
		printf ("3. Remove Medicine\n");
		printf ("4. Exit\n");
		printf (">> ");
		scanf ("%d",&input);
		
		switch (input) {
			case 1:
				
				printf ("Press Any Key To Continue...");
				getch();
				break;
			case 2:
				printf ("Press Any Key To Continue...");
				getch();
				break;
			case 3:
				printf ("Press Any Key To Continue...");
				getch();
				break;
			case 4:
				return 0;
			default:
				printf ("Invalid Input!!!");
				getch();
				break;
		}
	}while (input != 4);
	
	return 0;
}
