#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct listint {  /*definizione struct di lista*/
	int info;
	struct listint* next;
};
typedef struct listint* Listint;

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


int main(){	
	Listint head=NULL;
	int inserimento=0;
	while(1){
		printf("1 - Inserisci in testa nella lista\n2 - Stampa\n3 - Esci\n4 - Inserisci in coda nella lista\n5 - Distruggi lista :\n");
		scanf("%d", &inserimento);
		switch(inserimento){
			case 1:
				head=insTesta(&head);
				break;
			case 2:
				stampa(head);
				printf("La sua lunghezza e : %d\n",lungList(head));
				break;
			case 3:
				exit(1);
			case 4:
				head=insCoda(&head);
				break;
			case 5:
				distruggiL(head);
			default:
				printf("Carattere non valido\n");
				break;
		}
	}
	return 0;
}
