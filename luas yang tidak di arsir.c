#include <stdio.h>
#include <math.h>
const float pi = 3.14;
int main () {
	float a,b,c,d,e,luas1,luas2,luas3,luastotal;
	
	printf ("masukan panjang persegi panjang : ");
	scanf ("%f",&a);
	
	printf ("masukan lebar persegi panjang : ");
	scanf ("%f",&b);
	
	luas1 = a*b;
	
	printf ("luas persegi panjang = %.2f",luas1);
	
	printf ("\n-------------------------------------");
	
	printf ("\nmasukan panjang alas segitiga : ");
	scanf ("%f",&c);
	
	printf ("masukan tinggi segitiga : ");
	scanf ("%f",&d);
	
	luas2 = (c*d)/2;
	
	printf ("luas segitiga = %.2f",luas2);
	
	printf ("\n-------------------------------------");
	
	printf ("\nmasukan jari-jari : ");
	scanf ("%f",&e);
	
	luas3 = pi * (pow (e,2)) ;
	
	printf ("luas lingkaran = %.2f",luas3);
	
	printf ("\n-------------------------------------");
	
	luastotal = luas1 - (luas2+luas3);
	printf ("\nluas yang tidak di arsir = %.2f",luastotal);
	
	return 0 ;
	
}
