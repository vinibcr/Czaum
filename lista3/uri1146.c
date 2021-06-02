#include<stdio.h>
#include<stdlib.h>

int main(){
	int entrada;
	int cont;
	do{
	scanf("%d", &entrada);
		for(cont=1;cont<=entrada;cont++){
			printf(" %d ", cont);
		}
		if(cont != entrada){
			printf("\n", cont);
		}
		else{
			printf("%d\n", cont);
		}
	}
	while(entrada != 0);
	return 0;
	
}
