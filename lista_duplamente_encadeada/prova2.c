#include <stdio.h>
#include <stdlib.h>

typedef struct ListaEnc
{
    int codigo;
    char nomeContato[20];
    struct ListaEnc *prox;
    struct ListaEnc *ant;
} lista;

lista *criaLista()
{
    return NULL;
}

lista *insereElemento(lista *l)
{
    lista *p = NULL;
    system("cls");
    printf(">> INSERCAO DE CONTATOS <<\n\n");
    p = ((lista *)malloc(sizeof(lista)));
    printf("CODIGO: ");
    scanf("%d", &p->codigo);
    printf("NOME: ");
    setbuf(stdin, NULL);
    gets(p->nomeContato);
    p->ant = NULL;
    p->prox = l;

    return p;
}

void imprimeLista(lista *l)
{
    lista *p;
    p = l;
    system("cls");
    printf(">> CONSULTA DE CONTATOS <<\n");
    if (p == NULL)
        printf("LISTA VAZIA!");
    else
    {
        while (p)
        {
            printf("\n\nCODIGO: %d", p->codigo);
            printf("\nNOME: %s", p->nomeContato);
            p = p->prox;
        }
    }
}

void gravaArquivo(lista *l)
{
    FILE *arquivo;
    lista *p;
    p = l;

    arquivo = fopen("Contatos.txt", "wb");

    if (p == NULL)
    {
        printf("\nNAO HA CONTATOS A SEREM GRAVADOS EM DISCO."
               "\nLISTA VAZIA!");
    }
    else
    {
        fwrite(&p, sizeof(lista), 1, arquivo);
        p = p->prox;
    }
    fclose(arquivo);
    printf("\nDADOS GRAVADOS COM SUCESSO.");
}

lista *carregaContatos(lista *l)
{
    FILE *arquivo;
    lista *p;

    arquivo = fopen("Contatos.txt", "rb");
    rewind(arquivo);

    while (!feof(arquivo))
    {
        p = l;
        p = (lista *)malloc(sizeof(lista));
        if ((fread(p, sizeof(lista), 1, arquivo)) != 1)
            break;
        p = p->prox;
    }

    fclose(arquivo);
    return l;
}

int main()
{
    lista *minhaLista = criaLista();
    int op;

    do
    {
        system("cls");
        printf(">> MENU <<");
        printf("\n\n[1] - INSERIR CONTATOS"
               "\n[2] - EXCLUIR CONTATOS"
               "\n[3] - CONSULTAR CONTATOS"
               "\n[4] - GRAVAR CONTATOS EM DISCO"
               "\n[5] - CARREGAR OS CONTATOS PARA A MEMORIA");
        printf("\n\nOPCAO: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            minhaLista = insereElemento(minhaLista);
            fflush(stdin);
            getchar();
            break;
        case 3:
            imprimeLista(minhaLista);
            fflush(stdin);
            getchar();
            break;
        case 4:
            gravaArquivo(minhaLista);
            fflush(stdin);
            getchar();
            break;
        case 5:
            carregaContatos(minhaLista);
            fflush(stdin);
            getchar();
            break;
        }

    } while (op != 6);

    fflush(stdin);
    getchar();
    return 0;
}
// listaDupla *readList(listaDupla *cabeca)
// {
//     FILE *arquivo;
//     arquivo = fopen("empregados.txt", "r");
//     if (arquivo == NULL)
//     {
//         printf("Arquivo vazio\n");
//     }
//     else
//     {
//     }
//     while (!feof(arquivo))
//         if (cabeca == NULL)
//         {
//             cabeca = malloc(sizeof(listaDupla));
//             fscanf(arquivo, "%d", &cabeca->value);
//             cabeca->prox = NULL;
//         }
//         else
//         {
//             struct listaDupla *atual = cabeca;
//             struct listaDupla *temp = malloc(sizeof(listaDupla));
//             while (atual->prox != NULL)
//             {
//                 atual = atual->prox;
//             }
//             fscanf(arquivo, "%d", &temp->value);
//             atual->prox = temp;
//             temp->prox = NULL;
//         }
//     return cabeca;
// }
// void printList(listaDupla *cabeca)
// {
//     listaDupla *atual = cabeca;
//     while (atual != NULL)
//     {
//         printf("%d->", atual->value);
//         atual = atual->prox;
//     }
//     printf("NULL\n");
//     return;
// }
// int main()
// {
//     listaDupla *A = NULL; /* creating pointer to your linked list. */
//     A = readList(A);      /* Read linked list from file (And allocate it if it's not allocated */
//     printList(A);         /* print list */
//     return 0;
// }

