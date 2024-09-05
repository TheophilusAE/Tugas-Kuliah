#include <stdio.h>

typedef struct {
    char nama_kasir[101];
    int tgl;
    int bln;
    int thn;
    char jenis[100];
    char nama[100];
    int harga;
    int terjual;
    int total;
} database;

int main() {
	
	database cafe[100];
    FILE *fp;
    int main_menu;
    
    do {
    	printf("-------------\n");
	    printf("   Le cafe  \n");
	    printf("-------------\n");
	    printf("\n");
	    printf("1. Entry Sales\n");
	    printf("2. Lihat transaksi penjualan\n");
	    printf("3. Cari berdasarkan nama\n");
	    printf("4. Cari berdasarkan kisaran harga\n");
	    printf("5. Cari berdasarkan stok\n");
	    printf("6. Cari berdasarkan kisaran yang sudah terjual\n");
	    printf("7. Lihat menu\n");
	    printf("8. Keluar\n");
	
	    printf("Pilih Menu: ");
	    scanf("%d", &main_menu);
	    getchar();
	    
	     switch (main_menu) {
	        case 1: {
	            fp = fopen("sales.txt", "a+");

			    if (fp == NULL) {
			        printf("File not found!!!!");
			        return 0;
			    }
			
			    int i,idx;
			    do {
			        printf("Berapa transaksi : ");
			        scanf("%d", &idx);
			        getchar();
			        if(idx<=0){
			        	printf("Masukan angka lebih dari 0");
					}
			    } while (idx <= 0);
			
			    for (i = 0; i < idx; i++) {
			        printf("Transaksi ke %d\n", i + 1);
			
			        printf("Nama kasir: ");
			        scanf(" %[^\n]", cafe[i].nama_kasir);
			        getchar();
			
			
			        do {
			            printf("Tanggal transaksi: ");
			            scanf("%d", &cafe[i].tgl);
			            if (cafe[i].tgl <= 0 || cafe[i].tgl >= 31) {
			                printf("Masukan tanggal antara 1-31\n");
			            }
			        } while (cafe[i].tgl <= 0 || cafe[i].tgl >= 31);
			
			        do {
					    printf("Bulan transaksi: ");
					    scanf("%d", &cafe[i].bln);
					    if (cafe[i].bln <= 0 || cafe[i].bln > 12) {
					        printf("Masukan bulan antara 1-12\n");
					    }
					} while (cafe[i].bln <= 0 || cafe[i].bln > 12);
			
			        printf("Tahun transaksi: ");
			        scanf("%d", &cafe[i].thn);
			
			        do {
					    printf("Jenis konsumsi(makanan atau minuman): ");
					    scanf(" %s", cafe[i].jenis);
					
					    if (strcmp(cafe[i].jenis, "makanan") == 0) {
					        // Validation for nama when jenis konsumsi is makanan
					        printf("Nama (kentang-goreng, sandwich, hotdog, chicken-wings, burger): ");
					        scanf(" %s", cafe[i].nama);
					
					        // Check if the entered nama is valid for makanan
					        if (strcmp(cafe[i].nama, "kentang-goreng") != 0 && strcmp(cafe[i].nama, "sandwich") != 0 &&
					            strcmp(cafe[i].nama, "hotdog") != 0 && strcmp(cafe[i].nama, "chicken-wings") != 0 &&
					            strcmp(cafe[i].nama, "burger") != 0) {
					            printf("Masukan makanan yang ada di dalam menu\n");
					        }
					        if (strcmp(cafe[i].nama, "kentang-goreng") == 0) {
					            cafe[i].harga = 15000;
					        } else if (strcmp(cafe[i].nama, "sandwich") == 0 || strcmp(cafe[i].nama, "burger") == 0 ||
					                   strcmp(cafe[i].nama, "hotdog") == 0) {
					            cafe[i].harga = 20000;
					        } else if (strcmp(cafe[i].nama, "chicken-wings") == 0) {
					            cafe[i].harga = 25000;
					        }
					
					    } else if (strcmp(cafe[i].jenis, "minuman") == 0) {
					        // Validation for nama when jenis konsumsi is minuman
					        printf("Nama (es-teh, americano, air-mineral, espresso, capuccino): ");
					        scanf(" %s", cafe[i].nama);
					
					        // Check if the entered nama is valid for minuman
					        if (strcmp(cafe[i].nama, "es-teh") != 0 && strcmp(cafe[i].nama, "americano") != 0 &&
					            strcmp(cafe[i].nama, "air-mineral") != 0 && strcmp(cafe[i].nama, "espresso") != 0 &&
					            strcmp(cafe[i].nama, "capuccino") != 0) {
					            printf("Masukan minuman yang ada di dalam menu\n");
					        }
					        if (strcmp(cafe[i].nama, "es-teh") == 0) {
				            	cafe[i].harga = 5000;
					        } else if (strcmp(cafe[i].nama, "americano") == 0) {
					            cafe[i].harga = 20000;
					        } else if (strcmp(cafe[i].nama, "air-mineral") == 0) {
					            cafe[i].harga = 4000;
					        } else if (strcmp(cafe[i].nama, "espresso") == 0) {
					            cafe[i].harga = 15000;
					        } else if (strcmp(cafe[i].nama, "capuccino") == 0) {
					            cafe[i].harga = 25000;
					        }
					
					    } else {
					        // Display an error message for invalid jenis konsumsi
					        printf("Ketik makanan atau minuman\n");
					    }
					} while ((strcmp(cafe[i].jenis, "makanan") != 0 && strcmp(cafe[i].jenis, "minuman") != 0) ||
					         ((strcmp(cafe[i].jenis, "makanan") == 0 || strcmp(cafe[i].jenis, "minuman") == 0) &&
					          ((strcmp(cafe[i].nama, "kentang-goreng") != 0 && strcmp(cafe[i].nama, "sandwich") != 0 &&
					            strcmp(cafe[i].nama, "hotdog") != 0 && strcmp(cafe[i].nama, "chicken-wings") != 0 &&
					            strcmp(cafe[i].nama, "burger") != 0) &&
					           (strcmp(cafe[i].nama, "es-teh") != 0 && strcmp(cafe[i].nama, "americano") != 0 &&
					            strcmp(cafe[i].nama, "air-mineral") != 0 && strcmp(cafe[i].nama, "espresso") != 0 &&
					            strcmp(cafe[i].nama, "capuccino") != 0))));

			        do {
			            printf("Yang sudah terjual: ");
			            scanf("%d", &cafe[i].terjual);
			            if (cafe[i].terjual < 0) {
			                printf("Masukan angka tidak boleh kurang dari 0\n");
			            }
			        } while (cafe[i].terjual < 0);
					
					cafe[i].total=cafe[i].terjual*cafe[i].harga;
			        fprintf(fp, "%s,%d,%d,%d,%s,%s,%d,%d,%d\n",
			                cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
			                cafe[i].jenis, cafe[i].nama, cafe[i].terjual, cafe[i].harga, cafe[i].total);
			    }
	
	            fclose(fp);
	            break;
	        }
	        case 2:{
	        	int view_menu;
			    fp = fopen ("Sales.txt","r");
			    printf("1. Tanggal transaksi\n");
			    printf("2. Harga\n");
			    printf("3. Total\n");
			    printf("4. Paling sering terjual\n");
			
			    printf("Masukan pilihan: ");
			    scanf("%d", &view_menu);
		
		      	switch(view_menu){
		      		case 1: {
		      			int date_menu;
					    printf("Tampilkan tanggal transaksi dari:\n");
					    printf("1. Terlama ke terbaru\n");
					    printf("2. Terbaru ke terlama\n");
					    printf("Masukan pilihan: ");
					    scanf("%d", &date_menu);
					
					    if (date_menu != 1 && date_menu != 2) {
					        printf("Pilihan tidak valid\n");
					        return 1;
					    }
					
					    FILE *fp = fopen("Sales.txt", "r");
					
					    if (fp == NULL) {
					        printf("Error opening file\n");
					        return 1;
					    }
					
					    fscanf(fp, "%*[^\n]\n");
					
					    database cafe[25];
					    char line[500];
					    int count = 0;
					
					    while (fgets(line, sizeof(line), fp) != NULL && count < 25) {
					        sscanf(line, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
					               cafe[count].nama_kasir, &cafe[count].tgl,
					               &cafe[count].bln, &cafe[count].thn, cafe[count].jenis,
					               cafe[count].nama, &cafe[count].terjual, &cafe[count].harga, &cafe[count].total);
					        count++;
					    }
					
					    int i, j;
					    for (i = 0; i < count - 1; i++) {
					        for (j = 0; j < count - i - 1; j++) {
					            if ((date_menu == 1 && cafe[j].tgl > cafe[j + 1].tgl ) ||
					                (date_menu == 2 && cafe[j].tgl < cafe[j + 1].tgl )) {
					                
					                database temp = cafe[j];
					                cafe[j] = cafe[j + 1];
					                cafe[j + 1] = temp;
					            }
					        }
					    }
					
					    printf("============================================================================================================\n");
						printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-10s%-10s\n",
						       "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Terjual", "Harga", "Total");
						printf("============================================================================================================\n");
						for (i = 0; i < count; i++) {
						    printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-10d%-10d\n",
						           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
						           cafe[i].jenis, cafe[i].nama, cafe[i].terjual, cafe[i].harga, cafe[i].total);
						}

					    fclose(fp);
						break;
					}
					case 2: {
						int harga_menu;
			            printf("Tampilkan harga dari:\n");
			            printf("1. Termurah ke termahal\n");
			            printf("2. Termahal ke termurah\n");
			            printf("Masukan pilihan: ");
			            scanf("%d", &harga_menu);
			
			            if (harga_menu != 1 && harga_menu != 2) {
			                printf("Pilihan tidak valid\n");
			                return 1;
			            }
			
			            FILE *fp = fopen("Sales.txt", "r");
			
			            if (fp == NULL) {
			                printf("Error opening file\n");
			                return 1;
			            }
			
			            fscanf(fp, "%*[^\n]\n");
			
			            database cafe[25];
			            char line[500];
			            int count = 0;
			
			            while (fgets(line, sizeof(line), fp) != NULL && count < 25) {
			                sscanf(line, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
			                       cafe[count].nama_kasir, &cafe[count].tgl,
			                       &cafe[count].bln, &cafe[count].thn, cafe[count].jenis,
			                       cafe[count].nama, &cafe[count].terjual, &cafe[count].harga, &cafe[count].total);
			                count++;
			            }
			            
			            int i,j;
			            for (i = 0; i < count - 1; i++) {
			                for (j = 0; j < count - i - 1; j++) {
			                    if ((harga_menu == 1 && cafe[j].harga > cafe[j + 1].harga) ||
			                        (harga_menu == 2 && cafe[j].harga < cafe[j + 1].harga)) {
			                        database temp = cafe[j];
			                        cafe[j] = cafe[j + 1];
			                        cafe[j + 1] = temp;
			                    }
			                }
			            }
			
			            printf("============================================================================================================\n");
						printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-10s%-10s\n",
						       "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Terjual", "Harga", "Total");
						printf("============================================================================================================\n");
						for (i = 0; i < count; i++) {
						    printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-10d%-10d\n",
						           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
						           cafe[i].jenis, cafe[i].nama, cafe[i].terjual, cafe[i].harga, cafe[i].total);
						}

			
			            fclose(fp);
						break;
					}
					case 3: {
						int total_menu;
			            printf("Tampilkan total dari:\n");
			            printf("1. Terdikit\n");
			            printf("2. Terbanyak\n");
			            printf("Masukan pilihan: ");
			            scanf("%d", &total_menu);
			
			            if (total_menu != 1 && total_menu != 2) {
			                printf("Pilihan tidak valid\n");
			                return 1;
			            }
			
			            FILE *fp = fopen("Sales.txt", "r");
			
			            if (fp == NULL) {
			                printf("Error opening file\n");
			                return 1;
			            }
			
			            fscanf(fp, "%*[^\n]\n");
			
			            database cafe[25];
			            char line[500];
			            int count = 0;
			
			            while (fgets(line, sizeof(line), fp) != NULL && count < 25) {
			                sscanf(line, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
			                       cafe[count].nama_kasir, &cafe[count].tgl,
			                       &cafe[count].bln, &cafe[count].thn, cafe[count].jenis,
			                       cafe[count].nama, &cafe[count].terjual, &cafe[count].harga, &cafe[count].total);
			                count++;
			            }
			            
			            int i,j;
			            for (i = 0; i < count - 1; i++) {
			                for (j = 0; j < count - i - 1; j++) {
			                    if ((total_menu == 1 && cafe[j].total > cafe[j + 1].total) ||
			                        (total_menu == 2 && cafe[j].total < cafe[j + 1].total)) {
			                        database temp = cafe[j];
			                        cafe[j] = cafe[j + 1];
			                        cafe[j + 1] = temp;
			                    }
			                }
			            }
			
			            printf("============================================================================================================\n");
						printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-10s%-10s\n",
						       "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Terjual", "Harga", "Total");
						printf("============================================================================================================\n");
						for (i = 0; i < count; i++) {
						    printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-10d%-10d\n",
						           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
						           cafe[i].jenis, cafe[i].nama, cafe[i].terjual, cafe[i].harga, cafe[i].total);
						}

			
			            fclose(fp);
						break;
					}
					case 4: {
						int terjual_menu;
			            printf("Tampilkan jumlah yang terjual dari:\n");
			            printf("1. Yang paling jarang\n");
			            printf("2. Yang paling sering\n");
			            printf("Masukan pilihan: ");
			            scanf("%d", &terjual_menu);
			
			            if (terjual_menu != 1 && terjual_menu != 2) {
			                printf("Pilihan tidak valid\n");
			                return 1;
			            }
			
			            FILE *fp = fopen("Sales.txt", "r");
			
			            if (fp == NULL) {
			                printf("Error opening file\n");
			                return 1;
			            }
			
			            fscanf(fp, "%*[^\n]\n");
			
			            database cafe[25];
			            char line[500];
			            int count = 0;
			
			            while (fgets(line, sizeof(line), fp) != NULL && count < 25) {
			                sscanf(line, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
			                       cafe[count].nama_kasir, &cafe[count].tgl,
			                       &cafe[count].bln, &cafe[count].thn, cafe[count].jenis,
			                       cafe[count].nama, &cafe[count].terjual, &cafe[count].harga, &cafe[count].total);
			                count++;
			            }
			            
			            int i,j;
			            for (i = 0; i < count - 1; i++) {
			                for (j = 0; j < count - i - 1; j++) {
			                    if ((terjual_menu == 1 && cafe[j].terjual > cafe[j + 1].terjual) ||
			                        (terjual_menu == 2 && cafe[j].terjual < cafe[j + 1].terjual)) {
			                        database temp = cafe[j];
			                        cafe[j] = cafe[j + 1];
			                        cafe[j + 1] = temp;
			                    }
			                }
			            }
			
			            printf("============================================================================================================\n");
						printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-10s%-10s\n",
						       "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Terjual", "Harga", "Total");
						printf("============================================================================================================\n");
						for (i = 0; i < count; i++) {
						    printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-10d%-10d\n",
						           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
						           cafe[i].jenis, cafe[i].nama, cafe[i].terjual, cafe[i].harga, cafe[i].total);
						}

			
			            fclose(fp);
						break;
					}
				}
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
	        case 6:{
	        	printf("Menu makanan\n");
			    printf("=============================\n");
			    printf("%-20s%-10s\n", "Nama Makanan", "Harga");
			    printf("=============================\n");
			    printf("%-20s%-10d\n", "kentang-goreng", 15000);
			    printf("%-20s%-10d\n", "sandwich", 20000);
			    printf("%-20s%-10d\n", "hotdog", 20000);
			    printf("%-20s%-10d\n", "burger", 20000);
			    printf("%-20s%-10d\n", "chicken-wings", 25000);
				printf("\n");
			    printf("Menu minuman\n");
			    printf("=============================\n");
			    printf("%-20s%-10s\n", "Nama Minuman", "Harga");
			    printf("=============================\n");
			    printf("%-20s%-10d\n", "air-mineral", 4000);
			    printf("%-20s%-10d\n", "es-teh", 5000);
			    printf("%-20s%-10d\n", "americano", 20000);
			    printf("%-20s%-10d\n", "espresso", 15000);
			    printf("%-20s%-10d\n", "capuccino", 25000);
				break;
			}
			case 7:{
				return 0;
				break;
			}
		}
	}while(main_menu!=7);
	
	return 0;
}
