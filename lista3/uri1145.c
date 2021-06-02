#include<stdio.h>
#include<stdlib.h>

int main(){
	int linhas, maximo;
	int i;
	int cont=0;
	scanf("%d", &linhas);
	scanf("%d", &maximo);
		for(i=1;i<=maximo;i++){
			cont++;
			if(cont==linhas){
					printf("%d", i);
				}
					else{
						printf("%d ", i);
					}
					if(cont==linhas){	
					cont=0;
					printf("\n");
			}
			
			
			
		}

	
}
