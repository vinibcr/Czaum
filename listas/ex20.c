#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	int palavras=0;
	int carac=0;
	int tam, i;
	char frase[100];
	printf("FRASE:\n");
	gets(frase);
	tam=strlen(frase);
	for(i=0;i<tam;i++){
		if(frase[i]==' ' || frase[i]=='.'){
			palavras++;
		}else{
			carac++;
		}
	}
	printf("PALAVRAS: %d\nCARACTERES: %d\n", palavras, carac);
	return 0;
}
