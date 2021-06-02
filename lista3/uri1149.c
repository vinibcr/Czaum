#include<stdio.h>
#include<stdlib.h>

int main(){
	int entry;
	int out;
	int count;
	int soma=0;
	scanf("%d", &entry);
	scanf("%d", &out);
	while(out<=0)
		scanf("%d",&out);
		for(count=1;count<=out;count++){
			soma+=entry;
			entry++;
		}
		printf("%d\n", soma);

	return 0;
}
