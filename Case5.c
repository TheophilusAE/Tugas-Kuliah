case 5: {
	    		int cari_harga;
			    printf("1. 0-5\n");
			    printf("2. 6-10\n");
			    printf("3. 11-15\n");
			    printf("4. 16+\n");
			    printf("Masukan pilihan: ");
			    scanf("%d", &cari_harga);
			
			    FILE *fp = fopen("Sales.txt", "r");
			
			    if (fp == NULL) {
			        printf("Error opening file\n");
			        return 1;
			    }
			
			    printf("======================================================================================================\n");
						printf("%-20s%-10s%-10s%-10s%-15s%-15s%-15s%-15s\n",
						"Nama Kasir", "Tanggal", "Bulan", "Tahun", "Jenis", "Nama", "Terjual", "Harga");
				printf("======================================================================================================\n");
				
				switch(cari_harga){
					case 1:{
						database cafe;
						int found = 0;
						fscanf(fp, "%*[^\n]\n");
						while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
						cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
						cafe.jenis, cafe.nama, &cafe.terjual, &cafe.harga, &cafe.total) != EOF) {
						if (cafe.terjual >= 0 && cafe.terjual <= 5) {
							printf("%-21s%-10d%-10d%-10d%-15s%-15s%-15d%-15d\n",
							cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
							cafe.jenis, cafe.nama, cafe.terjual, cafe.harga);
							found = 1;
	    			}
				}
				
				if (!found) {
				printf("Produk dengan nama range harga tersebut tidak ditemukan dalam data.\n");
				}
						
						break;
					}
					
				case 2: {
					database cafe;
						int found = 0;
						fscanf(fp, "%*[^\n]\n");
						while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
						cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
						cafe.jenis, cafe.nama, &cafe.terjual, &cafe.harga, &cafe.total) != EOF) {
						if (cafe.terjual >= 6 && cafe.terjual <= 10) {
							printf("%-21s%-10d%-10d%-10d%-15s%-15s%-15d%-15d\n",
							cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
							cafe.jenis, cafe.nama, cafe.terjual, cafe.harga);
							found = 1;
	    			}
				}
				
				if (!found) {
				printf("Produk dengan nama range harga tersebut tidak ditemukan dalam data.\n");
				}
					
					break;
				}
				
				case 3: { 
					database cafe;
						int found = 0;
						fscanf(fp, "%*[^\n]\n");
						while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
						cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
						cafe.jenis, cafe.nama, &cafe.terjual, &cafe.harga, &cafe.total) != EOF) {
						if (cafe.terjual >= 11 && cafe.terjual <= 15) {
							printf("%-21s%-10d%-10d%-10d%-15s%-15s%-15d%-15d\n",
							cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
							cafe.jenis, cafe.nama, cafe.terjual, cafe.harga);
							found = 1;
	    			}
				}
				
				if (!found) {
				printf("Produk dengan nama range harga tersebut tidak ditemukan dalam data.\n");
				}
					
					break;
				}
				
				case 4: {
					database cafe;
						int found = 0;
						fscanf(fp, "%*[^\n]\n");
						while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
						cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
						cafe.jenis, cafe.nama, &cafe.terjual, &cafe.harga, &cafe.total) != EOF) {
						if (cafe.terjual >= 16) {
							printf("%-21s%-10d%-10d%-10d%-15s%-15s%-15d%-15d\n",
							cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
							cafe.jenis, cafe.nama, cafe.terjual, cafe.harga);
							found = 1;
	    			}
				}
				
				if (!found) {
				printf("Produk dengan nama range harga tersebut tidak ditemukan dalam data.\n");
				}
					
					break;
				}
					
				fclose(fp);
				break;
				}	
				   
			   break; 
			}
