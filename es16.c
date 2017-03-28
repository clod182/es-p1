#include <stdlib.h>
#include <stdio.h>
#include "es16.h"
/*****************************************Funzioni ausiliarie**************************/
int aus_zain(struct oggetto v[], int n, int p, int idx){
	if(v[idx].peso<=p){
		return aus_zain(v,n,p-v[idx].peso)+v[idx].valore;
	}
	else{
		if(v.peso+pesoComp<=p){
			pesoComp=pesoComp+v.peso;
			bestComb=bestComb+v.valore;
			aus_zain(v,n-1,p,bestComb,pesoComp);
		}
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
