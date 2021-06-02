#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	double numero;
	int i;
	int positivos=0;
	double media;
	for(i=1; i<=6;i++){
		scanf("%lf", &numero);
			if(numero>0){
				positivos++;
				media += numero;
			}
		}
		printf("%d valores positivos\n", positivos);
		media=media/positivos;
		printf("%.1lf\n", media);
	
		system("pause");
}
