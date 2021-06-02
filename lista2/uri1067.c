#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int inteiro;
	int i;
	scanf("%d", &inteiro);
	for(i=1;i<=inteiro;i++){
		if(i%2 !=0){
			printf("%d\n", i);
		}
	}
	system("pause");
}
