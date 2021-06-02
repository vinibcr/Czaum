#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main(){
	char letra;
	scanf("%c",&letra);
	letra= toupper(letra);
	printf("%c", letra);
	return 0;
	
}
