#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char entrada[40];
	int i, tama;
	gets(entrada);
	tama= strlen(entrada);
	for(i=0;i<tama;i++){
		if(entrada[i]== 'a' || entrada[i]=='e' || entrada[i]=='o' || entrada[i]=='u' || entrada[i]=='i'|| entrada[i]== 'A' || entrada[i]=='E' || entrada[i]=='O' || entrada[i]=='U' || entrada[i]=='I'){
			entrada[i]='*';
		}
	}
	printf("%s\n", entrada);
	return 0;
}
