#include <stdio.h>

typedef struct {
    char nama_kasir[101];
    int tgl;
    int bln;
    int thn;
    char jenis[100];
    char nama[100];
    int harga;
    int stok;
    int terjual;
} database;

int main() {
	
	database cafe[100];
    FILE *fp;
    int main_menu;
    
    do {
    	printf("\n-------------\n");
	    printf("   Le cafe  \n");
	    printf("-------------\n");
	    printf("\n");
	    printf("1. Entry Sales\n");
	    printf("2. Lihat transaksi penjualan\n");
	    printf("3. Cari berdasarkan nama\n");
	    printf("4. Cari berdasarkan kisaran harga\n");
	    printf("5. Cari berdasarkan stok\n");
	    printf("6. Cari berdasarkan kisaran yang sudah terjual\n");
	    printf("7. Keluar\n");
	
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
	
	            int idx;
	            printf("transaksi ke : ");
	            scanf("%d", &idx);
	            getchar();
	            
	            printf("Nama kasir: ");
	            scanf(" %[^\n]", cafe[idx].nama_kasir);
	            getchar();
	                
	            printf ("masukan tanggal : ");
	            scanf ("%d-%d-%d",&cafe[idx].tgl,&cafe[idx].bln,&cafe[idx].thn);
	
	            printf("Jenis konsumsi(makanan atau minuman): ");
	            scanf(" %s", cafe[idx].jenis);
	
	            printf("Nama: ");
	            scanf(" %s", cafe[idx].nama);
	
	            printf("Harga: ");
	            scanf("%d", &cafe[idx].harga);
	
	            printf("Stok: ");
	            scanf("%d", &cafe[idx].stok);
	
	            printf("Yang sudah terjual: ");
	        	scanf("%d", &cafe[idx].terjual);
	
	            fprintf(fp, "%-20s,%-10d,%-10d,%-10d,%-15s,%-15s,%-10d,%-5d,%-7d\n",
	                    cafe[idx].nama_kasir, cafe[idx].tgl, cafe[idx].bln, cafe[idx].thn,
	                    cafe[idx].jenis, cafe[idx].nama, cafe[idx].harga, cafe[idx].stok, cafe[idx].terjual);
	            fclose(fp);
	            break;
	        }
	        case 2: {
	        	int view_menu;
			    fp = fopen ("Sales.txt","r");
			    printf("1. Tanggal transaksi\n");
			    printf("2. Harga\n");
			    printf("3. Stok\n");
			    printf("4. Paling sering terjual\n");
			
			    printf("Masukan pilihan: ");
			    scanf("%d", &view_menu);
		
		      	switch(view_menu){
		        case 1: {
		          	int date_menu;
				    printf("Tampilkan stock menu dari:\n");
				    printf("1. Terbaru ke terlama\n");
				    printf("2. Terlama ke terbaru\n");
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
				               cafe[count].nama, &cafe[count].harga, &cafe[count].stok, &cafe[count].terjual);
				        count++;
				    }
				
				    int i, j;
				    for (i = 0; i < count - 1; i++) {
				        for (j = 0; j < count - i - 1; j++) {
				            if ((date_menu == 1 && cafe[j].tgl < cafe[j + 1].tgl ) ||
				                (date_menu == 2 && cafe[j].tgl > cafe[j + 1].tgl )) {
				                database temp = cafe[j];
				                cafe[j] = cafe[j + 1];
				                cafe[j + 1] = temp;
				            }
				        }
				    }
				
				    printf("======================================================================================================\n");
				    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
				           "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
				    printf("======================================================================================================\n");
					for (i = 0; i < count; i++) {
				        printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-5d%-7d\n",
				               cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
				               cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
				    }
				
				    fclose(fp);
		        }
		        case 2: {
		        	int tipe_menu;
		        	printf("1. Tanggal transaksi\n");
		        	printf("2. Harga\n");
		        	printf("3. Stok\n");
		        	printf("4. Terjual\n");
		        	printf("Pilih menu: \n");
		        	scanf("%d", &tipe_menu);
		        	
		        	switch (tipe_menu) {
		        		case 1: {
		        			
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
				                       cafe[count].nama, &cafe[count].harga, &cafe[count].stok, &cafe[count].terjual);
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
				
				            printf("======================================================================================================\n");
				            printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
				                   "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
				            printf("======================================================================================================\n");
				          for (i = 0; i < count; i++) {
				                printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-5d%-7d\n",
				                       cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
				                       cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
				            }
				
				            fclose(fp);
							break;
						}
					case 3: {
						int stock_menu;
				        printf("Tampilkan stock menu dari:\n");
			            printf("1. Terkecil ke terbesar\n");
				        printf("2. Terbesar ke terkecil\n");
					    printf("Masukan pilihan: ");
					    scanf("%d", &stock_menu);
					
					    if (stock_menu != 1 && stock_menu != 2) {
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
					                cafe[count].nama, &cafe[count].harga, &cafe[count].stok, &cafe[count].terjual);
					        count++;
					    }
					
					    int i, j;
					    for (i = 0; i < count - 1; i++) {
					        for (j = 0; j < count - i - 1; j++) {
					            if ((stock_menu == 1 && cafe[j].stok > cafe[j + 1].stok) ||
					                (stock_menu == 2 && cafe[j].stok < cafe[j + 1].stok)) {
					                database temp = cafe[j];
					                cafe[j] = cafe[j + 1];
					                cafe[j + 1] = temp;
					            }
					        }
					    }
					
					    printf("======================================================================================================\n");
					    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
					            "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
					    printf("======================================================================================================\n");
					    for (i = 0; i < count; i++) {
					        printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-5d%-7d\n",
					                cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
					                cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
					    }
					
					    fclose(fp);
						break;
					}
					case 4: {
						int terjual_menu;
			        	printf("Tampilkan jumlah terjual dari:\n");
				        printf("1. Paling sedikit terjual\n");
			            printf("2. Paling banyak terjual\n");
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
					                cafe[count].nama, &cafe[count].harga, &cafe[count].stok, &cafe[count].terjual);
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
					
					    printf("======================================================================================================\n");
					    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
					        "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
					        printf("======================================================================================================\n");
					    for (i = 0; i < count; i++) {
					        printf("%-20s%-10d%-10d%-10d%-15s%-15s%-10d%-5d%-7d\n",
					                cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
					                cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
					    }
					
					    fclose(fp);
						break;
						}
					}
				}
			}
	
			break;
			}
			case 3: {
				char productName[100];
			    printf("Masukkan nama produk yang ingin dicari: ");
			    scanf("%99s", productName);
			
			    FILE *fp = fopen("Sales.txt", "r");
			    if (fp == NULL) {
			        printf("Error opening file\n");
			        return 1;
			    }
			
			    printf("======================================================================================================\n");
			    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
			           "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
			    printf("======================================================================================================\n");
			
			    database cafe;
			    int found = 0;
			    while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
			        cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
			        cafe.jenis, cafe.nama, &cafe.harga, &cafe.stok, &cafe.terjual) != EOF) {
			        if (strcmp(cafe.nama, productName) == 0) {
			            printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			            cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
			            cafe.jenis, cafe.nama, cafe.harga, cafe.stok, cafe.terjual);
				found = 1;
	        		}
	    		}
	
			    if (!found) {
			        printf("Produk dengan nama '%s' tidak ditemukan dalam data.\n", productName);
			    }
			
			    fclose(fp);
			    break;
			}
			case 4: {
				int cari_harga;
			    printf("1. 0-5000\n");
			    printf("2. 5001-15000\n");
			    printf("3. 15001-25000\n");
			    printf("4. 25001+\n");
			    printf("Masukan pilihan: ");
			    scanf("%d", &cari_harga);
			
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
			               cafe[count].nama, &cafe[count].harga, &cafe[count].stok, &cafe[count].terjual);
			        count++;
			    }
			
			    printf("======================================================================================================\n");
			    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
			           "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
			    printf("======================================================================================================\n");
			    int i;
			    for (i = 0; i < count; i++) {
			        switch (cari_harga) {
			            case 1:
			                if (cafe[i].harga >= 0 && cafe[i].harga <= 5000) {
			                    printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			                           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
			                           cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
			                }
			                break;
			            case 2:
			                // Add conditions for other ranges (2, 3, 4) similarly
			                if (cafe[i].harga >= 5001 && cafe[i].harga <= 15000) {
			                    printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			                           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
			                           cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
			                }
			                break;
			            case 3:
			                if (cafe[i].harga >= 15001 && cafe[i].harga <= 25000) {
			                    printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			                           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
			                           cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
			                }
			                break;
			            case 4:
			                if (cafe[i].harga >= 25001) {
			                    printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			                           cafe[i].nama_kasir, cafe[i].tgl, cafe[i].bln, cafe[i].thn,
			                           cafe[i].jenis, cafe[i].nama, cafe[i].harga, cafe[i].stok, cafe[i].terjual);
			                }
			                break;
			            
			            default:
			                printf("Invalid option\n");
			        }
			    }
			
			    fclose(fp);
				break;
			}
			case 5: {
				int stockSearch;
			    printf("Masukkan jumlah stok yang ingin dicari: ");
			    scanf("%d", &stockSearch);
			
			    FILE *fp = fopen("Sales.txt", "r");
			    if (fp == NULL) {
			        printf("Error opening file\n");
			        return 1;
			    }
			
			    printf("======================================================================================================\n");
			    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
			           "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
			    printf("======================================================================================================\n");
			
			    database cafe;
			    int found = 0;
			    while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
			                  cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
			                  cafe.jenis, cafe.nama, &cafe.harga, &cafe.stok, &cafe.terjual) != EOF) {
			        if (cafe.stok == stockSearch) {
			            printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			                   cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
			                   cafe.jenis, cafe.nama, cafe.harga, cafe.stok, cafe.terjual);
			            found = 1;
			        }
			    }
			
			    if (!found) {
			        printf("Tidak ada produk dengan stok sebanyak %d.\n", stockSearch);
			    }
			
			    fclose(fp);
				break;
			}
			case 6:{
				int soldSearch;
			    printf("Masukkan jumlah terjual yang ingin dicari: ");
			    scanf("%d", &soldSearch);
			
			    FILE *fp = fopen("Sales.txt", "r");
			    if (fp == NULL) {
			        printf("Error opening file\n");
			        return 1;
			    }
			
			    printf("======================================================================================================\n");
			    printf("%-20s%-10s%-10s%-10s%-15s%-15s%-10s%-5s%-7s\n",
			           "Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Harga", "Stok", "Terjual");
			    printf("======================================================================================================\n");
			
			    database cafe;
			    int found = 0;
			    while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
			                  cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
			                  cafe.jenis, cafe.nama, &cafe.harga, &cafe.stok, &cafe.terjual) != EOF) {
			        if (cafe.terjual == soldSearch) {
			            printf("%-20s%-4d%-4d%-4d%-15s%-15s%-10d%-5d%-7d\n",
			                   cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
			                   cafe.jenis, cafe.nama, cafe.harga, cafe.stok, cafe.terjual);
			            found = 1;
			        }
			    }
			
			    if (!found) {
			        printf("Tidak ada produk yang terjual sebanyak %d.\n", soldSearch);
			    }
			
			    fclose(fp);
				break;
			}
			case 7:{
				return 0;
				break;
			}
	    }
	}while (main_menu != 7);
    return 0;
}

