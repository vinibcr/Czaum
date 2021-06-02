#include <stdlib.h>

typedef struct reg *no;
struct reg
{
    int nasc;
    int rg;
    char nome[20];
    char profissao[20];
    struct reg *prox;
};

typedef struct
{
    no first, last;
    int total;
} Descritor;

void cria_LSECD(Descritor *lista)
{
    (*lista).first = (*lista).last = NULL;
    (*lista).total = 0;
}

void mostra_LSECD(Descritor lista)
{
    if (lista.total == 0)
    {
        printf("\nLista vazia");
        return;
    }
    no p = lista.first;
    printf("\nElementos da lista: ");
    do
    {
        printf("%d, %s, %d, %s ", p->rg, p->nome[20], p->nasc, p->profissao[20]);
        p = p->prox;
    } while (p != NULL);
    printf("\nTotal de elementos: %d\n", lista.total);
}

void insere_inicio_LSECD(Descritor *lista, int rg, int nasc, char nome, char profissao)
{
    no p;
    p = (no)malloc(sizeof(struct reg));
    p->nome[20] = nome[20];
    p->nasc = nasc;
    p->profissao[20] = profissao;
    p->rg = rg;
    p->prox = (*lista).first;
    (*lista).first = p;
    if ((*lista).total == 0)
        (*lista).last = p;
    (*lista).total++;
}

void insere_final_LSECD(Descritor *lista, int rg, int nasc, char nome, char profissao)
{
    no p;
    p = (no)malloc(sizeof(struct reg));
    p->nome[20] = nome;
    p->nasc = nasc;
    p->profissao[20] = profissao;
    p->rg = rg;
    p->prox = NULL;
    if ((*lista).total == 0)
        (*lista).first = p;
    else
        (*lista).last->prox = p;
    (*lista).last = p;
    (*lista).total++;
}

void insere_ordenada_LSECD(Descritor *lista, int rg, int nasc, char nome, char profissao)
{
    no p = (no)malloc(sizeof(struct reg));
    p->nome[20] = nome;
    p->nasc = nasc;
    p->profissao[20] = profissao;
    p->rg = rg;
    if ((*lista).total == 0 || (*lista).first->rg > rg)
    {
        p->prox = (*lista).first;
        (*lista).first = p;
        if ((*lista).total == 0)
            (*lista).last = p;
    }
    else
    {
        no q = (*lista).first, r;
        do
        {
            r = q;
            q = q->prox;
        } while (q != NULL && q->rg < rg);
        p->prox = q;
        r->prox = p;
        if (q == NULL)
            (*lista).last = p;
    }
    (*lista).total++;
}

int remove_final_LSECD(Descritor *lista)
{
    if ((*lista).total == 0)
        return 0;
    no p, q;
    p = (*lista).first;
    while (p->prox)
    {
        q = p;
        p = p->prox;
    }
    (*lista).total--;
    if ((*lista).total == 0)
        (*lista).first = (*lista).last = NULL;
    else
    {
        (*lista).last = q;
        q->prox = NULL;
    }
    free(p);
    return 1;
}

int main()
{
    int rg;
    Descritor lista;
    char resp;
    cria_LSECD(&lista);
    printf("I N S E R C A O\n");
    do
    {
        printf("\nDigite um numero inteiro: ");
        scanf("%d", &rg);
        insere_ordenada_LSECD(&lista, rg);
        mostra_LSECD(lista);
        printf("\n\nContinua (S/N)? ");
        do
        {
            resp = toupper(getch());
        } while (resp != 'N' && resp != 'S');
    } while (resp != 'N');
    mostra_LSECD(lista);
    remove_final_LSECD(&lista);
    printf("\n\nRemocao do ultimo elemento da lista realizada!\n");
    mostra_LSECD(lista);
}
