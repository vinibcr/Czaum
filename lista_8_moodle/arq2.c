#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct DATA {
	int dia, mes, ano;	
};

struct DADOS {
	int numero_conta;
	char nome_cliente[50];
	double saldo;
	struct DATA data;	
};

int main(){
	
	setlocale (LC_ALL, "Portuguese");
	
	struct DADOS info;
	FILE *Arquivo;
	char resposta;
	int operacao;
	char numstr [100];
	
	printf("Selecione entre Gravação (1) e Leitura (2)");
	scanf("%d", &operacao);
	switch(operacao){
		case 1:
			if ((Arquivo = fopen("dados.dat", "r+b")) == NULL){
			  if ((Arquivo = fopen("dados.dat", "wb")) == NULL){
				printf("\n Error de abertura de arquivo");
				system ("exit");
			}
	    	}
			else
			  fseek (Arquivo,0,SEEK_END);
			do{
				printf("\n\n Numero da Conta: ");
				scanf("%d", &info.numero_conta);
				printf("\n\n Nome do Cliente: ");
				fflush(stdin);
				gets(info.nome_cliente);
				fflush(stdout);
				printf("\n\n Saldo: ");
				scanf("%lf", &info.saldo);
				printf("\n\n Data de ultima operação: ex.XX/XX/XXXX\n");
				scanf("%d %d %d", &info.data.dia, &info.data.mes, &info.data.ano);
				fwrite(&info, sizeof(info), 1, Arquivo); //Imprime os dados no arquivo.
				printf("\n Adicionar novo cliente (s/n)?: ");
				do {
					resposta = toupper(getch());
				} while (resposta != 'S' && resposta != 'N');
			} while (resposta == 'S');
			break;
		case 2:
			if((Arquivo = fopen("dados.dat", "rb")) == NULL){
				printf("\n Error de abertura de arquivo");
				system ("exit");
			}
			while (fread(&info, sizeof(info), 1, Arquivo)){
				printf("Numero da Conta: %d\t", info.numero_conta);
				printf("Nome do Cliente: %s\n", info.nome_cliente);
				printf("Saldo: %.2lf\t", info.saldo);
				printf("Ultima operação: %d %d %d\n\n", info.data.dia, info.data.mes, info.data.ano);			
		}
	}
	
	fclose (Arquivo);
	
	return 0;
	
}