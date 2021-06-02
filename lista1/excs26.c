#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	double raio;
	double volume;
	double pi= 3.114159;
	scanf("%lf", &raio);
	volume= 4.0*pi*pow(raio,3)/3;
	printf("VOLUME = %lf\n", volume);
	
	
	
	system("pause");
}
