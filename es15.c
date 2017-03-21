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

/*****************************************Funzioni ausiliarie**************************/
void aus_somma(char *s1, char *s2, char *ris,int riporto,int i,int j){
char a;
	if(s1[i]=='\0' && s2[j]=='\0'){
		if (j>i){
			ris[j]='\0';
		}
		else{
			ris[i]='\0';
		}
	}
	else if(s1[i]=='\0' && s2[j]!='\0'){
		a='0'+s2[j]+riporto+'0';
		riporto=48+a%57;
		ris[j]=a;
		aus_somma(s1,s2,ris,riporto,i,j+1);
	}
	else if(s1[i]!='\0' && s2[i]=='\0'){
		a='0'+s1[i]+riporto+'0';
		riporto=48+a%57;
		ris[i]=a;
		aus_somma(s1,s2,ris,riporto,i+1,j);
	}
	else{
		a=s1[i]+s2[j]+riporto+'0';
		//printf("aaa=%d",a);
		riporto=48+a%57;
		ris[j]=a;
		aus_somma(s1,s2,ris,riporto,i+1,j+1);
	}
}
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
	aus_somma(s1,s2,ris,0,0,0);
}
/*------------------------------------------------------------------------------------------------es3-*/
int confronta(char *s1, char *s2) {
	return 0;
}
