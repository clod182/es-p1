#include <stdlib.h>
#include <stdio.h>
#include "es16.h"
/*****************************************Funzioni ausiliarie**************************/
int aus_zain(struct oggetto v[], int n, int p, int idx){
	if(idx==n){
		return 0;
	}
	else if(v[idx].peso<=p ){
		return aus_zain(v,n,p-v[idx].peso,idx+1)+v[idx].valore;
	}
	else{
			return aus_zain(v,n,p,idx+1);
		}
}
/*------------------------------------------------------------------------------------------------es1-*/
int zaino(struct oggetto v[], int n, int p) {
	return aus_zain(v, n, p, 0);
}
/*------------------------------------------------------------------------------------------------es2-*/
int combinazioni_monete(struct moneta m[], int n, int somma) {
	return -1;
}
