#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int main(){
	char str1[40];
	char str2[40];
	char str3[100];
	
	printf("STRINGS:\n");
	gets(str1);
	gets(str2);
	strcpy(str3,str1);
	strcat(str3,str2);
		
	
	printf("CONCATENADO:\n");
	printf("%s\n", str3);
	return 0;
}
