#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	
	int   k, l, any;
	int t1, t2, tf;
	char primeiro[60], segundo[60], saida[130];
	int  tamanhoSA;
	int ent;
	scanf("%d", &ent);
	while(ent--){
	scanf("%s %s", primeiro, segundo);
	t1 =strlen(primeiro);
	t2 = strlen(segundo);
	if(t1>=t2){	
	for(k=0,l=0;k<2*t2;k++,l++){
	saida[k] = primeiro[l];
	k++;
	saida[k] = segundo[l];
	}
	for(k, any=t2; any<t1; k++,any++){
	saida[k] = primeiro[any];
	}
	saida[k] = '\0';
}else{
	for(k=0,l=0;k<2*t1;k++,l++){
		saida[k] = primeiro[l];
		k++;
		saida[k] = segundo[l];
	}
	for(k, any=t1;any<t2;k++,any++){
		saida[k] = segundo[any];
	}
}
	saida[k] = '\0';

	printf("%s\n", saida);
}
	return 0;
}
