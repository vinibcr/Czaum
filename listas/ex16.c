#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char frase[50];
	char letra;
	int i, tam;
	gets(frase);
	scanf("%c", &letra);
	tam = strlen(frase);
	for(i=0;i<tam;i++){
		if(frase[i]==letra){
			printf("LETRA %c APARECE NA POSICAO %d\n", letra, i+1);
		}
	}
	
	return 0;
}
