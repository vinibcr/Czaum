#include<stdio.h>
#include<stdlib.h>

int main() {
	double numerador;
	double denominador=1;
	double frac;
	double s=0;
	for(numerador=1;numerador<=39;numerador+=2){
		frac = numerador/denominador;
		s+=frac;
		denominador*=2;
	}
	printf("%.2lf\n", s);
	return 0;
}
