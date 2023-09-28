#include <stdio.h>
#include <string.h>

int main () {
	char s [100];
	
	printf ("masukan kalimat : ");
	gets(s);
	strrev (s);
	
	printf ("kalimat yang di balik : %s\n",s);
}
