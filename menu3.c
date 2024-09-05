char productName[100];
				
	printf("Masukkan nama produk yang ingin dicari: ");
	scanf("%99s", productName);
			
	FILE *fp = fopen("sales.txt", "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		return 1;
	}
			
	printf("======================================================================================================\n");
	printf("%-20s%-15s%-15s%-10s%-15s%-15s\n",
			"Nama Kasir", "Tanggal", "Jenis", "Nama", "Terjual", "Harga");
	printf("======================================================================================================\n");
			
	database cafe;
	int found = 0;
	while (fscanf(fp, "%100[^,],%d,%d,%d,%99[^,],%99[^,],%d,%d,%d[^\n]",
		cafe.nama_kasir, &cafe.tgl, &cafe.bln, &cafe.thn,
		cafe.jenis, cafe.nama, &cafe.terjual, &cafe.harga, &cafe.total) != EOF) {
		if (strcmp(cafe.nama, productName) == 0) {
			printf("%-20s %d /%d /%-7d %-15s%-15s%-10d%-10d\n",
			cafe.nama_kasir, cafe.tgl, cafe.bln, cafe.thn,
			cafe.jenis, cafe.nama, cafe.terjual, cafe.harga, cafe.total);
		found = 1;
	    }
	}
	
	if (!found) {
		printf("Produk dengan nama '%s' tidak ditemukan dalam data.\n", productName);
	}
			
	fclose(fp);
	break;
