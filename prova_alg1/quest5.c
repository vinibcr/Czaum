#include <stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10
int main(){
	srand(time(NULL));
    int valor, existe, vetor[MAX]={0}, i = 0, n;
    
	
	    while(i < MAX){ 
		       printf("Valor: ");        
			   scanf("%d", &valor);        
			   for(n = existe = 0; n < i; n++)            
			   if(vetor[n] == valor) existe = 1;        
			   if(existe)            
			  vetor[n] = rand() % 10 + 1;       
			   else            vetor[i++] = valor;    }    
			   printf("\nVetor:\n\n");    
			   for(i = 0; i < MAX; i++)        
			   printf("%d\n", vetor[i]);
		
			   return 0;
			   }
