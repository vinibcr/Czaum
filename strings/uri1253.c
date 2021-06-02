#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int ent;
	int tam;
	int i;
	char pal[1000];
	scanf("%d", &ent);
	int mud;
	while(i<ent){
		int pad;
	scanf(" %[^\n]s\n", pal);
		scanf("%d", &mud);
		tam = strlen(pal);
		for(pad=0;pad<tam;pad++){
			if(pal[pad]<'A' +mud){
				pal[pad] = 'Z'-mud+(pal[pad]-'A')+1;
			}else{
			
				pal[pad] = pal[pad]-mud;
	}
	
	}
	printf("%s\n", pal);
	i++;
	}
	return 0;
}

