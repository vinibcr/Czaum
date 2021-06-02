#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main() {
	int codigo;
	int alcool=0;
	int gasolina=0;
	int diesel=0;
	do {
	scanf("%d", &codigo);
	if(codigo==1){
		alcool++;
	}
	else if(codigo==2){
		gasolina++;
	}
	else if(codigo==3){
		diesel++;
	}
	if(codigo!=1 && codigo!=2 && codigo!=3){
		continue;
	}
	}while(codigo!=4);
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n", alcool);
	printf("Gasolina: %d\n", gasolina);
	printf("Diesel: %d\n", diesel);
	
	return 0;
}
