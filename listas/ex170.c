#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>

int main(){
	char t1[100];
	char t2[20];
	char *texto;
	gets(t1);
	gets(t2);
	texto = strstr(t1,t2);
	if(texto!=NULL){
		printf("A PALAVRA ""%s"" ESTA NO TEXTO\n", texto);
	}else{
		printf("n esta no texto:-(\n");
	}
	return 0;
}
