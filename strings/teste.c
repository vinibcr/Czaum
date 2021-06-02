#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char palavra[10000];
int entradas;
int tam;
int i=0;

scanf("%d\n", &entradas);

while(i < entradas){
	int elem=0;
	scanf("%[^\n]s\n", palavra);
	tam = strlen(palavra);
	while(elem<tam){
		int k;
		if(palavra[elem]>= 'a' && palavra[elem] <= 'z'){
			palavra[elem] = palavra[elem]+3;
		}else if(palavra[elem]>= 'A' && palavra[elem] <= 'Z'){
				palavra[elem] = palavra[elem]+3;
		}
		elem++;
	}
	
	char letra;
	int cont;
	for(cont=0;cont<tam/2;cont++){
		letra = palavra[cont];
		palavra[cont] = palavra[tam-1-cont];
		palavra[tam-1-cont] = letra;
	}
	
	
	int metade;
	int b;
	for(metade=tam/2;metade<tam;metade++){
		palavra[metade] = palavra[metade]-1;
		
	}
	printf("%s\n", palavra);
	i++;
}
return 0;	
}
