#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	float x1, x2, y1, y2;
	float comp, altura, distancia;
	
	printf("digite as coordenadas:\n");
	scanf("%f %f %f %f ", &x1, &x2, &y1, &y2);
	comp= pow(x2-x1,2);
	altura= pow(y2-y1,2);
	distancia= sqrt (altura+comp);

	printf("distancia entre P e Q:%f\n", distancia );
	
	
	system("pause");
}
