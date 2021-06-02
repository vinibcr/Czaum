#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	float nota1, somatorio=0, notas=0, media;
	
	while(1) {
		if(notas==2) {
			break;
		}
		scanf("%f", &nota1);
		if(nota1>=0 && nota1<=10){
			notas++;
			somatorio+=nota1;
		}	
		else {
			printf("nota invalida\n");
		}	
	}
	media = somatorio/2.00;
	printf("media = %.2f\n", media);
	return 0;
}
