#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>

void ordena(int *vetor,int tamanho){
	int i, j, aux;
	for(i=0;i<tamanho;i++){
		for(j=(i+1);j<tamanho;j++){
			if(vetor[i]>vetor[j]){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
}
int main(){
int n,i,z;
int vetor[10];
	srand(time(NULL));
scanf("%d",&n);
vetor[0]=n;
for (i=1;i<10;i++){
    scanf("%d",&n);
    for (z=0;z<i;z++){
        if (vetor[z]==n){
        	printf("numero ja digitado");
        	 vetor[z] = rand();
        }
        else{
            vetor[z]=n;
        }
        }
    }
 	ordena(vetor,10);
    system("cls");
    for (i=0;i<10;i++){
        printf(" %d",vetor[i]);
    }
    return 0;
}

 
