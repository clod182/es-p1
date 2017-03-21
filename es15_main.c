#include <stdlib.h>
#include <stdio.h>
#include "es15.h"

/*
 * Compilare con il comando `gcc -std=gnu89 -Wall -pedantic -o es15 es15.c es15_main.c`.
 * Aggiungere l'opzione `-ggdb` se volete utilizzare il debugger.
 */
int main() {
	//int i=0;
	int num1=543210;
	char string1[10];
	converti(num1,string1);
	printf("%s\n", string1);
	char string2[11]="123";
	char string3[11]="123";
	char string4[23];
	somma(string2,string3,string4);
	printf("%s\n", string4);
	return EXIT_SUCCESS;
}
