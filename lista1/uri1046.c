#include <stdio.h>
int main()
{
    int inicio, fim;
    scanf("%d %d", &inicio, &fim);
    	if(inicio==fim){
    		printf("O JOGO DUROU 24 HORA(S)\n");
		}
			else if(inicio<=fim){
				printf("O JOGO DUROU %d HORA(s)\n", fim-inicio);
				}
					else{
						printf("O JOGO DUROU %d HORA(S)\n", 24-inicio+fim);
					}
		
	
	return 0;
}
