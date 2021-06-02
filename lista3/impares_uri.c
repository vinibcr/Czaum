#include<stdio.h>
int main(){
    int n, x, y,soma;
    int i;
    int ii;
 scanf("%d", &n);
    for(i = 0; i < n; i++){
       scanf("%d", &x);
        scanf("%d", &y);
         soma = 0;
    if(x%2==0){
    	x++;
	}        
    for(ii=0;ii<y;ii++){
       soma += x;           
       x += 2; 
            }
            printf("%d\n", soma);
            soma=0;
    }
    return 0;
}
