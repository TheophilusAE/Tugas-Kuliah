#include <stdio.h>

int main(){
	FILE *file = fopen("Nama file i.e file.txt", "mode bukanya i.e r(read), w(write), a(append), a+(append and read) dll");
	
	if (file == NULL){ //ngecek file nya ada isi atau engga, kalau engga ada nanti berhenti
		printf("Error in reading the file");
		return 1;
	}
	
	fscanf(file (nama pointer filenya), "%d" (specifiernya), nama variable yang ingin dimasukkin); //ngebaca data di file
	fscanf(file, "%d", Theo);
	
	fprintf(file (nama pointer filen yang ingin ditulisi), "%d", yang ingin ditulisi); //menulis file 
	
	fclose(nama file); // untuk menutupi file 
	// setiap selesai penggunaan file perlu ditulisi ini supaya bisa berhenti programnya atau ga bakalan ngebuka terus filenya
}
