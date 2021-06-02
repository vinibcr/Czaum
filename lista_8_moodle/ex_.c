#include<stdio.h>

int main(){
	int linhas;
	int numero, quadrado, cubo; 
	scanf("%d", &linhas);
	for(numero=1;numero<=linhas;numero++){
	quadrado= numero*numero;
	cubo= numero*numero*numero;
	printf("%d %d %d\n", numero, quadrado, cubo);
	}
	return 0;
}


