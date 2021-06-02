#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float angulo, rad;
	printf("insira o angulo;\n");
	scanf("%f", &angulo);
	rad = (angulo * 175)/1000;
	printf("seno:%f\n",sin(rad) );
	printf("cosseno:%f\n", cos(rad));
	printf("tangente:%f\n", tan(rad));	
	system("pause");
	
}
