/*Manesso Claudio 859326*/
#include <stdlib.h>
#include <stdio.h>
#include "es14.h"

void riempi_scacchiera(char *fen, char campo[DIM][DIM]) {/*------------------------------------------------------------------------------------------------es1-*/
	int i=0,j=0,c=0;	
	for(i=0;i<DIM;i++){/*inizializzo a 0 la matrice*/
		for(j=0;j<DIM;j++){
			campo[i][j]=' ';
		}
	}	
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM ;j++){		//&& fen[c]!='/'	
				if((fen[c]>=65 && fen[c]<=90) || (fen[c]>=97 && fen[c]<=122)){
					campo[i][j]=fen[c];
				}
				else{
					j=j+(50-fen[c]);
				}					
			c++;
		}
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
	printf("*****diocan\n");
}


int main() {
	char parola[]="r1bq1rk1/pp3ppp/3n4/2p1N3/2B5/7P/PPP2PP1/R1BQR1K1";	
	char* npt;
	npt=&parola;
	char campo[DIM][DIM];	
	riempi_scacchiera(&parola,campo);
	stampa_matrice(campo);

	return EXIT_SUCCESS;
}

