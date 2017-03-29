#include <stdlib.h>
#include <stdio.h>
#include "es16.h"
/*****************************************Funzioni ausiliarie**************************/
/*
int aus_zain(struct oggetto v[], int n, int p, int idx,int cont){
	if(cont==n){
		return 0;
	}
	else if(idx==n){
		return aus_zain(v+1,n,p,0,cont+1);
	}
	else if(v[idx].peso<=p ){
		return aus_zain(v,n,p-v[idx].peso,idx+1,cont)+v[idx].valore;
	}
	else{
			return aus_zain(v,n,p,idx+1,cont);
		}
}
*/
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
int best_zain(struct oggetto v[], int n, int p, int idx,int best,int bestb){

	if(idx==n){
		return best;
	}
	else if(idx==0){
		best=aus_zain(v,n,p,idx);
		return best_zain(v,n,p,idx+1,best,bestb);
	}
	else {
		bestb=best;
		best=aus_zain(v,n,p,idx);
		if(best>bestb){
			return best_zain(v,n,p,idx+1,best,bestb);
		}
		else{
			best=bestb;
			return best_zain(v,n,p,idx+1,best,bestb);
		}
	}
}
/*------------------------------------------------------------------------------------------------es1-*/
int zaino(struct oggetto v[], int n, int p) {
	return best_zain(v, n, p, 0,-1,-1);
}
/*------------------------------------------------------------------------------------------------es2-*/
int combinazioni_monete(struct moneta m[], int n, int somma) {
	return -1;
}
