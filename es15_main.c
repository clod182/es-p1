#include <stdlib.h>
#include <stdio.h>
#include "es15.h"
//#include "es15.c"
/*
 * Compilare con il comando `gcc -std=gnu89 -Wall -pedantic -o es15 es15.c es15_main.c`.
 * Aggiungere l'opzione `-ggdb` se volete utilizzare il debugger.
 */

 /*void prova(char *ris, int *num) {
 	int i=0;
 	while(ris[i]){
 		printf("%c\n",ris[i] );
 		//sarebbe la stessa cosa di fare printf("%c\n",*(ris+i) );
 		printf("%d\n",*num);
 		i++;
 	}
 }*/
 /*************************main********************************************/
int main() {
	printf("-------------es1--*-*-*-*-*-*-\n");
	int num1=543210;
	char string1[10];
	converti(num1,string1);
	printf("num %d invertito == %s \n", num1,string1);
	printf("-------------es2--*-*-*-*-*-*-\n");
	char string2[11]="9999";
	char string3[11]="999912";
	char string4[23];
	somma(string2,string3,string4);
	printf("%s +\n%s =\n%s\n", string2,string3,string4);
	printf("-------------es3--*-*-*-*-*-*-\n");
	int con=-99;
	char string12[11]="21";
	char string13[11]="21";
	con=confronta(string12,string13);
	printf("%c\n",*(string12+1));
	printf("confronto fra \n%s e\n%s == \n%d",string12,string13,con);
	return EXIT_SUCCESS;
}
