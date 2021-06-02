#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct no {
    int num;
    struct no *prox;
    struct no *prev;
};

int main () {
    int leng, value, maxi;
    char com[5];
    struct no *ini = (struct no*) malloc(sizeof(struct no));
    ini->num = -1;
    ini->prox = NULL;
    ini->prev = NULL;
    struct no *cur = ini;
    scanf("%d", &leng);
    for ( ; leng > 0 ; leng --) {
        scanf(" %s", &com);
        if (strcmp(com,"PUSH") == 0) {
            scanf("%d", &value);
            struct no *novo = (struct no*) malloc(sizeof(struct no));
            novo->num = value;
            novo->prox = NULL;
            novo->prev = cur;
            cur->prox = novo;
            cur = novo;
        }
        else if (strcmp(com,"POP") == 0) {
            if (cur->num < 0)
            printf("EMPTY\n");
            else {
            cur = cur->prev;
            free(cur->prox);
            cur->prox = NULL;}
        }
        else if (strcmp(com,"MIN") == 0) {
            if (cur->num < 0) 
            printf("EMPTY\n");
            else {
            maxi = 1000000001;
            cur = ini;
            while (1) {
            if (cur->num < maxi && cur->num > 0)
            maxi = cur->num;
            if (cur->prox == NULL)
            break;
            else cur = cur->prox;
            }
            printf("%d\n", maxi);}
        }
    }
}