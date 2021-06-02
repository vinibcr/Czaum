#include<stdio.h>
int main(){
    int i,j;
	int tamanho, elemento;
    while(1){
        scanf("%d",&tamanho);
        if(tamanho==0)
		break;
        for(i=1;i<=tamanho;i++){
            for(j=1;j<=tamanho;j++){
                elemento = i;
                if(j < elemento)
				elemento = j;
                if(tamanho-i+1 < elemento)
				elemento = tamanho-i+1;
                if(tamanho-j+1 < elemento)
				elemento = tamanho-j+1;
                printf("%3d",elemento);
                (j < tamanho) ? printf(" ") : printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
