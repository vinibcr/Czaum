
#include <stdio.h>
#include <stdlib.h>

struct node
{

    int numeroReal, vezes;
    struct node *right, *left;
};

struct tree
{

    struct node *root;
};

void addNum(struct tree *arvore_reais, int numero);
void printTree(struct node *currentNode);
int main()
{

    int numero;
    struct tree arvore_reais;
    arvore_reais.root = NULL;
    printf("digite os números naturais, digite -0 para sair .\n");
    scanf("%d", &numero);
    while (numero != -0)
    {
        scanf("%d", &numero);
        addNum(&arvore_reais, numero);
    }
    fflush(stdin);
    printTree(arvore_reais.root);
}

void addNum(struct tree *arvore_reais, int numero)
{

    if (arvore_reais->root == NULL)
    {

        struct node *newRoot = malloc(sizeof(struct node));
        newRoot->right = newRoot->left = NULL;
        newRoot->vezes = 1;
        newRoot->numeroReal = numero;
        arvore_reais->root = newRoot;
        return;
    }

    struct node *currentNode = arvore_reais->root;
    while (currentNode->left != NULL && currentNode->right != NULL && newNode != NULL)
    {

        if (numero < currentNode->numeroReal)
        {
            if (!currentNode->left)
            {

                struct node *newNode = malloc(sizeof(struct node));
                newNode->right = newNode->left = NULL;
                newNode->vezes = 1;
                newNode->numeroReal = numero;
                currentNode->left = newNode;
                return;
            }
            else
            {
                currentNode = currentNode->left;
                continue;
            }
        }
        if (numero > currentNode->numeroReal)
        {
            if (!currentNode->right)
            {
                struct node *newNode = malloc(sizeof(struct node));
                newNode->right = newNode->left = NULL;
                newNode->vezes = 1;
                newNode->numeroReal = numero;
                currentNode->right = newNode;
                return;
            }
            else
            {
                currentNode = currentNode->right;
                continue;
            }
        }
        currentNode->vezes++;
        return;
    }
}
void printTree(struct node *currentNode)
{

    if (currentNode->left)
    {
        printTree(currentNode->left);
        printf("numeroReal: %d vezes que aparece: %d\n", currentNode->numeroReal, currentNode->vezes);
    }
    if (currentNode->right)
    {
        printTree(currentNode->right)
    }
}