#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float notaUm , notaDois;
	float pesoUm , pesoDois;
	float mediaPond;
	printf("digite as notas e os pesos repectivos:\n");
	scanf("%f %f %f %f ", &notaUm, &notaDois, &pesoUm, &pesoDois);
	mediaPond = (notaUm*pesoUm + notaDois*pesoDois)/(pesoUm +pesoDois) ;
	
	printf("%f\n", mediaPond);
	
	system("pause");
}
