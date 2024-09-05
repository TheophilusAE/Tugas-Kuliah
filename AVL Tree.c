#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main () {
	
	int choice;
	
	
	do {
		system("cls");
		printf ("Bluejack GShop\n");
		printf ("==============\n");
		printf ("1. Insert Game\n");
		printf ("2. View Game\n");
		printf ("3. Update Stock\n");
		printf ("4. Exit\n");
		printf (">> ");
		scanf ("%d",&choice);
		
		switch (choice){
			case 1:
				printf("menu");
				getch ();
				break;
			case 2:
				
				getch ();
				break;
				
			case 3:
				
				getch ();
				break;
				
			case 4:
				printf("Thankyou for using this program!!");
				getch ();
				break;
		}
	
	}while (choice != 4);
	
	return 0;
	
}
