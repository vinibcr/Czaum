#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char texto[40];
	char vogais[]={'a', 'e', 'i', 'o', 'u'};
	int tamt, j, consoante=0;
	gets(texto);
	tamt = strlen(texto);
	for(j=0;j<tamt;j++){
		if(texto[j]!=vogais[0] && texto[j]!=vogais[1] && texto[j]!=vogais[2] && texto[j]!=vogais[3] && texto[j]!=vogais[4]){
			consoante++;
		}
	}
	printf("CONSOANTES: %d\n", consoante);
	return 0;
}
