
//Senhas: 000123 ou 343434

#include <stdio.h>
//#include <conio.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>

int senha()						
{
	int password1 = 000123, password2 = 343434;  				
	char sen[7];
	
	do{
		
		printf("Bem vindo!"); 
		printf("BANCO DAS ILHAS WEBLANDS");
		printf("Aqui você encontra muitas vantagens!");
		printf("Para acessar ao caixa,");
		printf("digite a sua senha de acesso:");
		printf("Senha de acesso: ");	
		scanf("%s",&sen);
		
 		if(atoi(sen) == password1 || atoi(sen) == password2)				
			{
				printf("Senha correta!");
				system("cls");
				if(atoi(sen) == password1) return 1; 
				else return 0; 
			}else 
			{
				printf("Senha Incorreta!");
				system("cls");
			}	
	}while(atoi(sen) != password1 && atoi(sen) != password2);	
}

int menu(int u)							
{
	int op; 
	
	do{	
		printf("\n\t    BANCO DAS ILHAS WEBLANDS\n");
		if(u == 1) printf("Cliente: John Doe");
		else printf("Cliente: Jane Doe"); 
		printf("Escolha uma das opções para saque: ");
		printf("1 - Cheque");
		printf("2 - Dinheiro");
		printf("Opção: ");
		scanf("%d",&op);
		
		system("cls"); 
		
		switch(op)
		{
			case 1: 	return 1; 
						break; 
			case 2: 	return 0; 
						break; 			
		}
	}while(op != 2 && op != 1);	
}

void ler_q(char q[], int n)			
{
	int i, a=0, flag = 0, cont = 0; 
	fflush(stdin);
	printf("BANCO DAS ILHAS WEBLANDS\n");
	printf("SAQUE: ");
	printf("Digite a quantia desejada do saque em ");
	if(n == 0) printf("dinheiro");
	else printf("cheque");

	do{
		a = flag = cont = 0; 
		fflush(stdin);
		printf(" R$: ");
		gets(q);
			
		
		for(i=0;i<strlen(q);i++){
			if(q[i] == '.' || q[i] == ','){
				a++;
				flag = 1;
			}
			if(flag == 1)
				cont++;
			}
				
		if(a > 1 || cont > 3)
			printf("\n\n\t\tValor invalido! ");
		}while(a > 1 || cont > 3);
}

void trata_string(char q[])			 
{
	char aux2[20];
	int i, tam, flag = 0, aux; 
	tam = strlen(q) ;
	
	for(i=0; i<tam; i++)
		if(q[i] == '.' || q[i] == ',')
			flag = 1; 
	
	if(flag == 1)
	{
		for(i=0; i<tam; i++)
			if(q[i] == '.' || q[i] == ',')
				q[i] = '0';
	}else strcat(q, "000");
	
	tam = strlen(q);
	
	aux = 15 - strlen(q);
	
	for(i=0; i<aux; i++)
		aux2[i] = '0';
	
	strcat(aux2, q);
	strcpy(q, aux2);
	
	strrev(q);
}

