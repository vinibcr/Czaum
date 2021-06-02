#include <stdio.h>
#include <stdlib.h>

int main(){
	int indice, i, j, centro, centroFim;
	
	while(scanf("%d", &indice) != EOF){
		
		int matriz[indice][indice];
		
		for(i = 0; i < indice; i++)
			for(j = 0; j < indice; j++){
				if(i == j){
				 matriz[i][j] = 2;
			}
				else if(i + j == indice-1){
				 matriz[i][j] = 3;
			}
				else
				 matriz[i][j] = 0;
			}
		
		centro = indice/3;
		centroFim = indice-centro;
		
		for(i = centro; i < centroFim; i++){
		
			for(j = centro; j < centroFim; j++){
				 matriz[i][j] = 1;
				
			}
		}
		matriz[indice/2][indice/2] = 4;	
		for(i = 0; i < indice; i++){
			 for(j = 0; j < indice; j++){
				 printf("%d", matriz[i][j]);			 
			}
			 printf("\n");					
		 }
		 printf("\n");
				
	}
	return 0;
}
