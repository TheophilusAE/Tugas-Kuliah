#include <stdio.h>

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10}; //data-data yang mau dipake untuk mencari
	int i;
	for(i = 0; i < 10; i++){
		
		if (arr[i] == 1){ 	// angka yang dicari, bisa diganti pake variabel, kalau mau cari string pake strcmp() == 0 atau strstr()
			printf("The number is in index %d", i); 
			break;	
		}
		else printf("There's no such number!");
	}
	
	return 0;
}