void extenso(char q[], int n,char f[], long *ant)		 
{
	int un, dez, cent, soma, flag;  
										
	un = q[0] - 48;						
	dez = q[1] - 48;					
	cent = q[2] - 48;					
	
	switch(cent)
	{
			case 1: if(dez == 0 && un == 0) strcat(f," Cem "); 
					else strcat(f," Cento "); 
					break; 
			case 2: strcat(f," Duzentos "); break;
			case 3: strcat(f," Trezentos "); break;
			case 4: strcat(f," Quatrocentos "); break;
			case 5: strcat(f," Quinhentos "); break;
			case 6: strcat(f," Seiscentos "); break;
			case 7: strcat(f," Setecentos "); break;
			case 8: strcat(f," Oitocentos "); break;
			case 9: strcat(f," Novecentos "); break;
	}
	
	if(cent > 0 && (dez != 0 || un != 0)) strcat(f,"e");
	
	switch(dez)
	{
		case 1: switch(un)
				{
					case 0:  strcat(f," Dez "); break;
					case 1:  strcat(f," Onze "); break;
					case 2:  strcat(f," Doze "); break;
					case 3:  strcat(f," Treze "); break;
					case 4:  strcat(f," Quatorze "); break;
					case 5:  strcat(f," Quinze "); break;
					case 6:  strcat(f," Dezeseis "); break;
					case 7:  strcat(f," Dezesete "); break;
					case 8:  strcat(f," Dezoito "); break;
					case 9:  strcat(f," Dezenove "); break;	
				}
				break;
				
		case 2: strcat(f," Vinte "); break;
		case 3: strcat(f," Trinta "); break;
		case 4: strcat(f," Quarenta "); break;
		case 5: strcat(f," Cinquenta "); break;
		case 6: strcat(f," Sessenta "); break;
		case 7: strcat(f," Setenta "); break;
		case 8: strcat(f," Oitenta "); break;
		case 9: strcat(f," Noventa "); break;
	}
	
	if(dez > 1) strcat(f,"e");
	
	if(dez != 1)
	{
		switch (un)
			{
				 
				case 1:  if(n != 2) strcat(f," Um "); break;
				case 2:  strcat(f," Dois "); break;
				case 3:  strcat(f," Tres "); break;
				case 4:  strcat(f," Quatro "); break;
				case 5:  strcat(f," Cinco "); break;
				case 6:  strcat(f," Seis "); break;
				case 7:  strcat(f," Sete "); break;
				case 8:  strcat(f," Oito "); break;
				case 9:  strcat(f," Nove "); break;
			}
	}
}

void bilhao(char q[],int n,char f[])			
{
	int un, dez, cent, soma; 
	int soma1, soma2, soma3, soma4, soma5;
									
	un = q[0] - 48;						
	dez = q[1] - 48;					
	cent = q[2] - 48;					
	
	soma = (cent * 100) + (dez * 10) + un;
	
	switch(n)
	{
		case 0:		soma1 = soma; 
					if(soma == 1) strcat(f,"Bilhão");
					else if(soma != 0) strcat(f,"Bilhões");
					break;
		case 1:		soma2 = soma; 
					if(soma == 1) strcat(f,"Milhão");
					else if(soma != 0) strcat(f,"Milhões");
					break; 
		case 2:		soma3 = soma; 
					if(soma != 0) strcat(f,"Mil");
					break; 
		case 3:		soma4 = soma; 
					if(strlen(f) > 2) 
						if(soma1 == 0 && soma2 == 0 && soma3 == 0 && soma4 == 1) strcat(f,"Bit");
						else strcat(f," Bits");
					break; 
		case 4:		soma5 = soma; 
					if(soma != 0 )	strcat(f,"CentBits");
					break; 		
	}	
}

void cheque(char q[])				
{
	int i, cont = 14; 
	int dia, mes, ano; 
	long anterior = 0;
	char a[3], fim[250] = " ";
	
	printf("\t\t(Exemplo de data: 28 01 2018)\n");
	do{
		printf("\t\tDigite a data do preenchimento: ");
		scanf("%d %d %d",&dia,&mes,&ano);
	} while((dia < 0 || dia > 31) || (mes < 0 || mes > 12) || (ano < 2017 || ano > 2050));
	
	printf("\n\n\n\t\tSaque em cheque: ");
	printf("\n\t\tQuantia:");
	
	for(i = 0; i < 5; i++)
	{
		a[0] = q[cont - 2];
		a[1] = q[cont - 1];
		a[2] = q[cont];
		cont-=3; 
		
		extenso(a,i,fim,&anterior);
		bilhao(a,i,fim);
	}
	
	if(strlen(fim) > 1)	puts(fim);
	else printf("Quantia digitada igual a zero!");
	
	printf("\n\n\t\t\tData do cheque: %d / %d / %d ",dia, mes, ano);
	printf("\n\n\t\tBanco das Ilhas Weblands!\n\n\n");
}

