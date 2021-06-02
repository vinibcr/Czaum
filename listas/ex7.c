#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char texto[100];
	int tamt, j, palavras=0;
	gets(texto);
	tamt = strlen(texto);
	for(j=0;j<tamt;j++){
		if(texto[j]==' ' || texto[j]=='.' || texto[j]=='\0'){
			palavras++;
		}
	}
	printf("%s\n", texto);
	printf("NUMERO DE PALAVRAS: %d\n", palavras);
	return 0;
}
