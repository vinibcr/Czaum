#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char texto[40];
	int tam;
	int i,j, oco=1;
	gets(texto);
	tam = strlen(texto);
	for(i=0;i<tam;i++){
		for(j=tam;j>0;j--){
			if(texto[i]==texto[j]){
				oco++;
			}else{
				oco=1;
			}
		}
		printf("O CARACTERE %c OCORREU %d VEZES\n", texto[i], oco);
		oco=1;
	}
	return 0;
}
