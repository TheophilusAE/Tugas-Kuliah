#include <stdio.h>

//nama struct kalau mau dipake harus di declare lagi nama variable nya apa 
// seperti struct Theo Flou, nama variabel tersebut adalah Flou
// jadi kalau mau masukkin ke variabel yang di dalam struct nanti tinggal tulis
// Flou.umur atau Flou.tinggi dan seterusnya

struct Theo{ 
	
	int umur;
	int tinggi;
	char namalengkap[101];
	char namapacar[101];
	
};


//kalau yang ini sama, bedanya cuma di ngedeclare variable structnya
// ga usah tulis struct lagi, tinggi tulis ini
// Theo Flou

typedef struct{
	
	int umur;
	int tinggi;
	char namalengkap[101];
	char namapacar[101];
	
}Theo;
