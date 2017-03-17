/*Manesso Claudio 859326 */
#include <stdlib.h>
#include <stdio.h>
#include "es14.h"
int RandRange(int Min, int Max)
{
    int diff = Max-Min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + Min);
}
void ricerca_bin(int v[], int min, int max, int inf, int sup){
	int x=0,m=0;
	if (sup >= inf){
		x=RandRange(min,max);
		m=(inf+sup)/2;
		v[m]=x;
		ricerca_bin(v,min,max,inf,m-1);
		ricerca_bin(v,min,max,m+1,sup);
	}
}

void riempi_scacchiera(char *fen, char campo[DIM][DIM]) {/*------------------------------------------------------------------------------------------------es1-*/
	int i=0,j=0,c=0;	
	for(i=0;i<DIM;i++){/*inizializzo a 0 la matrice*/
		for(j=0;j<DIM;j++){
			campo[i][j]=' ';
		}
	}	
	for(i=DIM;i>0;i--){
		for(j=0;j<DIM ;j++){		
				if((fen[c]>='a' && fen[c]<='z') || (fen[c]>='A' && fen[c]<='Z')){
					campo[i-1][j]=fen[c];
				}
				else if(fen[c]>='0' && fen[c]<='9'){
					j=j+(fen[c]-'0')-1;
				}					
			c++;
		}
		c++;		
	}		
}

void vettore_casuale(int v[], int n, int min, int max) {/*------------------------------------------------------------------------------------------------es2-*/	
	ricerca_bin(v,min,max,0,n);
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
	int v[10]={-1,-1,-1,-1,-1};
	int z=0;
	for(z=0;z<10;z++){
		vettore_casuale(v,10,2,3);
		stampa_vettore(v,10);
	}
	
	return EXIT_SUCCESS;
}

