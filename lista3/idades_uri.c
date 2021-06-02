#include<stdio.h>
#include<stdlib.h>

int main() {
	int idade;
	float cont=0;
	int somador=0;
	float media;
	while(1){
		scanf("%d", &idade);
		if(idade<0){
			break;
		}
		else{
			somador+=idade;
			cont++;
		}
	
	}
	media=somador/cont;
	printf("%.2f\n", media);
	return 0;
}
