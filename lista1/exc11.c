#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	float diah, diau,diast;
	float mesh, mesu, mest;
	float anoh, anou, anost;
	float vidat;
	printf("digite a data atual:\n");
	scanf("%d %d %f", &diah , &mesh, &anoh);
	printf("digite a data de nascimento do usuario:\n");
	scanf("%d %d %f", &diau, &mesu, &anou );
	diast=(diau-diah);
	mest=(mesu-mesh)*30,43;
	anost=(anou-anoh)*365.25;
	vidat= anost + mest + diast;
	printf("dias vividos:%f", vidat);
	 return 0;
	
	
	
}
