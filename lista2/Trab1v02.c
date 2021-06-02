        //Trabalho 1 de Alg 1
#include <stdio.h>
#include <math.h>
int main () {
	char r;
    int opcao1,opcao2;
    float angulo,resp,arco;
    do {
    	do { system ("cls");
    		printf ("Escolha um dos calculos a serem feitos:\n");
			printf ("(1) Seno\n");
			printf ("(2) Cosseno\n");		
			printf ("(3) Tangente\n");
			printf ("(4) Secante\n");
			printf ("(5) Cossecante\n");
			printf ("(6) Cotangente\n");
			printf ("(7) Arcoseno\n");
			printf ("(8) Arcocosseno\n");
			printf ("(9) Arcocotangente\n");
			printf ("(10) para sair.\n");
    		scanf ("%d",&opcao1);
			   	if (opcao1<1||opcao1>10){
					printf ("Numero Invalido.	Digite um numero de 1 a 10!\n");
			    	}
			
			}
					 while (opcao1<1||opcao1>10);
				    		system ("cls");
				    	if (opcao1==10) {
				            	printf ("Obrigado, ateh a proxima!\n");
						        break;	
						}
						if (opcao1==7) {
						printf ("digite o valor do Seno:\n");
						scanf ("%f",&arco);
						}
							else if (opcao1==8) {
							printf ("Digite o valor do Cosseno:\n");
							scanf ("%f",&arco);
							}
								else if (opcao1==9) {
								printf ("Digite o valor da tangente:\n");
								scanf ("%f",&arco);	
								}
									else {
									opcao2=3;
									while(opcao2!=1&&opcao2!=2) {
									printf ("O Valor do Angulo sera em graus ou radianos?\n");
						    		printf ("(1) Graus\n(2) Radianos\n");
						    		scanf ("%d",&opcao2);
						    		printf ("Digite o Angulo:\n");
						    		scanf ("%f",&angulo);
										}
    								}				
								    	//escolha de angulos ou radianos
										switch (opcao2) {
											case 1: {
												angulo=angulo*M_PI/180;
												break;
											}
											case 2:
											break;
										}
														//escolha de operação
														switch (opcao1) {
															/*Sen*/case 1: {
																resp=sin(angulo);
																break;
															}
															/*Cos*/case 2: {
																resp=cos(angulo);
																break;
															}
															/*Tan*/case 3: {
																resp=tan(angulo);
																break;
															}
															/*Sec*/case 4: {
																resp=1/cos(angulo);
																break;
															}
															/*Cossec*/case 5: {
																resp=1/sin(angulo);
																break;
															}
															/*Cotang*/case 6: {
																resp=1/tan(angulo);
																break;
															}
															/*Arcosen*/case 7: {
																resp=asin(arco);
																break;
															}
															/*Arcocos*/case 8: {
																resp=acos(arco);
																break;
															}
															/*ArcTangente*/case 9: {
																resp=atan(arco);
																break;
															}
														}
		printf ("O Resultado eh: %.4f\n",resp);
		r='a';
		while(r!='s'&&r!='n') {
		printf ("Gostaria de fazer um novo calculo? (S/N)\n");
		r=getch();	
		}
		if (r=='n') {
			system ("cls");
			printf ("Obrigado, ateh a proxima!\n");
			break;
		}
	} while (opcao1!=10);
}
