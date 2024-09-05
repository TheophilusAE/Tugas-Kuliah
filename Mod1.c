#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/**
+---------------------------------+
|Nama : Theophilus Alexander Elvan|
|NIM : 2702259986				  |
+---------------------------------+
**/

//Declaration Variable for looping
int i;

//Struct
struct barang {
	char num[3];
	char code[10];
	char med_name[50];
	char disease[50];
	int stock;
	float price;
};

//Prototype void
void add(struct barang *ptr);
void sell(struct barang *ptr);

//main
int main () {
	int input;
	struct barang medic[10];
	
	//Declare struct
	strcpy(medic[0].num,"01");
	strcpy(medic[0].code,"DIZ001");
	strcpy(medic[0].med_name,"Paramex");
	strcpy(medic[0].disease,"Dizziness");
	medic[0].stock = 120;
	medic[0].price = 14.000;
	
	strcpy(medic[1].num,"02");
	strcpy(medic[1].code,"FLU001");
	strcpy(medic[1].med_name,"Panadol");
	strcpy(medic[1].disease,"Flu & Fever");
	medic[1].stock = 57;
	medic[1].price = 8.000;
	
	strcpy(medic[2].num,"03");
	strcpy(medic[2].code,"DIA001");
	strcpy(medic[2].med_name,"Diatabs");
	strcpy(medic[2].disease,"Diarrhea");
	medic[2].stock = 10;
	medic[2].price = 6.500;
	
	strcpy(medic[3].num,"04");
	strcpy(medic[3].code,"DIA002");
	strcpy(medic[3].med_name,"Diatabs");
	strcpy(medic[3].disease,"Diarrhea");
	medic[3].stock = 18;
	medic[3].price = 6.000;
	
	
	//program
	do {
		system ("cls");
		printf ("                              +--------------------+                             \n");
		printf ("                              |   SUNIB HOSPITAL   |                             \n");
		printf ("                              +--------------------+                             \n");
	
		printf ("+-------------------------------------------------------------------------------+\n");
		printf ("| No. | Medicine code  | Medicine Name  | Disease      | Stock | Price          |\n");
		printf ("|-------------------------------------------------------------------------------|\n");
		for (i = 0;i<4;i++) {
			printf ("| %s  | %-13s  | %-13s  | %-12s | %-5d | RP. %-8.3f,- |\n"
		,medic[i].num,medic[i].code,medic[i].med_name,medic[i].disease,medic[i].stock,medic[i].price);
		}
		printf ("+-------------------------------------------------------------------------------+\n");
		
		printf ("\nMenu : \n");
		printf ("(1.) Add Stock\n");
		printf ("(2.) Sell\n");
		printf ("(3.) Exit\n");
		printf ("Input Choice (1-3) : ");
		scanf ("%d",&input);
		
		switch (input) {
			case 1:
				add(medic);
				printf ("\nPress any button to continue...\n");
				getch ();
				break;
			
			case 2:
				sell(medic);
				printf ("\nPress any button to continue...\n");
				getch ();
				break;
			
			case 3:
				printf ("\nThankyouu For Using This Program!!!\n");
				getch ();
				break;
			
			default:
				printf("\nInvalid Input!!\n");
				getch ();
				break;
		}
		
	} while (input != 3);
	
	return 0;
}

void add(struct barang *ptr) {
	char SearchID[10];
	int quantity;
	int idx = -1;
	
	//Checking ID Availability
    do 	 {
		printf ("\nEnter Medicine Code : ");
    	scanf ("%s", &SearchID);
    	for (i = 0; i < 4; i++)	{
			if (strcmp(ptr[i].code, SearchID) == 0) {
				idx = i;
		        break;
			}
		}
		
		if (idx == -1) {
			printf ("\nMedicine Code Doesn't Exist!!!\n");
		}
	} while (idx == -1);
	
	//Updating stock
	do {
		printf ("\nEnter Medicine Quantity (1-100) :  ");
		scanf ("%d",&quantity);
		
		if ((1 <= quantity) && (quantity <= 100)) {
			ptr[idx].stock += quantity;
			printf ("\nStock Updated!\n");
			break;
		}
	} while (1);
	
}

void sell(struct barang *ptr) {
	char SearchId[50];
	int quantity;
	int idx = -1;
	float price;
	float total_price;
	
	//Checking Item ID
	do {
		printf ("\nEnter Medicine Code  : ");
		scanf("%s",&SearchId);
		for (i = 0; i < 4;i++) {
			if (strcmp(ptr[i].code, SearchId) == 0) {
				idx = i;
				break;
			}
		}
		
		if (idx == -1) {
			printf ("\nMedicine Code Doesn't Exist!!!\n");
		}
	} while (idx == -1);
	
	//Selling Item
	do {
		printf ("\nEnter Medicine Quantity (1-%d) : ",ptr[i].stock);
		scanf ("%d",&quantity);
		
		if ((1<=quantity) && (quantity <= ptr[i].stock)) {
			ptr[i].stock -= quantity;
			break;
		}
	} while(1);
	
	
	total_price = ptr[i].price * quantity;
	
	printf ("+----Total Price----+\n");
	printf ("Rp. %.3f,-\n",ptr[i].price);
	printf ("Quantity: %d\n",quantity);
	printf ("--------------------x\n");
	printf ("Total: Rp. %.3f,-\n",total_price);
	printf ("+-------------------+\n");
	
	printf ("\nThank You For Purchasing !!!\n");
}

/**
+---------------------------------+
|Nama : Theophilus Alexander Elvan|
|NIM : 2702259986				  |
+---------------------------------+
**/
