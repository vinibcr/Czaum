#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	float coordx, coordy;
	scanf("%f %f", &coordx , &coordy);
		if(coordx > 0 && coordy > 0){
			printf("Q1\n");
		}
			else if(coordx > 0 && coordy < 0){
				printf("Q4\n");
			}
			else if (coordx < 0 && coordy > 0){
				printf("Q2\n");
			}
			else if(coordx < 0 && coordy < 0){
				printf("Q3\n");
			}
			else if (coordx == 0 && coordy != 0 ){
				printf("Eixo X\n");
			}
			else if ( coordx != 0 && coordy == 0){
				printf("Eixo Y\n");
			}
			else {
				printf("Origem\n");
			}
		
		
	return 0;
}
