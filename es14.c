/*Manesso Claudio 859326*/
#include <stdlib.h>
#include <stdio.h>
#include "es14.h"

void riempi_scacchiera(char *fen, char campo[DIM][DIM]) {/*------------------------------------------------------------------------------------------------es1-*/
	int i=0,j=0;
	for(i=0;i<DIM;i++){/*inizializzo a 0 la matrice*/
		for(j=0;j<DIM;j++){
			campo[i][j]='0';
		}
	}
	i=0;
	while(&fen[i]){
		printf("%c ",&fen[i]);
		i++;
	}	
}

void vettore_casuale(int v[], int n, int min, int max) {/*------------------------------------------------------------------------------------------------es2-*/
	
}

int conta_sequenze(int n) {/*------------------------------------------------------------------------------------------------es3-*/

}

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


int main() {
	char parola[]="casa";
	char *fen = &parola;
	char campo[DIM][DIM];
	stampa_matrice(campo);
	riempi_scacchiera(*fen,campo);
	stampa_matrice(campo);

	return EXIT_SUCCESS;
}

