#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

int main() {
	int linhas;
	int numero;
	int contador=1;
	scanf("%d", &linhas);
	numero = linhas*4;	
		for(contador=1;contador<=numero;contador++){
			if(contador%4==0){					
				printf("PUM\n");
				   }else{
					printf("%d ", contador);
				}
		}
	return 0;
}
