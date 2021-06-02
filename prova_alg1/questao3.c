#include<stdio.h>

int main(){
	int idade[100];
	char sexo[100];
	int quant;
	int idades;
	int media;
	int menor;
	int menorh;
	int i;
	do{
		for(i=0;i<100;i++){
		scanf("%d", &idade[i]);
		scanf("%s", &sexo);
		idade[i]=menor;
		if(idade[i+1]<menor){
			idade[i+1]=menor;
		}if(idade[i]==menor && sexo=='m'){
			menorh=idade[i];
		}
		}
		idades+=idade[i];
		quant++;
		
	}while(idade != 999);
	media = idades/quant;
	printf("%d",quant);
	printf("%d",media);
	printf("%d",menor);
	printf("%d",menorh);
	return 0;
}

