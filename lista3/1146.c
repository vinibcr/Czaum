#include<stdio.h>
#include<stdlib.h>

int main() {
	int entrada;
	int numeros;
	scanf("%d", &entrada);
	do{
	
	for(numeros=1;numeros<entrada;numeros++){
		printf("%d ",numeros);
		if(numeros==entrada){
			printf("%d", numeros);
			printf("/n");
			
		}
	}
	while(entrada!=0);	
return 0;
}
}
