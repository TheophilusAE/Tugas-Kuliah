/*
    COFFE SHOP
    NAMA KELOMPOK :
         1. ADIGUNA SANJAYA LIGAWAN ()
         2. KIKI ()
         3. FLOURENSIA ()

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //tidur


#define CLEAR_SCREEN "clear"


#define ANSI_BOLD "\033[1m"
#define ANSI_RESET "\033[0m"
#define ANSI_BG_BLUE "\033[44m"
#define ANSI_FG_WHITE "\033[37m"
#define ANSI_FG_RED "\033[31m"

int i,j;

struct SalesData {
    int tanggal;
    int bulan;
    char kasir[50];
    char jenis[20];
    char nama[50];
    int jumlah;
    float harga;
    float total_pembayaran;
};

struct ItemFrequency {
   char nama[50];
   int frequency;
};

struct Stock {
    char jenis[20];
    char nama[50];
    int jumlah;
    float harga;

};

struct Item {
 char category[20];
 char name[20];
 int quantity;
 float price;
};

void swich (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high) {
	int j;
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swich(&arr[i], &arr[j]);
        }
    }
    swich(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void readFile(struct Item makanan[], int* makanan_count) {
    FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    *makanan_count = 0;

    while (!feof(file)) {
        struct Item item;
        if (fscanf(file, "%s %s %d %f", item.category, item.name, &item.quantity, &item.price) != EOF) {
            if(strcmp(item.category, "Makanan") == 0) {
                makanan[*makanan_count] = item;
                (*makanan_count)++;
            }
        }
    }

    fclose(file);
}

void printMakanan(struct Item makanan[], int makanan_count) {
	int i;
 for(i = 0; i < makanan_count; i++) {
  printf("Category: %s - Name: %s - Quantity: %d - Price: %.2f\n", 
          makanan[i].category, makanan[i].name, makanan[i].quantity, makanan[i].price);
 }
}

void readFile1(struct Item minuman[], int* minuman_count) {
    FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    *minuman_count = 0;

    while (!feof(file)) {
        struct Item item;
        if (fscanf(file, "%s %s %d %f", item.category, item.name, &item.quantity, &item.price) != EOF) {
            if(strcmp(item.category, "Minuman") == 0) {
                minuman[*minuman_count] = item;
                (*minuman_count)++;
            }
        }
    }

    fclose(file);
}

int getMinumanCount(int* minuman_count) {
    return *minuman_count;
}

void printMinuman(struct Item minuman[], int minuman_count) {
	int i;
 for(i = 0; i < minuman_count; i++) {
  printf("Category: %s - Name: %s - Quantity: %d - Price: %.2f\n", 
          minuman[i].category, minuman[i].name, minuman[i].quantity, minuman[i].price);
 }
}




void print_menu() {
    FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
    if (file != NULL) {
        struct Stock stock;
        printf("\nMenu Barang:\n");
        printf("| %-20s | %-20s | %-10s | %-10s |\n", "Jenis", "Nama", "Stok", "Harga");
        while (fscanf(file, "%s %s %d %f", stock.jenis, stock.nama, &stock.jumlah, &stock.harga) != EOF) {
            printf("| %-20s | %-20s | %-10d | %-10.2f |\n", stock.jenis, stock.nama, stock.jumlah, stock.harga);
        }
        fclose(file);
    } else {
        printf("Gagal membuka file stock.\n");
    }
}

void sort_stock(char *key) {
 struct Stock stock[100];
 int count = 0;
 int i;

 FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
 if (file != NULL) {
     while (fscanf(file, "%s %s %d %f", stock[count].jenis, stock[count].nama, &stock[count].jumlah, &stock[count].harga) != EOF) {
         count++;
     }

     fclose(file);
 } else {
     printf("Failed to open file.\n");
     return;
 }

 // Sort the stock based on the quantity of the item
 for (i = 1; i < count; i++) {
     struct Stock key = stock[i];
     int j = i - 1;

     // Move elements of stock[0..i-1] that have less quantity than key to one position ahead of their current position
     while (j >= 0 && stock[j].jumlah > key.jumlah) {
         stock[j + 1] = stock[j];
         j = j - 1;
     }
     stock[j + 1] = key;
 }

 // Display the sorted stock
 printf("\nSorted Stock:\n");
 for (i = 0; i < count; i++) {
     printf("%s %s %d %f\n", stock[i].jenis, stock[i].nama, stock[i].jumlah, stock[i].harga);
 }
}


void sort_stock_desc(char *key) {
 struct Stock stock[100];
 int count = 0;
 int i;

 FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
 if (file != NULL) {
    while (fscanf(file, "%s %s %d %f", stock[count].jenis, stock[count].nama, &stock[count].jumlah, &stock[count].harga) != EOF) {
        count++;
    }

    fclose(file);
 } else {
    printf("Failed to open file.\n");
    return;
 }

 // Sort the stock in descending order based on the quantity of the item
 for (i = 1; i < count; i++) {
    struct Stock key = stock[i];
    int j = i - 1;

    // Move elements of stock[0..i-1] that have more quantity than key to one position ahead of their current position
    while (j >= 0 && stock[j].jumlah < key.jumlah) {
        stock[j + 1] = stock[j];
        j = j - 1;
    }
    stock[j + 1] = key;
 }

 // Display the sorted stock
 printf("\nSorted Stock in Descending Order:\n");
 for (i = 0; i < count; i++) {
    printf("%s %s %d %f\n", stock[i].jenis, stock[i].nama, stock[i].jumlah, stock[i].harga);
 }
}

void add_stock(const char* nama, int jumlah) {
 FILE* tempFile = fopen("/Users/adisl/Downloads/tugas_finpro/stock_temp.txt", "w");
 FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
 if (tempFile != NULL && file != NULL) {
    struct Stock stock;
    int found = 0;
    while (fscanf(file, "%s %s %d %f\n", stock.jenis, stock.nama, &stock.jumlah, &stock.harga) != EOF) {
        if (strcmp(stock.nama, nama) == 0) {
            stock.jumlah += jumlah; // Add the new quantity to the existing stock
            found = 1;
        }
        fprintf(tempFile, "%s %s %d %f\n", stock.jenis, stock.nama, stock.jumlah, stock.harga);
    }
    if (!found) {
        printf("Item not found in stock.\n");
    }
    fclose(file);
    fclose(tempFile);
    remove("/Users/adisl/Downloads/tugas_finpro/stock.txt");
    rename("/Users/adisl/Downloads/tugas_finpro/stock_temp.txt", "/Users/adisl/Downloads/tugas_finpro/stock.txt");
    printf("Stock berhasil diubah.\n");
 } else {
    printf("Gagal membuka file stock.\n");
 }
}





int get_stock(const char* nama) {
    FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
    if (file != NULL) {
        struct Stock stock;
        while (fscanf(file, "%s %d", stock.nama, &stock.jumlah) != EOF) {
            if (strcmp(stock.nama, nama) == 0) {
                fclose(file);
                return stock.jumlah;
            }
        }
        fclose(file);
    }
    return -1; // Stock not found
}

void decrease_stock(const char* nama, int jumlah) {
  int stock = get_stock(nama);
  if (stock == -1) {
      printf("Error: Stock tidak ditemukan.\n");
  } else if (stock < jumlah) {
      printf("Error: Jumlah yang dibeli melebihi stok yang tersedia.\n");
  } else {
      stock -= jumlah;
      FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
      FILE* tempFile = fopen("/Users/adisl/Downloads/tugas_finpro/stock_temp.txt", "w");
      if (file != NULL && tempFile != NULL) {
          struct Stock tempStock;
          while (fscanf(file, "%s %s %d %f\n", tempStock.jenis, tempStock.nama, &tempStock.jumlah, &tempStock.harga) != EOF) {

              if (strcmp(tempStock.nama, nama) == 0) {
                tempStock.jumlah = stock;
                printf("Stock updated.\n");
              }
              fprintf(tempFile, "%s %s %d %f\n", tempStock.jenis, tempStock.nama, tempStock.jumlah, tempStock.harga);
          }
          fclose(file);
          fclose(tempFile);
          remove("/Users/adisl/Downloads/tugas_finpro/stock.txt");
          rename("/Users/adisl/Downloads/tugas_finpro/stock_temp.txt", "/Users/adisl/Downloads/tugas_finpro/stock.txt");

      } else {
          printf("Gagal membuka file stock.\n");
      }
  }
}

void print_stock() {
   FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
   if (file != NULL) {
       struct Stock stock;
       printf("\nStock Barang:\n");
       printf("| %-20s | %-20s | %-10s | %-10s |\n", "Nama", "Jenis", "Stok", "Harga");

       // Print "minuman" items first
       while (fscanf(file, "%s %s %d %f", stock.nama, stock.jenis, &stock.jumlah, &stock.harga) != EOF) {
           if (strcmp(stock.jenis, "minuman") == 0) {
               printf("| %-20s | %-20s | %-10d | %-10.2f |\n", stock.nama, stock.jenis, stock.jumlah, stock.harga);
           }

       }

       // Print other items
       rewind(file);
       while (fscanf(file, "%s %s %d %f", stock.nama, stock.jenis, &stock.jumlah, &stock.harga) != EOF) {
           if (strcmp(stock.jenis, "minuman") != 0) {
               printf("| %-20s | %-20s | %-10d | %-10.2f |\n", stock.nama, stock.jenis, stock.jumlah, stock.harga);
           }

       }

       fclose(file);
   } else {
       printf("Gagal membuka file stock.\n");
   }
}



void count_item_frequency(struct ItemFrequency *items, int count) {
   for (i = 0; i < count; i++) {
       items[i].frequency = 0;
   }

   FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "r");
   if (file != NULL) {
       struct SalesData data;
       while (fscanf(file, "%d %d %s %s %s %d %f %f",
                    &data.tanggal, &data.bulan, data.kasir,
                    data.jenis, data.nama, &data.jumlah,
                    &data.harga, &data.total_pembayaran) != EOF) {
           for (i = 0; i < count; i++) {
               if (strcmp(items[i].nama, data.nama) == 0) {
                  items[i].frequency++;
                  break;
               }
           }
       }

       fclose(file);
   } else {
       printf("Gagal membaca file.\n");
   }
}


// Fungsi untuk membandingkan data berdasarkan tanggal dan bulan
int compare(const void *a, const void *b) {
    struct SalesData *dataA = (struct SalesData *)a;
    struct SalesData *dataB = (struct SalesData *)b;

    // Membandingkan tanggal jika bulan sama
    if (dataA->bulan == dataB->bulan) {
        return dataA->tanggal - dataB->tanggal;
    } else {
        return dataA->bulan - dataB->bulan;
    }
}

int compareDecending(const void *a, const void *b) {
    struct SalesData *dataA = (struct SalesData *)a;
    struct SalesData *dataB = (struct SalesData *)b;

    // Membandingkan tanggal jika bulan sama
    if (dataA->bulan == dataB->bulan) {
        return dataB->tanggal - dataA->tanggal;
    } else {
        return dataB->bulan - dataA->bulan;
    }
}


int compareTotalHargaDecending(const void *a, const void *b) {
    struct SalesData *dataA = (struct SalesData *)a;
    struct SalesData *dataB = (struct SalesData *)b;

    // Compare total_pembayaran if the month is the same
    if (dataA->bulan == dataB->bulan) {
        float totalA = dataA->total_pembayaran;
        float totalB = dataB->total_pembayaran;
        if (totalA < totalB) {
            return 1;
        } else if (totalA > totalB) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return dataB->bulan - dataA->bulan;
    }
}

int compareTotalHarga(const void *a, const void *b) {
    struct SalesData *dataA = (struct SalesData *)a;
    struct SalesData *dataB = (struct SalesData *)b;

    // Compare total_pembayaran if the month is the same
    if (dataA->bulan == dataB->bulan) {
        float totalA = dataA->total_pembayaran;
        float totalB = dataB->total_pembayaran;
        if (totalA < totalB) {
            return -1;
        } else if (totalA > totalB) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return dataA->bulan - dataB->bulan;
    }
}
void sort_data_decending(char* key){
    struct SalesData data[100];
    int count = 0;

    FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "r");
    if(file != NULL){
        while (fscanf(file, "%d %d %s %s %s %d %f %f",
                      &data[count].tanggal, &data[count].bulan, data[count].kasir,
                      data[count].jenis, data[count].nama, &data[count].jumlah,
                      &data[count].harga, &data[count].total_pembayaran) != EOF) {
            count++;
        }
        fclose(file);
    }else{
        printf("Gagal membaca file.\n");
        return;
    }

    if(strcmp(key, "tanggal") == 0){
        qsort(data, count, sizeof(struct SalesData), compareDecending);}
    else if(strcmp(key, "harga") == 0){
        qsort(data, count, sizeof(struct SalesData), compareTotalHargaDecending);}
    else if(strcmp(key, "terjual") == 0){
        struct ItemFrequency itemFrequency[100];
        int itemFrequencyCount = 0;
        int found = 0;

        FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "r");

        if (file != NULL) {
            struct SalesData data;
            while (fscanf(file, "%d %d %s %s %s %d %f %f",
                          &data.tanggal, &data.bulan, data.kasir,
                          data.jenis, data.nama, &data.jumlah,
                          &data.harga, &data.total_pembayaran) != EOF) {
                for (i = 0; i < itemFrequencyCount; i++) {
                    if (strcmp(itemFrequency[i].nama, data.nama) == 0) {
                        itemFrequency[i].frequency += data.jumlah;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(itemFrequency[itemFrequencyCount].nama, data.nama);
                    itemFrequency[itemFrequencyCount].frequency = data.jumlah;
                    itemFrequencyCount++;
                }

                found = 0;
            }

            fclose(file);

            // Mengurutkan data berdasarkan frekuensi terjual
            for (i = 0; i < itemFrequencyCount; i++) {
                for (j = i + 1; j < itemFrequencyCount; j++) {
                    if (itemFrequency[i].frequency < itemFrequency[j].frequency) {
                        struct ItemFrequency temp = itemFrequency[i];
                        itemFrequency[i] = itemFrequency[j];
                        itemFrequency[j] = temp;
                    }
                }
            }

            printf("\nBarang yang Sering Terjual:\n");
            printf("+=======+=========+========+\n");
            printf("|  No   |   Nama  | Jumlah |\n");
            printf("+=======+=========+========+\n");
            for (i = 0; i < itemFrequencyCount; i++) {
                printf("| %-5d | %-7s | %-6d |\n", i + 1 , itemFrequency[i].nama, itemFrequency[i].frequency);
            }
            printf("+=======+=========+========+\n");
            return;
        } else {
            printf("Gagal membaca file.\n");
            return;
        }
    }
    else{
        printf("Kriteria sort tidak valid.\n");
        return;
    }

    printf("\nData Penjualan Terurut:\n");
    printf("======================================================================================\n");
    printf("| Tanggal | Bulan | Kasir | Jenis   | Nama    | Jumlah | Harga    | Total Pembayaran |\n");
    printf("======================================================================================\n");
    for (i = 0; i < count; i++) {
    printf("| %-7d | %-5d | %-5s | %-5s | %-7s | %-6d | %-8.2f | %-20.2f |\n", 
            data[i].tanggal, data[i].bulan, data[i].kasir, data[i].jenis, data[i].nama, 
            data[i].jumlah, data[i].harga, data[i].total_pembayaran);
    }
    printf("=====================================================================================\n");

}

void sort_data(char *key) {
    struct SalesData data[100];
    int count = 0;

    FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %d %s %s %s %d %f %f",
                      &data[count].tanggal, &data[count].bulan, data[count].kasir,
                      data[count].jenis, data[count].nama, &data[count].jumlah,
                      &data[count].harga, &data[count].total_pembayaran) != EOF) {
            count++;
        }

        fclose(file);
    } else {
        printf("Gagal membaca file.\n");
        return;
    }
    


    // Mengurutkan data berdasarkan kriteria tertentu
    if (strcmp(key, "tanggal") == 0) {
        qsort(data, count, sizeof(struct SalesData), compare);
    } else if (strcmp(key, "harga") == 0) {
        qsort(data, count, sizeof(struct SalesData), compareTotalHarga);
    } else if (strcmp(key, "terjual") == 0) {
        
        // Tambahkan implementasi untuk terjual jika diperlukan

        struct ItemFrequency itemFrequency[100];
        int itemFrequencyCount = 0;
        int found = 0;

        FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "r");

        if (file != NULL) {
            struct SalesData data;
            while (fscanf(file, "%d %d %s %s %s %d %f %f",
                          &data.tanggal, &data.bulan, data.kasir,
                          data.jenis, data.nama, &data.jumlah,
                          &data.harga, &data.total_pembayaran) != EOF) {
                for (i = 0; i < itemFrequencyCount; i++) {
                    if (strcmp(itemFrequency[i].nama, data.nama) == 0) {
                        itemFrequency[i].frequency += data.jumlah;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(itemFrequency[itemFrequencyCount].nama, data.nama);
                    itemFrequency[itemFrequencyCount].frequency = data.jumlah;
                    itemFrequencyCount++;
                }

                found = 0;
            }

            fclose(file);

            // Mengurutkan data berdasarkan frekuensi terjual
            for (i = 0; i < itemFrequencyCount; i++) {
                for (j = i + 1; j < itemFrequencyCount; j++) {
                    if (itemFrequency[i].frequency < itemFrequency[j].frequency) {
                        struct ItemFrequency temp = itemFrequency[i];
                        itemFrequency[i] = itemFrequency[j];
                        itemFrequency[j] = temp;
                    }
                }
            }

            printf("\nBarang yang Sering Terjual:\n");
            printf("+=======+=========+========+\n");
            printf("|  No   |   Nama  | Jumlah |\n");
            printf("+=======+=========+========+\n");
            for (i = 0; i < itemFrequencyCount; i++) {
                printf("| %-5d | %-7s | %-6d |\n", i + 1 , itemFrequency[i].nama, itemFrequency[i].frequency);
            }
            printf("+=======+=========+========+\n");
            return;
        } else {
            printf("Gagal membaca file.\n");
            return;
        }
        return;
    } else {
        printf("Kriteria sort tidak valid.\n");
        return;
    }

    // Menampilkan data yang sudah diurutkan
    printf("\nData Penjualan Terurut:\n");
    printf("======================================================================================\n");
    printf("| Tanggal | Bulan | Kasir | Jenis   | Nama    | Jumlah | Harga    | Total Pembayaran |\n");
    printf("======================================================================================\n");
    for (i = 0; i < count; i++) {
    printf("| %-7d | %-5d | %-5s | %-5s | %-7s | %-6d | %-8.2f | %-20.2f |\n", 
            data[i].tanggal, data[i].bulan, data[i].kasir, data[i].jenis, data[i].nama, 
            data[i].jumlah, data[i].harga, data[i].total_pembayaran);
    }
    printf("=====================================================================================\n");

}

void search_data() {
    struct SalesData data;
    int found = 0;
    char key[20];
    char value[50];

    int menuChoice;
    printf("\n");
    printf("=========================================\n");
    printf("           Pilih kriteria pencarian       \n");
    printf("=========================================\n");
    printf("1. tanggal\n");
    printf("2. bulan\n");
    printf("3. kasir\n");
    printf("4. jenis\n");
    printf("5. nama\n");
    printf("6. jumlah\n");
    printf("7. harga\n");
    printf("8. total_pembayaran\n");
    printf("=========================================\n");
    printf("Masukkan pilihan (1-8): ");
    scanf("%d", &menuChoice);
    printf("\n");
    switch (menuChoice) {
        case 1:
            strcpy(key, "tanggal");
            break;
        case 2:
            strcpy(key, "bulan");
            break;
        case 3:
            strcpy(key, "kasir");
            break;
        case 4:
            strcpy(key, "jenis");
            break;
        case 5:
            strcpy(key, "nama");
            break;
        case 6:
            strcpy(key, "jumlah");
            break;
        case 7:
            strcpy(key, "harga");
            break;
        case 8:
            strcpy(key, "total_pembayaran");
            break;
        default:
            printf("Pilihan kriteria pencarian tidak valid.\n");
            return;
    }

    printf("Masukkan nilai yang dicari: ");
    scanf("%s", value);
    printf("======================================================================================\n");
    printf("| Tanggal | Bulan | Kasir | Jenis   | Nama    | Jumlah | Harga    | Total Pembayaran |\n");
    printf("======================================================================================\n");
    FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %d %s %s %s %d %f %f",
                      &data.tanggal, &data.bulan, data.kasir,
                      data.jenis, data.nama, &data.jumlah,
                      &data.harga, &data.total_pembayaran) != EOF) {
            if ((strcmp(key, "tanggal") == 0 && data.tanggal == atoi(value)) ||
                (strcmp(key, "bulan") == 0 && (data.bulan) == atoi(value)) ||
                (strcmp(key, "kasir") == 0 && strcmp(data.kasir, value) == 0) ||
                (strcmp(key, "jenis") == 0 && strcmp(data.jenis, value) == 0) ||
                (strcmp(key, "nama") == 0 && strcmp(data.nama, value) == 0) ||
                (strcmp(key, "jumlah") == 0 && data.jumlah == atoi(value)) ||
                (strcmp(key, "harga") == 0 && data.harga == atof(value)) ||
                (strcmp(key, "total_pembayaran") == 0 && data.total_pembayaran == atof(value))) {
                printf("| %-7d | %-5d | %-5s | %-5s | %-7s | %-6d | %-8.2f | %-10.2f |\n", data.tanggal, data.bulan, data.kasir, data.jenis, data.nama, data.jumlah, data.harga, data.total_pembayaran);
                printf("======================================================================================\n");
                found = 1;
            }
        }
        fclose(file);

        if (!found) {
            printf("Data tidak ditemukan.\n");
        }
    } else {
        printf("Gagal membaca file.\n");
    }
}

void entry() {
    struct SalesData data;
    int kasirChoice;
    int jenisChoice;
    int menuChoice;
    int jumlah;
    float total_pembayaran = 0;
    char stop;
    
    // print_menu();

      system(CLEAR_SCREEN); // Clear the terminal screen
        int width = 80; // Set this to the actual terminal width
        int padding = (width - 50) / 2; // 50 is the length of the menu text
        printf("%*s", padding, " "); // Print spaces
        printf("\033[1m"); // Make the text bold 
        printf("\n");
        printf("==================================\n");
        printf("=        PEMILIHAN KASIR         =\n");
        printf("==================================\n");
        printf("| 1. Adiguna                     |\n");
        printf("| 2. Kiki                        |\n");
        printf("| 3. Flouren                     |\n");
        printf("| 4. Exit                        |\n");
        printf("==================================\n");
        printf("= Choose an option: ");
        printf("\033[0m"); // Reset the text style

        scanf("%d", &kasirChoice);

   switch (kasirChoice) {
       case 1:
           strcpy(data.kasir, "adi");
           break;
       case 2:
           strcpy(data.kasir, "kiki");
           break;
       case 3:
           strcpy(data.kasir, "flou");
           break;
       default:
           printf("Pilihan nama kasir tidak valid.\n");
           return;
   }

   printf("\033[1m= Tanggal Transaksi dan Bulan Transaksi (dd mm): \033[0m");
   scanf("%d %d", &data.tanggal, &data.bulan);

   do {
        printf("==================================\n");
        printf("|              Jenis             |\n");
        printf("==================================\n");
        printf("| 1. makanan                     |\n");
        printf("| 2. minuman                     |\n");
        printf("==================================\n");
        printf("= Pilih jenis (1-2): ");
       scanf("%d", &jenisChoice);
       switch (jenisChoice) {
           case 1:
               strcpy(data.jenis, "makanan");
               break;
           case 2:
               strcpy(data.jenis, "minuman");
               break;
           default:
               printf("Pilihan jenis tidak valid.\n");
               return;
       }

       if (strcmp(data.jenis, "minuman") == 0) {
            struct Item minuman[100];
            int minuman_count = 0;
            readFile1(minuman, &minuman_count);
            int angka = getMinumanCount(&minuman_count);
            printf("==================================\n");
            printf("|         Menu Minuman           |\n");
            printf("==================================\n");
            for(i = 0; i < angka; i++) {
                
                printf("| %d. %s | Rp. %.2f | %d \n", i + 1, minuman[i].name, minuman[i].price, minuman[i].quantity);
            }
            printf("==================================\n");
            printf("Pilih menu (1-%d): ", minuman_count);
            scanf("%d", &menuChoice);
            for(i = 0; i < angka; i++) {
                if(menuChoice == i + 1) {
                    strcpy(data.nama, minuman[i].name);
                    data.harga = minuman[i].price;
                }
            }
       } else if (strcmp(data.jenis, "makanan") == 0) {
            struct Item makanan[100];
            int makanan_count = 0;
            readFile(makanan, &makanan_count);
            int angka = getMinumanCount(&makanan_count);
            printf("Menu Makanan:\n");
            printf("==================================\n");
            printf("|         Menu Makanan           |\n");
            printf("==================================\n");
            for(i = 0; i < angka; i++) {
                
                printf("%d. %s | Rp. %.2f | %d \n", i + 1, makanan[i].name, makanan[i].price, makanan[i].quantity);
            }
            printf("==================================\n");
            printf("Pilih menu (1-%d): ", makanan_count);
            scanf("%d", &menuChoice);
            for(i = 0; i < angka; i++) {
                if(menuChoice == i + 1) {
                    strcpy(data.nama, makanan[i].name);
                    data.harga = makanan[i].price;
                }
            }
       } else {
           printf("Jenis tidak valid.\n");
           return;
       }

       printf("Jumlah: ");
       scanf("%d", &jumlah);
       decrease_stock(data.nama, jumlah);

       data.total_pembayaran = jumlah * data.harga;
       total_pembayaran += data.total_pembayaran;

    //    decrease_stock(data.nama, jumlah);
        
       FILE *file = fopen("/Users/adisl/Downloads/tugas_finpro/data.txt", "a");
       if (file != NULL) {
           fprintf(file, "%d %d %s %s %s %d %.2f %.2f\n", data.tanggal, data.bulan, data.kasir,
                 data.jenis, data.nama, jumlah, data.harga, data.total_pembayaran);
           fclose(file);

   

        //    system("clear"); // Clear the terminal screen
       } else {
           printf("Gagal membuka file.\n");
       }
        // decrease_stock(data.nama, jumlah);
       printf("Apakah Anda ingin melanjutkan? (y/n): ");
       scanf(" %c", &stop);
       system("clear"); // Clear the terminal screen
   } while (stop == 'y' || stop == 'Y');

    printf(ANSI_BG_BLUE ANSI_BOLD ANSI_FG_WHITE "Data berhasil ditambahkan.\n" ANSI_RESET);
    sleep(2); // Wait for 2 seconds before clearing the terminal
   printf("Total pembayaran: %.2f\n", total_pembayaran);
}


void add_new_item() {
    
  FILE* tempFile = fopen("/Users/adisl/Downloads/tugas_finpro/stock_temp.txt", "w");
  FILE* file = fopen("/Users/adisl/Downloads/tugas_finpro/stock.txt", "r");
  if (tempFile != NULL && file != NULL) {
      struct Stock stock;
      while (fscanf(file, "%s %s %d %f\n", stock.jenis, stock.nama, &stock.jumlah, &stock.harga) != EOF) {
          fprintf(tempFile, "%s %s %d %f\n", stock.jenis, stock.nama, stock.jumlah, stock.harga);
      }
      int jenis_pilihan;
      printf("Jenis Barang (1. Makanan | 2. Minuman ): ");
      scanf("%d", &jenis_pilihan);
      switch (jenis_pilihan) {
          case 1:
              strcpy(stock.jenis, "makanan");
              break;
          case 2:
              strcpy(stock.jenis, "minuman");
              break;
          default:
              printf("Pilihan jenis tidak valid.\n");
              return;
      }
      printf("Nama Barang: ");
      scanf("%s", stock.nama);
      printf("Jumlah: ");
      scanf("%d", &stock.jumlah);
      printf("Harga: ");
      scanf("%f", &stock.harga);
      fprintf(tempFile, "%s %s %d %f\n", stock.jenis, stock.nama, stock.jumlah, stock.harga);
      fclose(file);
      fclose(tempFile);
      remove("/Users/adisl/Downloads/tugas_finpro/stock.txt");
      rename("/Users/adisl/Downloads/tugas_finpro/stock_temp.txt", "/Users/adisl/Downloads/tugas_finpro/stock.txt");
      printf("Item berhasil ditambahkan.\n");
  } else {
      printf("Gagal membuka file stock.\n");
  }
}



int main() {
    int choice; // Declare the variable before the do-while loop
    int nambah;
    int pilstock;

 
    do {
        system(CLEAR_SCREEN); // Clear the terminal 
        int width = 80; // Set this to the actual terminal width
        int padding = (width - 50) / 2; // 50 is the length of the menu text
        printf("%*s", padding, " "); // Print spaces
        printf("\033[1m"); //  text bolx
        printf("\n");
        printf("==================================\n");
        printf("=             MENU               =\n");
        printf("==================================\n");
        printf("| 1. Entry Data                  |\n");
        printf("| 2. Sort Data                   |\n");
        printf("| 3. Search Data                 |\n");
        printf("| 4. stock                       |\n");
        printf("| 5. Exit                        |\n");
        printf("==================================\n");
        printf("= Choose an option: ");
        printf("\033[0m"); 

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                entry();
                break;
            case 2:
                printf("\n");
                printf("\033[1m"); 
                printf("==================================\n");
                printf("|         Pilihan Sort:          |\n");
                printf("==================================\n");
                printf("| 1. Berdasarkan Tanggal         |\n");
                printf("| 2. Berdasarkan Harga           |\n");
                printf("| 3. Berdasarkan Stok            |\n");
                printf("| 4. Barang yang Sering Terjual  |\n");
                printf("==================================\n");
                printf("Pilih metode sort (1-4): ");
                printf("\033[0m"); // Reset the text style
                int sortChoice;
                scanf("%d", &sortChoice);

                switch (sortChoice) {
                    case 1:
                        printf("Sorting by Date:\n");
                        printf("1. Ascending\n");
                        printf("2. Descending\n");
                        printf("Choose an option (1-2): ");
                        int sortChoice;
                        scanf("%d", &sortChoice);
                        switch (sortChoice) {
                            case 1:
                                sort_data("tanggal");
                                break;
                            case 2:
                                sort_data_decending("tanggal");
                                break;
                            default:
                                printf("Invalid choice.\n");
                                break;
                        }
                        break;
                    case 2:
                        printf("Sorting by Price:\n");
                        printf("1. Ascending\n");
                        printf("2. Descending\n");
                        printf("Choose an option (1-2): ");
                        int sortChoiceHarga;
                        scanf("%d", &sortChoiceHarga);

                        switch (sortChoiceHarga) {
                            case 1:
                                sort_data("harga");
                                break;
                            case 2:
                                sort_data_decending("harga");
                                break;
                            default:
                                printf("Invalid choice.\n");
                                break;
                        }
                        break;
                    case 3:
                        printf("Sorting by Stock:\n");
                        printf("1. Ascending\n");
                        printf("2. Descending\n");
                        printf("Choose an option (1-2): ");
                        int sortChoiceTanggal;
                        scanf("%d", &sortChoiceTanggal);

                        switch (sortChoiceTanggal) {
                            case 1:
                                sort_stock("jumlah");
                                break;
                            case 2:
                                sort_stock_desc("jumlah");
                                break;
                            default:
                                printf("Invalid choice.\n");
                                break;
                        }
                        break;
                    case 4:
                        sort_data("terjual");
                        break;
                    default:
                        printf("Pilihan sort tidak valid.\n");
                        break;
                }
                break;
                case 3:
                    search_data();
                    break;

                case 4:
                    printf("\n===== Pilihan Stock: =====\n");
                    printf("1. Tambah ke data yang ada  \n");
                    printf("2. Lihat data stock         \n");
                    printf("3. Tambah data baru         \n");
                    printf("Pilih metode stock (1-3): ");
                    scanf("%d", &pilstock);
                    char nama[50];

                    switch(pilstock){
                        case 1:
                            do{
                                printf("Nama Barang: ");
                                char nama[50];
                                scanf("%s", nama);

                                printf("Jumlah: ");
                                int jumlah;
                                scanf("%d", &jumlah);

                                add_stock(nama, jumlah);

                                printf("Apakah Anda ingin menambahkan stock lagi? (1. Ya / 2. Tidak): ");
                                scanf(" %d", &nambah);

                            } while(nambah == 1);
                        break;
                        case 2:
                            print_stock();
                            break;
                        case 3:
                            add_new_item();
                            break;
                        default:
                            printf("Pilihan tidak valid.\n");
                            break;
                    }
                break;
                
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
        getchar(); // Consume the newline character left in the input buffer
        printf("Press Enter to continue...");
        getchar();
    } while (choice != 5);

    return 0;
}

