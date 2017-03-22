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
int a;
	if(s1[i]=='\0' && s2[j]=='\0'){/*caso base */
		if (riporto!=0){
			if (j>i){
				ris[j]=riporto+'0';
				ris[j+1]='\0';
			}
			else{
				ris[i]=riporto+'0';
				ris[i+1]='\0';
			}
		}
		else{
			if (j>i){
				ris[j]='\0';
			}
			else{
				ris[i]='\0';
			}
		}
	}
	else if(s1[i]=='\0' && s2[j]!='\0'){/*caso part 1*/
		a=s2[j]+riporto;
		if(a>'9'){
			a=('0'+(a%'9'))-1;
			riporto=1;
		}
		else{
			riporto=0;
		}
		ris[j]=a;
		aus_somma(s1,s2,ris,riporto,i,j+1);
	}
	else if(s1[i]!='\0' && s2[i]=='\0'){/*caso part 2*/
		a=s1[i]+riporto;
		if(a>'9'){
			a=('0'+(a%'9'))-1;
			riporto=1;
		}
		else{
			riporto=0;
		}
		ris[i]=a;
		aus_somma(s1,s2,ris,riporto,i+1,j);
	}
	else{                           /*altri casi*/
		a=s1[i]+s2[j]+riporto-'0';
		if(a>'9'){
			a=('0'+(a%'9'))-1;
			riporto=1;
		}
		else{
			riporto=0;
		}
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
	int i=0,j=0;
	if(s1[i]=='\0' && s2[j]=='\0'){
		if(s1[i]==s2[j]){
			return 0;
		}
		else if(s1[i]<s2[j]){
			return -1;
		}
		else if(s1[i]>s2[j]){
			return 1;
		}
	}
	else if(s1[i]!='\0' && s2[j]=='\0'){
		return -1;
	}
	else if(s1[i]=='\0' && s2[j]!='\0'){
		return 1;
	}
	else{
		return confronta(&s1[i+1],&s2[j+1]);
	}
}
