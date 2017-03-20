/*Manesso Claudio 859326 */
#include <stdlib.h>
#include <stdio.h>
#include "es14.h"

/*****************************************Funzioni ausiliarie**************************/
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
		ricerca_bin(v,min,x,inf,m-1);
		ricerca_bin(v,x,max,m+1,sup);
	}
}

int seq_bigl(int n, char last, char prev){
	if(n<=0){
		return 1;
	}
	else if (last=='B' && prev=='B'){
		return seq_bigl(n-1, 'G', last) + seq_bigl(n-1, 'R', last);
	}
	else if(last=='G'){
		return seq_bigl(n-1, 'B', last) + seq_bigl(n-1, 'G', last);
	}
	else if(last=='R'){
		return seq_bigl(n-1, 'B', last) + seq_bigl(n-1, 'R', last);
	}
	else{
		return seq_bigl(n-1, 'B', last) + seq_bigl(n-1, 'R', last) + seq_bigl(n-1, 'G', last);
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
	seq_bigl(n,'x','y');
}
