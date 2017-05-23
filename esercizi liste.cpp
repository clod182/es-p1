#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

struct listint {  /*definizione struct di lista*/
	int info;
	struct listint* next;
};
typedef struct listint* Listint;

struct liststring {  /*definizione struct di lista*/
	char* info;
	struct liststring* next;
};
typedef struct liststring* Liststring;


Listint insTesta(Listint *testa){ /*inserimento in testa della lista iterativo*/
	Listint nuovo=NULL;
	int valore=0;
	nuovo = (Listint)malloc(sizeof(struct listint));
	printf("Inserisci il valore: \n");
	scanf("%d", &valore);
	nuovo->info=valore;
	nuovo->next=*testa;
	*testa=nuovo;
	return nuovo;
}

Listint insCoda(Listint* coda){ /*Inserimento in coda della lista iterativo*/
	Listint nuovo=NULL;
	int valore=0;
	nuovo = (Listint)malloc(sizeof(struct listint));
	printf("Inserisci il valore: \n");
	scanf("%d", &valore);
	nuovo->info=valore;
	nuovo->next=NULL;
	
	if(!(*coda)){
		*coda=nuovo;
		return *coda;
	}
	else{
		Listint pc = *coda;
		while(pc->next){
			pc = pc->next;
		}
		pc->next=nuovo;
		return *coda;
	}
}

void distruggiL(Listint l){
	Listint pc = l;
	while(pc){
		l = pc->next;
		free(pc);
		pc = l;
	}
}

int lungList(Listint l){
	int lung=0;
	while(l){
		lung++;
		l=l->next;
	}
	return lung;
}

void stampa(Listint testa){ /*stampa di una lista*/
	Listint temp=NULL;
	temp=testa;
	printf("-------------Stampa Lista----------------\n");
	while(temp != NULL){
		printf("Valore: %d\n", temp->info);
		temp=temp->next;
	}
}

void stampaLS(Liststring testa){ /*stampa di una lista*/
	Liststring temp=NULL;
	temp=testa;
	printf("-------------Stampa Lista----------------\n");
	while(temp != NULL){
		printf("Valore: %s\n", temp->info);
		temp=temp->next;
	}
}
/*-----------------MIEI ES---------------------------------------------------------------------------*/
Listint riempilistadavet(int vet[],int dim){ //riempire una lista da un vettore
	int i;
	Listint neww=NULL;
	Listint pc=NULL;	
	for(i=0;i<dim;i++){
		Listint nuovo=(Listint)malloc(sizeof(struct listint));		
		nuovo->info=vet[i];
		nuovo->next=NULL;
		if(pc){
			pc->next=nuovo;
			pc=pc->next;
		}
		else{//primo elemento
			pc=nuovo;
			neww=nuovo;
		}
	}	
	return neww;
}
Listint riempilistadavetRic(int vet[],int dim,int i){	
	if(dim==i){
		return NULL;
	}
	else{
		Listint nuovo=(Listint)malloc(sizeof(struct listint));
		nuovo->info=vet[i];
		nuovo->next=riempilistadavetRic(vet,dim,i+1);			
		return nuovo;
	}
}
Liststring riempilistadastring(char* s){	
	int len,i;
	Liststring nuovo=(Liststring)malloc(sizeof(struct liststring));
	len=strlen(s);
	nuovo->info=(char*)malloc((len+1)*sizeof(char));
	for(i=0;i<len;i++){
		(nuovo->info)[i]=s[i];
	}
	(nuovo->info)[len]='\0';
	nuovo->next=NULL;
	return nuovo;		
}

Listint sommal (Listint l1, Listint l2,int carry){
	if(l1==NULL && l2==NULL && carry==0){
		return NULL;
	}
	else{
		Listint next1=NULL;
		Listint next2=NULL;
		int nextcarry=0;
		Listint nuovo=(Listint)malloc(sizeof(struct listint));
		nuovo->info=carry;
		if(l1){
			nuovo->info+=l1->info;
			next1=l1->next;
		}
		if(l2){
			nuovo->info+=l2->info;
			next2=l2->next;
		}
		nextcarry=nuovo->info/10;
		nuovo->info=nuovo->info%10;
		nuovo->next=sommal(next1,next2,carry);
		return nuovo;
	}
}

