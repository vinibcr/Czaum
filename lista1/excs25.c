#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	float deposito, taxa , juro, vfinal;
	printf("insira o deposito e a taxa:\n");
	scanf("%f %f", &deposito, &taxa);
	juro=deposito*taxa;
	printf("valor do rendimento:%f\n", juro);
	vfinal=deposito + juro;
	printf("valor apos rendimento:%f\n", vfinal);
	
	system("pause");
}