void dinheiro(char q[])				
{
	int i, cont = 14, valor; 
	double total = 0, soma = 0;  	
	int nota100, nota50, nota20, nota10, nota5, nota2, nota1, md5, md25, md10, md1; 	
	nota100 = nota50 = nota20 = nota10 = nota5 = nota2 = nota1 = md5 = md25 = md10 = md1 = 0; 
	char a[3];
	
	for(i = 0; i < 5; i++)
	{
		a[2] = q[cont - 2];
		a[1] = q[cont - 1];
		a[0] = q[cont];
		cont-=3; 
		
		valor = atoi(a);
		
		switch(i)		
		{
			case 0:    total = total + valor * 10000000;
					   break; 
			case 1:    total = total + valor * 10000; 
					   break; 
			case 2:    total = total + valor * 10; 
					   break; 
			case 3:    while(valor >= 100) {
							nota100++; 
							valor-=100; 		
					   }
					   while(valor >= 50)  {
					   		nota50++; 
					   		valor-=50;
					   }
					   while(valor >= 20)  {
					   		nota20++; 
					   		valor-=20; 
					   }
					   while(valor >= 10)  {
					   		nota10++; 
					   		valor-=10;
					   }
					   while(valor >= 5)   {
					   		nota5++; 
					   		valor-=5;
					   }
					   while(valor >= 2)   {
					   		nota2++; 
					   		valor-=2; 
					   }
					   while(valor >= 1)   {
					   		nota1++; 
					   		valor--; 
					   }
					   break; 
			
			case 4:    while(valor >= 50) {
					   		md5++; 
					   		valor-=50; 
					   }
					   while(valor >= 25) {	
					   		md25++; 
					   		valor-=25;
					   }
					   while(valor >= 10) {
					   		md10++;
					   		valor-=10;
					   }
					   while(valor >= 1)  {
					   		md1++;
					   		valor--;
					   }
					   break;}
	}	
	
	printf("\n\n");
	
	if(total > 0 || nota100 > 0)	{
		total = total + nota100;
		printf("\n\t\tNotas de $100 bits: %.0lf",total);		
	}
	if(nota50 > 0)	printf("\n\t\tNotas de $50 bits: %d",nota50);
	if(nota20 > 0)  printf("\n\t\tNotas de $20 bits: %d",nota20);
	if(nota10 > 0)  printf("\n\t\tNotas de $10 bits: %d",nota10); 
	if(nota5 > 0)   printf("\n\t\tNotas de $5 bits: %d",nota5);
	if(nota2 > 0)	printf("\n\t\tNotas de $2 bits: %d",nota2); 
	if(nota1 > 0)   printf("\n\t\tMoedas de $1 bits: %d",nota1);
	if(md5 > 0)	    printf("\n\t\tMoedas de $0,50 centbits: %d",md5); 
	if(md25 > 0)	printf("\n\t\tMoedas de $0,25 centbits: %d",md25); 
	if(md10 > 0)	printf("\n\t\tMoedas de $0,10 centbits: %d",md10); 
	if(md1 > 0)		printf("\n\t\tMoedas de $0,01 centbits: %d",md1);
	
	printf("\n\n\n");
	
	soma = total + nota50 + nota20 + nota10 + nota5 + nota2 + nota1 + md5 + md25 + md10 + md1; 
	
	if(total >= 30) printf("\n\n\t\tQuantias maiores que $3000\n\t\tdevem ser retiradas com o atendente no caixa interno!");
	else if(soma == 0)	 printf("\n\t\tQuantia digitada igual a zero!"); 
		else {
				printf("\n\n\t\t\t  Retire o dinheiro...");
				_sleep(2000); 
				printf("\n\t\t\t (maquina solta o dinheiro)\n\n");
		}
	}

int main()
{
	int saque, user; 
	char quantia[20], e; 
	setlocale(LC_ALL, "Portuguese");
	
	do{
		user = senha();
		do{							
			saque = menu(user);
			ler_q(quantia,saque);
			trata_string(quantia);		
			
			if(!saque) dinheiro(quantia);			
			else cheque(quantia);
			
			_sleep(1500);
			
			printf("\n\t Realizar outra operação?: ");
			do{	
				scanf("%c",&e);
				e = toupper(e);
			}while(e != 'S' && e != 'N');
			if(e != 'N') system("cls");
			fflush(stdin);			
		} while(e != 'N');
		
		printf("\n\t Deseja mudar de usuario?: ");
		do{
			scanf("%c",&e);
			e = toupper(e);
		} while(e != 'S' && e != 'N');
		system("cls");
	} while(e != 'N');
	
	gotoxy(24,4); 
	printf("Operação finalizada!");		
	gotoxy(18,8);
	printf("Obrigado por usar o banco das ilhas Weblands");
	gotoxy(24,12); 
	printf("Volte sempre!\n\n\n\n");
	_sleep(2000);	
}