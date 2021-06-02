
#include <stdlib.h>
#include <stdio.h>

typedef struct reg *no;
struct reg
{
    int nasc;
    int rg;
    char nome[20];
    char profissao[20];
    no ant, prox;
    ;
};

void cria_LLDE(no *lista)
{
    *lista = NULL;
}

void mostra_LLDE(no lista)
{
    if (lista == NULL)
    {
        printf("\n\nLista vazia");
        return;
    }
    no p = lista;
    printf("\n\nElementos da lista: ");
    do
    {
        printf("%d %s %d %s", p->rg, p->nome, p->nasc, p->profissao);
        p = p->prox;
    } while (p != NULL);
}
void mostra_LLDE_contrario(no lista)
{
    if (lista == NULL)
    {
        printf("\n\nLista vazia");
        return;
    }
    // posicionar p no �ltimo no da lista
    no p = lista;
    while (p->prox != NULL)
        p = p->prox;
    printf("\n\nElementos da lista ao contrario: ");
    do
    {
        printf("%d %s %d %s ", p->rg, p->nome, p->nasc, p->profissao);
        p = p->ant;
    } while (p != NULL);
}
void inclui_inicio_LLDE(no *lista, int rg, int nasc, char nome, char profissao)
{
    no p = (no)malloc(sizeof(struct reg));
    p->ant = NULL;
    p->rg = rg;
    p->nome = nome;
    p->nasc = nasc;
    p->profissao = profissao;
    p->prox = *lista;
    if (*lista)
        (*lista)->ant = p;
    *lista = p;
}
int main()
{
    no lista;
    int rg;
    int nasc;
    char nome;
    char profissao;
    char resp;
    cria_LLDE(&lista);
    do
    {
        printf("\nDigite um numero inteiro: ");
        scanf("%d %d %s %s", &rg, int nasc, char nome, char profissao);
        inclui_inicio_LLDE(&lista, rg, nasc, nome, profissao);
        mostra_LLDE(lista);
        printf("\nContinua (S/N)? \n");
        do
        {
            resp = toupper(getch());
        } while (resp != 'N' && resp != 'S');
    } while (resp != 'N');
    mostra_LLDE(lista);
    mostra_LLDE_contrario(lista);
    return 0;
}
