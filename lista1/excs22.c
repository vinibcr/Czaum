#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	float numero, ptFrac;
	int ptInt;
	printf("digite um inteiro:\n");
	scanf("%f", &numero);
	ptInt = numero;
	ptFrac= numero-ptInt;
	printf("%d\n", ptInt);
	printf("%f\n", ptFrac);
	printf("%f\n", round(numero));
	
	system("pause");
	
}
