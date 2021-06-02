#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	double numero;
	int i;
	int positivos=0;
	for(i=1; i<=6;i++){
		scanf("%lf", &numero);
			if(numero>0){
				positivos++;
			}
		}
		printf("%d valores positivos\n", positivos);
	
		system("pause");
}
