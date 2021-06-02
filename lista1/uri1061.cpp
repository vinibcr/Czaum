#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	int diaInicio, horaInicio, minutoInicio, segundoInicio;
	int diaFim, horaFim, minutoFim, segundoFim;
	int diaTotal, horaTotal, minutoTotal, segundoTotal;
	scanf("%d", &diaInicio);
	printf("Dia %d\n", diaInicio);
	scanf("%d %d %d", horaInicio, minutoInicio, segundoInicio);
	printf("%d : %d : %d\n", horaInicio, minutoInicio, segundoInicio);
	scanf("%d", &diaFim);
	printf("Dia %d\n", diaFim);
	scanf("%d %d %d", horaFim, minutoFim, segundoFim);
	printf("%d : %d : %d\n", horaFim, minutoFim, segundoFim);
	
	diaTotal = diaFim-diaInicio;
	
	
	
}
