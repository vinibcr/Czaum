#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	int entradas;
	char nome1[30];
	char opcao[30];
	int numero1;
	int numero2;
	char nome2[30];
	char soma;
	char i;

	for(i = 0;i < 30; i++){
	 nome1[i] = nome2[i] = 0;
}
	scanf("%d", &entradas);
	
	while(	entradas--){
		scanf("%s", nome1);
			scanf("%s", opcao);
		scanf("%s", nome2);
		scanf("%s", opcao);
		scanf("%d %d", &numero1, &numero2);
		
		if(numero1%2==0 && numero2%2==0){
			soma = 'P';
		}
			else if(numero1%2!=0 && numero2%2!=0){
					soma = 'P';
			}else{
				soma = 'I';
			}
	if(opcao[0] == 'P' && soma == 'P'){
		printf("%s\n", nome2);
	}else if(opcao[0] == 'I' && soma == 'I'){
		printf("%s\n", nome2);
	}else{
		printf("%s\n", nome1);
	}
	
	}	
	return 0;
}
