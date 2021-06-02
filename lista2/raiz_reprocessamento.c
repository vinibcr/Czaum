#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	float a;
	int resp;
	scanf("%f", &a);
	printf("%f\n", sqrt(a));
	printf("desejar repetir?(S/N)\n");
	scanf("%d", &resp);
	while(resp!=0){
		scanf("%f", &a);
	printf("%f\n", sqrt(a));
		
	};
	system("pause");
	
	
}
