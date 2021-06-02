typedef struct 
{
string nome[10];
float saldo;
 string operacao[10];
 int numero_conta;

} cliente;
int main(){
cliente  cli[50];

//-----------------------
 printf("Dados: nome(sem espacos), saldo, ultima operacao, numero da conta\n");
        for(int i=0; (i <50); i++){
                printf("\nInforme os dados do cliente(%i): ",i+1);
                scanf("%s %f %s %d", &cli[i].nome, &cli[i].saldo,
                        &cli[i].operacao, &cli[i].numero_conta);
       }
 printf("\nsaldo\tNome\toperacao\tnumero_conta\n");
        for(int i=0; (i < 50); i++){
                printf("%f\t%s\t%s\t%d\n", cli[i].saldo,cli[i].nome,
                 cli[i].operacao,cli[i].numero_conta);
        }

        getchar();
        return 0;
}
