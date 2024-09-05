#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
	int j;
  
  	int pivot = array[high];
  
  	int i = (low - 1);

  	for (j = low; j < high; j++) {
   	 if (array[j] <= pivot) {
    	i++;
      	swap(&array[i], &array[j]);
   		}
  	}

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
	int i;
  	for (i = 0; i < size; ++i) {
    	printf("%d  ", array[i]);
  	}
  printf("\n");
}


int main() {
  int i,m,l;
  l = 1;
  printf ("Masukan jumlah data : ");
  scanf ("%d",&m);
  int data[m];
  
  for (i = 0;i < m; i++) {
  	printf ("Data ke %d : ",l);
  	scanf ("%d",&data[i]);
  	l++;
  }
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  
  quickSort(data, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}
