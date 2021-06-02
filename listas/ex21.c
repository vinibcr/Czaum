#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	int digitos=0;
	int carac=0;
	int tam, i;
	char frase[100];
	printf("FRASE:\n");
	gets(frase);
	tam=strlen(frase);
	for(i=0;i<tam;i++){
		if(frase[i]>= 48 && frase[i]<= 59){
			digitos++;
		}else if(frase[i] != ' ' && frase[i]!='.'){
			carac++;
		}
	}
	printf("DIGITOS: %d\nCARACTERES: %d\n", digitos, carac);
	return 0;
}
