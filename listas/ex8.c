#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char texto[100];
	int tamt, j;
	int maiusculas=0;
	gets(texto);
	tamt = strlen(texto);
	for(j=0;j<tamt;j++){
		if(texto[j]>='A' && texto[j]<='Z'){
			maiusculas++;
		}
	}
	printf("%s\n", texto);
	printf("NUMERO DE letras maiusculas: %d\n", maiusculas);
	return 0;
}
