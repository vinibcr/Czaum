#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct CONTA {
       int numero;
       char nome[30];
       float saldo;
        int data;
};
int main() {
  struct CONTA cliente;
  char numstr[81], resp;
  FILE *arquivo;
  	int operacao;
    printf("Selecione entre Gravação (1) e Leitura (2)");
	scanf("%d", &operacao);
	switch(operacao){
		case 1:
  if ((arquivo = fopen("contas.dat", "wb")) == NULL) {
     printf("\n Erro de abertura de arquivo");
     exit(1); 
  }
  do {
     printf("\n\n Numero da conta: ");
     gets(numstr);
     cliente.numero = atoi(numstr);
     printf("\n nome: ");
     gets(cliente.nome);
     printf("\n saldo: ");
     gets(numstr);
     cliente.saldo = atof(numstr);
     printf("\n data da ultima operacao: ");
     gets(numstr);
     cliente.data = atoi(numstr);
     fwrite(&cliente, sizeof(cliente), 1, arquivo);
     printf("\n Adicionar outro cliente (s/n)?: ");
     do {
         resp = toupper(getch());
     } while (resp != 'S' && resp != 'N');
  } while (resp == 'S');
 

	case 2:
			if((arquivo = fopen("dados.dat", "rb")) == NULL){
				printf("\n Error de abertura de arquivo");
				system ("exit");
			}
			while (fread(&cliente, sizeof(cliente), 1, arquivo)){
				printf("Numero da Conta: %d\t", cliente.numero);
				printf("Nome do Cliente: %s\n", cliente.nome);
				printf("Saldo: %.2lf\t", cliente.saldo);
				printf("Ultima operação: %d %d\n\n", cliente.data);			
		}
  fclose(arquivo);
  return 0;
};