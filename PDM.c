#include <stdio.h>

int main() {
    int a,b;
    int c,d;
    int e,f;
    int g;
    int total;
    char s;
    
    do {
    printf ("===================================\n");
    printf ("Insert Departure Time : ");
    scanf ("%d.%d",&a,&b);
    getchar ();
    
	if (((a >= 0) && (a <= 24))&&((b >= 0)&&(b <= 60))){
    	printf ("Insert Arrival Time   : ");
    	scanf ("%d.%d",&c,&d);
    	printf ("====================================\n");
    	getchar ();
    	
		if (((c >= 0) && (c <= 24))&&((d >= 0)&&(d <= 60))) {
    		e = c-a;
    		f = d-b;
    		g = e * 60;
    		total = f + g;
    		
			while (total != 30){
    			total--;
    			
				if ((total % 5 == 0) && (total <= 30)) {
					printf ("\n===============================================");
    				printf ("\n||You Will Arrive in 30 Minute Or Less!!!    ||\n");
    				printf ("===============================================\n");
    				printf ("\n");
    				printf ("============================================\n");
					printf ("Have you got off the train?             \n") ;
					printf ("Do You Want To Change Destination (Y/N): ");
					scanf ("%c",&s);
					printf ("\n============================================\n");
				}
			}
		}
		else {
			printf ("Go back? (Y/N) : ");
			scanf ("%c",&s);	
		}
	}
	else {
		printf ("Go back? (Y/N) : ");
		scanf ("%c",&s);
	}
/*DEBUG*/

/**/

//	printf ("============================================\n");
//	printf ("Have you got off the train?             \n") ;
//	printf ("Do You Want To Change Destination (Y/N): \n");
//	scanf ("%c",&s);	
//	printf ("============================================\n");
	} while ((s != 'N') && (s != 'n')) ;
	
    
    return 0;
}
