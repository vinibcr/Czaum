#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
int main(){
	char texto[50];
	
	int A=0, E=0, I=0, O=0, U=0;
	int j;
	int tam;
	while(1){
	
	gets(texto);
	tam = strlen(texto);
	for(j=0;j<tam;j++){
		if(texto[j]=='a'){
			A++;
		}
		 if(texto[j]=='e'){
			E++;
		}
		 if(texto[j]=='i'){
			I++;
		}
		 if(texto[j]=='o'){
			O++;
		}
		 if(texto[j]=='u'){
			U++;
		}
	}
	printf("vogal A: %d\n", A);
	printf("vogal E: %d\n", E);
	printf("vogal I: %d\n", I);
	printf("vogal O: %d\n", O);
	printf("vogal U: %d\n", U);
	A=0, E=0, I=0, O=0, U=0;
}
	return 0;
}
