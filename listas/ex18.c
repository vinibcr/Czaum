#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int dia;
	int mes;
	int ano;
	char diac[10];
	char mesc[10];
	char anoc[10];
	printf("DIGITE A DATA:\n");
	scanf("%d %d %d", &dia, &mes, &ano);
	itoa(dia,diac,10);
	itoa(mes,mesc,10);
	itoa(ano,anoc,10);
	printf("DATA: %s %s %s", diac, mesc, anoc);
	return 0;
}
