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
						if (cafe.harga >= 0 && cafe.harga <= 5000) {
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
						if (cafe.harga >= 5001 && cafe.harga <= 15000) {
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
						if (cafe.harga >= 15001 && cafe.harga <= 25000) {
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
						if (cafe.harga >= 25001) {
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
