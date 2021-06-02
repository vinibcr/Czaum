#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char vet[20];
	gets(vet);
	int tam=0;
	int aux=0;
	tam = strlen(vet);
	int x=0;
	int y=0;

	for(x=0;x<=tam;x++){
		for(y=x+1;y<=tam;y++){
			if(vet[y]<vet[x]){
				aux = vet[x];
				vet[x] = vet[y];
				vet[y] = aux;
			}
		}
	}

	int i=0;
	for(i=0;i<tam;i++){
		printf("%c", vet[i]);
	}
	return 0;
}


