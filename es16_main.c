#include <stdlib.h>
#include <stdio.h>
#include "es16.h"
#include "es16.c"
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
	struct oggetto v33[5]={{3, 5}, {8, 11}, {6, 7},{1,3},{2, 3}};
	struct oggetto v4[5]={{3, 5}, {2, 80}, {2, 3}, {6, 20}, {6, 7}};
	x=zaino(v1, 3, 8);
	printf("-*-*-*-*-*-*-*-*-   es1    *-*-*-*-*-*-*-**\n");
	printf("v1 == %d \n", x);
	printf("v2 == %d \n", zaino(v2, 4, 10));
	printf("v3 == %d \n", zaino(v3, 4, 10));
	printf("v33 == %d \n", zaino(v33, 5, 10));
	printf("v4 == %d \n", zaino(v4, 5, 8));
	printf("-*-*-*-*-*-*-*-*-   es2    *-*-*-*-*-*-*-**\n");
	struct moneta m1[3]={{5, 2}, {2, 3}, {1, 7}};
	struct moneta m2[3]={{5, 2}, {2, 3}, {1, 7}};
	struct moneta m3[3]={{5, 2}, {2, 2}, {1, 5}};
	printf("m1 == %d \n", combinazioni_monete(m1, 3, 6));
	printf("m2 == %d \n", combinazioni_monete(m2, 3, 7));
	printf("m3 == %d \n", combinazioni_monete(m3, 3, 7));
	return EXIT_SUCCESS;
}
