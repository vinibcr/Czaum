#include<stdio.h>
#include<stdlib.h>

int main(){
	int linhas;
	int numero, quadrado, cubo;
	int quadradoMais, cuboMais;
	scanf("%d", &linhas);
		for(numero=1;numero<=linhas;numero++){
			quadrado = numero*numero;
			cubo = numero*numero*numero;
			printf("%d %d %d\n", numero, quadrado, cubo);
			quadradoMais = quadrado+1;
			cuboMais = cubo+1;
			printf("%d %d %d\n", numero, quadradoMais, cuboMais);
		}
		
	
	
	return 0;
}
