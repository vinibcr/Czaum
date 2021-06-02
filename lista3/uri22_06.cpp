#include<stdio.h>
#include<stdlib.h>

int main(){
	double matriz[12][12];
	int i,j;
	double sum = 0;
	char oper[5];
	scanf("%s", &oper);
	
	for(i=0;i<12;i++)
		for(j=0;j<12;j++)
			scanf("%lf", &matriz[i][j]);
			
	for(i=1;i<=10;i++){
	if(i<=5)	
		for(j=11;j>11-i;j--)	
		sum += matriz[i][j];
		else
		for(j=11;j>i;j--)
		sum += matriz[i][j];	
}
			
		
	if(oper[0]=='M')
	sum = sum/30.0;
	printf("%.1lf\n", sum);
	
	
	return 0;
}
