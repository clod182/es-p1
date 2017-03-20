#include <stdlib.h>
#include <stdio.h>
#include "es14.h"

/*
 * Compilare con il comando `gcc -std=gnu89 -Wall -pedantic -o es14 es14.c es14_main.c`.
 * Aggiungere l'opzione `-ggdb` se volete utilizzare il debugger.
 */
 /***********************MAIN*****************************/
 void stampa_matrice(char mat[DIM][DIM]){
 	int i=0,j=0;
 	for(i=0;i<DIM;i++){
 		for(j=0;j<DIM;j++){
 			printf("%c ",mat[i][j]);
 		}
 		printf("\n");
 	}
 	printf("\n");
 }

 void stampa_vettore(int v[], int n){
 	int i=0;
 	while(i<n){
 		printf("%d ",v[i]);
 		i++;
 	}
 	printf("\n");
 }


 int main() {
 	printf("------------------------------------------------es1\n");
 	srand(time(NULL));
 	char parola[]="r1bq1rk1/pp3ppp/3n4/2p1N3/2B5/7P/PPP2PP1/R1BQR1K1";
 	char* npt;
 	npt=&parola;
 	char campo[DIM][DIM];
 	riempi_scacchiera(&parola,campo);
 	stampa_matrice(campo);
 	printf("------------------------------------------------es2\n");
 	int v[10];
 	int z=0;
 	for(z=0;z<10;z++){
 		vettore_casuale(v,10,1,12);
 		stampa_vettore(v,10);
 	}
 	printf("------------------------------------------------es3\n");
 	int seq=0;
 	int i=0;
 	for(i=0;i<7;i++){
 		seq=conta_sequenze(i);
 		printf("sequenze di : %d == %d\n",i,seq);
 	}

 	return EXIT_SUCCESS;
 }
