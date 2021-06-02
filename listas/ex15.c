#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char frase[50];
	char aux[20];
	int j;
	int tam;
	gets(frase);
	tam = strlen(frase);
	for(j=0;j<tam;j++){
		 strcpy(aux, frase[j - 1]);
         strcpy(frase[j - 1], frase[j]);
         strcpy(frase[j], aux);
	}
	printf("%s\n", frase);
	return 0;
}
