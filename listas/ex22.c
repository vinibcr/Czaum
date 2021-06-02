#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char palavra[100];
	int  tam;
	printf("DIGITE A STRING:\n");
	gets(palavra);
	tam = strlen(palavra);
	printf("PRIMEIRO E ULTIMO CARACTERE:\n");
	printf("%c %c", palavra[0], palavra[tam-1]);
	return 0;
}