void removeint(Listint *l,int val){//rimuove tutti gli elementi val dalla lista
	if(*l){
		removeint(&(*l)->next,val);
		if((*l)->info==val){			
			//Listint pc=*l;
			*l=(*l)->next;
			//free(pc);
		}
		
	}
}

Listint controllo(Listint l,int vet[],int dim){//ritorna una lista con tutti gli elemnti presenti nella lista l ma non nel vettore vet
	if(l){
		int presente=0;
		int i;
		for(i=0;i<dim && presente==0;i++){
			if(l->info==vet[i]){
				presente=1;
			}			
		}
		if(presente==0){
				Listint nuovo=(Listint)malloc(sizeof(struct listint));
				nuovo->info=l->info;
				nuovo->next=controllo(l->next,vet,dim);
				return nuovo;			
			}
			else{
				return controllo(l->next,vet,dim);
			}
	}
	else
		return NULL;
}

int LUguali(Listint l1,Listint l2){//confronta se due liste sono uguali
	if(!l1 && !l2){
		return 1;
	}
	else if(!l1 || !l2){
		return 0;
	}
	else{
		int controllo=1;
		if (l1->info != l2->info){
			controllo=0;
		}
		return controllo && LUguali(l1->next,l2->next);
	}		
}


int mystrlen(char *s){
	int n=0;
	while(*s!='\0' && *s!=' '){
		n++;
		s++;
	}
	return n;
}
Liststring dividiparole(char* s){//divide una lista di parole 1 parola per nodo della lista
	if(*s=='\0'){
		return NULL;
	}
	else if(*s==' '){
		return dividiparole(s+1);
	}
	else{
		int i,len;
		Liststring nuovo=(Liststring)malloc(sizeof(struct liststring));
		len=mystrlen(s);
		nuovo->info=(char*)malloc((len+1)*sizeof(char));
		for(i=0;i<len;i++){
			(nuovo->info)[i]=s[i];
		}
		(nuovo->info)[len]='\0';
		nuovo->next=dividiparole(s+len);
		return nuovo;
	}
}

void cumSum(Listint l){//presa lista di int modificarla in modo che ogni nodo abbia la somma di lui fino alla fine
	if(l && l->next){
		cumSum(l->next);
		l->info+=l->next->info;
	}
}

void setz(Listint l){//data lista senza 0, modificare la lista mettendo tutti 0 dall'ultimo carattere positivo fino alla fine
	if(l){
		setz(l->next);
		if((!(l->next)||l->next->info==0)&&l->info<0){
			l->info=0;
		}
	}
}
/*-----------------------------------------------eserciziario------------------------------------*/


//es 5.1
Listint createlist (unsigned int number ) {
	if ( number == 0 )
		return NULL;
	else {
		Listint newcell = ( Listint ) malloc ( sizeof ( struct listint) ) ;
		newcell->info = number%10;
		newcell->next = createlist ( number/10 );
		return newcell ;
	}
}

//es 5.3
void remove(Listint *l){
	if(*l){
		remove(&((*l)->next));
		if((*l)->info==0){
			*l=(*l)->next;
		}
	}
}

/*-------------------------------main--------------------------------------------------------------*/

int main(){		
	int vet[3]={1,2,3};
	int vet2[3]={1,2,9};
	int vet3[10]{2,0,3,3,4,5,3,9,7,3};
	Listint prova;	
	Listint prova2;
	Listint l1;
	prova=riempilistadavet(vet,3);
	prova2=riempilistadavetRic(vet2,3,0);
	stampa(prova);
	stampa(prova2);
	l1=sommal(prova,prova2,0);
	stampa(l1);
	Listint listarimuovi=riempilistadavet(vet3,10);
	stampa(listarimuovi);
	removeint(&listarimuovi,3);
	stampa(listarimuovi);
	Listint con=controllo(prova,vet2,3);
	stampa(con);
	printf("1=sono guali, %d\n",LUguali(prova,prova2));
	
	Liststring ls1=riempilistadastring("Hello");
	stampaLS(ls1);
	Liststring ls2=dividiparole("Hello dio cane");
	stampaLS(ls2);
	
	int vt[7]{2,0,3,3,4,5,3};
	Listint ll=riempilistadavet(vt,7);
	stampa(ll);
	cumSum(ll);
	stampa(ll);
	
	int v2t[7]{2,0,3,-3,-4,-5,-3};
	Listint l2l=riempilistadavet(v2t,7);
	stampa(l2l);
	setz(l2l);
	stampa(l2l);
	return 0;
}
