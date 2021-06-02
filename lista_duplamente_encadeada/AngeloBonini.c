// Angelo Monte Serrat Bonini
// R.A: 191026077
typedef struct listaDupla
{
    char nome[20];
    int cpf;
    char sexo[10];
    int nascimento;
    char cargo[20];
    int salario;
    int dependentes;
    char instrucao[20];
    listaDupla *prox;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct listaDupla
{
    char nome[20];
    int cpf;
    char sexo[10];
    int nascimento;
    char cargo[20];
    int salario;
    int dependentes;
    char instrucao[20];
    int value;
    struct listaDupla *prox;
    struct listaDupla *ant;
} listaDupla, cabeca;

void inserePrimeiro(int rg, int cpf, int nascimento, char nome, char cargo, int salario, int dependentes, char instrucao)
{
    struct listaDupla *link = (struct listaDupla *)malloc(sizeof(struct listaDupla));
    link->rg = rg;
    link->cpf = cpf;
    link->nascimento = nascimento;
    link->nome = nome;
    link->cargo = cargo;
    link->salario = salario;
    link->dependentes = dependentes;
    link->instrucao = instrucao;
    link->cargo = cargo;
    link->prox = cabeca;

    cabeca = link;
}

void removeUltimoElemento(tamanho)
{
    aux = inicio;
    while (aux->prox != (struct listaDupla *)NULL && aux->tamanho != tamanho)
        aux = aux->prox;
    if (aux->tamanho == tamanho)
    {
        if (aux->prox == (struct listaDupla *)NULL)
        {
            aux->ant->prox = aux->prox;
            aux->ant = (struct listaDupla *)NULL;
            free(aux);
            aux = (struct listaDupla *)NULL;
        }
    }
}

void escreveBinario(FILE *f1){
    listaDupla empregados;
    f1=fopen("binary.dat","wb");
    if(empregados.salario > 2000){
    fwrite(&empregados,sizeof(empregados) , 1, f1); 
    }
}

listaDupla *ld_insereinicio(listaDupla *plst, int pn)
{
       listaDupla *aux;
       aux = (listaDupla*)malloc(sizeof(listaDupla));
       aux -> n = pn;
       aux -> prox = plst;
       return aux;
}
int main(){
    int rg;
    char nome[20];
    int cpf;
    char sexo[10];
    int nascimento;
    char cargo[20];
    int salario;
    int dependentes;
    char instrucao[20];
    listaDupla *empregados;
    empregados = NULL;
    File *arquivo;
    arquivo = fopen("funcionarios.txt", "r");
    if (arquivo)
    {
        do
        {
            fscanf(arquivo, "%d", &rg);
            fscanf(arquivo, "%s", &nome);
            fscanf(arquivo, "%d", &cpf);
            fscanf(arquivo, "%s", &sexo);
            fscanf(arquivo, "%d", &nascimento);
            fscanf(arquivo, "%s", &cargo);
            fscanf(arquivo, "%d", &salario);
            fscanf(arquivo, "%d", &dependentes);
            fscanf(arquivo, "%s", &instrucao);
            empregados = ld_insereinicio(empregados, rg);
            empregados = ld_insereinicio(empregados, nome);
            empregados = ld_insereinicio(empregados, cpf);
            empregados = ld_insereinicio(empregados, sexo);
            empregados = ld_insereinicio(empregados, nascimento);
            empregados = ld_insereinicio(empregados, cargo);
            empregados = ld_insereinicio(empregados, salario);
            empregados = ld_insereinicio(empregados, dependentes);
            empregados = ld_insereinicio(empregados, instrucao);
        } while (!feof(arquivo));
    }
}
