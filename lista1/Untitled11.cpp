#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
		double a, b , c , d;
		double media, exame;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		fflush(stdin);
		media = (2*a+b*3+c*4+d)/10;
		printf("Media: %.1f\n", media);
			if(media>=7){
				printf("Aluno aprovado.\n");
			}
			  	else if(media>=5){
				printf("Aluno em exame.\n");
				scanf("%lf", &exame);
				printf("Nota do exame: %.1f\n", exame);
					if((exame + media)/2.0 > 5.0){
					 printf("Aluno aprovado.\n");
					}
					else{
						printf("Aluno reprovado.\n");
					}
					 printf("Media final: %.1f\n", (exame + media ) / 2.0);
				
					}
				
				else {
				printf("Aluno reprovado.\n");
			}
				
					
		return 0;	
		}
			
			
			
			
					
	
	
	
	
	
	
	


