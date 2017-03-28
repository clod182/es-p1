#include <stdlib.h>
#include <stdio.h>
#include "es16.h"

/*
 * Compilare con il comando `gcc -std=gnu89 -Wall -pedantic -o es16 es16.c es16_main.c`.
 * Aggiungere l'opzione `-ggdb` se volete utilizzare il debugger.
 */
int main() {

	/* Scrivete il vostro main qui. */
	int x=0;
	struct oggetto v1[3]={{3, 5}, {8, 11}, {2, 3}};
	struct oggetto v2[4]={{3, 5}, {8, 11}, {2, 3}, {5, 7}};
	struct oggetto v3[4]={{3, 5}, {8, 11}, {2, 3}, {6, 7}};
	x=zaino(v1, 3, 9);
	printf("-*-*-*-*-*-*-*-*-   es1    *-*-*-*-*-*-*-**\n");
	printf("v1 == %d \n", x);
	printf("v2 == %d \n", zaino(v2, 4, 10));
	printf("v3 == %d \n", zaino(v3, 4, 10));
	return EXIT_SUCCESS;
}
