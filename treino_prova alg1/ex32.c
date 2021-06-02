#include<stdio.h>
#include<conio.h>


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
	int i, l=0;
int tam1, tam2, tam3;
scanf("%d", &tam1);
scanf("%d", &tam2);
tam3=tam1+tam2;
int vet1[tam1], vet2[tam2], vet3[tam3];
for(i=0;i<tam1;i++){
	scanf("%d", &vet1[i]);
}
for(i=0;i<tam2;i++){
	scanf("%d", &vet2[i]);
}
ordena(vet1,tam1);
ordena(vet2,tam2);

for(i=0,l=0;i<tam3;i+=2,l++){
	if(l<tam1){
		vet3[i]= vet1[l]; 
	}else{
		i--;
	}
		vet3[i+1]=vet2[l];
}
ordena(vet3,tam3);
for(i=0;i<tam3;i++){
	printf("%d\t", vet3[i]);
}
  return 0;
}
