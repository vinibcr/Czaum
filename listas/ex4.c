#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

int main(){
	char entrada[30];
	int i;
	int tamanho;
	while(1){
	
	gets(entrada);
	tamanho = strlen(entrada);
	for(i=0;i<tamanho;i++){
		entrada[i]=toupper(entrada[i]);
	}
	printf("%s\n", entrada);
		for(i=0;i<tamanho;i++){
		entrada[i]=tolower(entrada[i]);
	}
	printf("%s\n", entrada);
	}
	return 0;
}
