#include <stdlib.h>
#include <stdio.h>
#include "es15.h"

/*void prova(char *ris, int *num) {
	int i=0;
	while(ris[i]){
		printf("%c\n",ris[i] );
		//sarebbe la stessa cosa di fare printf("%c\n",*(ris+i) );
		printf("%d\n",*num);
		i++;
	}
}*/
/*------------------------------------------------------------------------------------------------es1-*/
void converti(int n, char *ris) {
	int i=0,resto=0;
	if(n==0){
		ris[i]='0';
		ris[i+1]='\0';
	}
	else{
		while(n>0){
			resto=n%10;
			n=n/10;
			ris[i] = resto+'0';
			i++;
		}
		ris[i]='\0';
	}
}
/*------------------------------------------------------------------------------------------------es2-*/
void somma(char *s1, char *s2, char *ris) {

}
/*------------------------------------------------------------------------------------------------es3-*/
int confronta(char *s1, char *s2) {
	return 0;
}
