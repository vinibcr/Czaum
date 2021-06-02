#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char entry[50];
	const char sp[2]= " ";
	char *token;
	
	
	gets(entry);

		token = strtok(entry, sp);
		while(token != NULL){
			printf(" %s\n", token);
			token = strtok(NULL, sp);
		}
		
	return 0;
}
