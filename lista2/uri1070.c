#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int numero;
	int impares;
	scanf("%d", &numero);
	for(impares=numero;impares<=numero+12;impares++){
		if(impares%2!=0){
			printf("%d\n", impares);
		}
	}
	
	
	
	
	system("pause");
	
}
