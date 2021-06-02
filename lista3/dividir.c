#include<stdio.h>
#include<stdlib.h>

int main() {
	int dividido;
	int divisor;
	 scanf("%d", &dividido);
	 for(divisor=1;divisor<=dividido;divisor++){
	 	if(dividido%divisor==0){
	 		printf("%d\n", divisor);
		 }
	 }
	return 0;
}
